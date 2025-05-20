//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define MAX_SIZE 1024

struct hostent *host;
struct sockaddr_in server_addr;
int sock;

void init_socket() {
    host = gethostbyname("www.google.com");
    if (host == NULL) {
        fprintf(stderr, "Error: %s", strerror(errno));
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        fprintf(stderr, "Error: %s", strerror(errno));
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    server_addr.sin_addr = *((struct in_addr *)host->h_addr);
}

void send_request() {
    char request[MAX_SIZE];
    sprintf(request, "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n");

    int len = strlen(request);
    if (send(sock, request, len, 0) < 0) {
        fprintf(stderr, "Error: %s", strerror(errno));
        exit(1);
    }
}

void recv_response() {
    char response[MAX_SIZE];
    int len;

    while ((len = recv(sock, response, MAX_SIZE, 0)) > 0) {
        printf("%s", response);
    }

    if (len < 0) {
        fprintf(stderr, "Error: %s", strerror(errno));
        exit(1);
    }
}

void cleanup() {
    close(sock);
}

int main() {
    init_socket();
    send_request();
    recv_response();
    cleanup();

    return 0;
}