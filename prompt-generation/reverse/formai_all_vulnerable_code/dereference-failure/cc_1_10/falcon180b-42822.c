//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>

#define MAX_PINGS 10
#define PING_INTERVAL 1
#define PING_TIMEOUT 2

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <number of pings>\n", argv[0]);
        return 1;
    }

    char *ip_address = argv[1];
    int num_pings = atoi(argv[2]);

    if (num_pings > MAX_PINGS) {
        printf("Maximum number of pings is %d\n", MAX_PINGS);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        printf("Error creating socket: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(ip_address);

    int opt = 1;
    setsockopt(sock, IPPROTO_IP, IP_HDRINCL, &opt, sizeof(opt));

    for (int i = 0; i < num_pings; i++) {
        sendto(sock, "PING", strlen("PING"), 0, (struct sockaddr *)&addr, sizeof(addr));
        struct timeval timeout;
        timeout.tv_sec = PING_TIMEOUT;
        timeout.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

        char buffer[1024];
        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);

        if (bytes_received <= 0) {
            printf("Ping %d failed\n", i + 1);
        } else {
            buffer[bytes_received] = '\0';
            printf("Ping %d: %s\n", i + 1, buffer);
        }

        usleep(PING_INTERVAL * 1000000);
    }

    close(sock);
    return 0;
}