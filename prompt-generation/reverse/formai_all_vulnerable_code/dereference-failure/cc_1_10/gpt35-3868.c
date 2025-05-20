//FormAI DATASET v1.0 Category: Phone Book ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// structure for storing contact information
struct Contact {
    char name[50];
    char phone_num[20];
    char address[100];
};

// function for searching contact by name
void search_by_name(char* buffer, struct Contact* arr, int contact_count, char* name) {
    int found = 0;
    for (int i = 0; i < contact_count; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            sprintf(buffer, "%s %s %s", arr[i].name, arr[i].phone_num, arr[i].address);
            found = 1;
            break;
        }
    }
    if (!found) {
        sprintf(buffer, "Contact not found!");
    }
}

// function for adding a contact
void add_contact(char* buffer, struct Contact* arr, int* contact_count, char* name, char* phone_num, char* address) {
    // check if the contact already exists
    for (int i = 0; i < *contact_count; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            sprintf(buffer, "Contact with this name already exists!");
            return;
        }
    }
    // add the contact
    struct Contact new_contact;
    strcpy(new_contact.name, name);
    strcpy(new_contact.phone_num, phone_num);
    strcpy(new_contact.address, address);
    arr[*contact_count] = new_contact;
    *contact_count += 1;
    sprintf(buffer, "Contact added successfully!");
}

// function for deleting a contact
void delete_contact(char* buffer, struct Contact* arr, int* contact_count, char* name) {
    int found = 0;
    for (int i = 0; i < *contact_count; i++) {
        if (strcmp(arr[i].name, name) == 0) {
            // shift all the contacts after the deleted contact one place to the left
            for (int j = i+1; j < *contact_count; j++) {
                arr[j-1] = arr[j];
            }
            *contact_count -= 1;
            found = 1;
            sprintf(buffer, "Contact deleted successfully!");
            break;
        }
    }
    if (!found) {
        sprintf(buffer, "Contact not found!");
    }
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <port>\n", argv[0]);
        return 0;
    }
    int port = atoi(argv[1]);

    // create socket
    int server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket == -1) {
        printf("Error creating socket!\n");
        return 0;
    }

    // set server address
    struct sockaddr_in server_address;
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);
    server_address.sin_addr.s_addr = INADDR_ANY;

    // bind the socket to the address
    if (bind(server_socket, (struct sockaddr*) &server_address, sizeof(server_address)) == -1) {
        printf("Error binding socket to address!\n");
        return 0;
    }

    // listen for incoming connections
    if (listen(server_socket, 5) == -1) {
        printf("Error listening for incoming connections!\n");
        return 0;
    }

    // initialize contact list
    struct Contact contacts[100];
    int contact_count = 0;

    // communicate with clients
    while (1) {
        // accept incoming connection
        int client_socket = accept(server_socket, NULL, NULL);
        if (client_socket == -1) {
            printf("Error accepting incoming connection!\n");
            continue;
        }

        // receive message from client
        char client_message[1024];
        recv(client_socket, client_message, 1024, 0);

        // parse the message and perform appropriate action
        char* token = strtok(client_message, " ");
        char buffer[1024];
        if (strcmp(token, "search") == 0) {
            token = strtok(NULL, " ");
            search_by_name(buffer, contacts, contact_count, token);
        } else if (strcmp(token, "add") == 0) {
            char name[50], phone_num[20], address[100];
            token = strtok(NULL, " ");
            strcpy(name, token);
            token = strtok(NULL, " ");
            strcpy(phone_num, token);
            token = strtok(NULL, "");
            strcpy(address, token);
            add_contact(buffer, contacts, &contact_count, name, phone_num, address);
        } else if (strcmp(token, "delete") == 0) {
            token = strtok(NULL, " ");
            delete_contact(buffer, contacts, &contact_count, token);
        } else {
            sprintf(buffer, "Invalid command!");
        }

        // send the response back to the client
        send(client_socket, buffer, strlen(buffer), 0);

        // close the client socket
        close(client_socket);
    }

    // close the server socket
    close(server_socket);

    return 0;
}