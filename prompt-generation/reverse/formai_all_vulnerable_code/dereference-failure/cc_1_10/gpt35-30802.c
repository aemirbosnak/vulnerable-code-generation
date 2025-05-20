//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s [hostname] [port]\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *hostname = argv[1];
    int port = atoi(argv[2]);

    struct hostent *server = gethostbyname(hostname);
    if (server == NULL) {
        printf("Error: no such host %s\n", hostname);
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = *((unsigned long*)server->h_addr_list[0]);
    addr.sin_port = htons(port);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        printf("Error: could not create socket\n");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        printf("Error: could not connect to server\n");
        exit(EXIT_FAILURE);
    }

    char request[BUFFER_SIZE];
    printf("Enter HTTP request (GET /index.html HTTP/1.0):\n");
    fgets(request, BUFFER_SIZE, stdin);

    if (send(sock, request, strlen(request), 0) < 0) {
        printf("Error: could not send request\n");
        exit(EXIT_FAILURE);
    }

    char response[BUFFER_SIZE];
    memset(response, 0, BUFFER_SIZE);

    int bytes_received = recv(sock, response, BUFFER_SIZE, 0);
    if (bytes_received < 0) {
        printf("Error: could not receive response\n");
        exit(EXIT_FAILURE);
    }

    printf("%s", response);

    close(sock);

    return 0;
}