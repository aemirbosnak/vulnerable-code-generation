//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: visionary
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h>
#include <sys/time.h>
#include <stdlib.h>

// Function prototypes
int connect_to_server(char* server_ip, int server_port);
void print_usage(char* program_name);
void print_error(char* message, int errno_value);

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        print_usage(argv[0]);
        return 1;
    }

    char* server_ip = argv[1];
    int server_port = atoi(argv[2]);

    int sockfd = connect_to_server(server_ip, server_port);
    if (sockfd < 0) {
        print_error("Failed to connect to server", errno);
        return 1;
    }

    char buffer[1024];
    int nread = read(sockfd, buffer, sizeof(buffer));
    if (nread < 0) {
        print_error("Failed to read from server", errno);
        return 1;
    }

    printf("Server response: %s\n", buffer);

    close(sockfd);
    return 0;
}

// Connect to the server
int connect_to_server(char* server_ip, int server_port) {
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        return -1;
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Failed to connect to server");
        return -1;
    }

    return sockfd;
}

// Print usage information
void print_usage(char* program_name) {
    printf("Usage: %s <server_ip> <server_port>\n", program_name);
    exit(1);
}

// Print error message
void print_error(char* message, int errno_value) {
    printf("%s: %s\n", message, strerror(errno_value));
    exit(1);
}