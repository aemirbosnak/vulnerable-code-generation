//FormAI DATASET v1.0 Category: Database Indexing System ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a struct to hold database entries
typedef struct {
    char name[20];
    int id;
    double salary;
} Employee;

// Define a struct to represent a node in the binary search tree
typedef struct BSTNode {
    Employee employee;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Define a struct to represent the BST
typedef struct {
    BSTNode* root;
} BST;

// Function to create a new empty BST
BST* createBST() {
    BST* bst = malloc(sizeof(BST));
    bst->root = NULL;
    return bst;
}

// Function to create a new BST node
BSTNode* createBSTNode(Employee employee) {
    BSTNode* node = malloc(sizeof(BSTNode));
    node->employee = employee;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new employee into the BST
void insert(BSTNode* node, Employee employee) {
    if (employee.id < node->employee.id) {
        if (node->left == NULL) {
            node->left = createBSTNode(employee);
        } else {
            insert(node->left, employee);
        }
    } else {
        if (node->right == NULL) {
            node->right = createBSTNode(employee);
        } else {
            insert(node->right, employee);
        }
    }
}

// Function to search for an employee by their ID in the BST
Employee* search(BSTNode* node, int id) {
    if (node == NULL) {
        return NULL;
    } else if (node->employee.id == id) {
        return &(node->employee);
    } else if (id < node->employee.id) {
        return search(node->left, id);
    } else {
        return search(node->right, id);
    }
}

// Function to print the BST in order
void printInOrder(BSTNode* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->left);
    printf("%-20s %-10d %.2f\n", node->employee.name, node->employee.id, node->employee.salary);
    printInOrder(node->right);
}

// Function to read employee data from a file and insert it into the BST
BST* readEmployeesFromFile(char* filename) {
    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }
    BST* bst = createBST();
    char line[50];
    while (fgets(line, 50, fp) != NULL) {
        char name[20];
        int id;
        double salary;
        sscanf(line, "%s %d %lf", name, &id, &salary);
        Employee employee = { .id = id, .salary = salary };
        strcpy(employee.name, name);
        insert(bst->root, employee);
    }
    fclose(fp);
    return bst;
}

int main(void) {
    BST* bst = readEmployeesFromFile("employees.txt");
    printf("%-20s %-10s %s\n", "Name", "ID", "Salary");
    printf("---------------------------------------\n");
    printInOrder(bst->root);
    int idToSearch;
    printf("Enter an employee ID to search for: ");
    scanf("%d", &idToSearch);
    Employee* result = search(bst->root, idToSearch);
    if (result == NULL) {
        printf("No employee with ID %d\n", idToSearch);
    } else {
        printf("%-20s %-10d %.2f\n", result->name, result->id, result->salary);
    }
    return 0;
}