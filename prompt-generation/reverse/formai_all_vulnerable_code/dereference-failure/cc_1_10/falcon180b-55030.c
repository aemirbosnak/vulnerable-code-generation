//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s hostname\n", argv[0]);
        return 1;
    }

    char hostname[MAX_HOSTNAME];
    strncpy(hostname, argv[1], MAX_HOSTNAME - 1);
    hostname[MAX_HOSTNAME - 1] = '\0';

    int sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        die("socket");
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(7);

    if (inet_pton(AF_INET, hostname, &serv_addr.sin_addr) <= 0) {
        if (errno == EAFNOSUPPORT) {
            die("EAFNOSUPPORT");
        } else {
            die("inet_pton");
        }
    }

    char data[MAX_DATA];
    strcpy(data, "PING");

    if (sendto(sock, data, strlen(data), 0, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
        die("sendto");
    }

    char buffer[MAX_DATA];
    memset(buffer, 0, sizeof(buffer));

    int bytes_received = recvfrom(sock, buffer, sizeof(buffer), 0, NULL, NULL);
    if (bytes_received == -1) {
        die("recvfrom");
    }

    close(sock);

    if (strncmp(buffer, "PONG", 4)!= 0) {
        fprintf(stderr, "Host %s did not respond with PONG\n", hostname);
        return 1;
    }

    fprintf(stdout, "Host %s is alive\n", hostname);
    return 0;
}