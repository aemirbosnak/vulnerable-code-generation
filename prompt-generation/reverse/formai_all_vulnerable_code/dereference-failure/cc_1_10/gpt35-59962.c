//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

/*
  Method: sendMessage
  Description: This function takes a socket file descriptor client_socket_fd
               and a message buffer message and sends the message recursively
               until the entire message is sent.
*/
void sendMessage(int client_socket_fd, char* message) {
    int message_length = strlen(message);
    int sent_length = send(client_socket_fd, message, message_length, 0);
    if (sent_length == 0) {
        printf("Message not sent successfully.\n");
        exit(EXIT_FAILURE);
    } else if (sent_length < message_length) {
        sendMessage(client_socket_fd, &message[sent_length]);
    }
}

/*
  Method: receiveMessage
  Description: This function takes a socket file descriptor client_socket_fd
               and a message buffer message and receives the message recursively
               until the entire message is received.
*/
void receiveMessage(int client_socket_fd, char* message) {
    int message_length;
    if ((message_length = recv(client_socket_fd, message, MAX_BUFFER_SIZE, 0)) < 0) {
        printf("Unable to receive message.\n");
        exit(EXIT_FAILURE);
    } else if (message_length > 0) {
        message[message_length] = '\0';
        printf("Server: %s\n", message);
    } else {
        printf("Connection closed by server.\n");
        exit(EXIT_SUCCESS);
    }
}

int main(int argc, char const *argv[]) {
    int client_socket_fd;
    struct sockaddr_in server_address;

    // Create socket
    if ((client_socket_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Unable to create socket.\n");
        exit(EXIT_FAILURE);
    }

    // Set server address details
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        printf("Invalid address/ Address not supported.\n");
        exit(EXIT_FAILURE);
    }

    // Connect to server
    if (connect(client_socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        printf("Connection failed.\n");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    char message[MAX_BUFFER_SIZE];
    printf("Enter message: ");
    fgets(message, MAX_BUFFER_SIZE, stdin);
    sendMessage(client_socket_fd, message);

    // Receive message from server
    receiveMessage(client_socket_fd, message);
    close(client_socket_fd);
    return 0;
}