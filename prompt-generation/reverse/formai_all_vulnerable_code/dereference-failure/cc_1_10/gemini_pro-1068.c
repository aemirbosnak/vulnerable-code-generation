//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_LEN 1024

struct sockaddr_in server_addr;
int sockfd;

void create_socket() {
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Couldn't create socket");
        exit(EXIT_FAILURE);
    }
}

void set_server_addr(char *address, char *port) {
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    if (inet_pton(AF_INET, address, &server_addr.sin_addr) <= 0) {
        perror("Couldn't convert IP address");
        exit(EXIT_FAILURE);
    }
}

void send_ping(char *message) {
    ssize_t sent = sendto(sockfd, message, strlen(message), 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (sent < 0) {
        perror("Couldn't send message");
        exit(EXIT_FAILURE);
    }
}

void receive_ping() {
    char buf[MAX_BUF_LEN];
    socklen_t addr_len = sizeof(server_addr);
    ssize_t recv_len = recvfrom(sockfd, buf, MAX_BUF_LEN, 0, (struct sockaddr *)&server_addr, &addr_len);
    if (recv_len < 0) {
        perror("Couldn't receive message");
        exit(EXIT_FAILURE);
    }
    buf[recv_len] = '\0';
    printf("Response from server: %s\n", buf);
}

void close_socket() {
    if (sockfd >= 0) {
        close(sockfd);
    }
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <address> <port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *address = argv[1];
    char *port = argv[2];

    create_socket();
    set_server_addr(address, port);
    send_ping("PING");
    receive_ping();
    close_socket();

    return EXIT_SUCCESS;
}