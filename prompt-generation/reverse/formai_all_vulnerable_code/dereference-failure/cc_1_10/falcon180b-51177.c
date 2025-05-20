//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

typedef struct {
    char ip[MAX];
    int port;
} target;

void print_usage(char* argv[]) {
    printf("Usage: %s <IP> <port>\n", argv[0]);
}

int validate_ip(char* ip) {
    int i, j, k;
    char* ptr;
    if (strlen(ip)!= 15) {
        return FALSE;
    }
    for (i = 0, j = 0; i < strlen(ip); i++) {
        if (ip[i] == '.') {
            j++;
        } else if (!isdigit(ip[i])) {
            return FALSE;
        }
    }
    if (j!= 3) {
        return FALSE;
    }
    for (i = 0; i < 4; i++) {
        ptr = strtok(ip, ".");
        k = atoi(ptr);
        if (k < 0 || k > 255) {
            return FALSE;
        }
    }
    return TRUE;
}

int validate_port(int port) {
    if (port <= 0 || port > 65535) {
        return FALSE;
    }
    return TRUE;
}

int main(int argc, char* argv[]) {
    int sock, ret;
    struct sockaddr_in server;
    char buffer[1024];
    int len;
    int i, j;
    target target;

    if (argc!= 3) {
        print_usage(argv);
        return 1;
    }

    if (!validate_ip(argv[1])) {
        printf("Invalid IP address\n");
        return 1;
    }

    target.port = atoi(argv[2]);
    if (!validate_port(target.port)) {
        printf("Invalid port number\n");
        return 1;
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("socket failed\n");
        return 1;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(target.port);
    inet_pton(AF_INET, argv[1], &server.sin_addr);

    if (connect(sock, (struct sockaddr*)&server, sizeof(server)) == -1) {
        printf("connect failed\n");
        close(sock);
        return 1;
    }

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        ret = recv(sock, buffer, sizeof(buffer), 0);
        if (ret <= 0) {
            printf("recv failed\n");
            close(sock);
            return 1;
        }
        printf("Received: %s\n", buffer);
    }

    close(sock);
    return 0;
}