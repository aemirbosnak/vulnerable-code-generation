//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: active
#include <arpa/inet.h>
#include <errno.h>
#include <netdb.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

// Error handling macro
#define CHECK_ERR(err, msg) do { if (err == -1) { perror(msg); exit(EXIT_FAILURE); } } while (0)

int main(int argc, char **argv)
{
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    CHECK_ERR(sockfd, "socket");

    // Resolve the hostname
    struct hostent *hostent = gethostbyname(argv[1]);
    CHECK_ERR(hostent, "gethostbyname");

    // Set up the server address
    struct sockaddr_in server_addr = {
        .sin_family = AF_INET,
        .sin_port = htons(atoi(argv[2])),
        .sin_addr = { .s_addr = *(uint32_t *)hostent->h_addr },
    };

    // Connect to the server
    CHECK_ERR(connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)), "connect");

    // Send data to the server
    char *data = "Hello, world!";
    CHECK_ERR(send(sockfd, data, strlen(data), 0), "send");

    // Receive data from the server
    char buffer[1024];
    CHECK_ERR(recv(sockfd, buffer, sizeof(buffer), 0), "recv");

    // Print the data received from the server
    printf("Received from server: %s\n", buffer);

    // Close the socket
    CHECK_ERR(close(sockfd), "close");

    return EXIT_SUCCESS;
}