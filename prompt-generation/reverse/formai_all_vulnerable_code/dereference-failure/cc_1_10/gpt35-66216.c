//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Linked list node structure.
typedef struct Node {
    char* data;
    struct Node* next;
} Node;

// Function to insert data at the end of a linked list.
void insertAtEnd(Node** head, char* data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL)
        current = current->next;
    
    current->next = newNode;
}

int main() {
    // Variables to store read file data.
    char line[MAX_SIZE];
    char* ipAddress;
    char* username;
    char* filename;
    char* dateTime;

    const char* delimiter = " ";
    Node* ipAddresses = NULL;
    Node* usernames = NULL;
    Node* filenames = NULL;
    Node* dateTimes = NULL;

    // Open input file for reading.
    FILE* inputFile = fopen("input.txt", "r");

    if (inputFile == NULL) {
        printf("Error: Could not open input file.\n");
        return 1;
    }

    // Read file data line by line and extract data.
    while (fgets(line, MAX_SIZE, inputFile)) {
        char* token = strtok(line, delimiter);
        int tokenIndex = 0;

        while (token != NULL) {
            switch (tokenIndex) {
                case 0:
                    ipAddress = token;
                    insertAtEnd(&ipAddresses, ipAddress);
                    break;

                case 1:
                    username = token;
                    insertAtEnd(&usernames, username);
                    break;

                case 2:
                    filename = token;
                    insertAtEnd(&filenames, filename);
                    break;

                case 3:
                    dateTime = token;
                    insertAtEnd(&dateTimes, dateTime);
                    break;
            }

            token = strtok(NULL, delimiter);
            tokenIndex++;
        }
    }

    // Close input file.
    fclose(inputFile);

    // Print extracted data.
    printf("IP Addresses:\n");
    Node* ipAddressPtr = ipAddresses;
    while (ipAddressPtr != NULL) {
        printf("%s", ipAddressPtr->data);
        ipAddressPtr = ipAddressPtr->next;
    }

    printf("\nUsernames:\n");
    Node* usernamePtr = usernames;
    while (usernamePtr != NULL) {
        printf("%s", usernamePtr->data);
        usernamePtr = usernamePtr->next;
    }

    printf("\nFilenames:\n");
    Node* filenamePtr = filenames;
    while (filenamePtr != NULL) {
        printf("%s", filenamePtr->data);
        filenamePtr = filenamePtr->next;
    }

    printf("\nDate/Times:\n");
    Node* dateTimePtr = dateTimes;
    while (dateTimePtr != NULL) {
        printf("%s", dateTimePtr->data);
        dateTimePtr = dateTimePtr->next;
    }

    // Free linked list memory.
    Node* current;
    while (ipAddresses != NULL) {
        current = ipAddresses;
        ipAddresses = ipAddresses->next;
        free(current);
    }
    while (usernames != NULL) {
        current = usernames;
        usernames = usernames->next;
        free(current);
    }
    while (filenames != NULL) {
        current = filenames;
        filenames = filenames->next;
        free(current);
    }
    while (dateTimes != NULL) {
        current = dateTimes;
        dateTimes = dateTimes->next;
        free(current);
    }

    return 0;
}