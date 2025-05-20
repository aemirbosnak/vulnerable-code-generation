//Falcon2-11B DATASET v1.0 Category: Building a HTTP Client ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to send a GET request to the specified URL and print the response
void send_get_request(const char* url) {
    // Create a socket
    int sockfd;
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Create a struct for the server address
    struct sockaddr_in serv_addr;
    bzero((char *)&serv_addr, sizeof(serv_addr));

    // Set the address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80); // Default port for HTTP
    serv_addr.sin_addr.s_addr = inet_addr("www.example.com");

    // Connect to the server
    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("connection failed");
        exit(EXIT_FAILURE);
    }

    // Send the GET request
    char request[100];
    sprintf(request, "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n");
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("sending request failed");
        exit(EXIT_FAILURE);
    }

    // Receive the response
    char response[100];
    if (recv(sockfd, response, sizeof(response), 0) < 0) {
        perror("receiving response failed");
        exit(EXIT_FAILURE);
    }

    // Print the response
    printf("%s", response);

    // Close the socket
    close(sockfd);
}

int main(int argc, char** argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <URL>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Call the function to send the GET request
    send_get_request(argv[1]);

    return 0;
}