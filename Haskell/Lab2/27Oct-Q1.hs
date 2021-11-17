flattenlist :: [[a]] -> [a]
flattenlist [] = []
flattenlist (x:xs) = x ++ flattenlist xs

list1 = [[1, 5, 6],[6, 0, 4],[23, 9, 5]]
list2 = [[1, 5, 3],[1, 0],[5],[9, 4, 7, 3]]

main = do
    print $ flattenlist list1
    print $ flattenlist list2
