//Falcon-180B DATASET v1.0 Category: Port Scanner ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char **argv) {
    if(argc!= 3) {
        printf("Usage: %s <ip address> <port range>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = start_port + 100;

    printf("Scanning %s:%d - %d...\n", ip, start_port, end_port);

    for(int i = start_port; i <= end_port; i++) {
        int sock = socket(AF_INET, SOCK_STREAM, 0);
        if(sock == -1) {
            error("socket");
        }

        struct sockaddr_in serv_addr;
        memset(&serv_addr, 0, sizeof(serv_addr));
        serv_addr.sin_family = AF_INET;
        serv_addr.sin_port = htons(i);
        inet_pton(AF_INET, ip, &serv_addr.sin_addr);

        if(connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
            close(sock);
            continue;
        }

        char buffer[1024];
        memset(buffer, 0, sizeof(buffer));
        send(sock, "GET / HTTP/1.0\r\nHost: 127.0.0.1\r\n\r\n", strlen("GET / HTTP/1.0\r\nHost: 127.0.0.1\r\n\r\n"), 0);

        int bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        if(bytes_received > 0) {
            char *http_version = strstr(buffer, "HTTP/");
            if(http_version!= NULL) {
                printf("%d - Open\n", i);
            }
        }

        close(sock);
    }

    return 0;
}