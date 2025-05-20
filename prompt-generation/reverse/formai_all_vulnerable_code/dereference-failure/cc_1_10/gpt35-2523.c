//FormAI DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[50];
    int age;
    char address[100];
    struct Customer *left_child;
    struct Customer *right_child;
};

typedef struct Customer Customer;

Customer* insert(Customer *root, char *name, int age, char *address);
void inorder_traversal(Customer *root);
Customer* search_by_name(Customer *root, char *name);
Customer* search_by_age(Customer *root, int age);

int main() {
    Customer *root = NULL;

    // inserting customers
    root = insert(root, "John Smith", 35, "123 Main St");
    root = insert(root, "Mary Brown", 48, "456 Market St");
    root = insert(root, "David Lee", 22, "789 Broad St");

    // printing customers in alphabetical order
    printf("Printing customers in alphabetical order:\n\n");
    inorder_traversal(root);
    printf("\n\n");

    // searching for a customer by name
    char search_name[50];
    printf("Enter name to search for: ");
    scanf("%s", search_name);
    Customer *searched_customer = search_by_name(root, search_name);
    if (searched_customer == NULL) {
        printf("Customer not found.\n");
    } else {
        printf("Name: %s  Age: %d  Address: %s\n", searched_customer->name, searched_customer->age, searched_customer->address);
    }

    // searching for a customer by age
    int search_age;
    printf("Enter age to search for: ");
    scanf("%d", &search_age);
    searched_customer = search_by_age(root, search_age);
    if (searched_customer == NULL) {
        printf("Customer not found.\n");
    } else {
        printf("Name: %s  Age: %d  Address: %s\n", searched_customer->name, searched_customer->age, searched_customer->address);
    }

    return 0;
}

Customer* insert(Customer *root, char *name, int age, char *address) {
    if (root == NULL) {
        Customer *new_customer = (Customer*)malloc(sizeof(Customer));
        strcpy(new_customer->name, name);
        new_customer->age = age;
        strcpy(new_customer->address, address);
        new_customer->left_child = NULL;
        new_customer->right_child = NULL;
        return new_customer;
    }

    if (strcmp(name, root->name) < 0) {
        root->left_child = insert(root->left_child, name, age, address);
    } else {
        root->right_child = insert(root->right_child, name, age, address);
    }

    return root;
}

void inorder_traversal(Customer *root) {
    if (root == NULL) {
        return;
    }

    inorder_traversal(root->left_child);
    printf("Name: %s  Age: %d  Address: %s\n", root->name, root->age, root->address);
    inorder_traversal(root->right_child);
}

Customer* search_by_name(Customer *root, char *name) {
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(name, root->name) == 0) {
        return root;
    } else if (strcmp(name, root->name) < 0) {
        return search_by_name(root->left_child, name);
    } else {
        return search_by_name(root->right_child, name);
    }
}

Customer* search_by_age(Customer *root, int age) {
    if (root == NULL) {
        return NULL;
    }

    if (age == root->age) {
        return root;
    } else if (age < root->age) {
        return search_by_age(root->left_child, age);
    } else {
        return search_by_age(root->right_child, age);
    }
}