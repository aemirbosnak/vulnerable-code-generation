//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <pthread.h>

#define BUFSIZE 1024
#define PORT 8080
#define MAX_CONNECTIONS 10

void *serve(void *p);
int main() {
    int server_fd, new_connection, n;
    struct sockaddr_in server_addr, client_addr;
    struct hostent *host;
    char buffer[BUFSIZE];
    pthread_t thread[MAX_CONNECTIONS];
    int i;

    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("Socket creation failed\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_fd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        printf("Binding failed\n");
        exit(1);
    }

    if (listen(server_fd, MAX_CONNECTIONS) < 0) {
        printf("Listen failed\n");
        exit(1);
    }

    printf("Server started on port %d\n", PORT);

    for (i = 0; i < MAX_CONNECTIONS; i++) {
        if (pthread_create(&thread[i], NULL, serve, NULL)!= 0) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    while (1) {
        new_connection = accept(server_fd, (struct sockaddr *) &client_addr, (socklen_t *) &n);
        if (new_connection < 0) {
            printf("Accept failed\n");
            exit(1);
        }

        if (pthread_create(&thread[new_connection % MAX_CONNECTIONS], NULL, serve, NULL)!= 0) {
            printf("Error creating thread\n");
            exit(1);
        }
    }

    return 0;
}

void *serve(void *p) {
    int connection, n;
    char buffer[BUFSIZE];
    struct sockaddr_in client_addr;

    connection = *((int *) p);
    while (1) {
        bzero(buffer, BUFSIZE);
        n = recv(connection, buffer, BUFSIZE, 0);
        if (n < 0) {
            printf("Error receiving from client\n");
            exit(1);
        }

        printf("Received from client: %s\n", buffer);
        send(connection, "HTTP/1.1 200 OK\r\n\r\n", 26, 0);
        bzero(buffer, BUFSIZE);
        strcat(buffer, "Hello World!");
        send(connection, buffer, strlen(buffer), 0);
    }

    return NULL;
}