//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int main(int argc, char *argv[]) {
    int sock;
    struct addrinfo *addrinfo;
    struct sockaddr_in *addr;
    char hostname[MAX_HOSTNAME];
    char data[MAX_DATA];
    int ret;

    if (argc!= 3) {
        printf("Usage: %s hostname data\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    strcpy(data, argv[2]);

    ret = getaddrinfo(hostname, NULL, NULL, &addrinfo);
    if (ret!= 0) {
        printf("Error: %s\n", gai_strerror(ret));
        exit(1);
    }

    addr = (struct sockaddr_in *)addrinfo->ai_addr;
    sock = socket(addrinfo->ai_family, SOCK_DGRAM, 0);

    ret = sendto(sock, data, strlen(data), 0, addr, addrinfo->ai_addrlen);
    if (ret!= strlen(data)) {
        printf("Error: sendto()\n");
        exit(1);
    }

    ret = recvfrom(sock, data, MAX_DATA, 0, addr, &addrinfo->ai_addrlen);
    if (ret <= 0) {
        printf("Error: recvfrom()\n");
        exit(1);
    }

    close(sock);

    printf("Received: %s\n", data);

    return 0;
}