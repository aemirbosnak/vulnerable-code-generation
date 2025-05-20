//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

int main() {
    int sockfd, portno, n;
    struct sockaddr_in servaddr;
    struct hostent *server;
    char message[100];
    char response[100];

    printf("Enter a message to send to the server: ");
    fgets(message, sizeof(message), stdin);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    server = gethostbyname("localhost");
    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    bzero((char *) &servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &servaddr.sin_addr.s_addr, server->h_length);
    servaddr.sin_port = htons(8888);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    printf("Message: %s\n", message);
    send(sockfd, message, strlen(message), 0);

    n = recv(sockfd, response, sizeof(response), 0);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("Response: %s\n", response);

    close(sockfd);
    return 0;
}