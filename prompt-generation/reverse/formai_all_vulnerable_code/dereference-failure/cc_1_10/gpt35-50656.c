//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_RESPONSE_SIZE 1024

int main(int argc, char *argv[]) {
    int client_sock, bytes, port = 80;
    char *host, *path;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char buffer[MAX_RESPONSE_SIZE];

    if (argc != 3) {
        printf("Usage: %s <hostname> <path>\n", argv[0]);
        exit(1);
    }

    host = argv[1];
    path = argv[2];

    if ((server = gethostbyname(host)) == NULL) {
        perror("Couldn't resolve host");
        exit(1);
    }

    if ((client_sock = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Couldn't create socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = *((unsigned long *) server->h_addr);
    server_addr.sin_port = htons(port);

    if (connect(client_sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        perror("Couldn't connect to server");
        exit(1);
    }

    sprintf(buffer, "GET %s HTTP/1.1\r\nHost: %s\r\n\r\n", path, host);
    if (send(client_sock, buffer, strlen(buffer), 0) == -1) {
        perror("Couldn't send request");
        exit(1);
    }

    while ((bytes = recv(client_sock, buffer, MAX_RESPONSE_SIZE - 1, 0)) > 0) {
        buffer[bytes] = '\0';
        printf("%s", buffer);
    }

    if (bytes == -1) {
        perror("Error receiving response");
        exit(1);
    }

    close(client_sock);
    return 0;
}