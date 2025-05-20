//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_BUFFER 1024

void *recv_handler(void *args);
void *send_handler(void *args);

int main(int argc, char *argv[]) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    char buffer[MAX_BUFFER];
    pthread_t recv_t, send_t;
    char *username, *password;

    if (argc < 4) {
        printf("Usage: %s hostname port username password\n", argv[0]);
        return -1;
    }

    portno = atoi(argv[2]);
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return -1;
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        printf("Error, no such host\n");
        return -1;
    }

    memset((void *)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((void *)&serv_addr.sin_addr.s_addr, (void *)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error connecting");
        return -1;
    }

    username = argv[3];
    password = argv[4];

    // Send login credentials to the server
    sprintf(buffer, "LOGIN %s %s\n", username, password);
    send(sockfd, buffer, strlen(buffer), 0);

    // Create send and receive threads
    pthread_create(&recv_t, NULL, recv_handler, (void *)&sockfd);
    pthread_create(&send_t, NULL, send_handler, (void *)&sockfd);

    // Wait for threads to finish
    pthread_join(recv_t, NULL);
    pthread_join(send_t, NULL);

    close(sockfd);
    return 0;
}

void *recv_handler(void *args) {
    int sockfd = *(int *)args;
    char buffer[MAX_BUFFER];

    while (1) {
        memset(buffer, 0, MAX_BUFFER);

        // Receive data from server
        if (recv(sockfd, buffer, MAX_BUFFER, 0) < 0) {
            return NULL;
        }

        if (strcmp(buffer, "LOGGEDIN\n") == 0) {
            printf("Successfully logged in.\n");
        } else {
            printf("Received: %s", buffer);
        }
    }

    return NULL;
}

void *send_handler(void *args) {
    int sockfd = *(int *)args;
    char buffer[MAX_BUFFER];

    while (1) {
        fgets(buffer, MAX_BUFFER, stdin);

        // Send data to server
        if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
            perror("Error sending message");
            return NULL;
        }

        if (strcmp(buffer, "QUIT\n") == 0) {
            return NULL;
        }
    }

    return NULL;
}