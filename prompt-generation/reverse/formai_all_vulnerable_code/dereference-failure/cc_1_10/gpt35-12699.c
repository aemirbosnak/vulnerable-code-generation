//FormAI DATASET v1.0 Category: Database Indexing System ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//define struct for database records
typedef struct{
    int record_id;
    char name[50];
    int age;
    float salary;
}Record;

//define struct for binary search tree node
typedef struct BSTNode{
    Record data; //store database record data in each node
    struct BSTNode *left; //left child
    struct BSTNode *right; //right child
}BSTNode;

//function to insert a new record into BST
BSTNode* insertRecord(BSTNode* root, Record data){
    if (root == NULL){
        BSTNode* newNode = (BSTNode*)malloc(sizeof(BSTNode));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (data.record_id < root->data.record_id)
        root->left = insertRecord(root->left, data);
    else
        root->right = insertRecord(root->right, data);
    return root;
}

//function to search for a record in BST using its ID
BSTNode* searchRecord(BSTNode* root, int record_id){
    if (root == NULL || root->data.record_id == record_id)
        return root;
    if (root->data.record_id < record_id)
        return searchRecord(root->right, record_id);
    return searchRecord(root->left, record_id);
}

//function to print all the records in BST
void printRecords(BSTNode* root){
    if (root != NULL){
        printRecords(root->left);
        printf("Record ID: %d, Name: %s, Age: %d, Salary: %.2f\n", root->data.record_id, root->data.name, root->data.age, root->data.salary);
        printRecords(root->right);
    }
}

//function to read records from file and insert them into BST
BSTNode* readRecords(char* filename){
    FILE* fp = fopen(filename, "r");
    if (fp == NULL){
        printf("Error reading file %s\n", filename);
        return NULL;
    }
    BSTNode* root = NULL;
    Record data;
    while (fscanf(fp, "%d,%[^,],%d,%f", &data.record_id, data.name, &data.age, &data.salary) != EOF){
        root = insertRecord(root, data);
    }
    fclose(fp);
    return root;
}

int main(){
    BSTNode* root = NULL;
    root = readRecords("records.csv"); //read records from file and insert them into BST
    printf("All records:\n");
    printRecords(root); //print all the records in BST
    printf("\n");
    int id_to_find = 1003;
    BSTNode* record_to_find = searchRecord(root, id_to_find); //search for record with ID 1003
    if (record_to_find != NULL){
        printf("Record with ID %d found:\n", id_to_find);
        printf("Record ID: %d, Name: %s, Age: %d, Salary: %.2f\n", record_to_find->data.record_id, record_to_find->data.name, record_to_find->data.age, record_to_find->data.salary);
    }
    else{
        printf("Record with ID %d not found\n", id_to_find);
    }
    return 0;
}