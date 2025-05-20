//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server-host> <server-port>\n", argv[0]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(argv[1]);
    addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return 1;
    }

    int n = 0;
    char buf[4096];
    int buf_size = sizeof(buf);

    while (1) {
        int len = read(sock, buf, buf_size);
        if (len == 0) {
            break;
        }

        printf("Proxy: %s\n", buf);
        int sent = sendto(sock, buf, len, 0, (struct sockaddr *)&addr, sizeof(addr));
        if (sent == -1) {
            perror("sendto");
            return 1;
        }

        n += len;
        if (n >= buf_size) {
            n = 0;
            memset(buf, 0, buf_size);
        }
    }

    close(sock);
    return 0;
}