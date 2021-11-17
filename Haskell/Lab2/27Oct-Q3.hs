import Data.List (delete)
 
selectionSort :: (Ord a) => [a] -> [a]
selectionSort [] = []
selectionSort xs = selectionSort (delete x xs) ++ [x]
  where x = maximum xs

arr1 = [14, 47, 63, 47, 14]
arr2 = [2, 4, 1, 7, 4]

main = do
    print $ selectionSort arr1
    print $ selectionSort arr2
