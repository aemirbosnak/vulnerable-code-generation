//MISTRAL-7B DATASET v1.0 Category: Port Scanner ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define BUF_SIZE 1024

void die(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if (argc != 3) {
        printf("Usage: %s <IP_ADDRESS> <PORT_RANGE_START>\n", argv[0]);
        return 1;
    }

    const char *ip = argv[1];
    int start_port = atoi(argv[2]);

    int sockfd, connfd;
    struct sockaddr_in serv_addr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
        die("socket");

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(0);

    if (inet_pton(AF_INET, ip, &serv_addr.sin_addr) <= 0)
        die("inet_pton");

    for (int port = start_port; port <= start_port + 255; port++) {
        serv_addr.sin_port = htons(port);

        if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
            continue;

        char buf[BUF_SIZE];
        write(sockfd, "Ken Thompson Port Scanner\n", 32);
        ssize_t n = read(sockfd, buf, BUF_SIZE);
        if (n > 0) {
            printf("[+] Open port %d on %s\n", port, ip);
            close(sockfd);
            exit(0);
        }

        close(sockfd);
    }

    printf("[*] Scan completed, no open ports found on %s:%d-%d\n", ip, start_port, start_port + 255);
    close(sockfd);
    return 0;
}