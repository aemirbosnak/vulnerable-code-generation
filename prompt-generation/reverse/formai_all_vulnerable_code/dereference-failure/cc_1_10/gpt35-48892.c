//FormAI DATASET v1.0 Category: Port Scanner ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MAXPORT 65535
#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, status;
    struct sockaddr_in target_addr;
    char target[16], port[MAXPORT];
    uint16_t start_port, end_port;
    fd_set scan_fdset;

    if (argc < 2) {
        printf("Usage: %s <target IP>\n", argv[0]);
        return 0;
    }

    strcpy(target, argv[1]);
    printf("Scanning ports on %s...\n", target);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 1;
    }

    target_addr.sin_family = AF_INET;
    target_addr.sin_port = 0; // Required by some implementations
    target_addr.sin_addr.s_addr = inet_addr(target);

    printf("Enter starting port: ");
    scanf("%hu", &start_port);
    printf("Enter ending port: ");
    scanf("%hu", &end_port);

    for (uint16_t i = start_port; i <= end_port; ++i) {
        target_addr.sin_port = htons(i);
        status = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));
        if (status == 0) {
            printf("[+] Port %hu is open.\n", i);
            close(sockfd);
            sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd < 0) {
                perror("Socket creation failed");
                return 1;
            }
        }
    }

    printf("Port scan complete.\n");

    return 0;
}