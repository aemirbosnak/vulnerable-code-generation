//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <time.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024
#define TIMEOUT 1000 // in milliseconds

struct sockaddr_in target;
int sock;

void print_usage(char *prog_name) {
    printf("Usage: %s <IP Address> <Start Port> <End Port>\n", prog_name);
    exit(1);
}

int is_port_open(int port) {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) == 0) {
        close(sock);
        return 1;
    } else {
        close(sock);
        return 0;
    }
}

void scan_ports(char *ip, int start_port, int end_port) {
    int i;
    for (i = start_port; i <= end_port; i++) {
        if (is_port_open(i)) {
            printf("Port %d is open\n", i);
        } else {
            printf("Port %d is closed\n", i);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 4) {
        print_usage(argv[0]);
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port > end_port) {
        printf("Invalid port range\n");
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    target.sin_family = AF_INET;
    target.sin_port = htons(start_port);
    inet_pton(AF_INET, ip, &target.sin_addr);

    scan_ports(ip, start_port, end_port);

    close(sock);
    return 0;
}