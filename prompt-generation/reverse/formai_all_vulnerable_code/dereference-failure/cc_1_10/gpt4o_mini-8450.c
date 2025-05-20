//GPT-4o-mini DATASET v1.0 Category: Building a HTTP Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 4096

void die(const char *message) {
    perror(message);
    exit(1);
}

void http_get(const char *host, const char *path) {
    int sock;
    struct sockaddr_in server_addr;
    struct hostent *host_info;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        die("Socket creation failed");
    }

    // Retrieve host information
    if ((host_info = gethostbyname(host)) == NULL) {
        die("Host not found");
    }
    
    // Prepare server address structure
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr.s_addr, host_info->h_addr, host_info->h_length);

    // Connect to the server
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        die("Connection failed");
    }

    // Construct the GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\n"
                                       "Host: %s\r\n"
                                       "Connection: close\r\n\r\n", path, host);

    // Send the request to the server
    if (send(sock, request, strlen(request), 0) < 0) {
        die("Send failed");
    }

    // Receive the server's response
    char response[BUFFER_SIZE];
    while (1) {
        int received = recv(sock, response, sizeof(response) - 1, 0);
        if (received < 0) {
            die("Receive failed");
        } else if (received == 0) {
            break; // Socket closed
        }

        // Null-terminate the response
        response[received] = '\0';
        printf("%s", response);
    }

    // Close the socket and free resources
    close(sock);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <path>\n", argv[0]);
        return 1;
    }

    const char *host = argv[1];
    const char *path = argv[2];

    // In this digital age, the pursuit of knowledge is boundless.
    // With a mere whisper, a soul can traverse wires and waves to 
    // attain information hidden in the vast ether of the Internet.
    // So let us embark on a journey!
    printf("Initiating request to %s%s...\n", host, path);
    http_get(host, path);
    printf("\nOperation completed. Knowledge acquired.\n");

    return 0;
}