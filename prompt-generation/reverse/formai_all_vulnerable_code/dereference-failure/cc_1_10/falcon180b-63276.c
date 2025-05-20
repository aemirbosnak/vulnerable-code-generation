//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 1024
#define PING_INTERVAL 1 // seconds
#define MAX_PINGS 10

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void print_usage(const char *progname) {
    printf("Usage: %s <host>\n", progname);
}

int main(int argc, char **argv) {
    if (argc!= 2) {
        print_usage(argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        die("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(7); // echo port

    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        die("inet_pton");
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        if (errno == ECONNREFUSED) {
            printf("Host is down\n");
        } else {
            die("connect");
        }
    } else {
        printf("Host is up\n");
    }

    close(sock);
    return 0;
}