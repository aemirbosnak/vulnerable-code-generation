//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Function to resolve a hostname to an IP address
char *resolve_hostname(char *hostname) {
    struct hostent *host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return NULL;
    }
    return inet_ntoa(*((struct in_addr *)host->h_addr_list[0]));
}

// Function to send an HTTP request to a server
char *send_http_request(char *hostname, char *path) {
    // Resolve the hostname to an IP address
    char *ip_address = resolve_hostname(hostname);
    if (ip_address == NULL) {
        return NULL;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return NULL;
    }

    // Connect to the server
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr.s_addr = inet_addr(ip_address);
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return NULL;
    }

    // Send the HTTP request
    char request[1024];
    snprintf(request, sizeof(request), "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, hostname);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        close(sockfd);
        return NULL;
    }

    // Receive the HTTP response
    char response[4096];
    memset(response, 0, sizeof(response));
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("recv");
        close(sockfd);
        return NULL;
    }

    // Close the socket
    close(sockfd);

    // Return the HTTP response
    return strdup(response);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <path>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Send the HTTP request
    char *response = send_http_request(argv[1], argv[2]);
    if (response == NULL) {
        fprintf(stderr, "Error sending HTTP request\n");
        return EXIT_FAILURE;
    }

    // Print the HTTP response
    printf("%s", response);

    // Free the HTTP response
    free(response);

    return EXIT_SUCCESS;
}