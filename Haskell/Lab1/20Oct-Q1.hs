checkPythagoreantriplet :: (Int, Int, Int) -> Bool
checkPythagoreantriplet (x, y, z) = x*x + y*y + z*z == 2 * maximum set * maximum set
    where set = [x,y,z]
    
main = do
  
  print $ checkPythagoreantriplet (12,5,13)  
  print $ checkPythagoreantriplet (4,8,12)
  print $ checkPythagoreantriplet (10,6,8)
