//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>

void *processRequest(void *arg) {
    int sockfd, portno, n;
    struct sockaddr_in their_addr;
    struct hostent *server;
    char buffer[256];
    char *request = (char *)arg;

    sockfd = *((int *)arg);

    printf("Received request: %s\n", request);

    // Connect to the server
    server = gethostbyname("www.example.com");
    if (server == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    portno = htons(80); // Default port for HTTP
    their_addr.sin_family = AF_INET;
    their_addr.sin_port = htons(portno);
    their_addr.sin_addr.s_addr = *(long *)server->h_addr;

    if (connect(sockfd, (struct sockaddr *)&their_addr, sizeof(their_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the request to the server
    strcpy(buffer, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    send(sockfd, buffer, strlen(buffer), 0);

    // Read the response from the server
    while ((n = recv(sockfd, buffer, 255, 0)) > 0) {
        printf("%s", buffer);
    }

    // Close the connection
    close(sockfd);
}

int createSocket(int port) {
    int sockfd, err;
    struct sockaddr_in server_addr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    bzero((char *)&server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *(long *)server->h_addr;
    server_addr.sin_port = htons(port);

    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("listen");
        exit(1);
    }

    return sockfd;
}

int main() {
    int sockfd, portno, n;
    struct sockaddr_in their_addr;
    struct hostent *server;
    char buffer[256];
    pthread_t thread;
    int status;

    sockfd = createSocket(80);

    while (1) {
        printf("Waiting for incoming connection...\n");
        if ((n = accept(sockfd, (struct sockaddr *)&their_addr, (socklen_t *)&portno)) < 0) {
            perror("accept");
            exit(1);
        }

        printf("Accepted connection from %s:%d\n", inet_ntoa(their_addr.sin_addr), ntohs(their_addr.sin_port));

        // Create a new thread to handle the connection
        if (pthread_create(&thread, NULL, processRequest, (void *)&sockfd)!= 0) {
            perror("pthread_create");
            exit(1);
        }

        status = pthread_join(thread, NULL);
        if (status!= 0) {
            perror("pthread_join");
            exit(1);
        }

        close(sockfd);
    }

    close(sockfd);

    return 0;
}