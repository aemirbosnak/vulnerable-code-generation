//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Alan Touring
#include<stdio.h>
#include<string.h>

typedef struct {
    int id;
    char name[20];
    char address[50];
    int phone;
} Customer;
 
typedef struct node {
    Customer c;
    struct node *left, *right;
} Node;
 
void addCustomer(Node **root, Customer c) {
    if(*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->c = c;
        (*root)->left = (*root)->right = NULL;
        return;
    }
 
    if(c.id < (*root)->c.id) {
        addCustomer(&((*root)->left), c);
    }
    else if(c.id > (*root)->c.id) {
        addCustomer(&((*root)->right), c);
    }
}
 
Customer* searchCustomer(Node *root, int id) {
    if(root == NULL) {
        return NULL;
    }
    else if(root->c.id == id) {
        return &(root->c);
    }
    else if(id < root->c.id) {
        return searchCustomer(root->left, id);
    }
    else {
        return searchCustomer(root->right, id);
    }
}
 
void printCustomers(Node *root) {
    if(root == NULL) {
        return;
    }
 
    printCustomers(root->left);
    printf("ID: %d\tName: %s\tAddress: %s\tPhone: %d\n", root->c.id, root->c.name, root->c.address, root->c.phone);
    printCustomers(root->right);
}
 
int main() {
    Node *root = NULL;
    Customer c1 = {101, "Alice", "123 Main St", 5551234};
    Customer c2 = {102, "Bob", "456 Oak St", 5555678};
    Customer c3 = {103, "Charlie", "789 Pine St", 5559101};
    addCustomer(&root, c1);
    addCustomer(&root, c2);
    addCustomer(&root, c3);
    printf("Printing all customers:\n");
    printCustomers(root);
    printf("\n");
    Customer *c = searchCustomer(root, 102);
    if(c != NULL) {
        printf("Found customer with ID 102:\n");
        printf("Name: %s\tAddress: %s\tPhone: %d\n", c->name, c->address, c->phone);
    }
    else {
        printf("Could not find customer with ID 102\n");
    }
    return 0;
}