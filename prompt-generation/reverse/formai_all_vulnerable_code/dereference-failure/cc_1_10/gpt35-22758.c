//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define SERVER_IP "127.0.0.1"
#define TIMEOUT_SECS 5

int main() {
    int sockfd, n;
    float time_elapsed;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in serveraddr;
    struct timeval timeout;
    fd_set readfds;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Set server address
    bzero(&serveraddr, sizeof(serveraddr));
    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(PORT);
    if(inet_pton(AF_INET, SERVER_IP, &serveraddr.sin_addr) <= 0) {
        perror("ERROR invalid server address");
        exit(1);
    }

    // Connect to server
    if(connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr)) < 0) {
        perror("ERROR connecting to server");
        exit(1);
    }

    // Send message to server and measure time elapsed
    clock_t t;
    t = clock();
    n = write(sockfd, "hello", 5);
    if(n < 0) {
        perror("ERROR writing to socket");
        exit(1);
    }

    // Set timeout for receiving server response
    timeout.tv_sec = TIMEOUT_SECS;
    timeout.tv_usec = 0;
    FD_ZERO(&readfds);
    FD_SET(sockfd, &readfds);

    // Wait for server response or timeout
    select(sockfd+1, &readfds, NULL, NULL, &timeout);
    if(FD_ISSET(sockfd, &readfds)) {
        // Receive response from server and measure time elapsed
        bzero(buffer, BUFFER_SIZE);
        n = read(sockfd, buffer, BUFFER_SIZE-1);
        if(n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        t = clock() - t;
        time_elapsed = ((float)t)/CLOCKS_PER_SEC;

        // Print result
        printf("Server response: %s\n", buffer);
        printf("Time elapsed: %.4f seconds\n", time_elapsed);
    } else {
        printf("Timeout. No response received from server\n");
    }

    // Close socket
    close(sockfd);

    return 0;
}