//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    // Parse the URL into host and path
    char* url = argv[1];
    char* host = NULL;
    char* path = NULL;
    char* http_version = "HTTP/1.1";
    int port = 80;

    if (strncmp(url, "http://", 7) == 0) {
        url += 7;
    }

    host = url;

    char* slash_ptr = strchr(url, '/');
    if (slash_ptr != NULL) {
        *slash_ptr = '\0';
        path = slash_ptr + 1;
    } else {
        path = "";
    }

    // Prepare the request message
    char request_message[MAX_BUFFER_SIZE];
    sprintf(request_message, "GET /%s %s\r\nHost: %s\r\nConnection: close\r\n\r\n", path, http_version, host);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        return 1;
    }

    // Resolve the host name
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        printf("Error resolving host name\n");
        return 1;
    }

    // Prepare the address structure
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to server\n");
        return 1;
    }

    // Send the request message
    if (send(sockfd, request_message, strlen(request_message), 0) < 0) {
        printf("Error sending request message\n");
        return 1;
    }

    // Receive and print the response message
    char response_message[MAX_BUFFER_SIZE];
    int total_bytes_received = 0;
    int num_bytes_received = 0;

    do {
        num_bytes_received = recv(sockfd, response_message + total_bytes_received, MAX_BUFFER_SIZE - total_bytes_received, 0);
        if (num_bytes_received < 0) {
            printf("Error receiving response message\n");
            return 1;
        }
        total_bytes_received += num_bytes_received;
    } while (num_bytes_received > 0);

    printf("%s", response_message);

    // Close the socket
    close(sockfd);

    return 0;
}