//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

#define MAX_HEADER_LENGTH 1024
#define MAX_RESPONSE_LENGTH 4096

int main(int argc, char *argv[]) {
    //Check if the arguments are correct
    if(argc != 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return EXIT_FAILURE;
    }

    char *hostname = argv[1];
    char request[MAX_HEADER_LENGTH];

    //Build HTTP request
    snprintf(request, MAX_HEADER_LENGTH, "GET /index.html HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", hostname);

    //Resolve host
    struct hostent *he = gethostbyname(hostname);
    if(he == NULL) {
        fprintf(stderr, "Could not resolve host\n");
        return EXIT_FAILURE;
    }

    //Create socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if(sock == -1) {
        fprintf(stderr, "Failed to create socket\n");
        return EXIT_FAILURE;
    }

    //Connect to remote server
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr = *((struct in_addr*)he->h_addr);
    if(connect(sock, (struct sockaddr*)&server, sizeof(server)) < 0) {
        fprintf(stderr, "Could not connect to server\n");
        return EXIT_FAILURE;
    }

    //Send HTTP request
    int length = strlen(request);
    if(send(sock, request, length, 0) != length) {
        fprintf(stderr, "Failed to send request\n");
        return EXIT_FAILURE;
    }

    //Receive HTTP response
    char response[MAX_RESPONSE_LENGTH];
    int total = 0;
    int bytes_received;
    while(total < MAX_RESPONSE_LENGTH) {
        bytes_received = recv(sock, response+total, MAX_RESPONSE_LENGTH-total, 0);
        if(bytes_received == 0) {
            break;
        } else if(bytes_received == -1) {
            fprintf(stderr, "Failed to receive response\n");
            return EXIT_FAILURE;
        }
        total += bytes_received;
    }
    response[total] = '\0';

    printf("Response:\n%s", response);
    close(sock);

    return EXIT_SUCCESS;
}