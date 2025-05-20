//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define SERVER_ADDR "mail.example.com"
#define SERVER_PORT 993
#define MAX_BUFFER 1024

void error(char *msg) {
    fprintf(stderr, "%s\n", msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int client_sockfd;
    ssize_t n;
    char buffer[MAX_BUFFER];
    struct sockaddr_in server_addr;
    struct hostent *server;

    // create socket
    client_sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_sockfd < 0)
        error("ERROR opening socket");

    // get server info
    server = gethostbyname(SERVER_ADDR);
    if (server == NULL)
        error("ERROR, no such host");

    // initialize server_addr struct
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(SERVER_PORT);

    // connect to server
    if (connect(client_sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0)
        error("ERROR connecting");

    // send IMAP request
    char request[MAX_BUFFER];
    strcpy(request, "tag LOGIN username password\r\n");
    write(client_sockfd, request, strlen(request));

    // read response from server
    bzero(buffer, MAX_BUFFER);
    n = read(client_sockfd, buffer, MAX_BUFFER);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    // send another IMAP request
    strcpy(request, "tag LIST \"\" *\r\n");
    write(client_sockfd, request, strlen(request));

    // read response from server
    bzero(buffer, MAX_BUFFER);
    n = read(client_sockfd, buffer, MAX_BUFFER);
    if (n < 0)
        error("ERROR reading from socket");
    printf("%s\n", buffer);

    // close socket
    close(client_sockfd);
    return 0;
}