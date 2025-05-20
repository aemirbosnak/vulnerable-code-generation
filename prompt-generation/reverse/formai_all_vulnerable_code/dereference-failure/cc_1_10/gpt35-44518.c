//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    // Welcome message
    printf("Hello! Let's build a HTTP Client!\n");

    // Initialize variables
    int sockfd;
    char buffer[1024];
    struct sockaddr_in servaddr;

    // Check if hostname and port are provided as arguments
    if (argc < 3) {
        printf("Usage: %s <hostname> <port>", argv[0]);
        exit(1);
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    // Check if socket was created successfully
    if (sockfd == -1) {
        printf("Error: Failed to create socket");
        exit(1);
    }
    printf("Socket created successfully!\n");

    // Set the values of sockaddr_in
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(argv[1]);
    servaddr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) != 0) {
        printf("Error: Failed to connect to server");
        exit(1);
    }
    printf("Connected to server successfully!\n");

    // Send HTTP GET request
    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    write(sockfd, request, strlen(request));
    printf("HTTP GET request sent successfully!\n");

    // Receive HTTP response
    while(read(sockfd, buffer, sizeof(buffer)) != 0) {
        printf("%s", buffer);
        memset(buffer, 0, sizeof(buffer));
    }
    
    // Close socket
    close(sockfd);
    printf("Socket closed successfully!\n");

    // Goodbye message
    printf("Thanks for building a HTTP Client with me! Have a great day!\n");

    return 0;
}