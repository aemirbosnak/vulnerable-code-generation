//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: detailed
#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <target_host>\n", argv[0]);
        return 1;
    }

    int sockfd, port;
    struct sockaddr_in server_addr;
    char buffer[256];

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket");
        return 1;
    }

    // Set up the server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[1]));
    server_addr.sin_addr.s_addr = inet_addr(argv[1]);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        return 1;
    }

    // Send a message to the server
    if (send(sockfd, "Hello, world!", strlen("Hello, world!"), 0) < 0) {
        perror("send");
        return 1;
    }

    // Receive the server's response
    if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
        perror("recv");
        return 1;
    }

    // Print the server's response
    printf("Server response: %s\n", buffer);

    // Close the socket
    close(sockfd);

    return 0;
}