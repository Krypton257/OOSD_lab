--Ques2
--19MA20039
--Rahul Saini

random :: [[Int]] -> [[Int]]
random [] = []
random (x:xs) = x : random (filter (x /=) xs)

permutations :: [Int] -> [[Int]]
permutations [] = [[]]
permutations (x:xs) = [y | p <- permutations xs, y <- permu p]
  where
    permu [] = [[x]]
    permu (y:ys) = (x:y:ys) : map (y:) (permu ys)

arr1 = [3,5,7]

main = do
    print $ random (permutations arr1)