//Summation of 2 matrices


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
float* get_input();


float* get_input()
{
    float buff[50][50];
    int i,j,m,n,p,q;

    //Inputting Dimensions
    printf("Enter the number of rows and colmns in A : ");
    scanf("%f %f",&dim[0],&dim[1]);
    printf("Enter the number of rows and colmns in B : ");
    scanf("%f %f",&dim[2],&dim[3]);

    //Local use of dimensions is done using m,n,p,q while the dim array is passed for future reference
    m=dim[0];n=dim[1];
    p=dim[2];q=dim[3];


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


    return dim;
}


float* m_sum(struct matrix M1,struct matrix M2)
{
  int i,j;
  //int A[50][50];
  int compatibility=1;


  do  //Force iterate until proper input
  {
    //Matrix compatibility check
    if( (M1.row_size != M2.row_size) || (M1.colm_size != M2.colm_size))
    {
        printf("The given matrices are NOT of the same dimensions");
        compatibility=0;
        //Create break condition
    }

    else
        compatibility=1;

    //Summation
    for (i=0;i<M1.row_size;i++)
    {

      for(j=0;j<M1.colm_size;j++)
      {
        A[i][j]=M1.arr[i][j] + M2.arr[i][j];
      }

    }

    ans_ptr=&A[0][0];//creating to pointer to pass array reference

    if(compatibility==1)
      return(ans_ptr);
    else
        printf("Error");
    }while(compatibility!=0);
}

void main()
{
  float *dim_arr;

  dim_arr=get_input();//will have the pointer point to array containing dimensions of A and B

  float *a;//Will contain pointer pointing to the resultant matrix
  a=m_sum(X,Y);//struct matrix X,struct matrix Y);

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
