//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/**
 * Function to build and send a HTTP request
 * to the specified host and port.
 */
void send_http_request(char* host, int port, char* path) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct hostent* server;
    char buffer[BUFFER_SIZE];

    /* Create a TCP socket */
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    /* Get the IP address of the server */
    if ((server = gethostbyname(host)) == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(1);
    }

    /* Fill in the server's address details */
    memset((char*)&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char*)&serv_addr.sin_addr.s_addr, (char*)server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    /* Connect to the server */
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    /* Build the HTTP request */
    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    /* Send the HTTP request */
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    /* Receive and print the response */
    memset(buffer, 0, BUFFER_SIZE);
    n = read(sockfd, buffer, BUFFER_SIZE);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }
    printf("%s\n", buffer);

    /* Close the socket */
    close(sockfd);
}

int main() {
    char host[] = "www.example.com";
    int port = 80;
    char path[] = "/index.html";

    /* Send a HTTP request to the server */
    send_http_request(host, port, path);

    return 0;
}