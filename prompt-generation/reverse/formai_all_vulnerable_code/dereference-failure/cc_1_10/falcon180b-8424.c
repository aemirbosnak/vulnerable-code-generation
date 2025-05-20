//Falcon-180B DATASET v1.0 Category: Building a HTTP Client ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    char *host;
    char *port;
    char *request;
    char *response = NULL;
    int response_len = 0;
    int len;
    int ret;

    if (argc < 4) {
        printf("Usage: %s host port request\n", argv[0]);
        return -1;
    }

    host = argv[1];
    port = argv[2];
    request = argv[3];

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Error creating socket\n");
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(host);

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        return -1;
    }

    send(sock, request, strlen(request), 0);

    response = (char *)malloc(BUFFER_SIZE);
    response_len = 0;

    while (1) {
        ret = recv(sock, response + response_len, BUFFER_SIZE - response_len, 0);
        if (ret == 0) {
            printf("Connection closed by server\n");
            break;
        } else if (ret == -1) {
            printf("Error receiving data from server\n");
            return -1;
        }

        response_len += ret;

        if (response_len >= BUFFER_SIZE) {
            printf("Response too large\n");
            return -1;
        }

        response[response_len] = '\0';
        printf("%s", response);
    }

    close(sock);
    return 0;
}