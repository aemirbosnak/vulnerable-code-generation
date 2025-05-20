//FormAI DATASET v1.0 Category: Database Indexing System ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REC_SIZE 1024

// Structure to hold the record data
struct Record {
    int id;
    char name[50];
    char description[MAX_REC_SIZE];
};

// Node structure for the linked list
struct Node {
    int key;
    int offset;
    struct Node* next;
};

// Function to add a record to the index
void addRecordToIndex(struct Node** head, int key, int offset) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->key = key;
    newNode->offset = offset;
    newNode->next = NULL;

    if (*head == NULL) {
        // The linked list is empty, so make the new node the head
        *head = newNode;
    } else if ((*head)->key > key) {
        // The new node is smaller than the head, so make it the new head
        newNode->next = *head;
        *head = newNode;
    } else {
        // Traverse the list to find the insertion point
        struct Node* temp = *head;
        while (temp->next != NULL && temp->next->key < key) {
            temp = temp->next;
        }

        // Insert the new node
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

// Function to search for a record in the index
int searchIndex(struct Node* head, int key) {
    while (head != NULL) {
        if (head->key == key) {
            // Found the key, return the offset
            return head->offset;
        } else if (head->key > key) {
            // The key was not found, return -1
            return -1;
        }
        head = head->next;
    }

    // The key was not found, return -1
    return -1;
}

int main() {
    // Create a file to store the records
    FILE* fp = fopen("records.dat", "wb");
    if (fp == NULL) {
        printf("Error creating file!");
        return 1;
    }

    // Create the index linked list
    struct Node* index = NULL;

    // Add some records to the file and index
    struct Record r1 = {1, "Record 1", "This is the first record"};
    fwrite(&r1, sizeof(struct Record), 1, fp);
    addRecordToIndex(&index, r1.id, ftell(fp) - sizeof(struct Record));

    struct Record r2 = {3, "Record 3", "This is the third record"};
    fwrite(&r2, sizeof(struct Record), 1, fp);
    addRecordToIndex(&index, r2.id, ftell(fp) - sizeof(struct Record));

    struct Record r3 = {2, "Record 2", "This is the second record"};
    fwrite(&r3, sizeof(struct Record), 1, fp);
    addRecordToIndex(&index, r3.id, ftell(fp) - sizeof(struct Record));

    // Close the file and reopen it for reading
    fclose(fp);
    fp = fopen("records.dat", "rb");
    if (fp == NULL) {
        printf("Error opening file!");
        return 1;
    }

    // Search for record 2
    int offset = searchIndex(index, 2);
    if (offset == -1) {
        printf("Record not found!");
        return 1;
    }

    // Read the record from the file
    struct Record r;
    fseek(fp, offset, SEEK_SET);
    fread(&r, sizeof(struct Record), 1, fp);

    // Display the record data
    printf("Record found:\n");
    printf("ID: %d\n", r.id);
    printf("Name: %s\n", r.name);
    printf("Description: %s\n", r.description);

    // Close the file and free the index memory
    fclose(fp);
    while (index != NULL) {
        struct Node* temp = index;
        index = index->next;
        free(temp);
    }
    return 0;
}