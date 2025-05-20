//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 4096

int main(int argc, char const *argv[]) {

    // Check if the arguments are valid
    if (argc != 3) {
        printf("Usage: %s <hostname> <portnumber>\n", argv[0]);
        return 1;
    }

    // Extract the hostname and port number
    char *hostname = (char*) argv[1];
    int portno = atoi(argv[2]);

    // Get the host information
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: cannot resolve hostname %s\n", hostname);
        return 1;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        printf("Error: can't open socket\n");
        return 1;
    }

    // Set up the address
    struct sockaddr_in server;
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(inet_ntoa(*(struct in_addr*) host->h_addr_list[0]));
    server.sin_port = htons(portno);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*) &server, sizeof(server)) < 0) {
        printf("Error: can't connect to server\n");
        return 1;
    }

    // Send an HTTP GET request
    char request[BUFFER_SIZE];
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);
    int request_len = strlen(request);
    if (send(sockfd, request, request_len, 0) != request_len) {
        printf("Error: can't send HTTP request\n");
        return 1;
    }

    // Receive the response
    char response[BUFFER_SIZE];
    int response_len = 0;
    int n = 0;
    do {
        n = recv(sockfd, response + response_len, BUFFER_SIZE - response_len, 0);
        if (n < 0) {
            printf("Error: can't receive HTTP response\n");
            return 1;
        }
        response_len += n;
    } while (n > 0 && response_len < BUFFER_SIZE);

    // Print the response to the console
    fwrite(response, 1, response_len, stdout);

    // Close the socket
    if (close(sockfd) < 0) {
        printf("Error: can't close socket\n");
        return 1;
    }

    return 0;
}