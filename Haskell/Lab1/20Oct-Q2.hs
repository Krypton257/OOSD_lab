checkPythagoreantriplet :: (Int, Int, Int) -> Bool
checkPythagoreantriplet (x, y, z) = x*x + y*y + z*z == 2 * z * z
    where set = [x,y,z]

triplet :: Int -> [(Int,Int,Int)]
triplet n = [(a,b,n) | a <- [2..n], b <- [2..a-1], checkPythagoreantriplet (a,b,n)]

main = do
    putStrLn "Enter the value of n "
    k <- getLine 
    let n = read k::Int
    print $ triplet n
