//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

#define BUF_SIZE 1024

// Function to print error message and exit program
void error(char *msg) {
    perror(msg);
    exit(1);
}

// Function to send ICMP echo request and receive response
int ping(char *hostname, int timeout) {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        error("socket");
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(0);
    if (inet_pton(AF_INET, hostname, &addr.sin_addr) <= 0) {
        error("inet_pton");
    }

    char buf[BUF_SIZE];
    memset(buf, 0, BUF_SIZE);
    sendto(sock, "ABCDEFGHIJKLMNOPQRSTUVWXYZ", 26, 0, (struct sockaddr *)&addr, sizeof(addr));

    struct timeval tv;
    tv.tv_sec = timeout;
    tv.tv_usec = 0;
    setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (char *)&tv, sizeof(tv));

    int bytes_received = recv(sock, buf, BUF_SIZE, 0);
    if (bytes_received <= 0) {
        error("recv");
    }

    if (buf[0]!= 'A' || buf[1]!= 'B' || buf[2]!= 'C' || buf[3]!= 'D' || buf[4]!= 'E' || buf[5]!= 'F') {
        return 0;
    }

    return 1;
}

// Function to resolve hostname to IP address
int resolve_hostname(char *hostname, struct in_addr *ip) {
    struct hostent *he = gethostbyname(hostname);
    if (he == NULL) {
        error("gethostbyname");
    }

    memcpy(ip, he->h_addr, he->h_length);
    return 0;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s hostname timeout\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    int timeout = atoi(argv[2]);

    struct in_addr ip;
    if (resolve_hostname(hostname, &ip)!= 0) {
        exit(1);
    }

    if (ping(inet_ntoa(ip), timeout) == 1) {
        printf("Host is reachable\n");
    } else {
        printf("Host is not reachable\n");
    }

    return 0;
}