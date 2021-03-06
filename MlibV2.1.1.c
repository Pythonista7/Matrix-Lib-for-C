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
float dim[4];     //Is an array which contains the dimesions of both the matrices in the order -> [no of row in A,no of colmns in A,no of row in B,no of colmns in B]
float A[50][50];  //Stores resultant matrix
float ans;        //Store single value answers such as determinent and rank
float *ans_ptr;   //points to array A[0][0]
int compatibility;
/*
  Tells what type of compatibility is required for the selected operation.
  > compatibility=0 is to input matrix for single matrix operations such as inverse , adjoint , reshape , transpose etc.
  > compatibility=1 is to check if both input matrices are of equal dimensions.Its used in m_sum() and m_diff()
  > compatibility=2 is for check if both the input matrices are suitable for muliplication.
    That is if X= m x n and Y= p x q , n == p for multiplication.
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
float* m_reshape(struct matrix);                // feature unavaible
float* m_det(struct matrix);                    // feature unavaible

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
      //Inputting Dimensions
      printf("Enter the number of rows and colmns in A : ");
      scanf("%f %f",&dim[0],&dim[1]);
      printf("Enter the number of rows and colmns in B : ");
      scanf("%f %f",&dim[2],&dim[3]);

      //Local use of dimensions is done using m,n,p,q while the dim array is passed for future reference
      m=dim[0];n=dim[1];
      p=dim[2];q=dim[3];

      //Matrix compatibility check
      if(compatibility==0)
      {
        break;
      }

      if( compatibility==1 )//(m != p) || (n != q) )
      {   if( (m != p) || (n != q) )
            { printf("The given matrices are NOT of the same dimensions\n");
              compatibility=1;
              continue;
            }
          else
              break;
      }

      else if ( compatibility==2)
        { if (n == p)
            { compatibility=2;
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

    //For a single matrix operation function we shall return at this points
    if(compatibility==0)
      return;


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
    int m,n;
    if(compatibility==1)//||compatibility==0)
    {
      m=dim[0]; n=dim[1];//m & n for equal dimensioned matrices
      ///printf("FOUND COMPATIBLE");
    }
    else if(compatibility==2)
    {
      m=dim[0]; n=dim[3];//m & n for resultant of product of 2 matrices
    }
    printf("\n\n\n\n\n\n\n");
    printf("Result:\nrowsize = %f \t \t column size = %f\n\n",dim[0],dim[1]);
    for(int i=0;i<m;i++)
    {   //printf("Value of i is %d\n",i);
        for(int j=0;j<n;j++)
          {
            printf("%f \t",*(a+ctr));
            //printf("Value of j is %d\n",j);
            ctr++;
          }
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

      case 9:/*
             compatibility=refer header comments;
             get_input(compatibility);
             a=m_funtion(input parameters);
             show_output(a);
             */
             break;

     case 10:/*
            compatibility=refer header comments;
            get_input(compatibility);
            a=m_funtion(input parameters);
            show_output(a);
            */
            break;

          }


    }while(choice!=0);





}
