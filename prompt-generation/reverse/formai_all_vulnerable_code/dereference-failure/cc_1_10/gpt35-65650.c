//FormAI DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <signal.h>

void handle_sigint(int sig) {
    printf("\nExiting...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    signal(SIGINT, handle_sigint);
  
    if (argc < 3) {
        printf("Usage: %s <IP address> <start port> <end port>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);
    int port;

    struct sockaddr_in target;
    socklen_t target_len = sizeof(target);
    memset(&target, 0, target_len);
    target.sin_family = AF_INET;
    if (inet_pton(AF_INET, ip, &target.sin_addr) != 1) {
        printf("Invalid IP address\n");
        return 1;
    }

    for (port = start_port; port <= end_port; port++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("socket");
            return 1;
        }
        target.sin_port = htons(port);
        if (connect(sock, (struct sockaddr *)&target, target_len) == 0) {
            printf("Port %d is open\n", port);
        }
        close(sock);
    }
  
    printf("Scan complete\n");
    return 0;
}