//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define SERVER_PORT 8080
#define SERVER_ADDR "www.google.com"
#define BUFFER_SIZE 1024

void error_handling(const char* message) {
    perror(message);
    exit(1);
}

int main() {
    int sock;
    struct hostent* server;
    char buffer[BUFFER_SIZE];

    // create socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        error_handling("socket failed");
    }

    server = gethostbyname(SERVER_ADDR);
    if (server == NULL) {
        error_handling("gethostbyname failed");
    }

    // connect to server
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = *(unsigned long*)server->h_addr;

    // send request
    char request[50] = "GET / HTTP/1.1\r\nHost: www.google.com\r\nConnection: close\r\n\r\n";
    send(sock, request, strlen(request), 0);

    // receive response
    int bytes_received = 0;
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("%s", buffer);
    }

    close(sock);
    return 0;
}