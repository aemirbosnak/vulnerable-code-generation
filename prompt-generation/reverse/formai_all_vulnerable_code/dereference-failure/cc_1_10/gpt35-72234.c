//FormAI DATASET v1.0 Category: TCP/IP Programming ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char const *argv[]) {
    int socket_fd;
    struct sockaddr_in server_address;
    char message[1024] = {0};
    char *response_message;

    // Creating socket file descriptor
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Setting up server address struct
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(PORT);
    if (inet_pton(AF_INET, "127.0.0.1", &server_address.sin_addr) <= 0) {
        perror("invalid address");
        exit(EXIT_FAILURE);
    }

    // Connecting to server
    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Prompting user for message to send to server
    printf("Enter message for server: ");
    scanf("%[^\n]", message);

    // Sending message to server
    send(socket_fd, message, strlen(message), 0);

    // Receiving response message from server
    response_message = malloc(1024 * sizeof(char));
    read(socket_fd, response_message, 1024);

    // Printing out response from server
    printf("Server response: %s\n", response_message);

    free(response_message);
    close(socket_fd);

    return 0;
}