//GEMINI-pro DATASET v1.0 Category: Simple HTTP Proxy ; Style: Cryptic
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/types.h>

typedef struct {
    int s;
    char *b;
    int l;
} c;

void h(c *q) {
    char *p = q->b;
    int i;
    for (i = 0; i < q->l; i++) {
        if (p[i] == '\r' && p[i + 1] == '\n' && p[i + 2] == '\r' && p[i + 3] == '\n') {
            q->b[i] = '\0';
            return;
        }
    }
}

int main(int argc, char **argv) {
    if (argc != 4) {
        fprintf(stderr, "usage: %s <host> <port> <input>\n", argv[0]);
        exit(1);
    }
    int s, r;
    struct sockaddr_in a;
    s = socket(AF_INET, SOCK_STREAM, 0);
    if (s == -1) {
        perror("socket");
        exit(1);
    }
    memset(&a, 0, sizeof(a));
    a.sin_family = AF_INET;
    a.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &a.sin_addr) != 1) {
        perror("inet_pton");
        exit(1);
    }
    if (connect(s, (struct sockaddr *)&a, sizeof(a)) == -1) {
        perror("connect");
        exit(1);
    }
    FILE *f = fopen(argv[3], "r");
    if (f == NULL) {
        perror("fopen");
        exit(1);
    }
    char b[1024];
    c q = {s, b, 0};
    while ((r = fread(b, 1, sizeof(b), f)) > 0) {
        q.l = r;
        h(&q);
        if (send(s, q.b, q.l, 0) == -1) {
            perror("send");
            exit(1);
        }
        while ((r = recv(s, q.b, sizeof(b), 0)) > 0) {
            q.l = r;
            h(&q);
            if (write(1, q.b, q.l) == -1) {
                perror("write");
                exit(1);
            }
        }
    }
    fclose(f);
    close(s);
    return 0;
}