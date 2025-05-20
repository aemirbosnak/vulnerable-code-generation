//FormAI DATASET v1.0 Category: Networking ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BUFFER_SIZE 4096

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main() {
    struct sockaddr_in serv_addr;
    struct hostent *server;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    char *hostname = "localhost";
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr = *((struct in_addr *) server->h_addr);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR connecting");

    char message[BUFFER_SIZE];

    while (1) {
        memset(message, 0, BUFFER_SIZE);
        printf("Enter message: ");
        if (fgets(message, BUFFER_SIZE, stdin) == NULL)
            break;
        message[strcspn(message, "\n")] = 0;

        if (send(sockfd, message, strlen(message), 0) < 0)
            error("ERROR sending message");

        memset(message, 0, BUFFER_SIZE);

        if (recv(sockfd, message, BUFFER_SIZE, 0) < 0)
            error("ERROR receiving message");

        printf("Server response: %s\n", message);
    }

    close(sockfd);
    return 0;
}