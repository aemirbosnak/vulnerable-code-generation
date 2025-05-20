//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUF_SIZE 1024
#define PORT_NUM 10000

void error(char *message) {
    perror(message);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sock, port, opt;
    struct sockaddr_in addr;
    char hostname[BUF_SIZE];
    char port_str[BUF_SIZE];
    struct hostent *host;

    if (argc!= 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }

    strcpy(hostname, argv[1]);
    printf("Scanning host: %s\n", hostname);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error("socket");
    }

    opt = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1) {
        error("setsockopt");
    }

    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT_NUM);
    addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        error("bind");
    }

    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("Host not found: %s\n", hostname);
        close(sock);
        exit(1);
    }

    strcpy(port_str, argv[1]);
    strcat(port_str, ":");
    strcat(port_str, inet_ntoa(*(struct in_addr *)host->h_addr));

    printf("Scanning ports on host: %s\n", port_str);

    for (port = PORT_NUM; port <= 65535; port++) {
        sprintf(port_str, "%d", port);

        if (connect(sock, (struct sockaddr *)host, sizeof(*host)) == 0) {
            printf("Port %s is open\n", port_str);
        } else {
            printf("Port %s is closed\n", port_str);
        }
    }

    close(sock);
    exit(0);
}