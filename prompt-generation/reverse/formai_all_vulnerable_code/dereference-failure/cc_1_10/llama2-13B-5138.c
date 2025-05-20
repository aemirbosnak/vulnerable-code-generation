//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sock;
    struct sockaddr_in server_addr;
    char buffer[1024];

    // Create a socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Use loopback address
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    // Send a random message
    srand(time(NULL));
    int message_len = rand() % 1024;
    char *message = malloc(message_len);
    for (int i = 0; i < message_len; i++) {
        message[i] = 'a' + rand() % 26; // Generate a random character
    }
    send(sock, message, message_len, 0);

    // Receive a response
    recv(sock, buffer, 1024, 0);

    // Print the response
    printf("Received message: %s\n", buffer);

    // Close the socket
    close(sock);

    return 0;
}