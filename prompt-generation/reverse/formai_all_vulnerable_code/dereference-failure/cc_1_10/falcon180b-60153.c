//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUF_SIZE 8192

struct sockaddr_in server_addr;
int sockfd;

void error_handling(const char* message);

int main(int argc, char* argv[]) {
    if (argc!= 3) {
        printf("Usage:./speedtest <server_ip> <port>\n");
        return 1;
    }

    char* server_ip = argv[1];
    int port = atoi(argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        error_handling("socket failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(server_ip);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(struct sockaddr)) < 0) {
        error_handling("connect failed");
    }

    char request[100];
    sprintf(request, "GET /speedtest.txt HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", server_ip);

    send(sockfd, request, strlen(request), 0);

    char response[BUF_SIZE];
    memset(response, 0, BUF_SIZE);

    int bytes_received = 0;
    int total_bytes_received = 0;

    while ((bytes_received = recv(sockfd, response + total_bytes_received, BUF_SIZE - total_bytes_received, 0)) > 0) {
        total_bytes_received += bytes_received;
    }

    close(sockfd);

    float speed = (float)total_bytes_received / (1024.0 * 1024.0);
    printf("Speed: %.2f Mbps\n", speed);

    return 0;
}

void error_handling(const char* message) {
    perror(message);
    exit(1);
}