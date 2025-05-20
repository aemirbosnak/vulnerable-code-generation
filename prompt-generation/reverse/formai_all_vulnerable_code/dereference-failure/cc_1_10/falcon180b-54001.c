//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <pthread.h>

#define BUFFER_SIZE 1024

// Function prototypes
void *send_message(void *args);
void *receive_response(void *args);

int main() {
    int sockfd;
    struct sockaddr_in server_addr;
    char *server_ip = "127.0.0.1";
    int server_port = 25;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Send message
    pthread_t send_thread;
    pthread_create(&send_thread, NULL, send_message, (void *)sockfd);

    // Receive response
    pthread_t receive_thread;
    pthread_create(&receive_thread, NULL, receive_response, (void *)sockfd);

    // Close socket
    close(sockfd);

    return 0;
}

void *send_message(void *args) {
    int sockfd = *((int *)args);
    char message[BUFFER_SIZE];

    // Prompt user for message
    printf("Enter message: ");
    fgets(message, BUFFER_SIZE, stdin);

    // Send message to server
    if (send(sockfd, message, strlen(message), 0) == -1) {
        printf("Error sending message\n");
        exit(1);
    }

    return NULL;
}

void *receive_response(void *args) {
    int sockfd = *((int *)args);
    char response[BUFFER_SIZE];

    // Receive response from server
    if (recv(sockfd, response, BUFFER_SIZE, 0) == -1) {
        printf("Error receiving response\n");
        exit(1);
    }

    // Print response
    printf("Response: %s\n", response);

    return NULL;
}