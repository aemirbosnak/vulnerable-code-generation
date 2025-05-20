//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // getting server information
    server = gethostbyname("localhost");

    if (server == NULL) {
        fprintf(stderr, "ERROR: no such host\n");
        exit(EXIT_FAILURE);
    }

    // assigning values to structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(10000);

    // connecting to server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    printf("Connection established with server\n");

    // send message to server
    char buffer[100];
    bzero(buffer, 100);

    printf("Enter the message: ");
    fgets(buffer, 100, stdin);

    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("send failed");
        exit(EXIT_FAILURE);
    }

    // receive message from server
    n = recv(sockfd, buffer, 100, 0);

    if (n < 0) {
        perror("recv failed");
        exit(EXIT_FAILURE);
    }

    printf("Message from server: %s\n", buffer);

    // close connection
    close(sockfd);

    return 0;
}