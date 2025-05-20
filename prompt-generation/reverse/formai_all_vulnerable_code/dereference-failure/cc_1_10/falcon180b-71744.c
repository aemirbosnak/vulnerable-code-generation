//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define MAX_DATA_LEN 1024

/* Function to print error message and exit program */
void error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

/* Function to send ICMP echo request and receive response */
int ping(const char *host, int timeout) {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        error("socket");
    }

    struct sockaddr_in dest;
    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_addr.s_addr = inet_addr(host);

    char data[MAX_DATA_LEN];
    memset(data, 0, sizeof(data));
    strcpy(data, "PING");

    struct timeval tv;
    tv.tv_sec = timeout;
    tv.tv_usec = 0;

    int ret = setsockopt(sock, IPPROTO_IP, IP_TTL, &timeout, sizeof(timeout));
    if (ret == -1) {
        error("setsockopt");
    }

    ret = sendto(sock, data, strlen(data), 0, (struct sockaddr *)&dest, sizeof(dest));
    if (ret == -1) {
        error("sendto");
    }

    ret = recvfrom(sock, data, sizeof(data), 0, NULL, NULL);
    if (ret == -1) {
        error("recvfrom");
    }

    close(sock);

    if (strncmp(data, "PING", strlen("PING")) == 0) {
        return 0;
    } else {
        return 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s host timeout\n", argv[0]);
        return 1;
    }

    char host[MAX_HOST_LEN];
    strncpy(host, argv[1], MAX_HOST_LEN - 1);

    int timeout = atoi(argv[2]);

    int result = ping(host, timeout);

    if (result == 0) {
        printf("Host is alive.\n");
    } else {
        printf("Host is not alive.\n");
    }

    return 0;
}