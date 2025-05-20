//GEMINI-pro DATASET v1.0 Category: Bucket Sort Implementation ; Style: portable
#include <stdlib.h>
#include <stdio.h>

typedef struct node{
    int val;
    struct node *next;
} node_t;

node_t *get_node(){
    return (node_t *) malloc(sizeof(node_t));
}

void free_node(node_t *node){
    free(node);
}

typedef struct bucket{
    int count;
    node_t *top;
} bucket_t;

bucket_t *get_bucket(){
    return (bucket_t *) malloc(sizeof(bucket_t));
}

void free_bucket(bucket_t *bucket){
    node_t *current = bucket->top;
    node_t *next;
    while(current){
        next = current->next;
        free_node(current);
        current = next;
    }
    free(bucket);
}

void insert_bucket(bucket_t *bucket, int val){
    node_t *node = get_node();
    node->val = val;
    node->next = bucket->top;
    bucket->top = node;
    bucket->count++;
}

void bucket_sort(int *arr, int n, int max){
    bucket_t **buckets = (bucket_t **) malloc(sizeof(bucket_t *) * max);
    for(int i = 0; i < max; i++){
        buckets[i] = get_bucket();
    }
    for(int i = 0; i < n; i++){
        insert_bucket(buckets[arr[i]], arr[i]);
    }
    int index = 0;
    for(int i = 0; i < max; i++){
        node_t *current = buckets[i]->top;
        while(current){
            arr[index++] = current->val;
            current = current->next;
        }
        free_bucket(buckets[i]);
    }
    free(buckets);
}

int main(){
    int arr[] = {5, 3, 1, 7, 4, 1, 2, 8, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 9;
    bucket_sort(arr, n, max);
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}