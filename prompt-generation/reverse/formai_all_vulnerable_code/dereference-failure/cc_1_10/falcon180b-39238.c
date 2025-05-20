//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_HOST_LEN 256
#define MAX_DATA_LEN 1024
#define TIMEOUT 5

void ping_recursive(const char *host, int depth);

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    ping_recursive(argv[1], 0);
    return 0;
}

void ping_recursive(const char *host, int depth) {
    struct hostent *he;
    struct sockaddr_in server;
    int sockfd, bytes_sent, bytes_received;
    char data[MAX_DATA_LEN];
    char hostname[MAX_HOST_LEN];

    strncpy(hostname, host, MAX_HOST_LEN);
    he = gethostbyname(hostname);

    if (he == NULL) {
        printf("Host not found: %s\n", hostname);
        return;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Socket creation failed\n");
        return;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    server.sin_addr = *((struct in_addr *)he->h_addr);

    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) == -1) {
        printf("Connection failed\n");
        close(sockfd);
        return;
    }

    bytes_sent = send(sockfd, "GET / HTTP/1.0\r\n\r\n", strlen("GET / HTTP/1.0\r\n\r\n"), 0);
    if (bytes_sent == -1) {
        printf("Data send failed\n");
        close(sockfd);
        return;
    }

    bytes_received = recv(sockfd, data, MAX_DATA_LEN, 0);
    if (bytes_received <= 0) {
        printf("No data received\n");
        close(sockfd);
        return;
    }

    printf("Depth %d: Host %s is up\n", depth, hostname);

    close(sockfd);
    ping_recursive(host, depth + 1);
}