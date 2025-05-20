//FormAI DATASET v1.0 Category: Socket programming ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define PORT 8080

int sockfd;
struct sockaddr_in server_addr;

void* receive_message() {
    char buffer[1024];
    int n;

    while ((n = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
        buffer[n] = '\0';
        printf("%s\n", buffer);
    }
}

int main(int argc, char const *argv[]) {
    char username[20];
    pthread_t thread;

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(1);
    }

    // server address and port
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection error");
        exit(1);
    }

    // get username
    printf("Enter your username: ");
    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    // send username to server
    send(sockfd, username, strlen(username), 0);

    // receive messages from server
    pthread_create(&thread, NULL, receive_message, NULL);

    // send messages to server
    char message[1024];
    while (fgets(message, sizeof(message), stdin) > 0) {
        send(sockfd, message, strlen(message), 0);
    }

    close(sockfd);

    return 0;
}