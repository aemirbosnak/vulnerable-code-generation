//LLAMA2-13B DATASET v1.0 Category: Phone Book ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

// Structure to store contact information
struct contact {
    char name[50];
    char number[20];
};

// Function to create a new contact
struct contact *new_contact(char *name, char *number) {
    struct contact *contact = malloc(sizeof(struct contact));
    strcpy(contact->name, name);
    strcpy(contact->number, number);
    return contact;
}

// Function to add a contact to the phone book
void add_contact(struct contact *contact) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // Set up the address structure
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    // Connect to the server
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    // Send the contact information to the server
    send(sock, contact, sizeof(struct contact), 0);
    // Receive the response from the server
    recv(sock, contact, sizeof(struct contact), 0);
    // Print the received contact information
    printf("Received contact: %s %s\n", contact->name, contact->number);
    // Close the socket
    close(sock);
}

// Function to search for a contact in the phone book
struct contact *search_contact(char *name) {
    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    // Set up the address structure
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(PORT),
        .sin_addr.s_addr = INADDR_ANY
    };
    // Connect to the server
    connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    // Send the name to search for to the server
    send(sock, name, strlen(name), 0);
    // Receive the response from the server
    recv(sock, name, strlen(name), 0);
    // Print the received name
    printf("Received name: %s\n", name);
    // Close the socket
    close(sock);
    return NULL;
}

int main() {
    // Create a new contact
    struct contact *contact = new_contact("John", "555-1234");
    // Add the contact to the phone book
    add_contact(contact);
    // Search for a contact
    struct contact *found_contact = search_contact("John");
    if (found_contact != NULL) {
        printf("Contact found: %s %s\n", found_contact->name, found_contact->number);
    } else {
        printf("Contact not found\n");
    }
    return 0;
}