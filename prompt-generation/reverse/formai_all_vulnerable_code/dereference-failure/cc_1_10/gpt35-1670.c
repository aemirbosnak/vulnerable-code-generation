//FormAI DATASET v1.0 Category: Port Scanner ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_PORTS 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        exit(0);
    }

    char *host = argv[1];
    struct hostent *host_info = gethostbyname(host);
    if (!host_info) {
        printf("Could not resolve host: %s\n", host);
        exit(1);
    }

    char *ip = inet_ntoa(*(struct in_addr *)host_info->h_addr_list[0]);
    printf("Scanning ports on %s...\n", ip);

    int sockfd, conn_result;
    struct sockaddr_in target_addr;
    int i = 1;
    int j;
    for (i; i <= MAX_PORTS; i++) {
        sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("Could not create socket for port %d\n", i);
            continue;
        }

        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_addr.s_addr = inet_addr(ip);
        target_addr.sin_port = htons(i);

        conn_result = connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr));
        if (conn_result == 0) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }

        close(sockfd);
    }

    printf("\nFinished scanning %d ports. Have a nice day!\n", MAX_PORTS);
    return 0;
}