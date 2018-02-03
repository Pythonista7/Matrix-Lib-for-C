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
            
            Note:
                 * Dimensions of X and Y need to be compatible for multiplication.
         
  
  4)div(X,Y)
  
            Input
                  X -type(pointer to 2D array)
                  Y -type(pointer to 2D array)
            
           
            
            Return
                  A pointer pointing to a 2D array containing the divident of X and Y.
             
            Note: 
                 * Works as X * Y^-1{i.e - prod(X,inverse(Y))  }
                 * Divion by 0 may throw errors.
 
 
  5)inverse(X)
  
              Input
                    X -type(pointer to 2D array)
                    
              Return
                    A pointer pointing to a 2D array containing inverse of X.
                    
  6)transpose(X)
  
                Input
                     X -type(pointer to 2D array)
                Return
                     A pointer pointing to a 2D array that is the transpose of array X.
                     
  7)adjoint(X)
              
              Input
                    X -type(pointer to 2D array)
              Return
                    A pointer pointing to a 2D array containing the adjoint of X.
              
  8)rank(X)
            
            Input
                  X -type(pointer to 2D array)
            
     ***    Return
                  An Integer that is rank of the matrix X.
     ***
  
  9)reshape(X,g,h)
  
            Input
                 X -type(pointer to a 2D array)
                 p -type(Interger),row size of reshaped matrix
                 q -type(Interger),column size of reshaped matrix
            
            Return
                 A pointer pointing to the reshaped array.
                 
            Note:
                * Rehape is possible only if the dimensions of the input matrix and reshape dimensions are compatible.
                  i.e - Consider dimesions of X to be m x n.Then if X needs to be reshaped to g x h,
                        p x q = m x n MUST BE TRUE.
            
