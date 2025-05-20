//GEMINI-pro DATASET v1.0 Category: Mailing list manager ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 9000
#define MAX_CLIENTS 100
#define MAX_LIST_SIZE 1000

// Define the mailing list structure
typedef struct mailing_list {
    char **subscribers;
    int num_subscribers;
    char *list_name;
} mailing_list;

// Create a new mailing list
mailing_list *create_mailing_list(char *list_name) {
    mailing_list *list = malloc(sizeof(mailing_list));
    list->subscribers = malloc(sizeof(char *) * MAX_LIST_SIZE);
    list->num_subscribers = 0;
    list->list_name = malloc(strlen(list_name) + 1);
    strcpy(list->list_name, list_name);
    return list;
}

// Add a subscriber to a mailing list
void add_subscriber(mailing_list *list, char *subscriber) {
    list->subscribers[list->num_subscribers] = malloc(strlen(subscriber) + 1);
    strcpy(list->subscribers[list->num_subscribers], subscriber);
    list->num_subscribers++;
}

// Remove a subscriber from a mailing list
void remove_subscriber(mailing_list *list, char *subscriber) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        if (strcmp(list->subscribers[i], subscriber) == 0) {
            free(list->subscribers[i]);
            list->subscribers[i] = list->subscribers[list->num_subscribers - 1];
            list->num_subscribers--;
            break;
        }
    }
}

// Send a message to all subscribers of a mailing list
void send_message(mailing_list *list, char *message) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        // Send the message to the subscriber
        printf("Sending message to %s: %s\n", list->subscribers[i], message);
    }
}

// Free the memory allocated for a mailing list
void free_mailing_list(mailing_list *list) {
    int i;
    for (i = 0; i < list->num_subscribers; i++) {
        free(list->subscribers[i]);
    }
    free(list->subscribers);
    free(list->list_name);
    free(list);
}

// Main function
int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Bind the socket to the port
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(PORT);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind");
        exit(1);
    }

    // Listen for connections
    if (listen(sockfd, MAX_CLIENTS) == -1) {
        perror("listen");
        exit(1);
    }

    // Create a mailing list
    mailing_list *list = create_mailing_list("test-list");

    // Accept connections and handle requests
    while (1) {
        // Accept a connection
        int clientfd = accept(sockfd, NULL, NULL);
        if (clientfd == -1) {
            perror("accept");
            continue;
        }

        // Read the request from the client
        char buffer[1024];
        int nbytes = read(clientfd, buffer, sizeof(buffer));
        if (nbytes == -1) {
            perror("read");
            close(clientfd);
            continue;
        }

        // Parse the request
        char *request = strtok(buffer, " ");
        if (request == NULL) {
            close(clientfd);
            continue;
        }

        // Handle the request
        if (strcmp(request, "ADD") == 0) {
            // Add a subscriber to the mailing list
            char *subscriber = strtok(NULL, " ");
            if (subscriber == NULL) {
                close(clientfd);
                continue;
            }
            add_subscriber(list, subscriber);
            printf("Added subscriber %s to mailing list %s\n", subscriber, list->list_name);
        } else if (strcmp(request, "REMOVE") == 0) {
            // Remove a subscriber from the mailing list
            char *subscriber = strtok(NULL, " ");
            if (subscriber == NULL) {
                close(clientfd);
                continue;
            }
            remove_subscriber(list, subscriber);
            printf("Removed subscriber %s from mailing list %s\n", subscriber, list->list_name);
        } else if (strcmp(request, "SEND") == 0) {
            // Send a message to all subscribers of the mailing list
            char *message = strtok(NULL, "\n");
            if (message == NULL) {
                close(clientfd);
                continue;
            }
            send_message(list, message);
            printf("Sent message %s to all subscribers of mailing list %s\n", message, list->list_name);
        } else {
            // Send an error message to the client
            char *error = "Invalid request\n";
            write(clientfd, error, strlen(error));
        }

        // Close the connection
        close(clientfd);
    }

    // Free the memory allocated for the mailing list
    free_mailing_list(list);

    // Close the socket
    close(sockfd);

    return 0;
}