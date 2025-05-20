//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define MAX_HOSTS 10

int main(int argc, char *argv[]) {
    int i, j, num_hosts, result;
    char *host_list[MAX_HOSTS];
    struct hostent *host;
    struct sockaddr_in addr;

    if (argc < 2) {
        printf("Usage: %s host1 [host2...]\n", argv[0]);
        return 1;
    }

    num_hosts = 1;
    for (i = 1; i < argc; i++) {
        if (num_hosts >= MAX_HOSTS) {
            printf("Too many hosts specified.\n");
            return 1;
        }
        host_list[num_hosts] = argv[i];
        num_hosts++;
    }

    for (i = 0; i < num_hosts; i++) {
        host = gethostbyname(host_list[i]);
        if (host == NULL) {
            printf("Host not found: %s\n", host_list[i]);
            continue;
        }

        for (j = 0; j < host->h_addrtype; j++) {
            memcpy(&addr.sin_addr, host->h_addr_list[j], host->h_length);
            addr.sin_family = AF_INET;
            addr.sin_port = htons(7);

            result = inet_pton(AF_INET, inet_ntoa(*(struct in_addr *)host->h_addr_list[j]), &addr.sin_addr);
            if (result <= 0) {
                printf("Invalid IP address: %s\n", host_list[i]);
                continue;
            }

            result = ping(host_list[i], addr);
            if (result == 0) {
                printf("%s is alive.\n", host_list[i]);
            } else if (result == 1) {
                printf("%s is not reachable.\n", host_list[i]);
            } else {
                printf("Error pinging %s: %s\n", host_list[i], strerror(errno));
            }
        }
    }

    return 0;
}

int ping(char *host, struct sockaddr_in addr) {
    int sock, result;
    char buf[BUF_SIZE];

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        return 1;
    }

    memset(buf, 0, BUF_SIZE);
    strcpy(buf, "PING ");
    strcat(buf, host);
    strcat(buf, "\r\n");

    result = sendto(sock, buf, strlen(buf), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (result == -1) {
        close(sock);
        return 1;
    }

    result = recvfrom(sock, buf, BUF_SIZE, 0, NULL, NULL);
    if (result == -1) {
        close(sock);
        return 1;
    }

    close(sock);

    if (result < 8 || strcmp(buf, "PING ")!= 0) {
        return 1;
    }

    return 0;
}