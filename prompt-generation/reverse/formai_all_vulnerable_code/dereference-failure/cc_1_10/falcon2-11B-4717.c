//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: careful
#include <stdio.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

int main() {
    struct addrinfo hints, *servinfo, *p;
    char portstr[16];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    int rv = getaddrinfo("www.google.com", "80", &hints, &servinfo);

    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        struct sockaddr_in sin;

        memset(&sin, 0, sizeof sin);
        sin.sin_family = AF_INET;
        sin.sin_port = htons(80);

        if (inet_pton(p->ai_family, p->ai_addr, &sin.sin_addr) <= 0) {
            continue;
        }

        int sock = socket(p->ai_family, SOCK_STREAM, 0);
        if (sock < 0) {
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen)!= 0) {
            continue;
        }

        char buffer[1024];
        int n = 0;

        while ((n = read(sock, buffer, sizeof buffer - 1)) > 0) {
            buffer[n] = 0;
            printf("%s\n", buffer);
        }

        close(sock);
    }

    freeaddrinfo(servinfo);

    return 0;
}