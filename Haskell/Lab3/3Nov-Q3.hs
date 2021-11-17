combination :: Int -> [a] -> [[a]]
combination 0 _ = [[]]
combination n xs = [ xs !! i : x | i <- [0..(length xs) -1]
                                  , x <- combination (n-1) (drop (i+1) xs) ]

calcCombination :: [a] -> [[a]]
calcCombination x = [y | i<- [1..(length x)], y<- combination i x ]

arr1 = [2,3,4]
arr2 = [1,3,2,5]

main = do
    print $ calcCombination arr1
    print $ calcCombination arr2
