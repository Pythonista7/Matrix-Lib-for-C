//Summation of 2 matrices

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
float dim[4];    //Is an array which contains the dimesions of both the matrices in the order -> [no of row in A,no of colmns in A,no of row in B,no of colmns in B]
float A[50][50];  //Stores answer
float *ans_ptr; //points to array A[0][0]

//FUNCTION PROTOTYPES
float* m_sum(struct matrix,struct matrix);
void get_input();
void show_output(float*);



////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////  INPUT DATA INTO ARRAYS X&Y  //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
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


////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////  DISPLAY THE RESULTANT ARRAY //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void show_output(float *a)
{

    int ctr=0;//to control printing of resultant array

    printf("\n\n\n\n\n\n\n");
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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////  THE MENU  //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
int menu()
{ int choice;
  printf("\n\n\n\n\n\n\n\n\n\nWelcome to matrix operations!\n");
  printf("Enter choice number:\n");
  printf("0.Exit\n");
  printf("1.Matrix Addition\n");
  printf("2.Matrix Subraction\n");

  scanf("%d",&choice);
  return(choice);
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
//////////////////////////////  THE MAIN  //////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void main()
{

  float *a;//Will contain pointer pointing to the resultant matrix
  int choice;

  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////////////////////////////////START OF MENU OPTION EXECUTION//////////////////////////////////////////////////
  ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  do
  {
    choice=menu();//variable recieves option number selected by the user

    switch(choice)
        {
          case 0:choice=0;
                 printf("\n\n\nTHANK YOU\n\n");
                 break;

          case 1:get_input();//will input all data into global struct A and B
                 a=m_sum(X,Y);//ADDITION of struct matrix X,struct matrix Y
                 show_output(a);//will print the result in matrix A[][]
                 break;

          case 2:get_input();//will input all data into global struct A and B
                 a=m_diff(X,Y);//Subraction of struct matrix X,struct matrix Y
                 show_output(a);//will print the result in matrix A[][]
                 break;

          }

    }while(choice!=0);





}
