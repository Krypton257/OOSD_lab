--Ques3
--19MA20039--Rahul Saini

checkPythagoreantriplet :: (Int, Int, Int) -> Bool
checkPythagoreantriplet (x, y, z) = x*x + y*y + z*z == 2 * z * z
    where set = [x,y,z]

triplet :: Int -> [(Int,Int,Int)]
triplet k = [(x,y,z)|x<-[1..k], y<-[1..x], z<-[1..k], checkPythagoreantriplet(x,y,z)]

main = do
    putStrLn "Enter the value till which we need to print triplets"
    k <- getLine 
    let n = read k::Int
    print $ triplet n