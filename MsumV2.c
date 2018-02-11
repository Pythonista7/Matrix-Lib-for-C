//Summation of 2 matrices

/*

Ver 2.0 has the following updates
  > Now the user is forced to input compatible dimensions and code will not break.
  > The above feature is implimented in the function get_inout()
  > Un-necessary and not so useful variables and pointers were removed and that data is now handled globally.
  > Hence get_input is now 'void' and will not return any pointers as in ver 1.

Note to dev
  > It is advised to use the Framework of matrix structure for any and all matrices involed in the program.
  > Do not forget to prototype your functions before defining them.
  > All matrix-operation-functions
      -> shall store the resultant in matrix A
      -> shall return ans_ptr(float pointer)
  > Please follow the indentation pattern.

Expected path ahead
  > Area's for inclusion of menu driven program(*If necessary*) is also specified,else a header file shall not contain a main().
  > In version of header file we need to display the resultant matrix within each function,depending on the called function.
  > For now focus shall be on core construction of matrix-operation-functions

*/


#include<stdio.h>

//Frame work for matrices
typedef struct matrix
{
    float arr[50][50];
    int row_size;
    int colm_size;

}matrix;

//GLOBAL VARIABLES
struct matrix X,Y;
float dim[4];    //Is an array which contains the dimesions of both the matrices in the order -> [no of row in A,no of colmns in A,no of row in B,no of colmns in B]
float A[50][50];  //Stores answer
float *ans_ptr; //points to array A[0][0]

//FUNCTION PROTOTYPES
float* m_sum(struct matrix,struct matrix);
void get_input();


void get_input()
{
    float buff[50][50];
    int i,j,m,n,p,q;
    int compatibility=1;

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
      if( (m != p) || (n != q) )
      {
          printf("The given matrices are NOT of the same dimensions\n");
          compatibility=0;

      }

      else
          compatibility=1;

          }while(compatibility==0);

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

void main()
{
  //float *dim_arr;
  get_input();//will input all data into global struct A and B


  float *a;//Will contain pointer pointing to the resultant matrix
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////START OF MENU OPTION EXECUTION//////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  a=m_sum(X,Y);//struct matrix X,struct matrix Y




  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////  DISPLAY THE RESULTANT ARRAY //////////////////////////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////


  int ctr=0;//to control printing of resultant array

  printf("The result is :\n");
  //printf("rowsize= %f and colum=%f\n",dim[0],dim[1]);
  for(int i=0;i<dim[0];i++)
  {   //printf("Value of i is %d\n",i);
      for(int j=0;j<dim[1];j++)
        {
          printf("%f \t",*(a+ctr));
          //printf("Value of j is %d\n",j);
          ctr++;
        }
        ctr+=(50-ctr);//To shift to next row
        printf("\n");
  }


}
