//GEMINI-pro DATASET v1.0 Category: Networking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Error handling macro
#define CHECK(expr, msg) do { \
    if (!(expr)) { \
        perror(msg); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

int main(int argc, char *argv[]) {
    // Check for correct usage
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <ip address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Get the IP address and port from the command line
    char *ip_addr = argv[1];
    int port = atoi(argv[2]);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    CHECK(sockfd >= 0, "socket");

    // Set up the server address
    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    CHECK(inet_aton(ip_addr, &serv_addr.sin_addr) != 0, "inet_aton");

    // Connect to the server
    CHECK(connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) == 0, "connect");

    // Send a message to the server
    char *msg = "Hello, world!\n";
    CHECK(send(sockfd, msg, strlen(msg), 0) == strlen(msg), "send");

    // Receive a message from the server
    char buf[256];
    CHECK(recv(sockfd, buf, sizeof(buf), 0) > 0, "recv");

    // Print the message from the server
    printf("Received: %s\n", buf);

    // Close the socket
    CHECK(close(sockfd) == 0, "close");

    return EXIT_SUCCESS;
}