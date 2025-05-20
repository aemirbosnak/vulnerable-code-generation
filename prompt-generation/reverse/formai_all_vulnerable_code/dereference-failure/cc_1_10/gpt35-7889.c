//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: ./http_client <url>\n");
        exit(1);
    }
    char *url = argv[1];
    char *host = strstr(url, "//");
    if (host == NULL) {
        host = url;
    } else {
        host += 2;
    }
    char *path = strchr(host, '/');
    if (path == NULL) {
        path = "/";
    } else {
        *path = '\0';
        path++;
    }
    struct hostent *he = gethostbyname(host);
    if (he == NULL) {
        printf("Could not resolve host %s\n", host);
        exit(1);
    }
    struct in_addr **addr_list = (struct in_addr **) he->h_addr_list;
    struct in_addr addr = *addr_list[0];

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        printf("Could not create socket\n");
        exit(1);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_addr.s_addr = inet_addr(inet_ntoa(addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);

    if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        printf("Could not connect to server\n");
        exit(1);
    }

    char request[512];
    sprintf(request, "GET /%s HTTP/1.0\r\nHost: %s\r\n\r\n", path, host);
    if (send(sock, request, strlen(request), 0) == -1) {
        printf("Could not send request\n");
        exit(1);
    }

    int recv_size;
    char response[4096], server_reply[4096];
    while ((recv_size = recv(sock, server_reply, 4096, 0)) > 0) {
        server_reply[recv_size] = '\0';
        strcat(response, server_reply);
    }

    printf("%s\n", response);

    close(sock);

    return 0;
}