//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>

#define BUCKET_SIZE 10
#define MAX_SIZE 100

typedef struct Node // Structure of a node in the bucket list
{
    int data;
    struct Node *next;
}Node;

Node *bucket[BUCKET_SIZE]; // Declaring an array of bucket list

void bucketSort(int arr[], int n) // Function which implements Bucket Sort
{
    int i, j, index;
    Node *p;

    // Initializing the bucket list
    for(i=0; i<BUCKET_SIZE; i++)
    {
        bucket[i] = (Node *)malloc(sizeof(Node));
        bucket[i]->data = -1;
        bucket[i]->next = NULL;
    }

    // Inserting elements into the bucket list
    for(i=0; i<n; i++)
    {
        index = arr[i]/BUCKET_SIZE;
        if(bucket[index]->data == -1)
        {
            bucket[index]->data = arr[i];
        }
        else
        {
            p = bucket[index];
            while(p->next != NULL)
            {
                p = p->next;
            }
            Node *newNode = (Node *)malloc(sizeof(Node));
            newNode->data = arr[i];
            newNode->next = NULL;
            p->next = newNode;
        }
    }

    // Sorting the individual bucket lists
    for(i=0; i<BUCKET_SIZE; i++)
    {
        if(bucket[i]->data != -1)
        {
            int count = 0;
            p = bucket[i];
            while(p != NULL)
            {
                arr[count++] = p->data;
                p = p->next;
            }

            // Sorting the arr using insertion sort
            for(j=1; j<count; j++)
            {
                int temp = arr[j];
                int k = j-1;
                while(k>=0 && arr[k]>temp)
                {
                    arr[k+1] = arr[k];
                    k--;
                }
                arr[k+1] = temp;
            }
        }
    }
}

int main()
{
    int arr[MAX_SIZE], n, i;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the elements of the array: ");
    for(i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    bucketSort(arr, n);

    printf("The sorted array is: ");
    for(i=0; i<n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}