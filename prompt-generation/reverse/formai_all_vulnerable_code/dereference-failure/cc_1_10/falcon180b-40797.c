//Falcon-180B DATASET v1.0 Category: Building a POP3 Client ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    struct addrinfo hints, *servinfo, *p;
    int rv, sd, bytes_read;
    char buffer[BUFFER_SIZE];
    const char *user = "user";
    const char *pass = "pass";
    const char *cmd = "STAT\r\n";

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;

    if ((rv = getaddrinfo("localhost", "110", &hints, &servinfo))!= 0) {
        fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(rv));
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sd = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("socket");
            continue;
        }

        if (connect(sd, p->ai_addr, p->ai_addrlen)!= -1) {
            break;
        }

        close(sd);
        perror("connect");
    }

    if (p == NULL) {
        exit(1);
    }

    printf("Connected to %s\n", p->ai_canonname);

    if (send(sd, user, strlen(user), 0)!= strlen(user)) {
        perror("send");
        exit(1);
    }

    if (send(sd, pass, strlen(pass), 0)!= strlen(pass)) {
        perror("send");
        exit(1);
    }

    if (send(sd, cmd, strlen(cmd), 0)!= strlen(cmd)) {
        perror("send");
        exit(1);
    }

    bytes_read = 0;
    while ((bytes_read = recv(sd, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_read] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sd);
    freeaddrinfo(servinfo);

    return 0;
}