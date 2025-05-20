//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    // First, we need to parse the input arguments to get the host and the port number
    if (argc != 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }
    char *host = argv[1];
    int port = atoi(argv[2]);

    // Next, we need to create a socket for the client
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    // Then, we need to resolve the host address
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        printf("Error resolving host: %s\n", strerror(errno));
        return 1;
    }

    // Next, we need to prepare the address struct for connecting to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server_addr.sin_zero), '\0', 8);

    // Now, we can connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        printf("Error connecting to server: %s\n", strerror(errno));
        return 1;
    }

    // Now, we can send an HTTP GET request to the server
    char *request = "GET / HTTP/1.0\r\n\r\n";
    int bytes_sent = send(sockfd, request, strlen(request), 0);
    if (bytes_sent == -1) {
        printf("Error sending request: %s\n", strerror(errno));
        return 1;
    }

    // Next, we need to receive the response from the server
    char buffer[MAX_BUFFER_SIZE];
    memset(buffer, 0, MAX_BUFFER_SIZE);
    bool headers_done = false;
    while (!headers_done) {
        int bytes_received = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if (bytes_received == -1) {
            printf("Error receiving response: %s\n", strerror(errno));
            return 1;
        }
        printf("%s", buffer);
        char *end_of_headers = strstr(buffer, "\r\n\r\n");
        if (end_of_headers != NULL) {
            headers_done = true;
            int body_size = bytes_received - (end_of_headers - buffer) - 4;
            if (body_size > 0) {
                printf("%.*s", body_size, end_of_headers + 4);
            }
        }
        memset(buffer, 0, MAX_BUFFER_SIZE);
    }

    // Finally, we can close the socket and exit
    close(sockfd);
    return 0;
}