//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s [hostname] [port]\n", argv[0]);
        return 1;
    }

    char *hostname = argv[1];
    char *port = argv[2];
    struct hostent *hp = gethostbyname(hostname);

    if (!hp) {
        fprintf(stderr, "Error: could not resolve hostname %s\n", hostname);
        return 2;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock < 0) {
        fprintf(stderr, "Error: could not create socket\n");
        return 3;
    }

    struct sockaddr_in addr = { 0 };
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr.s_addr, hp->h_addr, hp->h_length);
    addr.sin_port = htons(atoi(port));

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) < 0) {
        fprintf(stderr, "Error: could not connect to server\n");
        return 4;
    }

    char buffer[BUFFER_SIZE] = { 0 };
    recv(sock, buffer, BUFFER_SIZE - 1, 0);

    if (strstr(buffer, "OK") == NULL) {
        fprintf(stderr, "Error: server did not respond with OK\n");
        return 5;
    }

    sprintf(buffer, "USER %s\r\n", "username");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE - 1, 0);

    if (strstr(buffer, "OK") == NULL) {
        fprintf(stderr, "Error: did not receive OK after sending USER command\n");
        return 6;
    }

    sprintf(buffer, "PASS %s\r\n", "password");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE - 1, 0);

    if (strstr(buffer, "OK") == NULL) {
        fprintf(stderr, "Error: did not receive OK after sending PASS command\n");
        return 7;
    }

    sprintf(buffer, "LIST\r\n");
    send(sock, buffer, strlen(buffer), 0);
    recv(sock, buffer, BUFFER_SIZE - 1, 0);

    if (strstr(buffer, "OK") == NULL) {
        fprintf(stderr, "Error: did not receive OK after sending LIST command\n");
        return 8;
    }

    printf("%s", buffer);

    close(sock);

    return 0;
}