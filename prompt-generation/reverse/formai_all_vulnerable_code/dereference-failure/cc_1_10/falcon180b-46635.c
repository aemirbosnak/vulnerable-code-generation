//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char* argv[]) {
    char* hostname;
    int port;
    int sockfd;
    struct hostent* host;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int n;

    printf("Enter POP3 server hostname: ");
    scanf("%s", hostname);

    printf("Enter POP3 server port: ");
    scanf("%d", &port);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error resolving hostname\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to POP3 server\n");

    while (1) {
        printf("Enter command: ");
        scanf("%s", buffer);
        send(sockfd, buffer, strlen(buffer), 0);

        n = recv(sockfd, buffer, BUFFER_SIZE, 0);
        if (n <= 0) {
            printf("Error receiving data\n");
            exit(1);
        }

        buffer[n] = '\0';
        printf("Received: %s", buffer);
    }

    close(sockfd);

    return 0;
}