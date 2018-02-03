# Matrix-Lib-for-C

  This a header file for C which gives varible like functionalities to 2D matrices.
  All functions will accept pointers as input and return pointer/value depending on function.
  The following are the propossed functions for this project,
  
 1)sum(X,Y)
 
            Input
                  X -type(pointer to 2D array)
                  Y -type(pointer to 2D array)
                  
            Return
                  A pointer pointing to a 2D array containing the sum of X and Y.

 2)diff(X,Y)
 
            Input
                  X -type(pointer to 2D array)
                  Y -type(pointer to 2D array)
            Return
                  A pointer pointing to a 2D array containing the difference of X and Y.(i.e X - Y)
                  
 3)prod(X,Y)
 
            Input
                  X -type(pointer to 2D array)
                  Y -type(pointer to 2D array)
            
                     
            Return
                  A pointer pointing to a 2D array containing the product of X and Y.  
            
            Note:Dimensions of X and Y need to be compatible for multiplication.
         
  
  4)div(X,Y)
  
            Input
                  X -type(pointer to 2D array)
                  Y -type(pointer to 2D array)
            
           
            
            Return
                  A pointer pointing to a 2D array containing the divident of X and Y.
             
            Note:Divion by 0 may throw errors.
