//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/select.h>
#include <sys/time.h>
#include <pthread.h>

#define PORT 8080
#define BUFSIZE 1024

typedef struct {
    int sockfd;
    struct sockaddr_in addr;
    char buffer[BUFSIZE];
    pthread_t serverThread;
} ClientData;

void *client_thread(void *arg) {
    ClientData *client = (ClientData*)arg;
    char *host = "127.0.0.1";
    char *message = "Hello, World!";

    int n = sendto(client->sockfd, message, strlen(message), 0, (struct sockaddr*)&(client->addr), sizeof(client->addr));
    if (n == -1) {
        perror("Error sending message");
    } else {
        printf("Message sent successfully\n");
    }

    close(client->sockfd);
    free(client);
}

int main() {
    ClientData *client = malloc(sizeof(ClientData));
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Error creating socket");
        exit(1);
    }

    client->sockfd = sockfd;
    client->addr.sin_family = AF_INET;
    client->addr.sin_port = htons(PORT);
    client->addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(sockfd, (struct sockaddr*)&(client->addr), sizeof(client->addr)) == -1) {
        perror("Error binding socket");
        exit(1);
    }

    if (listen(sockfd, 5) == -1) {
        perror("Error listening on socket");
        exit(1);
    }

    pthread_create(&(client->serverThread), NULL, client_thread, client);

    int n;
    while (1) {
        struct sockaddr_in clientAddr;
        socklen_t addrlen = sizeof(clientAddr);
        int newsockfd = accept(sockfd, (struct sockaddr*)&(clientAddr), &addrlen);
        if (newsockfd == -1) {
            perror("Error accepting connection");
            exit(1);
        }

        printf("New connection from %s\n", inet_ntoa(clientAddr.sin_addr));

        n = recv(newsockfd, client->buffer, BUFSIZE, 0);
        if (n == -1) {
            perror("Error receiving data");
            exit(1);
        }

        printf("Received data: %s\n", client->buffer);

        send(newsockfd, client->buffer, n, 0);
        close(newsockfd);
    }

    close(sockfd);
    pthread_join(client->serverThread, NULL);
    free(client);
    return 0;
}