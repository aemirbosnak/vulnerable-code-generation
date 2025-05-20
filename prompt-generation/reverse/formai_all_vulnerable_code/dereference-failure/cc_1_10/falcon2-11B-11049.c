//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/tcp.h>

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: ping <target> <count>\n");
        return 1;
    }

    int sock;
    struct sockaddr_in target;
    struct hostent *he;

    memset(&target, 0, sizeof(target));
    target.sin_family = AF_INET;
    target.sin_addr.s_addr = inet_addr(argv[1]);
    target.sin_port = htons(80);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    he = gethostbyname(argv[1]);
    if (he == NULL) {
        fprintf(stderr, "No such host\n");
        return 1;
    }

    if (connect(sock, (struct sockaddr *)&target, sizeof(target)) < 0) {
        perror("connect");
        return 1;
    }

    char buf[1024];
    int count = atoi(argv[2]);
    for (int i = 0; i < count; i++) {
        if (send(sock, "GET / HTTP/1.0\r\n\r\n", 33, 0) < 0) {
            perror("send");
            return 1;
        }

        int n;
        while ((n = recv(sock, buf, sizeof(buf), 0)) > 0) {
            if (n < 33) {
                fprintf(stderr, "short read\n");
                return 1;
            }

            buf[n] = '\0';
            printf("%s\n", buf);
        }
    }

    return 0;
}