//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

// Recursive function to send data over a TCP socket
void send_data(int sockfd, char *data, int len) {
    if (len == 0) {
        return;
    } else {
        int nbytes = send(sockfd, data, len, 0);
        if (nbytes < 0) {
            perror("send");
            exit(1);
        } else if (nbytes < len) {
            send_data(sockfd, data + nbytes, len - nbytes);
        }
    }
}

// Recursive function to receive data over a TCP socket
void recv_data(int sockfd, char *data, int len) {
    if (len == 0) {
        return;
    } else {
        int nbytes = recv(sockfd, data, len, 0);
        if (nbytes < 0) {
            perror("recv");
            exit(1);
        } else if (nbytes < len) {
            recv_data(sockfd, data + nbytes, len - nbytes);
        }
    }
}

// Main function
int main(int argc, char *argv[]) {
    // Check arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <ip> <port>\n", argv[0]);
        return 1;
    }

    // Create socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return 1;
    }

    // Connect to server
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return 1;
    }
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        perror("connect");
        close(sockfd);
        return 1;
    }

    // Send data
    char *data = "Hello, world!\n";
    send_data(sockfd, data, strlen(data));

    // Receive data
    char buffer[1024];
    recv_data(sockfd, buffer, sizeof(buffer));

    // Print data
    printf("Received: %s", buffer);

    // Close socket
    close(sockfd);

    return 0;
}