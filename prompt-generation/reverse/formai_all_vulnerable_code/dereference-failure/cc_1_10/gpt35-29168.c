//FormAI DATASET v1.0 Category: Simple HTTP Proxy ; Style: multivariable
/*  C Simple HTTP Proxy Program */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#define PORT 8080

int main(int argc, char *argv[]) {
    if (argc < 2 || argc > 3) {
        printf("Usage: %s <proxy_ip_address> [port_number]\n", argv[0]);
        return 1;
    }

    int port = PORT;
    if (argc == 3) {
        port = atoi(argv[2]);
    }

    int client_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket_fd < 0) {
        perror("Unable to create socket");
        return -1;
    }

    struct sockaddr_in proxy_address;
    bzero((char *)&proxy_address, sizeof(proxy_address));
    proxy_address.sin_family = AF_INET;
    proxy_address.sin_port = htons(port);
    proxy_address.sin_addr.s_addr = inet_addr(argv[1]);

    if (connect(client_socket_fd, (struct sockaddr *)&proxy_address, sizeof(proxy_address)) < 0) {
        perror("Unable to connect to the proxy server");
        return -1;
    }

    char request[2048];
    char response[4096];

    printf("Enter HTTP Request:\n");
    fgets(request, 2048, stdin);
    if (strstr(request, "HTTP/") == NULL) {
        printf("Invalid request! Must be an HTTP request\n");
        return -1;
    }

    if (send(client_socket_fd, request, strlen(request), 0) < 0) {
        perror("Unable to send request to proxy server");
        return -1;
    }

    if (recv(client_socket_fd, response, 4096, 0) < 0) {
        perror("Unable to receive response from proxy server");
        return -1;
    }

    printf("Response received:\n");
    printf("%s", response);

    close(client_socket_fd);
    return 0;
}