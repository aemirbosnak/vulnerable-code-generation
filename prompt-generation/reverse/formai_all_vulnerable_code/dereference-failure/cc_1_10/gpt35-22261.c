//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Claude Shannon
/* C Wireless Network Scanner */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define MAX_ATTEMPTS 5
#define MAX_PORTS 100
#define BUFFER_SIZE 256

/* Function to scan a given IP address for open ports */
void scan_ip(char *ip_addr) {
    int sock, n, m, attempts = 0;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE];

    /* Create socket */
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(1);
    }

    /* Fill server address structure */
    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip_addr);

    /* Scan open ports */
    for (int i = 1; i <= MAX_PORTS; i++) {
        server.sin_port = htons(i);
        attempts = 0;
        while (attempts < MAX_ATTEMPTS) {
            /* Attempt to connect to port */
            if ((n = connect(sock, (struct sockaddr *)&server, sizeof(server))) < 0) {
                if (errno == ECONNREFUSED) {
                    /* Port is closed */
                    break;
                }
            } else {
                /* Port is open */
                printf("%s:%d is open\n", ip_addr, i);
                break;
            }
            attempts++;
        }

        /* Display progress */
        if (i % 10 == 0) {
            printf("Scanning %s: %d/%d\n", ip_addr, i, MAX_PORTS);
        }
    }

    /* Close socket */
    close(sock);
}

/* Main function */
int main(int argc, char *argv[]) {
    char ip_addr[BUFFER_SIZE];

    /* Display usage if not enough arguments */
    if (argc < 2) {
        printf("Usage: %s [IP address]\n", argv[0]);
        return 1;
    }

    /* Copy IP address */
    strncpy(ip_addr, argv[1], BUFFER_SIZE);

    /* Scan IP address for open ports */
    scan_ip(ip_addr);

    return 0;
}