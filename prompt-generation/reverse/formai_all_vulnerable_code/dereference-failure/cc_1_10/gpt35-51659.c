//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: distributed
/* A Distributed TCP/IP Programming Example */
/* This is a simple message passing program between server and clients */
/* The server listens on a specified port and receives messages from all the connected clients */
/* The clients connect to the server and send messages to it */


#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <sys/socket.h> 
#include <netinet/in.h> 
#include <arpa/inet.h> 

#define MAX_CLIENTS 5 
#define BUFFER_SIZE 256 
#define PORT 5000 

void handle_error(char* message) {
    fprintf(stderr, "%s: %s\n", message, strerror(errno));
    exit(EXIT_FAILURE);
}

/* Server function to receive messages from all the clients */
void server() {
    int server_fd, client_fd;
    struct sockaddr_in server_address, client_address;
    char buffer[BUFFER_SIZE];

    /* Create a socket for the server */
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        handle_error("Server socket creation failed");
    }

    /* Set server address */
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = INADDR_ANY;
    server_address.sin_port = htons(PORT);

    /* Bind server socket to the specified port and address */
    if (bind(server_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        handle_error("Binding server socket to address failed");
    }

    /* Listen for incoming connections */
    if (listen(server_fd, MAX_CLIENTS) == -1) {
        handle_error("Listening failed");
    }

    printf("Server listening on port %d...\n", PORT);

    /* Accept incoming connections and receive messages from clients */
    while (1) {
        socklen_t client_address_len = sizeof(client_address);

        /* Accept connection from a client */
        if ((client_fd = accept(server_fd, (struct sockaddr*)&client_address, &client_address_len)) == -1) {
            handle_error("Connection accepting failed");
        }

        printf("New client connected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));

        /* Receive message from the client */
        ssize_t num_bytes_received;
        while ((num_bytes_received = recv(client_fd, buffer, BUFFER_SIZE, 0)) > 0) {
            printf("%s:%d says: %s\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port), buffer);
            memset(buffer, 0, sizeof(buffer));
        }

        /* Close connection with the client */
        close(client_fd);
        printf("Client disconnected: %s:%d\n", inet_ntoa(client_address.sin_addr), ntohs(client_address.sin_port));
    }
}

/* Client function to send messages to the server */
void client() {
    int client_fd;
    struct sockaddr_in server_address;
    char buffer[BUFFER_SIZE];

    /* Create a socket for the client */
    if ((client_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        handle_error("Client socket creation failed");
    }

    /* Set server address */
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_address.sin_port = htons(PORT);

    /* Connect to the server */
    if (connect(client_fd, (struct sockaddr*)&server_address, sizeof(server_address)) == -1) {
        handle_error("Connection to server failed");
    }

    /* Send messages to the server */
    while (1) {
        printf("Enter a message: ");
        fgets(buffer, BUFFER_SIZE, stdin);
        buffer[strlen(buffer) - 1] = '\0';

        ssize_t num_bytes_sent;
        if ((num_bytes_sent = send(client_fd, buffer, strlen(buffer), 0)) == -1) {
            handle_error("Sending message to server failed");
        }
    }

    /* Close connection with the server */
    close(client_fd);
}

int main() {
    pid_t pid;

    /* Fork to create child process */
    if ((pid = fork()) == -1) {
        handle_error("Forking failed");
    } else if (pid == 0) {
        /* Child process runs the client function */
        client();
    } else {
        /* Parent process runs the server function */
        server();
    }

    return 0;
}