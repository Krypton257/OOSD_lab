data Btree a = Empty | Node (Btree a) a (Btree a)

max_t :: Int -> Int -> Int
max_t  x y = if x > y then x
                else y

tree_ht :: Btree Int -> Int
tree_ht  Empty = 0
tree_ht  (Node lt x rt) = max_t  ((tree_ht lt )+1) ((tree_ht rt)+1)

bst :: Btree Int -> Int -> [Int]
bst Empty i = []
bst (Node lt x rt) 1 = [x]
bst (Node Empty x rt) i = bst rt (i-1)
bst (Node lt x Empty) i = bst lt (i-1) 
bst (Node lt x rt) i = bst lt (i-1) ++ bst rt (i-1)

printbst :: Int -> Int -> Btree Int -> [Int]
printbst i h t  = if(i <= h) then bst t i ++ printbst (i+1) h t
                  else []

tree1 = (Node (Node (Node Empty 7 Empty) 5 (Node Empty 3 Empty)) 6 (Node (Node Empty 9 Empty) 4 Empty))

--tree1
{-
        6
       / \
      5    4
    / \    /
   7   3  9

-}

tree2 = (Node (Node (Node Empty 9 Empty) 6 (Node Empty 5 Empty)) 8 (Node (Node Empty 10 Empty) 4 (Node Empty 2 Empty)))

--tree2
{-
          8
         / \
        6   4
       /\   /\
      9  5 10 2

-}

main = do
     let h1 = tree_ht tree1
     let h2 = tree_ht tree2
     print $ printbst 1 h1 tree1
     print $ printbst 1 h2 tree2
