//FormAI DATASET v1.0 Category: Data recovery tool ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;             // Data to be stored
    struct Node* next;    // Pointer to next node
};

void insertNode(struct Node** head, int newData) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = newData;
    newNode->next = *head;
    *head = newNode;
}

void printList(struct Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

struct Node* recoverData(char* fileName) {
    FILE* fp = fopen(fileName, "rb");
    if (fp == NULL) {
        printf("Error opening file!\n");
        return NULL;
    }
    
    struct Node* head = NULL;
    int data;
    while (fread(&data, sizeof(int), 1, fp) == 1) {
        insertNode(&head, data);
    }
    
    fclose(fp);
    return head;
}

int main() {
    struct Node* recoveredList = recoverData("data.bin");
    if (recoveredList == NULL) {
        printf("Unable to recover data.\n");
        return 1;
    }
    
    printf("Recovered data:\n");
    printList(recoveredList);
    
    return 0;
}