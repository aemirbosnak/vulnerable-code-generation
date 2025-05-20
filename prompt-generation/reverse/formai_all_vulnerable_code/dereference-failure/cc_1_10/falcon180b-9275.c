//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX 1024
#define TRUE 1
#define FALSE 0
#define ERROR -1

int main(int argc, char *argv[]) {
    int sock, port, max_port, ret, val;
    struct sockaddr_in server;
    char *ip = "127.0.0.1";
    char buffer[MAX];
    int count = 0;

    if (argc!= 3) {
        printf("Usage: %s <IP Address> <Port Range>\n", argv[0]);
        exit(1);
    }

    strcpy(ip, argv[1]);
    max_port = atoi(argv[2]) + 1;

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == ERROR) {
        printf("Error creating socket\n");
        exit(1);
    }

    for (port = 1; port <= max_port; port++) {
        memset(&server, 0, sizeof(server));
        server.sin_family = AF_INET;
        server.sin_port = htons(port);
        inet_pton(AF_INET, ip, &server.sin_addr);

        ret = connect(sock, (struct sockaddr *)&server, sizeof(server));
        if (ret == 0) {
            printf("Port %d is open\n", port);
            close(sock);
            count++;
        } else if (errno!= ECONNREFUSED) {
            printf("Error connecting to port %d\n", port);
            exit(1);
        }
    }

    if (count == 0) {
        printf("No open ports found\n");
    }

    close(sock);
    return 0;
}