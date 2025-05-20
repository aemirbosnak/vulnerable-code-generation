//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// function prototypes
int create_connection(char *host, int port);
int send_request(int sockfd, char *request);
int receive_response(int sockfd, char *response);

// main function
int main(int argc, char *argv[]) {
    // check command line arguments
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <host>\n", argv[0]);
        exit(1);
    }

    // create a socket
    int sockfd = create_connection(argv[1], 80);

    // send HTTP request
    char request[256];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", argv[1]);
    send_request(sockfd, request);

    // receive HTTP response
    char response[256];
    receive_response(sockfd, response);

    printf("%s", response);

    return 0;
}

// function to create a TCP connection to the server
int create_connection(char *host, int port) {
    int sockfd;
    struct hostent *server;
    struct sockaddr_in server_addr;

    // convert host name to IP address
    if ((server = gethostbyname(host)) == NULL) {
        fprintf(stderr, "Hostname not found: %s\n", host);
        exit(1);
    }

    // create socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        exit(1);
    }

    // set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    memcpy((char *)&server_addr.sin_addr.s_addr, (char *)server->h_addr, server->h_length);

    // connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    return sockfd;
}

// function to send an HTTP request
int send_request(int sockfd, char *request) {
    int num_sent = 0;
    int bytes_left = strlen(request);

    while (bytes_left > 0) {
        int n = write(sockfd, request + num_sent, bytes_left);

        if (n < 0) {
            perror("write");
            exit(1);
        }

        num_sent += n;
        bytes_left -= n;
    }

    return num_sent;
}

// function to receive an HTTP response
int receive_response(int sockfd, char *response) {
    int num_received = 0;
    int bytes_left = strlen(response);

    while (bytes_left > 0) {
        int n = read(sockfd, response + num_received, bytes_left);

        if (n < 0) {
            perror("read");
            exit(1);
        }

        num_received += n;
        bytes_left -= n;
    }

    return num_received;
}