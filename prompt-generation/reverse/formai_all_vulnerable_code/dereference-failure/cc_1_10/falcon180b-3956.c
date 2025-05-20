//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: protected
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>

#define MAX_LINE 1024
#define PING_INTERVAL 1 // in seconds
#define PING_TIMEOUT 5 // in seconds

#define DEBUG 0

void debug(const char* format,...) {
    if (DEBUG) {
        va_list arg;
        va_start(arg, format);
        vprintf(format, arg);
        va_end(arg);
        printf("\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <hostname/IP> <port>\n", argv[0]);
        return 1;
    }

    char* host = argv[1];
    int port = atoi(argv[2]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    inet_pton(AF_INET, host, &addr.sin_addr);

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
        close(sock);
        perror("connect");
        return 1;
    }

    char buffer[MAX_LINE];
    while (1) {
        int bytes_received = recv(sock, buffer, MAX_LINE, 0);
        if (bytes_received <= 0) {
            close(sock);
            printf("Connection closed.\n");
            break;
        }

        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}