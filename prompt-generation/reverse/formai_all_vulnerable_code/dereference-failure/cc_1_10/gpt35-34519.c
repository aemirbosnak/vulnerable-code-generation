//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

int main(){

    int n,i,j;
    printf("Enter size of the array: ");
    scanf("%d", &n);

    int* array = (int*) malloc(n * sizeof(int));

    // inputting the array elements
    printf("Enter the array elements: ");
    for(i=0;i<n;i++)
        scanf("%d",&array[i]);

    // sorting the array in ascending order using bubble sort
    for(i=0;i<n-1;i++)
        for(j=0;j<n-1-i;j++)
            if(array[j]>array[j+1]){
                int temp=array[j];
                array[j]=array[j+1];
                array[j+1]=temp;
            }

    // calculating the sum of array elements
    int sum=0;
    for(i=0;i<n;i++)
        sum+=array[i];

    // finding the smallest subset of elements whose sum is greater than or equal to half of the sum of all elements
    int halfsum = sum/2;
    int* subset = (int*) malloc(n * sizeof(int));
    int subsetsum=0;
    int count=0;
    for(i=n-1;i>=0;i--){
        if(subsetsum+array[i]<=halfsum){
            subsetsum+=array[i];
            subset[count++]=array[i];
        }
        if(subsetsum==halfsum)
            break;
    }

    // printing the smallest subset of elements
    printf("The smallest subset of elements whose sum is greater than or equal to half of the sum of all elements is: \n");
    for(i=count-1;i>=0;i--)
        printf("%d ",subset[i]);
    printf("\n");

    return 0;
}