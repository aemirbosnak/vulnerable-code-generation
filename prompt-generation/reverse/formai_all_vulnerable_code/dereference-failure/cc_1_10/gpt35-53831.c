//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUFFER_SIZE 2048

int main(int argc, char *argv[]) {

    if (argc != 2) { // check for correct number of arguments
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct hostent *host;
    if ((host = gethostbyname(argv[1])) == NULL) { // obtain host information
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address; // set up server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr = *((struct in_addr *)host->h_addr);

    int socket_fd;
    if ((socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1) { // create socket
        perror("socket");
        exit(EXIT_FAILURE);
    }

    if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) { // establish connection to server
        perror("connect");
        exit(EXIT_FAILURE);
    }

    char request[BUFFER_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);
    if (send(socket_fd, request, strlen(request), 0) == -1) { // send request to server
        perror("send");
        exit(EXIT_FAILURE);
    }

    char response[BUFFER_SIZE];
    int received = 0;
    while ((received = recv(socket_fd, response, BUFFER_SIZE, 0)) > 0) { // receive and print response
        printf("%.*s", received, response);
    }

    close(socket_fd); // close connection
    return 0;
}