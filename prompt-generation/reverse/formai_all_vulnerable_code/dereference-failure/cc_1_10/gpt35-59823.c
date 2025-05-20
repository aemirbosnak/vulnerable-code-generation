//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFSIZE 4096

void error(const char *msg) {
    perror(msg);
    exit(0);
}

// Connect to the server specified in the URL and return a socket
int connect_to_server(char *url) {
    int sockfd;
    char hostname[1024];
    struct hostent *server;
    struct sockaddr_in serv_addr;

    // Get hostname
    sscanf(url, "http://%[^/]", hostname);

    // Get server entry by hostname
    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(0);
    }

    // Setup socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(80);

    // Connect to server
    if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    return sockfd;
}

int main(int argc, char *argv[]) {
    int sockfd_client, sockfd_server, portno, n;
    struct sockaddr_in serv_addr, cli_addr;
    socklen_t clilen;
    char buffer[BUFSIZE];

    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }

    sockfd_client = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd_client < 0) {
        error("ERROR opening socket");
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);

    if (bind(sockfd_client, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR on binding");
    }

    listen(sockfd_client, 5);
    clilen = sizeof(cli_addr);

    while (true) {
        // Accept incoming client request
        int sockfd_new = accept(sockfd_client, (struct sockaddr *) &cli_addr, &clilen);
        if (sockfd_new < 0) {
            error("ERROR on accept");
        }

        bzero(buffer, BUFSIZE);

        // Read client request
        n = read(sockfd_new, buffer, BUFSIZE);
        if (n < 0) {
            error("ERROR reading from socket");
        }

        printf("%s", buffer);

        // Get the requested URL
        char *url = strtok(buffer, " ");
        url = strtok(NULL, " ");
        if (url == NULL) {
            error("ERROR invalid request");
        }

        // Connect to the server
        sockfd_server = connect_to_server(url);

        // Forward client request to server
        n = write(sockfd_server, buffer, strlen(buffer));
        if (n < 0) {
            error("ERROR writing to socket");
        }

        // Read response from server and forward to client
        bzero(buffer, BUFSIZE);
        while ((n = read(sockfd_server, buffer, BUFSIZE)) > 0) {
            if (write(sockfd_new, buffer, n) < 0) {
                error("ERROR writing to socket");
            }
            bzero(buffer, BUFSIZE);
        }

        close(sockfd_new);
        close(sockfd_server);
    }

    return 0;
}