import threading
import sys

MAZE = """
#######################################################################
#S#                 #       # #   #     #         #     #   #         #
# ##### ######### # ### ### # # # # ### # # ##### # ### # # ##### # ###
# #   #     #     #     #   # # #   # #   # #       # # # #     # #   #
# # # ##### # ########### ### # ##### ##### ######### # # ##### ### # #
#   #     # # #     #   #   #   #         #       #   #   #   #   # # #
######### # # # ##### # ### # ########### ####### # # ##### ##### ### #
#       # # # #     # #     # #   #   #   #     # # #   #         #   #
# # ##### # # ### # # ####### # # # # # # # ##### ### ### ######### # #
# # #   # # #   # # #     #     #   #   #   #   #   #     #         # #
### # # # # ### # # ##### ####### ########### # ### # ##### ##### ### #
#   # #   # #   # #     #   #     #       #   #     # #     #     #   #
# ### ####### ##### ### ### ####### ##### # ######### ### ### ##### ###
#   #         #     #     #       #   # #   # #     #   # #   # #   # #
### ########### # ####### ####### ### # ##### # # ##### # # ### # ### #
#   #   #       # #     #   #   #     #       # # #     # # #   # #   #
# ### # # ####### # ### ##### # ####### ### ### # # ####### # # # ### #
#     #         #     #       #           #     #           # #      E#
#######################################################################
""".split('\n')

EMPTY = ' '
START = 'S'
EXIT = 'E'
PATH = '.'

HEIGHT = len(MAZE)
WIDTH = 0
for row in MAZE:
    if len(row) > WIDTH:
        WIDTH = len(row)

for i in range(len(MAZE)):
    MAZE[i] = list(MAZE[i])
    if len(MAZE[i]) != WIDTH:
        MAZE[i] = [EMPTY] * WIDTH

found_path = False
found_lock = threading.Lock()


def printMaze(maze):
    for y in range(HEIGHT):
        for x in range(WIDTH):
            print(maze[y][x], end='')
        print()
    print()


def findStart(maze):
    for x in range(WIDTH):
        for y in range(HEIGHT):
            if maze[y][x] == START:
                return (x, y)


def solveMazeParallel(maze, x, y, visited, result):
    global found_path

    with found_lock:
        if found_path:
            return False

    if maze[y][x] == EXIT:
        with found_lock:
            if not found_path:
                maze[y][x] = PATH
                found_path = True
                result.append(True)
        return True

    if x < 0 or x >= WIDTH or y < 0 or y >= HEIGHT:
        return False
    if maze[y][x] == '#':
        return False
    if (x, y) in visited:
        return False

    visited_copy = visited + [(x, y)]
    original = maze[y][x]

    if original != START and original != EXIT:
        maze[y][x] = PATH

    directions = [(0, -1), (1, 0), (0, 1), (-1, 0)]
    threads = []
    results = []

    for dx, dy in directions:
        new_x, new_y = x + dx, y + dy
        if 0 <= new_x < WIDTH and 0 <= new_y < HEIGHT:
            thread_result = []
            thread = threading.Thread(
                target=lambda nx, ny, vis, res: res.append(
                    solveMazeParallel(maze, nx, ny, vis, res)),
                args=(new_x, new_y, visited_copy, thread_result)
            )
            threads.append(thread)
            results.append(thread_result)
            thread.start()

    for thread in threads:
        thread.join()

    for res in results:
        if res and res[0]:
            return True

    if original != START and original != EXIT:
        maze[y][x] = original
    return False


def solveMaze(maze):
    global found_path
    found_path = False
    start_x, start_y = findStart(maze)
    result = []
    success = solveMazeParallel(maze, start_x, start_y, [], result)
    return success or (result and result[0])


if __name__ == "__main__":
    threading.stack_size(32768)
    sys.setrecursionlimit(10000)

    maze_copy = [row[:] for row in MAZE]

    print("Исходный лабиринт:")
    printMaze(maze_copy)

    if solveMaze(maze_copy):
        print("Путь найден!")
        printMaze(maze_copy)
    else:
        print("Путь не найден!")
