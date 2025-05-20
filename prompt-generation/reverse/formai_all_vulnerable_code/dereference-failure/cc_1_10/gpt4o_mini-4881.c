//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <errno.h>
#include <time.h>

#define TIMEOUT 1
#define TOTAL_PORTS 65535

void scan_port(const char *ip, int port);
void print_banner(const char *ip);
void delay(int seconds);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <ip-address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip = argv[1];
    print_banner(ip);

    for (int port = 1; port <= TOTAL_PORTS; port++) {
        scan_port(ip, port);
        delay(0); // You may adjust delay as needed for less/more output
    }

    return EXIT_SUCCESS;
}

void scan_port(const char *ip, int port) {
    int sockfd;
    struct sockaddr_in server_addr;
    socklen_t addr_len = sizeof(server_addr);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        return;
    }

    // Set timeout for connection
    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&tv, sizeof tv);

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    int connect_result = connect(sockfd, (struct sockaddr *)&server_addr, addr_len);

    if (connect_result >= 0) {
        printf("Port %d: OPEN\n", port);
    } else {
        if (errno == ECONNREFUSED) {
            printf("Port %d: CLOSED\n", port);
        }
        // Other errors can be ignored for this simple scanner
    }

    close(sockfd);
}

void print_banner(const char *ip) {
    printf("--------------------------------------------------\n");
    printf("        C Port Scanner - By Ada Lovelace Style     \n");
    printf("--------------------------------------------------\n");
    printf("Scanning the host: %s\n", ip);
    printf("This shall take a while...\n");
}

void delay(int seconds) {
    if (seconds > 0) {
        sleep(seconds);
    } 
}