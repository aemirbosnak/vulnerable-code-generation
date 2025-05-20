//FormAI DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_MIN 1
#define PORT_MAX 65535

void scan_ip(char *address) {
    struct sockaddr_in target_addr;
    int sockfd, start_port, end_port;

    memset(&target_addr, 0, sizeof(target_addr)); //initialized to zero
    target_addr.sin_family = AF_INET;
    target_addr.sin_addr.s_addr = inet_addr(address);

    printf("\n[*] Starting Scan on Target IP: %s\n\n", address);

    printf("[*] Enter Starting Port Number: ");
    scanf("%d", &start_port);

    printf("[*] Enter Ending Port Number: ");
    scanf("%d", &end_port);

    for(int port = start_port; port <= end_port; port++) {
        if((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
            perror("socket() error");
            return;
        }

        target_addr.sin_port = htons(port);

        if(connect(sockfd, (struct sockaddr *) &target_addr, sizeof(target_addr)) == 0) {
            printf("[*] Port %d - Open\n", port);
        }
        else {
            printf("[*] Port %d - Closed\n", port);
        }

        close(sockfd);
    }
}

int main(int argc, char *argv[]) {
    char address[16];

    if(argc != 2) {
        printf("Usage: %s <IPv4 Address>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    strncpy(address, argv[1], 16);

    scan_ip(address);

    return 0;
}