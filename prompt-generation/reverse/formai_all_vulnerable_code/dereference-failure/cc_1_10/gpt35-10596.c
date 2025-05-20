//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_REQUEST_LENGTH 1024
#define MAX_RESPONSE_LENGTH 1024
#define MAX_HEADER_LENGTH 1024

char* fetch(char *url) {
    struct sockaddr_in server_address;
    struct hostent *server;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error opening socket");
        return NULL;
    }

    char *domain_name = strtok(url, "/");
    char *path = strtok(NULL, "");

    server = gethostbyname(domain_name);

    if (server == NULL) {
        perror("Error, no such host");
        return NULL;
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_address.sin_addr.s_addr, server->h_length);
    server_address.sin_port = htons(80);

    if (connect(sockfd,(struct sockaddr *) &server_address,sizeof(server_address)) < 0) {
        perror("Error connecting");
        return NULL;
    }

    char *request;
    asprintf(&request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, domain_name);

    send(sockfd, request, strlen(request), 0);

    free(request);

    char *response = malloc(MAX_RESPONSE_LENGTH);

    int data_length = 0;

    char *header = malloc(MAX_HEADER_LENGTH);
    memset(header, 0, MAX_HEADER_LENGTH);
    int header_length = 0;

    while (recv(sockfd, response + data_length, MAX_RESPONSE_LENGTH - data_length, 0) > 0) {
        data_length = strlen(response);

        if (header_length <= 0 && strstr(response, "\r\n\r\n")) {
            header_length = strstr(response, "\r\n\r\n") - response + 4;
            strncpy(header, response, header_length);
        }

        if (header_length > 0 && data_length >= header_length) {
            break;
        }

        if (data_length + MAX_RESPONSE_LENGTH >= MAX_RESPONSE_LENGTH) {
            perror("Error response too large");
            free(response);
            free(header);
            return NULL;
        }
    }

    if (header_length <= 0) {
        perror("Error no response header");
        free(response);
        free(header);
        return NULL;
    }

    header[header_length - 4] = '\0';

    char *body = malloc(data_length - header_length + 1);
    strncpy(body, response + header_length, data_length - header_length + 1);

    free(response);
    free(header);

    return body;
}

int main(int argc, char **argv) {
    if (argc <= 1 || argc > 2) {
        printf("Usage: %s url\n", argv[0]);
        return 0;
    }

    char *url = argv[1];

    char *response = fetch(url);

    if (response == NULL || strlen(response) <= 0) {
        printf("Failed to retrieve URL: %s\n", url);
        return 0;
    }

    printf("%s\n", response);
    free(response);

    return 0;
}