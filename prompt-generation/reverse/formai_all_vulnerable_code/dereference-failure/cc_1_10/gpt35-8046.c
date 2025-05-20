//FormAI DATASET v1.0 Category: Database Indexing System ; Style: shocked
#include <stdio.h>
#include <stdlib.h>

/* Define a struct to represent a person */
typedef struct Person {
    char* name;
    int age;
    int id;
} Person;

/* Define a struct to represent a node in the binary tree */
typedef struct Node {
    Person person;
    struct Node* left;
    struct Node* right;
} Node;

/* Define a function to create a new node in the binary tree */
Node* new_node(Person person) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->person = person;
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Define a function to insert a person into the binary tree */
Node* insert(Node* root, Person person) {
    if (root == NULL) {
        return new_node(person);
    } else if (person.id < root->person.id) {
        root->left = insert(root->left, person);
    } else {
        root->right = insert(root->right, person);
    }
    return root;
}

/* Define a function to search for a person in the binary tree */
Person* search(Node* root, int id) {
    if (root == NULL) {
        return NULL;
    } else if (id == root->person.id) {
        return &(root->person);
    } else if (id < root->person.id) {
        return search(root->left, id);
    } else {
        return search(root->right, id);
    }
}

/* Define a function to print all the people in the binary tree */
void print(Node* root) {
    if (root == NULL) {
        return;
    }
    print(root->left);
    printf("Name: %s, Age: %d, ID: %d\n", root->person.name, root->person.age, root->person.id);
    print(root->right);
}

/* Define the main function */
int main() {
    Node* root = NULL;

    /* Insert some people into the binary tree */
    root = insert(root, (Person) { "Alice", 25, 1 });
    root = insert(root, (Person) { "Bob", 30, 2 });
    root = insert(root, (Person) { "Charlie", 35, 3 });

    /* Search for a person in the binary tree */
    Person* person = search(root, 2);
    if (person == NULL) {
        printf("Person not found!\n");
    } else {
        printf("Name: %s, Age: %d, ID: %d\n", person->name, person->age, person->id);
    }

    /* Print all the people in the binary tree */
    print(root);

    return 0; 
}