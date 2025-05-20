//FormAI DATASET v1.0 Category: Port Scanner ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_PORTS 65535

bool is_numeric(const char* str) {
    int i;
    for (i = 0; str[i] != '\0'; ++i) {
        if (!isdigit(str[i])) {
            return false;
        }
    }

    return true;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <target_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *target_ip = argv[1];

    struct sockaddr_in target_address;
    target_address.sin_addr.s_addr = inet_addr(target_ip);
    target_address.sin_family = AF_INET;

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation error: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    int i;
    for (i = 1; i < MAX_PORTS; ++i) {
        target_address.sin_port = htons(i);

        int conn_result = connect(sockfd,
                                  (struct sockaddr *)&target_address,
                                  sizeof(target_address));

        if (conn_result == 0) {
            printf("Port %i is open\n", i);
        }
    }

    close(sockfd);
    exit(EXIT_SUCCESS);
}