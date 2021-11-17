--Ques2
--19MA20039
--Rahul Saini

data Btree a = Empty | Node (Btree a) a (Btree a)

flatten :: Btree a -> [a]
flatten Empty = []
flatten (Node lt x rt) = (flatten lt) ++ [x] ++ (flatten rt)

is_increasing :: (Ord a) => [a] -> Bool
is_increasing [] = True
is_increasing [_] = True
is_increasing (x : y : xs) = (x <= y) && (is_increasing (y : xs))

is_bst :: (Ord a) => Btree a -> Bool
is_bst Empty = True
is_bst t = is_increasing (flatten t)

tree1 = (Node (Node (Node Empty 1 Empty) 3 (Node Empty 6 Empty)) 8 (Node Empty 10 (Node Empty 14 Empty)))

--tree1
{-
        8
       / \
      3   10
    / \    \
   1   6    14

-}

tree2 = (Node (Node (Node Empty 7 Empty) 15 (Node Empty 22 Empty)) 30 (Node Empty 13 Empty))

--tree2
{-
          30
         / \
        15  13
       /\   
      7  22 

-}

main = do
     print $ is_bst tree1
     print $ is_bst tree2
