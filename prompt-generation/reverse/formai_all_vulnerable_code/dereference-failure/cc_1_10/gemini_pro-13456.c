//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Claude Shannon's Information Theory
double entropy(unsigned char *data, size_t len) {
    double H = 0;
    unsigned char *p = data;
    unsigned int n[256] = {0};
    for (size_t i = 0; i < len; i++) {
        n[p[i]]++;
    }
    for (int i = 0; i < 256; i++) {
        if (n[i] == 0) continue;
        H += (double)n[i] / len * log2((double)len / n[i]);
    }
    return H;
}

int main(int argc, char **argv) {
    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(atoi(argv[2]));
    addr.sin_addr.s_addr = inet_addr(argv[1]);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket()");
        return 2;
    }

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect()");
        return 3;
    }

    char buf[1024];
    while (1) {
        int n = recv(sock, buf, sizeof(buf), 0);
        if (n == -1) {
            perror("recv()");
            return 4;
        } else if (n == 0) {
            printf("Connection closed by remote host.\n");
            break;
        }

        printf("Received %d bytes: %s\n", n, buf);
        printf("Entropy: %.2f\n", entropy((unsigned char *)buf, n));
    }

    close(sock);
    return 0;
}