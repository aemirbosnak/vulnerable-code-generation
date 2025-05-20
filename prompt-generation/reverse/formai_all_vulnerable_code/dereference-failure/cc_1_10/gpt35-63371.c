//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_REQUEST_SIZE 1024
#define MAX_RESPONSE_SIZE 102400

int main(int argc, char *argv[]) {

    /* Define variables to hold response */
    char response[MAX_RESPONSE_SIZE];
    memset(response, 0, MAX_RESPONSE_SIZE);

    /* Parse arguments */
    if (argc < 2) {
        printf("Usage: %s <hostname> <port> <path>\n", argv[0]);
        return 1;
    }
    char *hostname = argv[1];
    int port = atoi(argv[2]);
    char *path = argv[3];

    /* Create socket */
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error creating socket\n");
        return 1;
    }

    /* Resolve host */
    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error resolving host %s\n", hostname);
        return 1;
    }

    /* Define server address */
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);

    /* Connect to server */
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    /* Build request */
    char request[MAX_REQUEST_SIZE];
    memset(request, 0, MAX_REQUEST_SIZE);
    snprintf(request, MAX_REQUEST_SIZE, "GET %s HTTP/1.1\r\nHost: %s:%d\r\n\r\n", path, hostname, port);

    /* Send request */
    if (write(sockfd, request, strlen(request)) < 0) {
        printf("Error sending request\n");
        return 1;
    }

    /* Receive and print response */
    ssize_t len = 0;
    while ((len = read(sockfd, response, MAX_RESPONSE_SIZE)) > 0) {
        printf("%.*s", (int) len, response);
        memset(response, 0, MAX_RESPONSE_SIZE);
    }
    if (len < 0) {
        printf("Error receiving response\n");
        return 1;
    }

    /* Close socket */
    close(sockfd);
    return 0;
}