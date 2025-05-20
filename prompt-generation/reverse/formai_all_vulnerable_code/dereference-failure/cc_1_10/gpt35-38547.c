//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define BUFSIZE 1024

int main(int argc, char *argv[]) {
    int sock, portno, n;
    struct sockaddr_in server;
    struct hostent *hp;
    char buffer[BUFSIZE];

    if (argc != 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    hp = gethostbyname(argv[1]);
    if (hp == NULL) {
        fprintf(stderr, "Error: Could not resolve hostname '%s'\n", argv[1]);
        exit(1);
    }

    portno = atoi(argv[2]);

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Error: Could not create socket");
        exit(1);
    }

    memset(&server, 0, sizeof(server));
    server.sin_family = AF_INET;
    memcpy(&server.sin_addr.s_addr, hp->h_addr, hp->h_length);
    server.sin_port = htons(portno);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Error: Could not connect to server");
        exit(1);
    }

    printf("Connected to server %s:%d\n", hp->h_name, portno);

    n = read(sock, buffer, BUFSIZE);
    if (n < 0) {
        perror("Error: Could not read from socket");
        exit(1);
    }

    printf("%s", buffer);

    strcpy(buffer, "a001 LOGIN user@example.com password\n");
    write(sock, buffer, strlen(buffer));

    n = read(sock, buffer, BUFSIZE);
    if (n < 0) {
        perror("Error: Could not read from socket");
        exit(1);
    }

    printf("%s", buffer);

    strcpy(buffer, "a002 SELECT INBOX\n");
    write(sock, buffer, strlen(buffer));

    n = read(sock, buffer, BUFSIZE);
    if (n < 0) {
        perror("Error: Could not read from socket");
        exit(1);
    }

    printf("%s", buffer);

    close(sock);

    return 0;
}