//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>

int main(int argc, char *argv[]) {
    // Initialize variables
    int sockfd;
    char *domain_name = argv[1];
    char *path = argv[2];
    struct hostent *ip_address;
    struct sockaddr_in server_address;
    char message[1024];
    char response[4096];
    int bytes_sent, bytes_received;

    // Set up socket connection
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Get IP address using domain name
    if ((ip_address = gethostbyname(domain_name)) == NULL) {
        perror("Error getting IP address");
        exit(1);
    }

    // Set up server address
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80);
    server_address.sin_addr = *((struct in_addr *)ip_address->h_addr);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Construct HTTP GET request
    snprintf(message, sizeof(message), "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, domain_name);

    // Send request to server
    if ((bytes_sent = send(sockfd, message, strlen(message), 0)) < 0) {
        perror("Error sending request");
        exit(1);
    }

    // Receive response from server
    if ((bytes_received = recv(sockfd, response, sizeof(response), 0)) < 0) {
        perror("Error receiving response");
        exit(1);
    }

    // Print response
    printf("%s", response);

    // Close socket connection
    close(sockfd);

    return 0;
}