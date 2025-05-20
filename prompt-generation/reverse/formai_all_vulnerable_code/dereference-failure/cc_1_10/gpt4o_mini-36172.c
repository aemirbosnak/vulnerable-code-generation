//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_BUF_SIZE 4096
#define PORT 80

void die(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

void parse_response(char *response) {
    char *status_line = strtok(response, "\r\n");
    printf("Status Line: %s\n", status_line);

    char *header_line = NULL;
    while ((header_line = strtok(NULL, "\r\n"))) {
        if (strlen(header_line) == 0) {
            break; // End of headers
        }
        printf("Header: %s\n", header_line);
    }
}

void http_get(const char *hostname, const char *resource) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host;

    if ((host = gethostbyname(hostname)) == NULL) {
        die("Error: Unable to resolve hostname.");
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        die("Error: Unable to create socket.");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Error: Unable to connect to server.");
    }

    char request[MAX_BUF_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", resource, hostname);

    if (send(sockfd, request, strlen(request), 0) < 0) {
        die("Error: Unable to send request.");
    }

    char response[MAX_BUF_SIZE];
    memset(response, 0, sizeof(response));
    int received = recv(sockfd, response, sizeof(response) - 1, 0);
    
    if (received < 0) {
        die("Error: Unable to receive response.");
    }
    
    response[received] = '\0'; // Null terminate the response

    printf("Full Response:\n%s\n", response);
    parse_response(response);

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <resource>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *hostname = argv[1];
    const char *resource = argv[2];

    http_get(hostname, resource);
    return EXIT_SUCCESS;
}