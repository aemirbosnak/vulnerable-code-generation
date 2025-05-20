//FormAI DATASET v1.0 Category: Firewall ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string.h>

#define ALLOW 1
#define BLOCK 0

// Helper function to print error messages
void error(const char *msg) {
    perror(msg);
    exit(1);
}

// Helper function to check IP address validity
int is_valid_ip(char *ip_addr) {
    struct sockaddr_in sa;
    return inet_pton(AF_INET, ip_addr, &(sa.sin_addr)) != 0;
}

// Helper function to check port number validity
int is_valid_port(char *port_number) {
    int port = atoi(port_number);
    return port >= 1 && port <= 65535;
}

// Main function
int main(int argc, char *argv[]) {
    // Check the number of arguments
    if (argc != 4) {
        printf("Usage: %s [allow/block] [IP address] [port number]\n", argv[0]);
        exit(1);
    }

    // Parse arguments
    int action = strcmp(argv[1], "allow") == 0 ? ALLOW : BLOCK;
    char *ip_addr = argv[2];
    char *port_number = argv[3];

    // Check IP address and port number validity
    if (!is_valid_ip(ip_addr)) {
        printf("Invalid IP address\n");
        exit(1);
    }
    if (!is_valid_port(port_number)) {
        printf("Invalid port number\n");
        exit(1);
    }

    // Create a socket for IPv4 TCP connection
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    // Set up the server address
    struct sockaddr_in serv_addr;
    memset((char *) &serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(ip_addr);
    serv_addr.sin_port = htons(atoi(port_number));

    // Connect to the server address
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        if (action == ALLOW) {
            error("ERROR connecting");
        } else {
            printf("Blocked connection to %s:%s\n", ip_addr, port_number);
            close(sockfd);
            exit(1);
        }
    } else {
        if (action == ALLOW) {
            printf("Allowed connection to %s:%s\n", ip_addr, port_number);
        } else {
            printf("Blocked connection to %s:%s\n", ip_addr, port_number);
            close(sockfd);
            exit(1);
        }
    }

    // Close the socket
    close(sockfd);
    return 0;
}