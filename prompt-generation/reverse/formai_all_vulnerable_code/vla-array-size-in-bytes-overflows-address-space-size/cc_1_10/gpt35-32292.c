//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: automated
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int data;
    struct node* next;
}node;

void bucket_sort(int arr[], int n)
{
    node* buckets[10];
    int i;
    for(i=0;i<10;i++)
        buckets[i]=NULL;
    for(i=0;i<n;i++)
    {
        node* new=(node*)malloc(sizeof(node));
        new->data=arr[i];
        new->next=NULL;
        if(buckets[arr[i]/10]==NULL)
            buckets[arr[i]/10]=new;
        else
        {
            node* temp=buckets[arr[i]/10];
            while(temp->next!=NULL)
                temp=temp->next;
            temp->next=new;
        }
    }
    int j=0;
    for(i=0;i<10;i++)
    {
        node* temp=buckets[i];
        while(temp!=NULL)
        {
            arr[j++]=temp->data;
            temp=temp->next;
        }
    }
}

int main()
{
    int n;
    printf("Enter the number of elements:");
    scanf("%d",&n);
    int arr[n],i;
    printf("Enter the elements:\n");
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);
    bucket_sort(arr,n);
    printf("The sorted array is:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);
    return 0;
}