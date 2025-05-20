//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(argv[1]);
    if (host == NULL) {
        fprintf(stderr, "Unknown hostname: %s\n", argv[1]);
        exit(1);
    }

    // Set up the server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(argv[2]));
    serv_addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Print a welcome message
    printf("Connected to %s:%s\n", argv[1], argv[2]);

    // Create a buffer for receiving data
    char buf[1024];
    memset(buf, 0, sizeof(buf));

    // Receive the welcome message from the server
    int n = read(sockfd, buf, sizeof(buf));
    if (n == -1) {
        perror("read");
        exit(1);
    }

    // Print the welcome message
    printf("%s", buf);

    // Enter the FTP command loop
    while (1) {
        // Get the command from the user
        printf("> ");
        memset(buf, 0, sizeof(buf));
        fgets(buf, sizeof(buf), stdin);

        // Send the command to the server
        n = write(sockfd, buf, strlen(buf));
        if (n == -1) {
            perror("write");
            exit(1);
        }

        // Receive the response from the server
        memset(buf, 0, sizeof(buf));
        n = read(sockfd, buf, sizeof(buf));
        if (n == -1) {
            perror("read");
            exit(1);
        }

        // Print the response
        printf("%s", buf);

        // Check if the user wants to quit
        if (strcmp(buf, "QUIT\r\n") == 0) {
            break;
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}