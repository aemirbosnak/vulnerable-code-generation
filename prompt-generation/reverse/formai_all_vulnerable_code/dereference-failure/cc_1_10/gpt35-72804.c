//FormAI DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <pthread.h> 

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

// function to create a new node
struct node* createNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

// function to insert a node in BST
void insert(struct node* temp, int data) {
    if (root == NULL) {
        root = createNode(data);
        return;
    }
    if (data < temp->data) {
        if (temp->left != NULL) {
            insert(temp->left, data);
        }
        else {
            temp->left = createNode(data);
            return;
        }
    }
    else {
        if (temp->right != NULL) {
            insert(temp->right, data);
        }
        else {
            temp->right = createNode(data);
            return;
        }
    }
}

// function to search for a node in BST
bool search(struct node* temp, int data) {
    if (temp == NULL) {
        return false;
    }
    if (temp->data == data) {
        return true;
    }
    else if (temp->data > data) {
        return search(temp->left, data);
    }
    else {
        return search(temp->right, data);
    }
}

void inOrderTraversal(struct node* temp) {
    if (temp == NULL) {
        return;
    }
    inOrderTraversal(temp->left);
    printf("%d ", temp->data);
    inOrderTraversal(temp->right);
}

// function for asynchronous insertion of a node
void* asyncInsert(void* arg) {
    pthread_mutex_lock(&mutex);
    int data = *(int*)arg;
    insert(root, data);
    printf("Inserted %d asynchronously.\n", data);
    pthread_mutex_unlock(&mutex);
    return NULL;
}

int main() {
    root = createNode(50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST is:\n");
    inOrderTraversal(root);

    // asynchronous insertions
    pthread_t thread1, thread2;
    int data1 = 90, data2 = 10;
    pthread_create(&thread1, NULL, asyncInsert, &data1);
    pthread_create(&thread2, NULL, asyncInsert, &data2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    printf("Inorder traversal of the BST after asynchronous insertions is:\n");
    inOrderTraversal(root);

    return 0;
}