//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define DEFAULT_PORT 80
#define MAX_HOSTNAME_LENGTH 255
#define MAX_RESPONSE_LENGTH 1024

// Function to resolve a hostname to an IP address
struct hostent *resolve_hostname(char *hostname) {
    struct hostent *host;

    // Get the host entry for the hostname
    host = gethostbyname(hostname);
    if (host == NULL) {
        perror("gethostbyname");
        return NULL;
    }

    // Return the host entry
    return host;
}

// Function to create a socket and connect to a host
int create_socket_and_connect(struct hostent *host, int port) {
    int sockfd;
    struct sockaddr_in server_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Set the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *(struct in_addr *) host->h_addr;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Return the socket file descriptor
    return sockfd;
}

// Function to send a request to a host
int send_request(int sockfd, char *hostname) {
    char request[MAX_HOSTNAME_LENGTH + 16];

    // Create the request
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", hostname);

    // Send the request
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        return -1;
    }

    // Return 0 on success
    return 0;
}

// Function to receive a response from a host
int receive_response(int sockfd) {
    char response[MAX_RESPONSE_LENGTH];
    int bytes_received;

    // Receive the response
    bytes_received = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
    if (bytes_received < 0) {
        perror("recv");
        return -1;
    }

    // Return 0 on success
    return 0;
}

// Function to check the status of a website
int check_website_status(char *hostname, int port) {
    struct hostent *host;
    int sockfd;

    // Resolve the hostname
    host = resolve_hostname(hostname);
    if (host == NULL) {
        return -1;
    }

    // Create a socket and connect to the host
    sockfd = create_socket_and_connect(host, port);
    if (sockfd < 0) {
        return -1;
    }

    // Send a request to the host
    if (send_request(sockfd, hostname) < 0) {
        close(sockfd);
        return -1;
    }

    // Receive a response from the host
    if (receive_response(sockfd) < 0) {
        close(sockfd);
        return -1;
    }

    // Close the socket
    close(sockfd);

    // Return 0 on success
    return 0;
}

// Main function
int main(int argc, char *argv[]) {
    char hostname[MAX_HOSTNAME_LENGTH];
    int port;

    // Get the hostname and port from the command line arguments
    if (argc < 2) {
        printf("Usage: %s <hostname> [<port>]\n", argv[0]);
        return 1;
    } else {
        strcpy(hostname, argv[1]);
    }
    if (argc > 2) {
        port = atoi(argv[2]);
    } else {
        port = DEFAULT_PORT;
    }

    // Check the status of the website
    if (check_website_status(hostname, port) == 0) {
        printf("Website %s is up.\n", hostname);
    } else {
        printf("Website %s is down.\n", hostname);
    }

    return 0;
}