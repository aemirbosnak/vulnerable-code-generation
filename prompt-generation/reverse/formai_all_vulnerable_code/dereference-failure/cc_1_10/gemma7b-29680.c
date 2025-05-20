//Gemma-7B DATASET v1.0 Category: Email Client ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the futuristic email client structure
typedef struct EmailClient {
    char *name;
    char *email;
    char *password;
    struct EmailClient *next;
} EmailClient;

// Function to add a new email client to the list
void addClient(EmailClient **head) {
    EmailClient *newClient = malloc(sizeof(EmailClient));
    newClient->name = malloc(20);
    newClient->email = malloc(50);
    newClient->password = malloc(20);
    newClient->next = NULL;

    // Get the client's name, email, and password
    printf("Enter your name: ");
    scanf("%s", newClient->name);

    printf("Enter your email address: ");
    scanf("%s", newClient->email);

    printf("Enter your password: ");
    scanf("%s", newClient->password);

    // Add the new client to the list
    if (*head == NULL) {
        *head = newClient;
    } else {
        (*head)->next = newClient;
    }
}

// Function to print the list of email clients
void printClients(EmailClient *head) {
    EmailClient *currentClient = head;

    printf("List of email clients:\n");
    while (currentClient) {
        printf("Name: %s\n", currentClient->name);
        printf("Email: %s\n", currentClient->email);
        printf("Password: %s\n", currentClient->password);
        printf("\n");
        currentClient = currentClient->next;
    }
}

int main() {
    EmailClient *head = NULL;

    // Add some email clients
    addClient(&head);
    addClient(&head);
    addClient(&head);

    // Print the list of email clients
    printClients(head);

    return 0;
}