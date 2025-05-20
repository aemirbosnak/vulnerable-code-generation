//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);

    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        return 1;
    }

    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        fprintf(stderr, "Error: could not connect to server\n");
        return 1;
    }

    char *request = "GET / HTTP/1.1\r\n\r\n";
    if (write(sockfd, request, strlen(request)) < 0) {
        fprintf(stderr, "Error: could not send request\n");
        return 1;
    }

    char response[MAX_LINE];
    int bytes_read = read(sockfd, response, MAX_LINE);
    if (bytes_read < 0) {
        fprintf(stderr, "Error: could not read response\n");
        return 1;
    }

    printf("%s", response);

    close(sockfd);

    return 0;
}