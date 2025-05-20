//FormAI DATASET v1.0 Category: Data recovery tool ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

//Defining the structure for the data recovery program
typedef struct node {
    char data;
    struct node *next;
} node;

typedef struct data {
    node *head;
    int size;
} data;

//Function to create a new data node
node *createNode(char data) {
    node *newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Sorry, not enough memory to allocate new node\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

//Function to initialize a new data instance
data *initData() {
    data *newData = (data*)malloc(sizeof(data));
    if (newData == NULL) {
        printf("Sorry, not enough memory to allocate new data instance\n");
        exit(0);
    }
    newData->head = NULL;
    newData->size = 0;
    return newData;
}

//Function to add a node to the end of the data instance
void addNode(data *newData, char data) {
    node *newNode = createNode(data);
    if (newData->head == NULL) {
        newData->head = newNode;
    } else {
        node *curr = newData->head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
    newData->size++;
}

//Function to read in data from a file into a data instance
data *readFile(char *filename) {
    FILE *fp;
    char buffer[1000];
    data *newData = initData();
    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Sorry, couldn't open file %s\n", filename);
        exit(0);
    }
    while (fgets(buffer, sizeof(buffer), fp)) {
        int i = 0;
        while (buffer[i] != '\0') {
            addNode(newData, buffer[i]);
            i++;
        }
    }
    fclose(fp);
    return newData;
}

//Function to display the data in a data instance
void displayData(data *newData) {
    if (newData == NULL) {
        printf("Sorry, data instance not found\n");
        exit(0);
    }
    node *curr = newData->head;
    while (curr != NULL) {
        printf("%c", curr->data);
        curr = curr->next;
    }
}

//Function to recover the data from the data instance
void recoverData(data *newData) {
    if (newData == NULL) {
        printf("Sorry, data instance not found\n");
        exit(0);
    }
    char *recoveredData = (char*)malloc(newData->size * sizeof(char));
    if (recoveredData == NULL) {
        printf("Sorry, not enough memory to allocate recovered data\n");
        exit(0);
    }
    node *curr = newData->head;
    int i = 0;
    while (curr != NULL) {
        if (isupper(curr->data)) {
            recoveredData[i] = tolower(curr->data);
        } else if (islower(curr->data)) {
            recoveredData[i] = toupper(curr->data);
        } else if (isdigit(curr->data)) {
            recoveredData[i] = curr->data;
        } else {
            switch (curr->data) {
                case '!':
                    recoveredData[i] = '1';
                    break;
                case '@':
                    recoveredData[i] = '2';
                    break;
                case '#':
                    recoveredData[i] = '3';
                    break;
                case '$':
                    recoveredData[i] = '4';
                    break;
                case '%':
                    recoveredData[i] = '5';
                    break;
                case '^':
                    recoveredData[i] = '6';
                    break;
                case '&':
                    recoveredData[i] = '7';
                    break;
                case '*':
                    recoveredData[i] = '8';
                    break;
                case '(':
                    recoveredData[i] = '9';
                    break;
                case ')':
                    recoveredData[i] = '0';
                    break;
                default:
                    break;
            }
        }
        curr = curr->next;
        i++;
    }
    printf("Recovered data: %s\n", recoveredData);
}

int main() {
    char *filename = "data.txt";
    data *newData = readFile(filename);
    printf("Original data: ");
    displayData(newData);
    printf("\n");
    recoverData(newData);
    return 0;
}