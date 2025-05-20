//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: post-apocalyptic
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

#define MAX 100
#define PORT 8080
#define SERVER "localhost"

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, portno, clientlen, n;
    struct sockaddr_in serv_addr, cli_addr;
    char buffer[MAX];

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    bzero(&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER, &serv_addr.sin_addr);
    portno = PORT;
    serv_addr.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(EXIT_FAILURE);
    }

    // Send message to server
    sprintf(buffer, "MESSAGE FROM CLIENT: %s", argv[1]);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("write failed");
        exit(EXIT_FAILURE);
    }

    // Receive message from server
    n = read(sockfd, buffer, MAX);
    if (n < 0) {
        perror("read failed");
        exit(EXIT_FAILURE);
    }
    printf("MESSAGE FROM SERVER: %s\n", buffer);

    // Close connection
    close(sockfd);
    return 0;
}