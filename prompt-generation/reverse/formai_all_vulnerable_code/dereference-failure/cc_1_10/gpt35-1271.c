//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: scientific
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    char *host = argv[1];
    int port = 80;

    struct hostent *he;
    struct in_addr **addr_list;

    if ((he = gethostbyname(host)) == NULL) {
        printf("Cannot resolve hostname %s\n", host);
        return 1;
    }

    printf("IP addresses for %s:\n\n", host);
    addr_list = (struct in_addr **)he->h_addr_list;
    for (int i = 0; addr_list[i] != NULL; i++) {
        printf("%s\n", inet_ntoa(*addr_list[i]));
    }

    int sock = socket(AF_INET, SOCK_STREAM, 0);

    if (sock == -1) {
        printf("Could not create socket\n");
        return 1;
    }

    struct sockaddr_in server;
    server.sin_addr = *addr_list[0];
    server.sin_family = AF_INET;
    server.sin_port = htons(port);

    if (connect(sock, (struct sockaddr *)&server, sizeof(server)) != 0) {
        printf("Could not connect to %s:%d\n", inet_ntoa(server.sin_addr), port);
        return 1;
    }

    printf("Connected to %s:%d\n\n", inet_ntoa(server.sin_addr), port);

    char *request = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    int request_len = strlen(request);

    if (send(sock, request, request_len, 0) != request_len) {
        printf("Could not send request\n");
        return 1;
    }

    printf("Sent HTTP request:\n\n%s\n", request);

    char response[1024];
    int response_len = recv(sock, response, sizeof(response)-1, 0);

    if (response_len == -1) {
        printf("Error receiving response\n");
        return 1;
    }

    response[response_len] = '\0';

    printf("Received HTTP response:\n\n%s\n", response);

    close(sock);

    return 0;
}