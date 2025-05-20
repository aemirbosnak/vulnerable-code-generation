//FormAI DATASET v1.0 Category: Data recovery tool ; Style: systematic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
    char* data;
    int size;
} Node;

void recoverData(Node* arr, int numNodes) {
    // calculate the total size of the recovered data
    int totalSize = 0;
    for(int i = 0; i < numNodes; i++) {
        totalSize += arr[i].size;
    }

    // allocate memory for the recovered data
    char* recoveredData = (char*) malloc(totalSize * sizeof(char));

    // concatenate all the node data to recover the original data
    int currentPosition = 0;
    for(int i = 0; i < numNodes; i++) {
        memcpy(recoveredData + currentPosition, arr[i].data, arr[i].size);
        currentPosition += arr[i].size;
    }

    // print the recovered data
    printf("Recovered data: %s\n", recoveredData);

    // free memory
    free(recoveredData);
}

int main() {
    // initialize array of nodes
    Node arr[3];

    // create first node
    char* data1 = "Hello ";
    int size1 = strlen(data1);
    Node node1 = {data1, size1};

    // create second node
    char* data2 = "world!";
    int size2 = strlen(data2);
    Node node2 = {data2, size2};

    // create third node
    char* data3 = " This is a C data recovery tool example program.";
    int size3 = strlen(data3);
    Node node3 = {data3, size3};

    // add nodes to array
    arr[0] = node1;
    arr[1] = node2;
    arr[2] = node3;

    // recover data from nodes
    recoverData(arr, 3);

    return 0;
}