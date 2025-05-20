//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: multi-threaded
#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

typedef struct node{
    int data;
    struct node *left;
    struct node *right;
}Node;

Node *createNode(int data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

Node *insertNode(Node *root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else{
        root->right = insertNode(root->right, data);
    }
    return root;
}

Node *searchNode(Node *root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    if(data < root->data){
        return searchNode(root->left, data);
    }
    else{
        return searchNode(root->right, data);
    }
}

Node *deleteNode(Node *root, int data){
    if(root == NULL){
        return root;
    }
    if(data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else{
        if(root->left == NULL){
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = searchNode(root->right, minValue(root->right));
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int minValue(Node *root){
    int minvalue = root->data;
    while(root->left!= NULL){
        minvalue = root->left->data;
        root = root->left;
    }
    return minvalue;
}

void *threadFunc(void *arg){
    int data = *(int*)arg;
    Node *root = insertNode(NULL, data);
    printf("Inserted %d\n", data);
    pthread_exit(0);
}

int main(){
    pthread_t threads[10];
    int datas[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
    int i;
    for(i = 0; i < 10; i++){
        pthread_create(&threads[i], NULL, threadFunc, (void*)&datas[i]);
    }
    for(i = 0; i < 10; i++){
        pthread_join(threads[i], NULL);
    }
    Node *root = NULL;
    root = insertNode(root, 5);
    root = insertNode(root, 15);
    root = insertNode(root, 25);
    root = insertNode(root, 35);
    root = insertNode(root, 45);
    printf("Searching 15...\n");
    Node *searchresult = searchNode(root, 15);
    if(searchresult!= NULL){
        printf("Found 15\n");
    }
    else{
        printf("Not found\n");
    }
    printf("Deleting 15...\n");
    root = deleteNode(root, 15);
    printf("Deleted 15\n");
    return 0;
}