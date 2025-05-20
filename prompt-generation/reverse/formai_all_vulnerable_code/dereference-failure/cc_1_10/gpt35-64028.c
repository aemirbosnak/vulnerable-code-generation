//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: interoperable
// FTP client example program in an interoperable style

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
    // Check arguments
    if (argc < 3) {
        printf("Usage: %s [server ip] [server port]\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return EXIT_FAILURE;
    }

    // Configure server address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);
    server_addr.sin_port = htons(atoi(argv[2]));

    // Connect to server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return EXIT_FAILURE;
    }

    // Read initial message from server
    char buffer[BUFFER_SIZE];
    memset(buffer, 0, sizeof(buffer));
    if (read(sockfd, buffer, sizeof(buffer)) < 0) {
        perror("Error reading from server");
        return EXIT_FAILURE;
    }
    printf("%s", buffer);

    // Loop to process user commands
    while (1) {
        printf("ftp> ");
        scanf(" %[^\n]", buffer);
        strcat(buffer, "\r\n");  // Add newline characters
        if (write(sockfd, buffer, strlen(buffer)) < 0) {
            perror("Error writing to server");
            return EXIT_FAILURE;
        }

        // Check if command is to quit
        if (strcmp(buffer, "QUIT\r\n") == 0) {
            break;
        }

        // Read response from server
        memset(buffer, 0, sizeof(buffer));
        if (read(sockfd, buffer, sizeof(buffer)) < 0) {
            perror("Error reading from server");
            return EXIT_FAILURE;
        }
        printf("%s", buffer);
    }

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}