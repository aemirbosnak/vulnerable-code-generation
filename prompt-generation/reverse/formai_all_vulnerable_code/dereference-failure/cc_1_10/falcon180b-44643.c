//Falcon-180B DATASET v1.0 Category: Building a SMTP Client ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_LINE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct hostent *host;
    struct sockaddr_in server;
    char line[MAX_LINE];

    if (argc < 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    host = gethostbyname(argv[1]);
    if (host == NULL) {
        printf("Unknown host: %s\n", argv[1]);
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(atoi(argv[2]));
    server.sin_addr = *((struct in_addr *) host->h_addr);

    if (connect(sock, (struct sockaddr *) &server, sizeof(server)) == -1) {
        perror("connect");
        exit(1);
    }

    printf("Connected to %s:%d\n", argv[1], atoi(argv[2]));

    while (fgets(line, MAX_LINE, stdin)!= NULL) {
        send(sock, line, strlen(line), 0);
    }

    close(sock);

    return 0;
}