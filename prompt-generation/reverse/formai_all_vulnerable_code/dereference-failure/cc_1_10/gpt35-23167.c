//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BUFSIZE 1024

/**
 * Check for errors and exit if any are found.
 */
void error(char *msg) {
    perror(msg);
    exit(0);
}

/**
 * Handle a new client connection by forwarding its request to the server
 * and sending the server's response back to the client.
 */
void handle_client(int client_sockfd) {
    char buffer[BUFSIZE];
    struct sockaddr_in server_address;
    int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (server_sockfd < 0)
        error("ERROR opening socket");

    // Get server information
    struct hostent *server = gethostbyname("www.example.com");
    if (server == NULL)
        error("ERROR, no such host");

    // Set up server address
    bzero((char *)&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(80);

    // Connect to server
    if (connect(server_sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0)
        error("ERROR connecting to server");

    bzero(buffer, BUFSIZE);

    // Read client's request
    int n = read(client_sockfd, buffer, BUFSIZE);
    if (n < 0)
        error("ERROR reading from socket");

    printf("Client sent request:\n%s\n", buffer);

    // Forward client's request to server
    n = write(server_sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    bzero(buffer, BUFSIZE);

    // Read server's response
    n = read(server_sockfd, buffer, BUFSIZE);
    if (n < 0)
        error("ERROR reading from socket");

    printf("Received response from server:\n%s\n", buffer);

    // Send server's response back to client
    n = write(client_sockfd, buffer, strlen(buffer));
    if (n < 0)
        error("ERROR writing to socket");

    close(server_sockfd);
    close(client_sockfd);
}

int main(int argc, char *argv[]) {
    int sockfd, newsockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0)
        error("ERROR opening socket");

    bzero((char *)&serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    serv_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
        error("ERROR on binding");

    listen(sockfd, 5);
    clilen = sizeof(cli_addr);

    while (1) {
        newsockfd = accept(sockfd, (struct sockaddr *)&cli_addr, &clilen);
        if (newsockfd < 0)
            error("ERROR on accept");

        printf("Client connected\n");

        handle_client(newsockfd);
    }

    return 0;
}