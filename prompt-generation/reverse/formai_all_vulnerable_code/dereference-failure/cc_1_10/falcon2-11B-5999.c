//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s [IP address] [port]\n", argv[0]);
        exit(1);
    }

    char addr[INET6_ADDRSTRLEN];
    int port;

    if (inet_pton(AF_INET, argv[1], &addr) <= 0) {
        fprintf(stderr, "Invalid IP address\n");
        exit(1);
    }

    port = atoi(argv[2]);

    if (port < 0) {
        fprintf(stderr, "Invalid port number\n");
        exit(1);
    }

    char buf[1024];
    int sock;
    struct addrinfo hints, *servinfo, *p;

    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(addr, port, &hints, &servinfo)!= 0) {
        fprintf(stderr, "Error getting server address\n");
        exit(1);
    }

    for (p = servinfo; p!= NULL; p = p->ai_next) {
        if ((sock = socket(p->ai_family, p->ai_socktype, p->ai_protocol)) == -1) {
            perror("Error creating socket");
            continue;
        }

        if (connect(sock, p->ai_addr, p->ai_addrlen) == -1) {
            close(sock);
            perror("Error connecting");
            continue;
        }

        printf("Connected to %s:%d\n", addr, port);
        printf("Enter 'q' to quit\n");

        char c;
        while ((c = getchar())!= 'q') {
            if (read(0, buf, sizeof buf) == -1) {
                perror("Error reading input");
                break;
            }

            write(sock, buf, strlen(buf));
            printf("Sent: %s\n", buf);
        }

        close(sock);
        printf("Disconnected\n");
    }

    freeaddrinfo(servinfo);

    return 0;
}