//FormAI DATASET v1.0 Category: Port Scanner ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: %s <target-ip> <start-port> <end-port>\n", argv[0]);
        return 1;
    }

    char *target_ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port <= 0 || start_port > 65535 || end_port <= 0 || end_port > 65535) {
        printf("Invalid port range. Valid range is 1 to 65535.\n");
        return 1;
    }

    printf("Starting port scan on %s from port %d to %d\n", target_ip, start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        // create socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (sockfd < 0) {
            perror("socket() failed");
            return 1;
        }

        // set socket non-blocking
        int flags = fcntl(sockfd, F_GETFL, 0);
        fcntl(sockfd, F_SETFL, flags | O_NONBLOCK);

        // set socket timeout
        struct timeval timeout;
        timeout.tv_sec = 1;
        timeout.tv_usec = 0;

        setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

        // prepare target address
        struct sockaddr_in target_addr;
        target_addr.sin_family = AF_INET;
        target_addr.sin_port = htons(port);
        target_addr.sin_addr.s_addr = inet_addr(target_ip);

        // connect to target
        int ret = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));

        if (ret == 0) {
            printf("[+] Port %d is open\n", port);
        } else {
            close(sockfd);
        }
    }

    printf("Scan finished\n");

    return 0;
}