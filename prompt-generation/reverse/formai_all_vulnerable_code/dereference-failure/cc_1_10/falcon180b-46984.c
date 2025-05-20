//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX_THREADS 10

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node_t;

node_t* root = NULL;

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
sem_t sem;

void* insert(void* arg) {
    int data = *(int*) arg;
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;

    pthread_mutex_lock(&lock);

    if (root == NULL) {
        root = new_node;
    } else {
        node_t* curr_node = root;
        while (curr_node!= NULL) {
            if (data < curr_node->data) {
                if (curr_node->left == NULL) {
                    curr_node->left = new_node;
                    break;
                } else {
                    curr_node = curr_node->left;
                }
            } else {
                if (curr_node->right == NULL) {
                    curr_node->right = new_node;
                    break;
                } else {
                    curr_node = curr_node->right;
                }
            }
        }
    }

    pthread_mutex_unlock(&lock);

    sem_post(&sem);
    return NULL;
}

void* search(void* arg) {
    int data = *(int*) arg;
    node_t* curr_node = root;

    while (curr_node!= NULL) {
        if (data == curr_node->data) {
            printf("Data found!\n");
            break;
        } else if (data < curr_node->data) {
            curr_node = curr_node->left;
        } else {
            curr_node = curr_node->right;
        }
    }

    return NULL;
}

int main() {
    int i;
    pthread_t threads[MAX_THREADS];

    sem_init(&sem, 0, 0);

    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, insert, (void*) i);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    for (i = 0; i < 10; i++) {
        pthread_create(&threads[i], NULL, search, (void*) i);
    }

    for (i = 0; i < 10; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}