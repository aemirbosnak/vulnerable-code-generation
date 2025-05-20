//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Deductive reasoning function for error handling
void deduce_error() {
    if (errno == EACCES) {
        printf("It appears that we do not have the required access permissions.\n");
    } else if (errno == EINTR) {
        printf("Our program was interrupted by a signal.\n");
    } else if (errno == EINVAL) {
        printf("It seems that our program was passed an invalid argument.\n");
    } else if (errno == ENOMEM) {
        printf("Our program ran out of memory.\n");
    } else {
        printf("An unknown error occurred.\n");
    }
}

int main(int argc, char *argv[]) {
    // Case Setup
    printf("Welcome, dear Watson. Today we will be writing a program to build an HTTP client.\n");
    printf("First, let's start with the basics.\n");

    // Check for sufficient arguments
    if (argc < 2) {
        printf("It seems we were not given enough inputs.\n");
        printf("Please provide a URL to parse.\n");
        exit(EXIT_FAILURE);
    }

    // Parse input URL
    printf("Parsing input URL...\n");

    char *url = argv[1];
    char *protocol, *host, *port, *path, *filename;

    if (strncmp(url, "http://", 7) == 0) {
        protocol = "http";
        url += 7;
    } else if (strncmp(url, "https://", 8) == 0) {
        protocol = "https";
        url += 8;
    } else {
        printf("It seems that the input URL is invalid.\n");
        exit(EXIT_FAILURE);
    }

    // Parse host, port, and path
    char *temp = strtok(url, "/");
    host = temp;

    temp = strtok(NULL, "/");
    if (temp != NULL) {
        path = temp;
    } else {
        path = "/";
    }

    temp = strchr(host, ':');
    if (temp != NULL) {
        port = temp + 1;
        *temp = '\0';
    } else {
        port = "80";
    }

    // Output parsed information
    printf("Input URL successfully parsed.\n");
    printf("Protocol: %s\n", protocol);
    printf("Host: %s\n", host);
    printf("Port: %s\n", port);
    printf("Path: %s\n", path);

    // Create socket
    printf("Creating socket...\n");

    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd == -1) {
        printf("An error occurred while creating the socket.\n");
        deduce_error();
        exit(EXIT_FAILURE);
    }

    struct hostent *h = gethostbyname(host);
    if (h == NULL) {
        printf("An error occurred while getting host information.\n");
        deduce_error();
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    memcpy(&serv_addr.sin_addr.s_addr, h->h_addr, h->h_length);

    // Connect to server
    printf("Connecting to server...\n");

    if (connect(sock_fd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        printf("An error occurred while connecting to the server.\n");
        deduce_error();
        exit(EXIT_FAILURE);
    }

    // Send HTTP request
    printf("Sending HTTP GET request...\n");

    char *http_req = (char *)malloc(strlen(path) + 16);
    sprintf(http_req, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);

    if (send(sock_fd, http_req, strlen(http_req), 0) == -1) {
        printf("An error occurred while sending the HTTP request.\n");
        deduce_error();
        exit(EXIT_FAILURE);
    }

    free(http_req);

    // Receive HTTP response
    printf("Receiving HTTP response...\n");

    int bufsize = 1024;
    char *buffer = (char *)malloc(bufsize);

    if (buffer == NULL) {
        printf("An error occurred while allocating memory.\n");
        deduce_error();
        exit(EXIT_FAILURE);
    }

    memset(buffer, 0, bufsize);

    int bytes_received = recv(sock_fd, buffer, bufsize, 0);
    if (bytes_received == -1) {
        printf("An error occurred while receiving the HTTP response.\n");
        deduce_error();
        exit(EXIT_FAILURE);
    }

    // Output HTTP response
    printf("HTTP response received.\n\n");
    printf("%s\n", buffer);

    // Close socket
    printf("Closing socket...\n");

    if (close(sock_fd) == -1) {
        printf("An error occurred while closing the socket.\n");
        deduce_error();
        exit(EXIT_FAILURE);
    }

    free(buffer);

    // Case Cleanup
    printf("Our HTTP client program has successfully completed its task, Watson. Excellent work!\n");
    return 0;
}