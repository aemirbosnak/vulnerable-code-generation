//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;

    char buf[1000];

    // Create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(1);
    }

    // Resolve server host name
    server = gethostbyname("127.0.0.1");

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    // Set up the server address struct
    memset((char *) &servaddr, '\0', sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(8080);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("connection failed");
        exit(1);
    }

    printf("Connection established with server\n");

    // Send query to server
    sprintf(buf, "SELECT * FROM customers");
    write(sockfd, buf, strlen(buf));

    // Read response from server
    bzero(buf, 1000);
    n = read(sockfd, buf, 1000);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    buf[n] = '\0';
    printf("Server response: %s\n", buf);

    // Close socket
    close(sockfd);

    return 0;
}