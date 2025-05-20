//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

/* Function to print usage of the program */
void print_usage() {
    printf("Usage:./program <IP Address> <Port Range>\n");
    exit(1);
}

/* Function to check if the given IP address is valid or not */
int is_valid_ip(char* ip) {
    struct sockaddr_in sa;
    int ret;

    ret = inet_pton(AF_INET, ip, &(sa.sin_addr));

    if (ret == 0) {
        return 0;
    } else {
        return 1;
    }
}

/* Function to scan ports in the given range */
void scan_ports(char* ip, int start_port, int end_port) {
    int sock;
    struct sockaddr_in server;
    int port;

    sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = inet_addr(ip);

    for (port = start_port; port <= end_port; port++) {
        server.sin_port = htons(port);

        if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", port);
        } else {
            printf("Port %d is closed\n", port);
        }
    }

    close(sock);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        print_usage();
    }

    char* ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (!is_valid_ip(ip)) {
        printf("Invalid IP address\n");
        exit(1);
    }

    printf("Scanning ports from %d to %d on %s...\n", start_port, end_port, ip);
    scan_ports(ip, start_port, end_port);

    return 0;
}