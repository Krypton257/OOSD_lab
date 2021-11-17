--Ques2
--19MA20039
--Rahul Saini

rev :: [Int] -> [Int]
rev [] = []
rev (x : xs) = rev(xs) ++ [x]

isPalindrome :: [Int] -> Bool
isPalindrome xs = xs == (rev xs)

arr1 = [14, 47, 63, 47, 14]
arr2 = [2, 4, 1, 7, 4]

main = do
    print $ isPalindrome arr1
    print $ isPalindrome arr2