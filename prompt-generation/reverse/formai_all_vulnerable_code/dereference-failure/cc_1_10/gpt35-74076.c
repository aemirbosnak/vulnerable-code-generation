//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

int send_request(char *host, char *path, char *port) {
    // Step 1: Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return -1;
    }
    
    // Step 2: Get the IP address for the given host
    struct hostent *server = gethostbyname(host);
    if (server == NULL) {
        fprintf(stderr, "Error: no such host\n");
        return -1;
    }

    // Step 3: Create a socket address structure for the server
    struct sockaddr_in server_addr;
    bzero((char *) &server_addr, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    bcopy((char *)server->h_addr, (char *)&server_addr.sin_addr.s_addr, server->h_length);
    server_addr.sin_port = htons(atoi(port));

    // Step 4: Connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection error");
        return -1;
    }

    // Step 5: Generate the request message
    char request[1024];
    sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nUser-Agent: HTTPClient/1.0\r\n\r\n", path, host);

    // Step 6: Send the request message to the server
    int n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("Error sending request");
        return -1;
    }

    // Step 7: Receive the response from the server
    char response[4096];
    bzero(response, 4096);
    while ((n = read(sockfd, response, 4095)) > 0) {
        printf("%s", response);
        bzero(response, 4096);
    }
    if (n < 0) {
        perror("Error receiving response");
        return -1;
    }

    // Step 8: Close the socket
    close(sockfd);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Error: usage ./httpclient <host> <path> <port>\n");
        exit(1);
    }
    char *host = argv[1];
    char *path = argv[2];
    char *port = argv[3];
    send_request(host, path, port);
    return 0;
}