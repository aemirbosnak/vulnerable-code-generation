//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>

// A function to send a GET request to a given URL and return the response
char *send_get_request(char *url)
{
    // Parse the URL to get the hostname and port
    char *hostname = strtok(url, ":");
    char *port = strtok(NULL, ":");

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Connect to the server
    struct sockaddr_in serv_addr;
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    serv_addr.sin_addr.s_addr = inet_addr(hostname);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        exit(1);
    }

    // Send the GET request
    char *request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char *request_buffer = malloc(strlen(request) + strlen(hostname) + 1);
    sprintf(request_buffer, request, hostname);
    if (send(sockfd, request_buffer, strlen(request_buffer), 0) < 0) {
        perror("send");
        exit(1);
    }
    free(request_buffer);

    // Receive the response
    char *response = malloc(1024);
    int n = recv(sockfd, response, 1024, 0);
    if (n < 0) {
        perror("recv");
        exit(1);
    }
    response[n] = '\0';

    // Close the socket
    close(sockfd);

    // Return the response
    return response;
}

int main()
{
    // Send a GET request to the server
    char *response = send_get_request("http://example.com:80");

    // Print the response
    printf("%s\n", response);

    // Free the response
    free(response);

    return 0;
}