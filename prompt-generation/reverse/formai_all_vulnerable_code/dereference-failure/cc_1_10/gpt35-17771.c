//FormAI DATASET v1.0 Category: Database Indexing System ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Structure representing our database records
struct Record {
    char name[50];
    int age;
    float salary;
};

//Structure representing our tree node
struct TreeNode {
    struct Record data;
    struct TreeNode *left;
    struct TreeNode *right;
};

//Function to create a new node with given data
struct TreeNode* createNode(struct Record data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to insert a new record into the tree
struct TreeNode* insert(struct TreeNode* root, struct Record data) {
    if(root == NULL) {
        return createNode(data);
    }
    if(strcmp(data.name, root->data.name) < 0) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

//Function to search for a record with given name in the tree
struct TreeNode* search(struct TreeNode* root, char* name) {
    if(root == NULL || strcmp(name, root->data.name) == 0) {
        return root;
    }
    if(strcmp(name, root->data.name) < 0) {
        return search(root->left, name);
    }
    else {
        return search(root->right, name);
    }
}

//Function to traverse the tree in in-order fashion and print the data
void inorderTraversal(struct TreeNode* root) {
    if(root == NULL) {
        return;
    }
    inorderTraversal(root->left);
    printf("Name: %s, Age: %d, Salary: %.2f\n", root->data.name, root->data.age, root->data.salary);
    inorderTraversal(root->right);
}

int main() {
    struct TreeNode *root = NULL;
    struct Record r1 = {"John", 30, 50000.0};
    struct Record r2 = {"Jane", 25, 60000.0};
    struct Record r3 = {"David", 40, 70000.0};
    struct Record r4 = {"Alice", 35, 80000.0};
    struct Record r5 = {"Bob", 45, 90000.0};
    root = insert(root, r1);
    root = insert(root, r2);
    root = insert(root, r3);
    root = insert(root, r4);
    root = insert(root, r5);
    printf("In-order traversal of the tree:\n");
    inorderTraversal(root);
    printf("\nSearching for record with name Bob:\n");
    struct TreeNode* searchResult = search(root, "Bob");
    if(searchResult != NULL) {
        printf("Record found - Name: %s, Age: %d, Salary: %.2f\n", searchResult->data.name, searchResult->data.age, searchResult->data.salary);
    }
    else {
        printf("Record not found.\n");
    }
    return 0;
}