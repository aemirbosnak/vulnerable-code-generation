//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s <IP address>\n", argv[0]);
        return 1;
    }

    struct addrinfo hints, *res;
    memset(&hints, 0, sizeof hints);
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return 1;
    }

    int enable = 1;
    if (setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof enable) < 0) {
        perror("setsockopt");
        return 1;
    }

    struct sockaddr_in server;
    memset(&server, 0, sizeof server);
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);

    struct hostent *he = gethostbyname(argv[1]);
    if (he == NULL) {
        perror("gethostbyname");
        return 1;
    }

    memcpy(&server.sin_addr.s_addr, he->h_addr_list[0], he->h_length);

    res = NULL;
    if (getaddrinfo(argv[1], "8080", &hints, &res)!= 0) {
        perror("getaddrinfo");
        return 1;
    }

    server.sin_addr.s_addr = *((unsigned long *)res->ai_addr);

    if (connect(sock, (struct sockaddr *)&server, sizeof server) < 0) {
        perror("connect");
        return 1;
    }

    char buffer[1024];
    int bytes_read;

    while ((bytes_read = recv(sock, buffer, sizeof buffer, 0)) > 0) {
        printf("%s\n", buffer);
        sleep(1);
    }

    close(sock);
    return 0;
}