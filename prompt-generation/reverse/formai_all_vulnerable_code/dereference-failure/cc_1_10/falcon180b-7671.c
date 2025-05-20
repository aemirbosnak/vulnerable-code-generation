//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <netdb.h>

#define MAX_HOST_NAME 256
#define MAX_PORT_NUM 65535
#define TRUE 1
#define FALSE 0

// Function to resolve hostname
void resolve_hostname(char *hostname, struct sockaddr_in *sin)
{
    struct hostent *host;
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Error: %s\n", strerror(errno));
        exit(1);
    }
    memcpy(&sin->sin_addr, host->h_addr, host->h_length);
}

// Function to scan ports
void scan_ports(char *hostname, int start_port, int end_port)
{
    int sock;
    struct sockaddr_in sin;
    sin.sin_family = AF_INET;
    sin.sin_port = htons(start_port);
    resolve_hostname(hostname, &sin);

    for (int i = start_port; i <= end_port; i++) {
        sin.sin_port = htons(i);
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock == -1) {
            printf("Error: %s\n", strerror(errno));
            exit(1);
        }
        if (connect(sock, (struct sockaddr *)&sin, sizeof(sin)) == 0) {
            printf("Port %d is open\n", i);
            close(sock);
        } else {
            printf("Port %d is closed\n", i);
            close(sock);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc!= 4) {
        printf("Usage: %s <hostname> <start_port> <end_port>\n", argv[0]);
        exit(1);
    }

    char *hostname = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    scan_ports(hostname, start_port, end_port);

    return 0;
}