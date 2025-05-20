//LLAMA2-13B DATASET v1.0 Category: Socket programming ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(8080),
        .sin_addr.s_addr = inet_addr("127.0.0.1")
    };

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    char buffer[BUFFER_SIZE];
    int bytes_read = read(sock, buffer, BUFFER_SIZE);
    if (bytes_read < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }

    printf("Received message: %s\n", buffer);

    char message[] = "Hello, server!";
    int bytes_written = write(sock, message, strlen(message));
    if (bytes_written < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    printf("Sent message: %s\n", message);

    char *message_received = malloc(bytes_read);
    memcpy(message_received, buffer, bytes_read);
    printf("Received message: %s\n", message_received);

    free(message_received);

    close(sock);
    return 0;
}