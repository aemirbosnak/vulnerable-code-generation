//FormAI DATASET v1.0 Category: Matrix operations ; Style: irregular
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function prototypes
int** create(int rows, int cols);
void rndmat(int** m, int rows, int cols);
void display(int** m, int rows, int cols);
void add(int** a, int** b, int rows, int cols);
void sub(int** a, int** b, int rows, int cols);
void mlt(int** a, int** b, int rows1, int cols1, int rows2, int cols2);

int main()
{
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows of matrix 1: ");
    scanf("%d",&rows1);
    printf("Enter the number of columns of matrix 1: ");
    scanf("%d",&cols1);
    printf("Enter the number of rows of matrix 2: ");
    scanf("%d",&rows2);
    printf("Enter the number of columns of matrix 2: ");
    scanf("%d",&cols2);

    //check if matrix multiplication is possible
    if(cols1 != rows2)
    {
        printf("\nMatrix Multiplication is not possible!\n");
        return 0;
    }

    //create matrices
    int** a=create(rows1,cols1);
    int** b=create(rows2,cols2);

    printf("\nMatrix 1:\n");
    rndmat(a,rows1,cols1);
    display(a,rows1,cols1);
    printf("\nMatrix 2:\n");
    rndmat(b,rows2,cols2);
    display(b,rows2,cols2);
    printf("\nResult of Matrix Addition:\n");
    add(a,b,rows1,cols1);
    printf("\nResult of Matrix Subtraction:\n");
    sub(a,b,rows1,cols1);
    printf("\nResult of Matrix Multiplication:\n");
    mlt(a,b,rows1,cols1,rows2,cols2);

    //free memory for matrices
    free(a);
    free(b);
    return 0;
}

//function to create the matrix
int** create(int rows, int cols)
{
    int** m;

    m=(int**)malloc(rows*sizeof(int*));
    for(int i=0;i<rows;i++)
        m[i]=(int*)malloc(cols*sizeof(int));

    return m;
}

//function to fill matrix with random values
void rndmat(int** m, int rows, int cols)
{
    srand(time(0));
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            m[i][j]=rand()%100;
        }
    }
}

//function to display the matrix
void display(int** m, int rows, int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            printf("%d ",m[i][j]);
        }
        printf("\n");
    }
}

//function to add two matrices
void add(int** a, int** b, int rows, int cols)
{
    int** c=create(rows,cols);

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            c[i][j]=a[i][j]+b[i][j];
        }
    }
    display(c,rows,cols);
    free(c);
}

//function to subtract two matrices
void sub(int** a, int** b, int rows, int cols)
{
    int** c=create(rows,cols);

    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            c[i][j]=a[i][j]-b[i][j];
        }
    }
    display(c,rows,cols);
    free(c);
}

//function to multiply two matrices
void mlt(int** a, int** b, int rows1, int cols1, int rows2, int cols2)
{
    int** c=create(rows1,cols2);

    for(int i=0;i<rows1;i++)
    {
        for(int j=0;j<cols2;j++)
        {
            c[i][j]=0;
            for(int k=0;k<cols1;k++)
            {
                c[i][j]+=(a[i][k]*b[k][j]);
            }
        }
    }
    display(c,rows1,cols2);
    free(c);
}