//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: safe
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    struct hostent *host_info;
    char buffer[BUFFER_SIZE];
    int n;

    // Check if the user provided a hostname or IP address
    if (argc!= 3) {
        printf("Usage: %s <hostname/IP address> <port number>\n", argv[0]);
        return 1;
    }

    // Convert the hostname or IP address to a numerical IP address
    host_info = gethostbyname(argv[1]);
    if (host_info == NULL) {
        printf("Error: Host not found\n");
        return 1;
    }

    memcpy(&server_addr.sin_addr, host_info->h_addr, host_info->h_length);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Socket creation failed\n");
        return 1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error: Connection failed\n");
        return 1;
    }

    // Send a greeting to the server
    n = send(sockfd, "HELO client\r\n", 14, 0);
    if (n == -1) {
        printf("Error: Greeting send failed\n");
        return 1;
    }

    // Receive a response from the server
    n = recv(sockfd, buffer, BUFFER_SIZE, 0);
    if (n == -1) {
        printf("Error: Response receive failed\n");
        return 1;
    }

    // Print the response
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}