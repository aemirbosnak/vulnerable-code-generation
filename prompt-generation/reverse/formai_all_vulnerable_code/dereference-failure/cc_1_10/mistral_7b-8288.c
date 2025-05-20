//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define TIMEOUT 500

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int send_packet(int sockfd, const char *ip, int port) {
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, ip, &server_addr.sin_addr);
    server_addr.sin_port = htons(port);

    int len = sendto(sockfd, "PING\r\n", 5, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (len < 0) {
        return -1;
    }

    struct timeval tv;
    tv.tv_sec = 0;
    tv.tv_usec = TIMEOUT;

    fd_set master_fds, read_fds;
    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &master_fds);

    int result = select(sockfd + 1, &read_fds, NULL, NULL, &tv);

    if (result > 0 && FD_ISSET(sockfd, &read_fds)) {
        int recv_len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
        if (recv_len > 0) {
            if (strstr(buffer, "PONG") != NULL) {
                printf("Reply received from %s:%d\n", ip, port);
                return 1;
            }
        }
    }

    return 0;
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s IP PORT\n", argv[0]);
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        die("socket");
    }

    int test_result = send_packet(sockfd, argv[1], atoi(argv[2]));

    close(sockfd);

    if (test_result == 1) {
        printf("Thank you, %s:%s, for responding!\n", argv[1], argv[2]);
    } else {
        printf("Sorry, %s:%s, we couldn't reach you. Please check your network connection.\n", argv[1], argv[2]);
    }

    return 0;
}