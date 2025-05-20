//Falcon2-11B DATASET v1.0 Category: Database querying ; Style: energetic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_CONNECTIONS 5
#define PORT 8080

int main(int argc, char **argv)
{
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    server = gethostbyname(argv[1]);

    if (server == NULL) {
        fprintf(stderr, "No such host\n");
        exit(1);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(PORT);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket failed");
        exit(1);
    }

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to the server\n");

    // Send a query to the server
    char query[1024];
    bzero(query, sizeof(query));
    strcat(query, "SELECT * FROM customers WHERE id = 1");

    if (send(sockfd, query, strlen(query), 0) < 0) {
        perror("send failed");
        exit(1);
    }

    // Receive the response from the server
    char response[1024];
    bzero(response, sizeof(response));

    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("recv failed");
        exit(1);
    }

    printf("Server response: %s\n", response);

    // Close the connection
    close(sockfd);

    return 0;
}