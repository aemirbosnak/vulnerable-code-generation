//Falcon2-11B DATASET v1.0 Category: Networking ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/in.h>

int establish_tcp_connection(char* hostname, int port) {
    struct hostent* server;
    struct sockaddr_in addr;

    server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Could not resolve hostname\n");
        return -1;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr = *((struct in_addr*)server->h_addr);

    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket");
        return -1;
    }

    if (connect(sock, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
        perror("connect");
        return -1;
    }

    return sock;
}

void send_message(int sock, char* message) {
    int len = strlen(message) + 1;
    int sent = send(sock, message, len, 0);
    if (sent < 0) {
        perror("send");
    }
}

char* receive_response(int sock) {
    char buf[1024];
    int len;

    len = recv(sock, buf, sizeof(buf), 0);
    if (len <= 0) {
        return NULL;
    }

    buf[len] = '\0';
    return buf;
}

int main() {
    int sock = establish_tcp_connection("www.example.com", 80);
    if (sock < 0) {
        return 1;
    }

    char message[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    send_message(sock, message);

    char* response = receive_response(sock);
    if (response == NULL) {
        fprintf(stderr, "No response received\n");
        return 1;
    }

    printf("Response: %s\n", response);

    close(sock);
    return 0;
}