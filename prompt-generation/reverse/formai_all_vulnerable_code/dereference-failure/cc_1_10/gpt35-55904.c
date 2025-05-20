//FormAI DATASET v1.0 Category: Port Scanner ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {     
        printf("Usage: %s <ip_address> [start_port] [end_port]\n", argv[0]);
        exit(1);
    }

    char *ip_address = argv[1];     
    int start_port = argc > 2 ? atoi(argv[2]) : 1;     
    int end_port = argc > 3 ? atoi(argv[3]) : 65535;
    int timeout = 500; 

    printf("Scanning %s from port %d to port %d\n\n", ip_address, start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (sockfd == -1) {
            perror("socket() error");
            exit(1);
        }
        
        struct sockaddr_in target_addr;
        target_addr.sin_family = AF_INET;
        target_addr.sin_port = htons(port);
        target_addr.sin_addr.s_addr = inet_addr(ip_address);

        fd_set fds;
        FD_ZERO(&fds);
        FD_SET(sockfd, &fds);

        struct timeval tv;
        tv.tv_sec = 0;
        tv.tv_usec = timeout * 1000;

        if (connect(sockfd, (struct sockaddr *) &target_addr, sizeof(target_addr)) == -1) {
            close(sockfd);
        } else {
            printf("Port %d is open\n", port);
            close(sockfd);
        }
        
        select(sockfd + 1, NULL, &fds, NULL, &tv);
    }

    printf("\nScan completed!\n");
    return 0;
}