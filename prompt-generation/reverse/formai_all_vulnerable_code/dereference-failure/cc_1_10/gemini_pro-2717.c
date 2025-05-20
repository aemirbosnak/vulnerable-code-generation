//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <unistd.h>

#define MAX_PORTS 65535
#define MAX_HOST_LEN 256
#define MAX_BANNER_LEN 1024

// Function to print usage information
void usage(char *program_name) {
    printf("Usage: %s <host> <port1> <port2>\n", program_name);
    printf("Example: %s example.com 80 443\n", program_name);
    exit(EXIT_FAILURE);
}

// Function to scan a single port on a host
int scan_port(char *host, int port) {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return -1;
    }

    // Set up the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(port);
    if (inet_pton(AF_INET, host, &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        close(sockfd);
        return -1;
    }

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) < 0) {
        close(sockfd);
        return -1;
    }

    // Send a simple request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive the server's response
    char response[MAX_BANNER_LEN];
    int n = recv(sockfd, response, MAX_BANNER_LEN, 0);
    if (n < 0) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Close the socket
    close(sockfd);

    // Print the server's response
    printf("Port %d: %s", port, response);

    return 0;
}

int main(int argc, char **argv) {
    if (argc < 4) {
        usage(argv[0]);
    }

    char *host = argv[1];
    int port1 = atoi(argv[2]);
    int port2 = atoi(argv[3]);

    if (port1 < 0 || port1 > MAX_PORTS || port2 < 0 || port2 > MAX_PORTS) {
        fprintf(stderr, "Invalid port range: %d-%d\n", port1, port2);
        exit(EXIT_FAILURE);
    }

    for (int port = port1; port <= port2; port++) {
        scan_port(host, port);
    }

    return 0;
}