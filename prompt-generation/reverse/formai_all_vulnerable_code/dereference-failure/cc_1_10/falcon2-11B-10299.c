//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: surrealist
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;

    char buffer[256];

    // Connect to the server
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("ftp.example.com");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(21);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Connected to %s\n", server->h_name);

    // Send command to server
    printf("Enter command: ");
    fgets(buffer, sizeof(buffer), stdin);

    // Send command to server
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Read response from server
    bzero(buffer, sizeof(buffer));
    n = read(sockfd, buffer, sizeof(buffer));
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}