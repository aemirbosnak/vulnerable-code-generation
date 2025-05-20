//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#define MAX_LEN 1024

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    struct hostent *host = gethostbyname(argv[1]);
    if (!host) {
        fprintf(stderr, "Error: Could not resolve hostname %s\n", argv[1]);
        return 1;
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Error: Could not create socket");
        return 1;
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr.s_addr, host->h_addr_list[0], host->h_length);
    addr.sin_port = htons(atoi(argv[2]));

    if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("Error: Could not connect to server");
        close(sock);
        return 1;
    }

    char request[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    if (send(sock, request, strlen(request), 0) == -1) {
        perror("Error: Could not send request");
        close(sock);
        return 1;
    }

    char response[MAX_LEN];
    int recv_len;
    while ((recv_len = recv(sock, response, MAX_LEN - 1, 0)) > 0) {
        response[recv_len] = '\0';
        printf("%s", response);
    }

    if (recv_len < 0) {
        perror("Error: Could not receive response");
        close(sock);
        return 1;
    }

    close(sock);
    return 0;
}