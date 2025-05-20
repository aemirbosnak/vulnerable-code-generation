//Falcon2-11B DATASET v1.0 Category: Simple Web Server ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080

void serve_page(int sockfd) {
    char buffer[1024];
    int numBytes;

    bzero(buffer, sizeof(buffer));

    printf("Serving page...\n");

    // Send HTTP header
    sprintf(buffer, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\r\n");
    write(sockfd, buffer, strlen(buffer));

    // Send HTML page
    sprintf(buffer, "<html><head><title>My Page</title></head><body><h1>Hello, World!</h1></body></html>");
    write(sockfd, buffer, strlen(buffer));

    printf("Page served!\n");
}

int main() {
    int sockfd, portno;
    struct sockaddr_in server_address;
    struct hostent *server;

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

    bzero((char *) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(PORT);

    if (bind(sockfd, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    if (listen(sockfd, 5) < 0) {
        perror("ERROR on listen");
        exit(1);
    }

    while (1) {
        int newsockfd;
        struct sockaddr_in cli_address;
        int addrlen = sizeof(cli_address);

        newsockfd = accept(sockfd, (struct sockaddr *) &cli_address, &addrlen);
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        printf("New connection: %d\n", newsockfd);
        serve_page(newsockfd);

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}