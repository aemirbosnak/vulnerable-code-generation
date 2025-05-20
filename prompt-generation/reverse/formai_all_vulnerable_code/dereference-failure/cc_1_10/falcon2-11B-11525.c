//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 110

int connectToServer() {
    struct hostent *server;
    struct sockaddr_in addr;
    int sockfd, rc;
    char buffer[256];

    // Get server details
    if ((server = gethostbyname("your_server_name")) == NULL) {
        perror("gethostbyname()");
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket()");
        exit(1);
    }

    // Set up address structure
    memset((char *)&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    addr.sin_addr.s_addr = *(unsigned long *)server->h_addr;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        perror("connect()");
        exit(1);
    }

    return sockfd;
}

void disconnectFromServer(int sockfd) {
    if (close(sockfd) < 0) {
        perror("close()");
        exit(1);
    }
}

void main(int argc, char **argv) {
    int sockfd, rc;
    char buffer[256];

    // Connect to server
    sockfd = connectToServer();
    if (sockfd < 0) {
        printf("Failed to connect to server\n");
        exit(1);
    }

    // Login to server
    printf("Enter username: ");
    scanf("%s", buffer);
    rc = write(sockfd, buffer, strlen(buffer));
    if (rc < 0) {
        perror("write()");
        exit(1);
    }
    printf("Enter password: ");
    scanf("%s", buffer);
    rc = write(sockfd, buffer, strlen(buffer));
    if (rc < 0) {
        perror("write()");
        exit(1);
    }
    printf("Login successful\n");

    // Get list of messages
    printf("Getting list of messages...\n");
    rc = read(sockfd, buffer, sizeof(buffer));
    if (rc < 0) {
        perror("read()");
        exit(1);
    }
    printf("Messages: %s\n", buffer);

    // Disconnect from server
    disconnectFromServer(sockfd);
}