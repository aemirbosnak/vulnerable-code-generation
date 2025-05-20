//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define HTTP_PORT 80
#define MAX_MESSAGE_SIZE 1024

char* create_http_request(char* host, char* path) {
    char* request = (char*) malloc(MAX_MESSAGE_SIZE * sizeof(char));
    sprintf(request, "GET %s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);
    return request;
}

void parse_response(char* response) {
    char* status_code = strtok(response, " ");
    char* status_message = strtok(NULL, "\r\n");

    printf("HTTP/1.0 %s %s\n", status_code, status_message);
}

void make_request(char* host, char* path) {
    struct sockaddr_in server_address;
    struct hostent* server;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error: could not open socket\n");
        return;
    }

    server = gethostbyname(host);
    if (server == NULL) {
        printf("Error: no such host\n");
        return;
    }

    bzero((char*) &server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char*) server->h_addr, (char*) &server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(HTTP_PORT);

    if (connect(sockfd, (struct sockaddr*) &server_address, sizeof(server_address)) < 0) {
        printf("Error: could not connect to server\n");
        return;
    }

    char* request = create_http_request(host, path);
    if (write(sockfd, request, strlen(request)) < 0) {
        printf("Error: could not send request\n");
        return;
    }

    char* response = (char*) malloc(MAX_MESSAGE_SIZE * sizeof(char));
    bzero(response, MAX_MESSAGE_SIZE);
    if (read(sockfd, response, MAX_MESSAGE_SIZE - 1) < 0) {
        printf("Error: could not read response\n");
        return;
    }

    parse_response(response);
    printf("%s", response);

    free(request);
    free(response);
    close(sockfd);
}

int main(int argc, char** argv) {
    if (argc < 3) {
        printf("Error: usage ./http_client [host] [path]\n");
        return 1;
    }

    char* host = argv[1];
    char* path = argv[2];

    make_request(host, path);

    return 0;
}