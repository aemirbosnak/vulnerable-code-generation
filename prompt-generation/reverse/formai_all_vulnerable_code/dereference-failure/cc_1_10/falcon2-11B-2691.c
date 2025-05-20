//Falcon2-11B DATASET v1.0 Category: TCP/IP Programming ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define PORT 8080

int main() {
    int sockfd, numbytes;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Connect to server
    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "Failed to resolve hostname\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    // Send data
    char message[] = "Hello, World!";
    numbytes = write(sockfd, message, sizeof(message));
    if (numbytes < 0) {
        perror("Write failed");
        exit(1);
    }

    // Receive data
    numbytes = read(sockfd, message, sizeof(message));
    if (numbytes < 0) {
        perror("Read failed");
        exit(1);
    }

    printf("Received: %s\n", message);

    close(sockfd);
    return 0;
}