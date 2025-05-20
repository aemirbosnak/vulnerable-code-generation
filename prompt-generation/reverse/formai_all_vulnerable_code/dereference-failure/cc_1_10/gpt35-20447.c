//FormAI DATASET v1.0 Category: Port Scanner ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define TIMEOUT 3

void scan(char *host, int port)
{
    int sockfd, result;
    struct sockaddr_in addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sockfd < 0) {
        perror("socket() error");
        return;
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &timeout, sizeof(timeout));

    // Setup socket address
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(host);

    // Connect to target
    result = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (result == 0) {
        printf("[+] Port %d is open on %s\n", port, host);
    } else {
        printf("[-] Port %d is closed on %s\n", port, host);
    }

    // Close socket
    close(sockfd);
}

int main(int argc, char** argv)
{
    int start_port = 1;
    int end_port = 65535;
    char* host;

    // Check command line arguments
    if (argc < 2) {
        printf("USAGE: %s <host> [start_port] [end_port]\n", argv[0]);
        printf("Defaulting to scan all ports\n");
        return 1;
    } else {
        host = argv[1];
        if (argc >= 3) {
            start_port = atoi(argv[2]);
        }
        if (argc >= 4) {
            end_port = atoi(argv[3]);
        }
    }

    printf("[+] Scanning ports %d - %d on %s\n", start_port, end_port, host);

    for (int port = start_port; port <= end_port; port++) {
        scan(host, port);
    }

    printf("[+] Scan complete\n");

    return 0;
}