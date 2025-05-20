//FormAI DATASET v1.0 Category: Linked list operations ; Style: distributed
/*

This is a unique C Linked list program that implements various operations such as
creating a linked list, inserting, deleting and displaying elements in the list.
The program is designed to work in a distributed style where the linked list is shared
across multiple nodes in a network. The program uses sockets and threads to achieve 
this functionality.

Author: John Doe
Date: 01-01-2022

*/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<string.h>
#include<pthread.h>

// Structure definition for linked list node
struct node {
    int data;
    struct node *next;
};

// Function declarations
void displayList(struct node *);
void insertNode(struct node **, int);
void deleteNode(struct node **, int);
void *connectionHandler(void *);

// Global variables
struct node *head = NULL; // Starting node of linked list

/*
    Main function
*/
int main(int argc, char *argv[]) {

    int serverSocket, clientSocket, c, *newSocket;
    struct sockaddr_in server, client;
    pthread_t threadId;

    // Create socket
    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        printf("Could not create socket.");
        return 1;
    }

    // Prepare server structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons(8888);

    // Bind socket to a port
    if (bind(serverSocket, (struct sockaddr *)&server, sizeof(server)) < 0) {
        printf("Bind failed.");
        return 1;
    }

    // Listen for incoming connections
    listen(serverSocket, 3);
    printf("Waiting for incoming connections...");

    c = sizeof(struct sockaddr_in);

    // Accept incoming connection
    while ((clientSocket = accept(serverSocket, (struct sockaddr *)&client, (socklen_t*)&c))) {
        printf("Connection accepted from %s:%d.", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        newSocket = malloc(1);
        *newSocket = clientSocket;

        // Create thread for new connection
        if (pthread_create(&threadId, NULL, connectionHandler, (void*)newSocket) < 0) {
            printf("Could not create thread.");
            return 1;
        }

        // Detach thread from main thread
        pthread_detach(threadId);
    }

    if (clientSocket < 0) {
        printf("Accept failed.");
        return 1;
    }

    return 0;
}

/*
    Thread function to handle incoming connections
*/
void *connectionHandler(void *socket) {
    // Get socket descriptor
    int clientSocket = *(int*)socket;
    char clientMessage[2000];

    // Receive data from client
    while (recv(clientSocket, clientMessage, 2000, 0) > 0) {
        // Parse input message
        int command, data;
        sscanf(clientMessage, "%d %d", &command, &data);

        switch(command) {
            case 1:
                // Insert data into linked list
                insertNode(&head, data);
                printf("\nInserted %d into linked list.", data);
                break;
            case 2:
                // Delete data from linked list
                deleteNode(&head, data);
                printf("\nDeleted %d from linked list.", data);
                break;
            case 3:
                // Display linked list
                printf("\nLinked list:");
                displayList(head);
                break;
            default:
                printf("\nInvalid command.");
        }

        // Clear buffer and send response to client
        bzero(clientMessage, sizeof(clientMessage));
        strcpy(clientMessage, "Success");
        send(clientSocket, clientMessage, strlen(clientMessage), 0);
    }

    // Free socket descriptor
    free(socket);

    return NULL;
}

/*
    Function to display linked list
*/
void displayList(struct node *node) {
    // Traverse linked list and print elements
    while (node != NULL) {
        printf(" %d", node->data);
        node = node->next;
    }
}

/*
    Function to insert element into linked list
*/
void insertNode(struct node **head, int data) {
    struct node *newNode;
    newNode = (struct node *)malloc(sizeof(struct node));

    // Assign data and set next node to null
    newNode->data = data;
    newNode->next = NULL;

    // If list is empty, set new node as starting node
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Traverse to last node and set new node as next node
    struct node *temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/*
    Function to delete element from linked list
*/
void deleteNode(struct node **head, int data) {
    struct node *temp = *head, *prev;

    // If first node contains data
    if (temp != NULL && temp->data == data) {
        *head = temp->next;
        free(temp);
        return;
    }

    // Traverse linked list to find node with given data
    while (temp != NULL && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }

    // If data not found in linked list
    if (temp == NULL) {
        printf("\n%d not found in linked list.", data);
        return;
    }

    // Unlink node from linked list
    prev->next = temp->next;
    free(temp);
}