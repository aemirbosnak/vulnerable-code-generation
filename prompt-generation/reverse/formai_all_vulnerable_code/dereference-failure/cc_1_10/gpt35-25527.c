//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
 
struct node{
    int value;
    struct node* next;
};
 
void bucket_sort(int arr[], int n){
    int i, j;
    struct node* p;
    struct node** buckets = malloc(sizeof(struct node*) * n);
    for (i = 0; i < n; i++)
    {
        buckets[i] = NULL;
    }
    for (i = 0; i < n; i++)
    {
        int pos = (n * arr[i]) / (100 + 1);
        struct node* new_node = malloc(sizeof(struct node));
        new_node->value = arr[i];
        new_node->next = buckets[pos];
        buckets[pos] = new_node;
    }
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - 1; j++)
        {
            if (buckets[j] != NULL && buckets[j + 1] != NULL && buckets[j]->value > buckets[j + 1]->value)
            {
                p = buckets[j];
                buckets[j] = buckets[j + 1];
                buckets[j + 1] = p;
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (buckets[i] != NULL)
        {
            p = buckets[i];
            while (p != NULL)
            {
                printf("%d ", p->value);
                p = p->next;
            }
        }
    }
}
 
int main(){
    int arr[] = { 10, 80, 30, 90, 40, 50, 70 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bucket_sort(arr, n);
    return 0;
}