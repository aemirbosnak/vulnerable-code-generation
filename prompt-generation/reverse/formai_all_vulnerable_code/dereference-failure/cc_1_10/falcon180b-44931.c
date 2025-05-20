//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_PORTS 65535
#define BUF_SIZE 1024

void scan_ports(int sock, int target_ip, int start_port, int end_port) {
    int sport, s;
    char buffer[BUF_SIZE];
    struct sockaddr_in server;

    for (sport = start_port; sport <= end_port; sport++) {
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(sport);
        inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)&target_ip), &server.sin_addr);

        s = socket(AF_INET, SOCK_STREAM, 0);
        if (s == -1) {
            printf("Error creating socket\n");
            exit(1);
        }

        if (connect(s, (struct sockaddr *)&server, sizeof(server)) == 0) {
            printf("Port %d is open\n", sport);
            close(s);
        } else if (errno == ECONNREFUSED) {
            printf("Port %d is closed\n", sport);
        } else {
            printf("Error connecting to port %d\n", sport);
        }
    }
}

int main(int argc, char *argv[]) {
    int sock, target_ip, start_port, end_port;
    char *ip_str;

    if (argc!= 5) {
        printf("Usage: %s <IP Address> <Start Port> <End Port>\n", argv[0]);
        exit(1);
    }

    ip_str = argv[1];
    target_ip = inet_addr(ip_str);
    start_port = atoi(argv[2]);
    end_port = atoi(argv[3]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    scan_ports(sock, target_ip, start_port, end_port);

    close(sock);
    return 0;
}