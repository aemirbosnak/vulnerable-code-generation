//Falcon2-11B DATASET v1.0 Category: Port Scanner ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <string.h>

#define MAX_PORT 65535

// Function to scan a single port and return 1 if it's open, 0 if it's closed
int scan_port(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;
    socklen_t addrlen = sizeof(serv_addr);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 0;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&serv_addr, addrlen) < 0) {
        close(sockfd);
        return 0;
    }

    close(sockfd);
    return 1;
}

// Function to scan a range of ports and print the results
void scan_range(int start, int end) {
    for (int i = start; i <= end; i++) {
        if (scan_port(i) == 1) {
            printf("Port %d is open\n", i);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        fprintf(stderr, "Usage: %s <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    int start_port = atoi(argv[1]);
    int end_port = atoi(argv[2]);

    if (start_port < 0 || start_port > MAX_PORT || end_port < 0 || end_port > MAX_PORT) {
        fprintf(stderr, "Invalid port range\n");
        exit(1);
    }

    scan_range(start_port, end_port);

    return 0;
}