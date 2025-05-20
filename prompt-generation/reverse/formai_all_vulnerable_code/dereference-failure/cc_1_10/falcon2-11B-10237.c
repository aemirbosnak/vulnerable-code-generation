//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Initialize variables
    int sockfd, bytes_read, bytes_written;
    char buffer[MAX_BUF_SIZE];
    struct sockaddr_in server_addr;
    char *server_ip = "127.0.0.1";
    int port = 8080;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Set up server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        exit(1);
    }

    // Read from server
    bytes_read = read(sockfd, buffer, MAX_BUF_SIZE);
    if (bytes_read < 0) {
        perror("Error reading from server");
        exit(1);
    }

    // Print received data
    printf("Received data from server: %s\n", buffer);

    // Write to server
    bytes_written = write(sockfd, buffer, strlen(buffer));
    if (bytes_written < 0) {
        perror("Error writing to server");
        exit(1);
    }

    // Close socket
    close(sockfd);

    return 0;
}