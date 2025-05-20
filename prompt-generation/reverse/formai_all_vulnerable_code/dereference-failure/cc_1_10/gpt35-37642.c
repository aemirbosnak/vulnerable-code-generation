//FormAI DATASET v1.0 Category: Matrix operations ; Style: protected
// protected style C program to perform matrix operations

#include<stdio.h>
#include<stdlib.h>

// function to display matrix
void display(int **a, int r, int c){
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}

// function to add two matrices
int **add(int **a, int **b, int r, int c){
    int **res;
    res = (int **)malloc(r*sizeof(int *));
    for(int i=0;i<r;i++){
        res[i] = (int *)malloc(c*sizeof(int));
        for(int j=0;j<c;j++){
            res[i][j] = a[i][j]+b[i][j];
        }
    }
    return res;
}

// function to subtract two matrices
int **subtract(int **a, int **b, int r, int c){
    int **res;
    res = (int **)malloc(r*sizeof(int *));
    for(int i=0;i<r;i++){
        res[i] = (int *)malloc(c*sizeof(int));
        for(int j=0;j<c;j++){
            res[i][j] = a[i][j]-b[i][j];
        }
    }
    return res;
}

// function to multiply two matrices
int **multiply(int **a, int **b, int r1, int c1, int r2, int c2){
    int **res;
    if(c1!=r2){
        printf("Multiplication not possible\n");
        exit(0);
    }
    res = (int **)malloc(r1*sizeof(int *));
    for(int i=0;i<r1;i++){
        res[i] = (int *)malloc(c2*sizeof(int));
        for(int j=0;j<c2;j++){
            res[i][j] = 0;
            for(int k=0;k<c1;k++){
                res[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return res;
}

int main(){

    int r1, c1, r2, c2, choice;
    printf("Enter number of rows and columns for matrix 1: ");
    scanf("%d%d",&r1,&c1);
    int **a;
    a = (int **)malloc(r1*sizeof(int *));
    for(int i=0;i<r1;i++){
        a[i] = (int *)malloc(c1*sizeof(int));
        for(int j=0;j<c1;j++){
            printf("Enter element at [%d][%d]: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter number of rows and columns for matrix 2: ");
    scanf("%d%d",&r2,&c2);
    int **b;
    b = (int **)malloc(r2*sizeof(int *));
    for(int i=0;i<r2;i++){
        b[i] = (int *)malloc(c2*sizeof(int));
        for(int j=0;j<c2;j++){
            printf("Enter element at [%d][%d]: ",i,j);
            scanf("%d",&b[i][j]);
        }
    }
    while(1){
        printf("-------- MENU --------\n");
        printf("1. Display matrices\n2. Add matrices\n3. Subtract matrices\n4. Multiply matrices\n5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Matrix 1:\n");
                display(a,r1,c1);
                printf("Matrix 2:\n");
                display(b,r2,c2);
                break;
            case 2:
                if(r1!=r2 || c1!=c2){
                    printf("Addition not possible\n");
                    break;
                }
                printf("Resultant matrix:\n");
                display(add(a,b,r1,c1),r1,c1);
                break;
            case 3:
                if(r1!=r2 || c1!=c2){
                    printf("Subtraction not possible\n");
                    break;
                }
                printf("Resultant matrix:\n");
                display(subtract(a,b,r1,c1),r1,c1);
                break;
            case 4:
                printf("Resultant matrix:\n");
                display(multiply(a,b,r1,c1,r2,c2),r1,c2);
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}