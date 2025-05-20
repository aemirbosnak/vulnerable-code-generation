//Falcon-180B DATASET v1.0 Category: Binary search trees ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NAME_LENGTH 50

typedef struct {
    char name[MAX_NAME_LENGTH];
    int age;
    int height;
    int weight;
} Person;

typedef struct node {
    Person data;
    struct node* left;
    struct node* right;
} Node;

Node* create_node(Person person) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    new_node->data = person;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

Node* insert_node(Node* root, Person person) {
    if (root == NULL) {
        root = create_node(person);
        return root;
    }

    if (strcmp(root->data.name, person.name) < 0)
        root->right = insert_node(root->right, person);
    else
        root->left = insert_node(root->left, person);

    return root;
}

Node* search_node(Node* root, char* name) {
    if (root == NULL || strcmp(root->data.name, name)!= 0)
        return NULL;

    return root;
}

void inorder_traversal(Node* node) {
    if (node!= NULL) {
        inorder_traversal(node->left);
        printf("%s %d years old, %d cm tall and weighs %d kg\n", node->data.name, node->data.age, node->data.height, node->data.weight);
        inorder_traversal(node->right);
    }
}

int main(int argc, char* argv[]) {
    srand(time(NULL));
    int num_people = rand() % 100 + 1;
    Node* root = NULL;

    for (int i = 0; i < num_people; i++) {
        Person person;
        strcpy(person.name, (char*)malloc(sizeof(char) * MAX_NAME_LENGTH));
        sprintf(person.name, "Person %d", i + 1);
        person.age = rand() % 100 + 1;
        person.height = rand() % 200 + 1;
        person.weight = rand() % 100 + 1;

        root = insert_node(root, person);
    }

    printf("In-order traversal of the tree:\n");
    inorder_traversal(root);

    return 0;
}