//Matric library

/*

Ver 2.0 has the following updates
  > Now the user is forced to input compatible dimensions and code will not break.
  > The above feature is implimented in the function get_inout()
  > Un-necessary and not so useful variables and pointers were removed and that data is now handled globally.
  > Hence get_input is now 'void' and will not return any pointers as in ver 1.
Ver 2.1 update:
  > Program now contains dedicate function to display contents of resultant matrix A[][]
  > Matrix Subraction function implimented.
  > Menu system (Ver1) introduced.

Ver 2.1.1 patch:
  > All fuctions have been prototyped.(Refer readme file for details)
  > Framed switch case,please insert all the working functions into the switch-case.

Issue's:
> need to fix m_det/COFACTOR
>need to debug reshape

Note to dev
  > It is advised to use the Framework of matrix structure for any and all matrices involed in the program.
  > Do not forget to prototype your functions before defining them.
  > All matrix-operation-functions
      -> shall store the resultant in matrix A
      -> if the answer is a single digit as in m_rank,m_det store answer in float variable 'ans'.
      -> shall return ans_ptr(float pointer)
  > Please follow the indentation pattern.

Expected path ahead
  > Area's for inclusion of menu driven program(*If necessary*) is also specified,else a header file shall not contain a main().
  > In version of header file we need to display the resultant matrix depending on the called function.
  > For now focus shall be on core construction of matrix-operation-functions.

*/


#include<stdio.h>
#include<ctype.h>

//Frame work for matrices
typedef struct matrix
{
    float arr[50][50];
    int row_size;
    int colm_size;

}matrix;

//GLOBAL VARIABLES
struct matrix X,Y;
float temp[50][50];//used to temporarily store ,i.e, co-factors for determinant
float dim[4];     //Is an array which contains the dimesions of both the matrices in the order -> [no of row in A,no of colmns in A,no of row in B,no of colmns in B]
float A[50][50];  //Stores resultant matrix
float ans;        //Store single value answers such as determinent and rank
float *ans_ptr;   //points to array A[0][0]
int compatibility;
//int ctr;          //global counter
/*
  Tells what type of compatibility is required for the selected operation.
  > compatibility=0 is to input matrix for single matrix operations such as inverse , adjoint , reshape , transpose etc.
  > compatibility=1 is to check if both input matrices are of equal dimensions.Its used in m_sum() and m_diff()
  > compatibility=2 is for check if both the input matrices are suitable for muliplication.
    That is if X= m x n and Y= p x q , n == p for multiplication.
  >compatibility=3 is to check for reshape condition
*/


//FUNCTION PROTOTYPES
float* m_sum(struct matrix,struct matrix);      // completed
float* m_diff(struct matrix,struct matrix);     // completed
float* m_prod(struct matrix,struct matrix);     // completed
float* m_inverse(struct matrix);                // W.I.P
float* m_transpose(struct matrix);              // W.I.P
float* m_div(struct matrix,struct matrix);      // feature unavaible
float* m_adj(struct matrix);                    // feature unavaible
float* m_rank(struct matrix);                   // feature unavaible
float* m_reshape(struct matrix,struct matrix);  // W.I.P
float  m_det(float M1[50][50],int n);           // Need to fix,but doesn't break code

void get_input();
void show_output(float*);
int menu();


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////  INPUT DATA INTO ARRAYS X & Y  //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void get_input(int compatibility)
{
    float buff[50][50];
    int i,j,m,n,p,q;
    //compatibility=-1;

    do  //Force iterate until proper input
    {
      /*Inputting Dimensions
      printf("Enter the number of rows and colmns in A : ");
      scanf("%f %f",&dim[0],&dim[1]);
      printf("Enter the number of rows and colmns in B : ");
      scanf("%f %f",&dim[2],&dim[3]);

      //Local use of dimensions is done using m,n,p,q while the dim array is passed for future reference
      m=dim[0];n=dim[1];
      p=dim[2];q=dim[3];
      */
      //Matrix compatibility check
      if(compatibility==0)
      { printf("Enter the number of rows and colmns in A : ");
        scanf("%f %f",&dim[0],&dim[1]);
        m=dim[0];n=dim[1];
        break;
      }

      if( compatibility==1 )//(m != p) || (n != q) )
      {  printf("Enter the number of rows and colmns in A : ");
         scanf("%f %f",&dim[0],&dim[1]);
         printf("Enter the number of rows and colmns in B : ");
         scanf("%f %f",&dim[2],&dim[3]);

         //Local use of dimensions is done using m,n,p,q while the dim array is passed for future reference
         m=dim[0];n=dim[1];
         p=dim[2];q=dim[3];

         if( (m != p) || (n != q) )
            { printf("The given matrices are NOT of the same dimensions\n");
              compatibility=1;
              continue;
            }
          else
           {
              break;
            }
      }

      else if ( compatibility==2 || compatibility==3)
        { printf("Enter the number of rows and colmns in A : ");
          scanf("%f %f",&dim[0],&dim[1]);
          printf("Enter the number of rows and colmns in B : ");
          scanf("%f %f",&dim[2],&dim[3]);

          //Local use of dimensions is done using m,n,p,q while the dim array is passed for future reference
          m=dim[0];n=dim[1];
          p=dim[2];q=dim[3];
          if (compatibility==2 && n == p)
          {
              compatibility=2;
              break;
          }

          else if(m*n == p*q)
          {
            compatibility=3;
            break;
          }

          else
              { printf("The input dimension isn't compatible with selected operation.");
                continue;
              }
        }
      }while(1);


    //Input matrix A

    printf("Enter Elements of matrix A:\n");
    //Take Input and sotre it into a buffer 2d matrix
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
      {
        scanf("%f", &buff[i][j]);
      }

    }
    //Storing data to the global structure
    //struct matrix X
    //assigning array Elements for X
    for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
      {
        X.arr[i][j]=buff[i][j];
      }
    }
    //Assign row size and column row_size
    X.row_size=m;
    X.colm_size=n;
    Y.row_size= p;
    Y.colm_size= q;

    //For a single matrix operation function we shall return at this points
    if(compatibility==0||compatibility==3)
      return;
    //To input single matrix but also the size of the 2nd matrix as in reshape we use 3




    //Input matrix B

    printf("Enter Elements of matrix B:\n");
    //Take Input and sotre it into a buffer 2d matrix
    for(i=0;i<p;i++)
    {
      for(j=0;j<q;j++)
      {
        scanf("%f", &buff[i][j]);
      }

    }

    //Storing data to the global structure
    //struct matrix Y(buff,p,q);
    //assigning array Elements for Y
    for(i=0;i<p;i++)
    {
      for(j=0;j<q;j++)
      {
        Y.arr[i][j]=buff[i][j];
      }
    }
    //Assign row size and column row_size
    Y.row_size=p;
    Y.colm_size=q;



}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////  DISPLAY THE RESULTANT ARRAY //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void show_output(float *a)
{

    int ctr=0;//to control printing of resultant array
    float m,n;
    if(compatibility==1)//||compatibility==0)
    {
      m=dim[0]; n=dim[1];//m & n for equal dimensioned matrices
      ///printf("FOUND COMPATIBLE");
    }


    else if(compatibility==2)
    {
      m=dim[0]; n=dim[3];//m & n for resultant of product of 2 matrices
    }

    else if(compatibility==3)
    {
      m=Y.row_size;n=Y.colm_size;//dim[2];n=dim[3];//m & n for resultant is given by the user
    }
    printf("\n\n\n\n\n\n\n");
    printf("Result:\nrowsize = %f \t \t column size = %f\n\n",m,n);
    for(int i=0;i<m;i++)
    {   //printf("Value of i is %d\n",i);


        for(int j=0;j<n;j++)
          {
            printf("%f \t",*(a+ctr));
            //printf("Value of j is %d\n",j);
            //printf("ctr=%d\n",ctr);
            ctr++;
          }
          //For reshape to shift to next rows

          if((50-ctr)<0)
            ctr+=(50-n);
          else
          ctr+=(50-ctr);//To shift to next row

          printf("\n");
    }

}




////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////  MATRIX ADDITION  //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float* m_sum(struct matrix M1,struct matrix M2)
{
  int i,j;
  //int A[50][50];


    //Summation
    for (i=0;i<M1.row_size;i++)
    {

      for(j=0;j<M1.colm_size;j++)
      {
        A[i][j]=M1.arr[i][j] + M2.arr[i][j];
      }

    }

    ans_ptr=&A[0][0];//creating to pointer to pass array reference


    return(ans_ptr);


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////  MATRIX SUBRACTION  ////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////


float* m_diff(struct matrix M1,struct matrix M2)
{
  int i,j;
  //int A[50][50];


    //Subraction
    for (i=0;i<M1.row_size;i++)
    {

      for(j=0;j<M1.colm_size;j++)
      {
        A[i][j]=M1.arr[i][j] - M2.arr[i][j];
      }

    }

    ans_ptr=&A[0][0];//creating to pointer to pass array reference


    return(ans_ptr);


}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////  MATRIX MULTIPLICATON  /////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float* m_prod(struct matrix M1,struct matrix M2)
{
  int i,j,k;
  //int A[50][50];

  //MULTIPLICATION
	for(i=0;i<M1.row_size;i++)
	{
		for(j=0;j<M2.colm_size;j++)
		{
			A[i][j]=0;
			for(k=0;k<M1.colm_size;k++)
			{

				A[i][j]+=M1.arr[i][k]*M2.arr[k][j];

			}

		}

	}

  ans_ptr=&A[0][0];//creating to pointer to pass array reference


  return(ans_ptr);


}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////// INVERTING A MATRIX  /////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float* m_inverse(struct matrix M1)
{
  //compatibility=0     refer initial doc comment for details.


}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////// TRANSPOSE A MATRIX  /////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

float* m_transpose(struct matrix M1)
{
  //compatibility=0     refer initial doc comment for details.

}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////// RESHAPING A MATRIX  /////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
float* m_reshape(struct matrix M1,struct matrix M2)
{
  //compatibility=3
  int ctr=0; //used to increment pointer
  int m,n,p,q;
  m=M1.row_size; n=M1.colm_size;
  p=M2.row_size; q=M2.colm_size;
  int i=0,j=0;

  //Implimenting using a queue
  float queue[50];
  for(i=0;i<m;i++)
    {
      for(j=0;j<n;j++)
      {
        printf("M1 ele: %f\t",M1.arr[i][j]);
      }printf("\n");
    }
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    { queue[ctr]=M1.arr[i][j];
      printf("Qele=%f, i=%d, j=%d\n",M1.arr[i][j],i,j );
      ctr++;
    }
  }

  //CHKing Q content
  ctr=0;
  for(i=0;i<m;i++)
  {
    for(j=0;j<n;j++)
    {
      printf("Q element %d after entry:%f\n",ctr,queue[ctr]);
      ctr++;
    }
  }
  //using the queue
  ctr=0;
  for(i=0;i<p;i++)
  {
    for(j=0;j<q;j++)
    {
      A[i][j]=queue[ctr];

      ctr++;
    }
  }
  //Chking A matrix
  ctr=0;
  for(i=0;i<p;i++)
  {
    for(j=0;j<q;j++)
    {
      printf("Q element %d in A matrix:%f\n",ctr,queue[ctr]);
      ctr++;
    }
  }
/*
  for(i=0;i<p;i++)
  {
    A[i][j]=0;

    float *m1;//to extract data from M1.array
    m1=&(M1.arr[0][0]);

    for(j=0;j<q;j++)
    {
      A[i][j]= *(m1+(sizeof(float) * ctr ));
      printf("\n%f\n",&A[i][j]);
      ctr++;
    }
  }
*/
  ans_ptr=A;

  return ans_ptr;
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////// DET A MATRIX  /////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
ctr=0;
float m_det(float M1[50][50],int n)
{
  int D=0;
  //CHECK FOR SQUARE MATRIC

  if(n==1)
    return M1[0][0];

  int sign=1;

  for(int i=0;i<n-ctr;i++)
  {
    //Get Cofactor of the matrix m[0][i]
    get_cofactor(M1,0,i,n);

    D+= sign * M1[0][i] * m_det(temp,n-1);

    sign=-sign;
  }

  return D;
}
////////////////////////////////////////////////////////////////////////////////
////////////////////////////To get COFACTOR OF A MATRIX/////////////////////////
////////////////////////////////////////////////////////////////////////////////
void get_cofactor(float mat[50][50],int p,int q,int n)
{
  int i=0,j=0;

  for(int row=0;row<n;row++)
  {
      for(int col=0;col<n;col++)
      {
        //filtering out the co-fac matrix
        if(row!=p && col!=q)
        {
          temp[i][j++]=mat[row][col];

          //if row is filled,increment row index and rest column index
          if(j==n-1)
          {
            i++;
            j=0;
            }
          }

        }

}
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////  THE MENU  //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int  menu()  //return type is int
{ int choice;

  printf("\n\n\n\n\n\n\n\n\n\nWelcome to matrix operations!\n");
  printf("Enter choice number:\n");
  printf("0.Exit\n");
  printf("1.Matrix Addition\n");
  printf("2.Matrix Subraction\n");
  printf("3.Matrix Multiplication\n");
  printf("4.Matrix Divison\n");
  printf("5.Matrix Inversion\n");
  printf("6.Matrix Transpose\n");
  printf("7.Matrix Adjoint\n");
  printf("8.Matrix Rank\n");
  printf("9.Matrix Reshape\n");
  printf("10.Matrix Determinent\n");

  printf("\nYour choice:");
  scanf("%d",&choice);
  return(choice);
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////  THE MAIN  //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void main()
{

  float *a;//Will contain pointer pointing to the resultant matrix
  int choice;

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////START OF MENU///////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  do
  {
    choice=menu();//variable recieves option number selected by the user

    switch(choice)
        {
          case 0:choice=0;
                 printf("\n\n\nTHANK YOU\n\n");
                 break;

          case 1:compatibility=1;
                 get_input(compatibility);//will input all data into global struct A and B
                 a=m_sum(X,Y);//ADDITION of struct matrix X,struct matrix Y
                 show_output(a);//will print the result in matrix A[][]
                 break;

          case 2:compatibility=1;
                 get_input(compatibility);//will input all data into global struct A and B
                 a=m_diff(X,Y);//Subraction of struct matrix X,struct matrix Y
                 show_output(a);//will print the result in matrix A[][]
                 break;


          case 3:compatibility=2;
                 get_input(compatibility);//will input all data into global struct A and B
                 a=m_prod(X,Y);//Product of struct matrix X,struct matrix Y
                 show_output(a);//will print the result in matrix A[][]
                 break;

          case 4:/*
                 compatibility=2;
                 get_input(compatibility);
                 a=m_div(X,Y);
                 show_output(a);
                 */
                 break;

          case 5:/*
                 compatibility=refer header comments;
                 get_input(compatibility);
                 a=m_funtion(input parameters);
                 show_output(a);
                 */
                 break;

         case 6:/*
                compatibility=refer header comments;
                get_input(compatibility);
                a=m_funtion(input parameters);
                show_output(a);
                */
                break;

        case 7:/*
               compatibility=refer header comments;
               get_input(compatibility);
               a=m_funtion(input parameters);
               show_output(a);
               */
               break;

       case 8:/*
              compatibility=refer header comments;
              get_input(compatibility);
              a=m_funtion(input parameters);
              show_output(a);
              */
              break;

      case 9:
             compatibility=3;
             get_input(compatibility);
             a=m_reshape(X,Y);
             show_output(a);

             break;

	case 10:
		      compatibility=0;
		      get_input(compatibility);
		      ans=m_det(X.arr,X.row_size*X.colm_size);
		      printf("The result of the determinant is %f",ans);
		      break;

        }


    }while(choice!=0);





}
