//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: interoperable
/* A Simple HTTP Proxy Server in C */
/* Written by: Nithin Mallya (github.com/nithinmallya) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFSIZE 4096

void error(char *msg) {
    perror(msg);
    exit(0);
}

int main(int argc, char *argv[]) {

    int sockfd, clientsockfd, portno;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUFSIZE];

    if (argc < 2) {
        fprintf(stderr, "usage: %s <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[1]); // get port number from command line

    /* Create a socket */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    /* Fill in server address */
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    /* Bind socket to address */
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    /* Listen for incoming connections */
    listen(sockfd, 5);
    printf("Proxy server listening on port %d...\n", portno);

    while (1) {

        /* Accept incoming connection */
        clilen = sizeof(cli_addr);
        clientsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
        if (clientsockfd < 0) {
            error("ERROR on accept");
        }

        /* Get client details */
        char *client_ip = inet_ntoa(cli_addr.sin_addr);
        int client_port = ntohs(cli_addr.sin_port);
        printf("\nClient with IP address %s and port number %d connected.\n", client_ip, client_port);

        /* Receive request from client */
        bzero(buffer, BUFSIZE);
        if (recv(clientsockfd, buffer, BUFSIZE, 0) < 0) {
            error("ERROR reading from socket");
        }

        /* Extract requested URL */
        char url[BUFSIZE];
        sscanf(buffer, "GET http://%99[^\n]", url);

        /* Parse hostname and path */
        char hostname[BUFSIZE], path[BUFSIZE];
        sscanf(url, "%99[^/]/%99[^\n]", hostname, path);

        /* If no path was provided, set it to root */
        if (strlen(path) == 0) {
            strcpy(path, "/");
        }

        /* Print request */
        printf("--> Request: %s %s\n", hostname, path);

        /* Get IP address of requested server */
        struct hostent *server = gethostbyname(hostname);
        if (server == NULL) {
            fprintf(stderr, "ERROR, no such host\n");
            exit(0);
        }

        /* Create socket to connect to server */
        int server_sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (server_sockfd < 0) {
            error("ERROR opening socket");
        }

        /* Connect to server */
        bzero((char *) &serv_addr, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
        serv_addr.sin_port = htons(80);
        if (connect(server_sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
            error("ERROR connecting");
        }

        /* Send request to server */
        if (send(server_sockfd, buffer, strlen(buffer), 0) < 0) {
            error("ERROR sending to server");
        }

        /* Relay server response to client */
        bzero(buffer, BUFSIZE);
        while (recv(server_sockfd, buffer, BUFSIZE, 0) > 0) {
            if (send(clientsockfd, buffer, strlen(buffer), 0) < 0) {
                error("ERROR sending to client");
            }
            bzero(buffer, BUFSIZE);
        }

        /* Close client and server sockets */
        close(clientsockfd);
        close(server_sockfd);
        printf("Client with IP address %s and port number %d disconnected.\n", client_ip, client_port);
    }

    return 0;
}