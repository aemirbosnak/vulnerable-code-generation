//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: Cryptic
#include<stdio.h>
#include<stdlib.h>

int cmpfunc(const void *a,const void *b)     //declaring compare function for qsort
{
    return (*(int*)a-*(int*)b);
}

void main()     //main function
{
    int n, i, j;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int a[n];
    printf("Enter the elements: ");
    for(i=0;i<n;i++)    //for loop to take input from user
    {
        scanf("%d",&a[i]);
    }

    qsort(a,n,sizeof(int),cmpfunc);     //sorting the given array using qsort

    int max_count=0;     //max_count variable to store the maximum count of a repeating element
    int current_count=1;     //current_count variable to store the current count of a repeating element
    int max_element;     //max_element variable to store the element with maximum count
    int current_element=a[0];     //current_element variable to store the current element being counted

    for(i=1;i<n;i++)     //for loop to count the repeating elements
    {
        if(a[i]==current_element)     //if the current element is repeating
        {
            current_count++;     //increment the current count
        }
        else     //if the current element is not repeating
        {
            if(current_count>max_count)     //if the current count is greater than the maximum count
            {
                max_count=current_count;     //update the maximum count
                max_element=current_element;     //update the maximum element
            }
            current_element=a[i];     //set the current element to the new element
            current_count=1;     //reset the current count to 1
        }
    }

    if(current_count>max_count)     //if the last element is repeating and its count is greater than the maximum count
    {
        max_count=current_count;     //update the maximum count
        max_element=current_element;     //update the maximum element
    }

    printf("\nElement with maximum occurrence is: %d",max_element);     //print the element with maximum occurrence
}