//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, port, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Convert IP address and port number to network address format
    server = gethostbyname("192.168.1.100");
    if (server == NULL) {
        perror("ERROR, no such host");
        exit(1);
    }

    memset((char *) &serv_addr, '0', sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(9999);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s on port %d\n", inet_ntoa(serv_addr.sin_addr), ntohs(serv_addr.sin_port));

    // Read data from server
    n = read(sockfd, buffer, 1024);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("Received: %s\n", buffer);

    // Close socket
    close(sockfd);

    return 0;
}