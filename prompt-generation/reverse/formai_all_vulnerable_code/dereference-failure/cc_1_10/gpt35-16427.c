//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {

    // Surprise, surprise! We're building an HTTP Client!

    if (argc < 3) { // Oops! Looks like the user forgot to provide the URL and port
        printf("Uh-oh! You forgot to provide the URL and port number.\n");
        exit(1); // Let's exit the program gracefully
    }

    // Let's extract the URL and port from the user's input
    char *url = argv[1];
    int port = atoi(argv[2]);

    // Now let's get the hostname from the URL
    struct hostent *server = gethostbyname(url);
    if (server == NULL) { // Uh-oh! The hostname couldn't be resolved
        printf("Oops! The hostname couldn't be resolved.\n");
        exit(1); // Let's exit the program gracefully
    }

    // Let's create a socket for the client to connect to the server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) { // Oops! Socket creation failed
        printf("Uh-oh! Socket creation failed.\n");
        exit(1); // Let's exit the program gracefully
    }

    // Let's initialize the server address struct
    struct sockaddr_in serv_addr;
    memset((char*) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    memcpy((char*) &serv_addr.sin_addr.s_addr, (char*) server->h_addr, server->h_length);
    serv_addr.sin_port = htons(port);

    // Now let's connect to the server
    if (connect(sockfd, (struct sockaddr*) &serv_addr, sizeof(serv_addr)) < 0) { // Oops! Connection Failed
        printf("Oops! Connection Failed.\n");
        exit(1); // Let's exit the program gracefully
    }

    // Woohoo! We're finally connected to the server
    printf("Connected to the server.\n");

    // Let's form the HTTP request
    char *http_req = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char request[strlen(http_req) + strlen(url)];
    sprintf(request, http_req, url);

    // Let's send the HTTP request to the server
    if (send(sockfd, request, strlen(request), 0) < 0) { // Oops! Sending Failed
        printf("Oops! Sending Failed.\n");
        exit(1); // Let's exit the program gracefully
    }

    // Let's receive the response from the server
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) { // Oops! Receiving Failed
        printf("Oops! Receiving Failed.\n");
        exit(1); // Let's exit the program gracefully
    }

    // Woohoo! We received a response from the server
    printf("\nResponse from the server:\n");
    printf("%s", buffer);

    // Let's close the socket and exit the program
    close(sockfd);
    printf("\nHTTP Client program exit successful.\n");

    return 0;
}