//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX 100
#define PORT 8080
#define SA struct sockaddr

void die(const char *s)
{
    perror(s);
    exit(errno);
}

int main(int argc, char **argv)
{
    int sock;
    struct addrinfo hints, *servinfo, *p;
    int rv;
    char s[MAX];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo("localhost", "8080", &hints, &servinfo);
    if (rv!= 0) {
        die("getaddrinfo");
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (sock == -1) {
            continue;
        }

        break;
    }

    if (sock == -1) {
        die("socket");
    }

    if (connect(sock, p->ai_addr, p->ai_addrlen)!= 0) {
        die("connect");
    }

    while (1) {
        printf("Enter a message: ");
        fgets(s, MAX, stdin);
        send(sock, s, strlen(s), 0);
        memset(s, 0, MAX);
        recv(sock, s, MAX, 0);
        printf("Server: %s\n", s);
    }

    close(sock);

    return 0;
}