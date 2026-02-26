import unittest
import solution



class TestSum(unittest.TestCase):
    def test_1(self):
        lst = range(10)
        lst_len = len(lst)
        self.assertEqual(solution.len_massive(lst), lst_len)

    def test_2(self):
        lst = list(range(10 ** 2))
        lst_len = len(lst)
        self.assertEqual(solution.len_massive(lst), lst_len)

    def test_3(self):
        lst = range(10 ** 3)
        lst_len = len(lst)
        self.assertEqual(solution.len_massive(lst), lst_len)

    def test_4(self):
        lst = range(10 ** 4)
        lst_len = len(lst)
        self.assertEqual(solution.len_massive(lst), lst_len)

    def test_5(self):
        lst = range(10 ** 5)
        lst_len = len(lst)
        self.assertEqual(solution.len_massive(lst), lst_len)

    def test_6(self):
        lst = range(10 ** 6)
        lst_len = len(lst)
        self.assertEqual(solution.len_massive(lst), lst_len)


if __name__ == "__main__":
    unittest.main()
