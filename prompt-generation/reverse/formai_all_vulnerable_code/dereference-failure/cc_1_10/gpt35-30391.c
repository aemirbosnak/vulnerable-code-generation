//FormAI DATASET v1.0 Category: Port Scanner ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

/* function prototypes */
int hostname_to_ip(char *hostname, char *ip_address);
void scan_port(char *ip_address, int port);

int main(int argc, char *argv[]) {
    int start_port, end_port;

    if (argc != 4) {
        fprintf(stderr, "Usage: %s <hostname or IP> <start port> <end port>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    char *hostname_or_ip = argv[1];
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    char ip_address[INET_ADDRSTRLEN];
    int res = hostname_to_ip(hostname_or_ip, ip_address);
    if (res == -1) {
        fprintf(stderr, "Error: hostname %s could not be resolved.\n", hostname_or_ip);
        exit(EXIT_FAILURE);
    }

    printf("Port scan starting on %s (%s) from port %d to port %d.\n", hostname_or_ip, ip_address, start_port, end_port);

    for (int port = start_port; port <= end_port; port++) {
        scan_port(ip_address, port);
    }

    return 0;
}

/* function to resolve hostname to IP address */
int hostname_to_ip(char *hostname, char *ip_address) {
    struct addrinfo hints, *res;
    struct in_addr addr;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int status = getaddrinfo(hostname, NULL, &hints, &res);

    if (status != 0) {
        return -1;
    }

    addr.s_addr = ((struct sockaddr_in *)(res->ai_addr))->sin_addr.s_addr;
    strncpy(ip_address, inet_ntoa(addr), INET_ADDRSTRLEN);

    freeaddrinfo(res);
    return 0;
}

/* function to scan a particular port on the IP address */
void scan_port(char *ip_address, int port) {
    struct sockaddr_in server_address;
    int sock = socket(AF_INET, SOCK_STREAM, 0);

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip_address);
    server_address.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        if (errno == ECONNREFUSED) {
            printf("Port %d is closed on %s.\n", port, ip_address);
        }
    } else {
        printf("Port %d is open on %s.\n", port, ip_address);
        close(sock);
    }
}