//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: lively
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TRUE 1
#define FALSE 0
#define MAX_SIZE 100

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}Node;

typedef struct stack{
    Node* top;
    int size;
}Stack;

void push(Stack* s, Node* n){
    if(s->size >= MAX_SIZE){
        printf("Stack Overflow\n");
        exit(0);
    }
    s->top = n;
    s->size++;
}

Node* pop(Stack* s){
    if(s->size <= 0){
        printf("Stack Underflow\n");
        exit(0);
    }
    Node* n = s->top;
    s->top = s->top->right;
    s->size--;
    return n;
}

Node* createNode(int data){
    Node* n = (Node*)malloc(sizeof(Node));
    if(n == NULL){
        printf("Memory Error\n");
        exit(0);
    }
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void postOrder(Node* root){
    Stack s;
    s.top = NULL;
    s.size = 0;
    Node* curr = root;
    while(curr!= NULL || s.size!= 0){
        if(curr!= NULL){
            push(&s, curr);
            curr = curr->left;
        }
        else{
            curr = pop(&s);
            printf("%d ", curr->data);
            curr = curr->right;
        }
    }
}

int main(){
    Node* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(7);
    root->left->left = createNode(1);
    root->left->right = createNode(4);
    root->right->left = createNode(6);
    root->right->right = createNode(8);
    printf("Postorder traversal of the binary tree is:");
    postOrder(root);
    return 0;
}