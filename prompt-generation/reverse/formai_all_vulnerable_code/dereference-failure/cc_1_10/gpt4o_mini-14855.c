//GPT-4o-mini DATASET v1.0 Category: Database Indexing System ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct DataNode {
    char *data;
    struct DataNode *next;
} DataNode;

typedef struct IndexNode {
    char *key;
    DataNode *dataList;
    struct IndexNode *next;
} IndexNode;

IndexNode *indexHead = NULL;

// Function to create a new DataNode
DataNode *createDataNode(char *data) {
    DataNode *newNode = (DataNode *)malloc(sizeof(DataNode));
    newNode->data = strdup(data);
    newNode->next = NULL;
    return newNode;
}

// Function to create a new IndexNode
IndexNode *createIndexNode(char *key) {
    IndexNode *newNode = (IndexNode *)malloc(sizeof(IndexNode));
    newNode->key = strdup(key);
    newNode->dataList = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to add a data entry under a specified index key
void addData(char *key, char *data) {
    IndexNode *indexPtr = indexHead;

    // Search for the index node
    while (indexPtr != NULL && strcmp(indexPtr->key, key) != 0) {
        indexPtr = indexPtr->next;
    }

    if (indexPtr == NULL) {
        indexPtr = createIndexNode(key);
        indexPtr->next = indexHead;
        indexHead = indexPtr;
    }

    DataNode *dataNode = createDataNode(data);
    dataNode->next = indexPtr->dataList;
    indexPtr->dataList = dataNode;
}

// Function to display index and associated data entries
void displayIndex() {
    IndexNode *indexPtr = indexHead;

    while (indexPtr != NULL) {
        printf("Key: %s\n", indexPtr->key);
        DataNode *dataPtr = indexPtr->dataList;
        while (dataPtr != NULL) {
            printf("    Data: %s\n", dataPtr->data);
            dataPtr = dataPtr->next;
        }
        indexPtr = indexPtr->next;
    }
}

// Function to free allocated memory
void freeMemory() {
    while (indexHead != NULL) {
        IndexNode *tempIndex = indexHead;
        indexHead = indexHead->next;

        free(tempIndex->key);
        DataNode *tempData = tempIndex->dataList;
        while (tempData != NULL) {
            DataNode *nextData = tempData->next;
            free(tempData->data);
            free(tempData);
            tempData = nextData;
        }
        free(tempIndex);
    }
}

// Function to create surreal instances
void createSurrealData() {
    addData("dream", "A feathered whisper in night’s embrace.");
    addData("dream", "Echoes of laughter beneath the moon’s gaze.");
    addData("reality", "The clock ticks softly, a subtle tyrant.");
    addData("time", "A swirling river that stagnant souls sail.");
    addData("whimsy", "The cat in the hat dances with joy.");
    addData("whimsy", "Umbrellas bloom like flowers in a storm.");
    addData("memory", "Remnants of laughter trapped in glass.");
}

// Main function to initiate the indexing system
int main() {
    printf("Welcome to the Surreal Indexing System!\n");
    
    createSurrealData();
    
    printf("\nIndex and Associated Data:\n");
    displayIndex();
    
    // Clean up allocated memory
    freeMemory();
    
    printf("\nThank you for visiting the land of dreams.\n");
    return 0;
}