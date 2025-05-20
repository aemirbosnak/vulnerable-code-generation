//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    // Check for arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Get host and port
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return EXIT_FAILURE;
    }

    // Get host IP address
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        perror("gethostbyname");
        return EXIT_FAILURE;
    }

    // Create a sockaddr_in struct
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr, hostent->h_addr_list[0], hostent->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        return EXIT_FAILURE;
    }

    // Send HTTP request
    char *request = "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n";
    int request_len = strlen(request) + strlen(host);
    char *request_buf = malloc(request_len);
    sprintf(request_buf, request, host);
    if (send(sockfd, request_buf, request_len, 0) == -1) {
        perror("send");
        return EXIT_FAILURE;
    }
    free(request_buf);

    // Receive HTTP response
    char *response = malloc(1024);
    int response_len = 0;
    while ((response_len = recv(sockfd, response, 1024, 0)) > 0) {
        printf("%s", response);
    }
    free(response);

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}