//Falcon2-11B DATASET v1.0 Category: Internet Speed Test Application ; Style: medieval
#include <stdio.h>
#include <sys/socket.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>

int main()
{
    struct addrinfo hints, *servinfo, *p;
    int s, rv;
    char buffer[256];

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo("www.google.com", "80", &hints, &servinfo);
    if (rv) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        s = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (s == -1) {
            perror("socket");
            continue;
        }

        if (connect(s, p->ai_addr, p->ai_addrlen) == -1) {
            perror("connect");
            close(s);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "connect failed\n");
        return 1;
    }

    memset(buffer, 0, sizeof buffer);
    if (send(s, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n", 65, 0) == -1) {
        perror("send");
        close(s);
        return 1;
    }

    memset(buffer, 0, sizeof buffer);
    if (recv(s, buffer, sizeof buffer, 0) == -1) {
        perror("recv");
        close(s);
        return 1;
    }

    printf("Received %s\n", buffer);

    close(s);

    freeaddrinfo(servinfo);

    return 0;
}