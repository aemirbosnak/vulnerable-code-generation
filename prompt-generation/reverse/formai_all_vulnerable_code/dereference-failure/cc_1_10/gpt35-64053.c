//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: Alan Touring
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[])
{
    int sockfd, portno;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // Check if the correct number of arguments are provided
    if (argc < 3) {
        fprintf(stderr,"Usage: %s <ip_address> <port_number>\n", argv[0]);
        return 1;
    }

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Could not create socket\n");
        return 1;
    }

    // Set up server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    portno = atoi(argv[2]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("Error: Invalid IP address provided\n");
        return 1;
    }

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
        perror("Error: Could not connect to server\n");
        return 1;
    }

    // Send request to server
    strcpy(buffer, "GET file.txt\n");
    if (send(sockfd, buffer, strlen(buffer), 0) < 0) {
        perror("Error: Could not send request to server\n");
        return 1;
    }

    // Receive response from server
    memset(buffer, 0, BUFFER_SIZE);
    if (recv(sockfd, buffer, BUFFER_SIZE, 0) < 0) {
        perror("Error: Could not receive response from server\n");
        return 1;
    }

    // Print response
    printf("%s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}