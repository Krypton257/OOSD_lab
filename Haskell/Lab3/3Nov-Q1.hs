--function for elements smaller than pivot
smallerthanPivot :: Int -> [Int] -> [Int]
smallerthanPivot pivot z = [y | y <- z, y <= pivot]

--function for elements larger than pivot
largerthanPivot :: Int -> [Int] -> [Int]
largerthanPivot pivot z = [y | y <- z, y > pivot]

quicksort:: [Int] -> [Int]
quicksort [] = []
quicksort [x] = [x]
quicksort (x:xs) = quicksort (smallerthanPivot x xs) ++ [x] ++ quicksort (largerthanPivot x xs)

arr1 = [14, 47, 63, 20, 47, 100, 5]
arr2 = [2, 4, 1, 7, 4, 6]

main = do
    print $ quicksort arr1
    print $ quicksort arr2
