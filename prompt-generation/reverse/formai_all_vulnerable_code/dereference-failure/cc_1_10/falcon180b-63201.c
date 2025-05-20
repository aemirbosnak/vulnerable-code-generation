//Falcon-180B DATASET v1.0 Category: TCP/IP Programming ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUF_SIZE 1024

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[BUF_SIZE];
    int len, new_len;
    struct hostent *server;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == 0) {
        printf("Error: Socket creation failed\n");
        exit(1);
    }

    // Set server address
    server = gethostbyname("localhost");
    if (server == NULL) {
        printf("Error: Host not found\n");
        exit(1);
    }
    bcopy(server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(8080);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error: Connection failed\n");
        exit(1);
    }

    // Send data to server
    strcpy(buffer, "Hello, World!");
    len = strlen(buffer);
    if (send(sockfd, buffer, len, 0) < 0) {
        printf("Error: Data send failed\n");
        exit(1);
    }

    // Receive data from server
    new_len = recv(sockfd, buffer, BUF_SIZE, 0);
    if (new_len < 0) {
        printf("Error: Data receive failed\n");
        exit(1);
    }
    buffer[new_len] = '\0';
    printf("Received data: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}