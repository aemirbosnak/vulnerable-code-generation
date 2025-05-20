//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// function to create a socket
int create_socket(char *host, char *port) {
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    struct hostent *server;

    // get the port number
    portno = atoi(port);

    // create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // get the server's IP address
    server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr,"ERROR, no such host\n");
        exit(1);
    }

    // fill in the server's address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }

    return sockfd;
}

// function to send a request to the server
void send_request(int sockfd, char *request) {
    // send the request to the server
    if (write(sockfd, request, strlen(request)) < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }
}

// function to receive a response from the server
char *receive_response(int sockfd) {
    char *response;
    int n;

    // allocate memory for the response
    response = malloc(1024);
    if (response == NULL) {
        perror("ERROR allocating memory");
        exit(1);
    }

    // receive the response from the server
    n = read(sockfd, response, 1023);
    if (n < 0) {
        perror("ERROR reading from socket");
        exit(1);
    }

    // null-terminate the response
    response[n] = '\0';

    return response;
}

// main function
int main(int argc, char *argv[]) {
    int sockfd;
    char *request;
    char *response;

    // check if the user has provided enough arguments
    if (argc != 3) {
        fprintf(stderr,"Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    // create a socket
    sockfd = create_socket(argv[1], argv[2]);

    // create a request
    request = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";

    // send the request to the server
    send_request(sockfd, request);

    // receive the response from the server
    response = receive_response(sockfd);

    // print the response
    printf("%s", response);

    // free the memory allocated for the response
    free(response);

    // close the socket
    close(sockfd);

    return 0;
}