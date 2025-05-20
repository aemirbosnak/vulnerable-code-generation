//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_HEADER_LEN 8192
#define MAX_BODY_LEN 8192

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s hostname port path\n", argv[0]);
        exit(1);
    }
    
    // Parse the arguments
    char *host = argv[1];
    int port = atoi(argv[2]);
    char *path = argv[3];
    
    // Create a socket and connect to the server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        exit(1);
    }
    
    struct sockaddr_in serv_addr = {0};
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(port);
    
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }
    
    // Build the request and send it
    char *request = malloc(MAX_HEADER_LEN + strlen(path) + 1);
    sprintf(request, "GET %s HTTP/1.1\r\n", path);
    strcat(request, "Host: ");
    strcat(request, host);
    strcat(request, "\r\n");
    strcat(request, "Connection: close\r\n");
    strcat(request, "\r\n");
    
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        exit(1);
    }

    free(request);
    
    // Receive the response
    char *response = malloc(MAX_HEADER_LEN + MAX_BODY_LEN + 1);
    int total_len = 0;
    
    while (total_len < MAX_HEADER_LEN + MAX_BODY_LEN) {
        int num_bytes = recv(sockfd, response + total_len, MAX_HEADER_LEN + MAX_BODY_LEN - total_len, 0);
        
        if (num_bytes < 0) {
            perror("recv");
            exit(1);
        } else if (num_bytes == 0) {
            break;
        } else {
            total_len += num_bytes;
        }
    }
    
    // Check if the response was valid HTTP
    char *body = strstr(response, "\r\n\r\n") + 4;
    int body_len = strlen(body);
    
    if (body_len == total_len) {
        fprintf(stderr, "Error: invalid response\n");
        exit(1);
    }
    
    int status_code;
    char status_line[32];
    char *header = response;
    int header_len = body - response - 4;
    
    sscanf(header, "HTTP/1.1 %d %31[^\r\n]", &status_code, status_line);
    printf("Status code: %d\n", status_code);
    
    // Print the headers and body
    header[header_len] = '\0';
    printf("Headers:\n%s\n", header);
    printf("Body:\n%s\n", body);
    
    free(response);
    close(sockfd);
    
    return 0;
}