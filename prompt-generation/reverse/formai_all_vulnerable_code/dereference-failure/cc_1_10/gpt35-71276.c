//FormAI DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node_t;

node_t* root = NULL;
pthread_mutex_t lock;

void insert(node_t** node, int value){
    if(*node == NULL){
        *node = (node_t*) malloc(sizeof(node_t));
        (*node)->data = value;
        (*node)->left = NULL;
        (*node)->right = NULL;
    }else if(value <= (*node)->data){
        insert(&(*node)->left, value);
    }else{
        insert(&(*node)->right, value);
    }
}

void* insertThread(void* arg){
    int value = *(int*) arg;
    pthread_mutex_lock(&lock);
    insert(&root, value);
    pthread_mutex_unlock(&lock);
    free(arg);
    return NULL;
}

void search(node_t* node, int value){
    if(node == NULL){
        printf("Value not found\n");
    }else if(node->data == value){
        printf("Value found\n");
    }else if(value <= node->data){
        search(node->left, value);
    }else{
        search(node->right, value);
    }
}

void* searchThread(void* arg){
    int value = *(int*) arg;
    pthread_mutex_lock(&lock);
    search(root, value);
    pthread_mutex_unlock(&lock);
    free(arg);
    return NULL;
}

void printTree(node_t* node){
    if(node == NULL){
        return;
    }
    printTree(node->left);
    printf("%d ", node->data);
    printTree(node->right);
}

int main(){
    pthread_t threads[20];
    pthread_mutex_init(&lock, NULL);
    int i = 0;
    for(i = 0; i < 10; i++){
        int* value = (int*) malloc(sizeof(int));
        *value = rand() % 100;
        pthread_create(&threads[i], NULL, insertThread, value);
    }
    for(i = 0; i < 10; i++){
        pthread_join(threads[i], NULL);
    }
    printTree(root);
    printf("\n");
    for(i = 10; i < 20; i++){
        int* value = (int*) malloc(sizeof(int));
        *value = rand() % 100;
        pthread_create(&threads[i], NULL, searchThread, value);
    }
    for(i = 10; i < 20; i++){
        pthread_join(threads[i], NULL);
    }
    pthread_mutex_destroy(&lock);
    return 0;
}