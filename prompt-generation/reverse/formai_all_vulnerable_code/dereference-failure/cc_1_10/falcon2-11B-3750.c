//Falcon2-11B DATASET v1.0 Category: Building a FTP Client ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    struct addrinfo hints, *servinfo, *p;
    int rv, s, n;
    char buffer[1024];
    char* server = "ftp.example.com";
    int port = 21;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    rv = getaddrinfo(server, NULL, &hints, &servinfo);
    if (rv!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        return 1;
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        s = socket(p->ai_family, p->ai_socktype, p->ai_protocol);
        if (s == -1) {
            continue;
        }

        if (connect(s, p->ai_addr, p->ai_addrlen) == -1) {
            close(s);
            continue;
        }

        break;
    }

    if (p == NULL) {
        fprintf(stderr, "connection failed\n");
        return 1;
    }

    close(s);
    freeaddrinfo(servinfo);

    sprintf(buffer, "USER anonymous\r\n");
    write(s, buffer, strlen(buffer));

    sprintf(buffer, "PASS %s\r\n", "password");
    write(s, buffer, strlen(buffer));

    sprintf(buffer, "QUIT\r\n");
    write(s, buffer, strlen(buffer));

    close(s);
    return 0;
}