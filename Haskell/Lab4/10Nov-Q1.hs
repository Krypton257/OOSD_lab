data Heap a = Empty
             | Branch (Heap a) a (Heap a)
      deriving Show

leaf :: a -> Heap a
leaf x = Branch Empty x Empty

heapSort :: Ord a => [a] -> [a]
heapSort = sortH . initH

initH :: Ord a => [a] -> Heap a
initH = foldl (flip insert) Empty

insert :: Ord a => a -> Heap a -> Heap a
insert x Empty = leaf x
insert x (Branch left y right) =
   if x<y then Branch right y (insert x left)
          else Branch right x (insert y left)

sortH :: Ord a => Heap a -> [a]
sortH Empty                 = []
sortH (Branch left x right) = x : sortH (promote left right)

promote :: Ord a => Heap a -> Heap a -> Heap a
promote Empty right = right
promote left  Empty = left
promote l@(Branch l1 x1 r1) r@(Branch l2 x2 r2) =
 if x1>x2 then Branch (promote l1 r1) x1 r
            else Branch l x2 (promote l2 r2)

main = do 
    print $ heapSort [16,4,10,14,7,9,3,2,8]
