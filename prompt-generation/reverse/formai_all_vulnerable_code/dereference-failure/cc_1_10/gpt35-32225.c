//FormAI DATASET v1.0 Category: Client Server Application ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define MAX_MSG_LENGTH 200

int server_socket;
int client_socket;
pthread_t tid;

struct sockaddr_in server_address;
struct sockaddr_storage client_address;
socklen_t client_address_len;

void *client_handler(void *arg) {
    char message[MAX_MSG_LENGTH] = {0};
    char reply[MAX_MSG_LENGTH] = {0};

    // receive message from the client
    ssize_t recv_len = recv(client_socket, message, MAX_MSG_LENGTH, 0);
    if (recv_len <= 0) {
        return NULL;
    }

    // print the message
    printf("Received message: %s\n", message);

    // analyze the message
    char *first_word = strtok(message, " ");
    if (strcmp(first_word, "Hello") == 0) {
        strcpy(reply, "Hello to you too!");
    } else if (strcmp(first_word, "Goodbye") == 0) {
        strcpy(reply, "Goodbye, have a nice day!");
    } else {
        strcpy(reply, "Sorry, I didn't understand you.");
    }

    // send the reply to the client
    ssize_t send_len = send(client_socket, reply, strlen(reply), 0);
    if (send_len <= 0) {
        return NULL;
    }

    return NULL;
}

void start_server(int port) {
    // create socket
    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // setup server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(port);

    // bind socket to address
    if (bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // listen for incoming connections
    if (listen(server_socket, 5) < 0) {
        perror("listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server started on port %d\n", port);

    while (1) {
        // accept incoming connection
        client_address_len = sizeof(client_address);
        client_socket = accept(server_socket, (struct sockaddr *)&client_address, &client_address_len);
        if (client_socket < 0) {
            perror("accept failed");
            continue;
        }

        // start a new thread to handle the client
        if (pthread_create(&tid, NULL, &client_handler, NULL) != 0) {
            perror("pthread_create failed");
            continue;
        }

        // detach thread from main thread to avoid memory leaks
        pthread_detach(tid);
    }
}

int main() {
    printf("Welcome to the Sherlock Holmes Server\n\n");

    // start server on port 1234
    start_server(1234);

    return 0;
}