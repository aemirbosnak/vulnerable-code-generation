//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

char* get_host_ip(char* hostname) {
    struct hostent* host = gethostbyname(hostname);
    if (!host) {
        perror("gethostbyname");
        return NULL;
    }
    struct in_addr* addr = (struct in_addr*)host->h_addr_list[0];
    return inet_ntoa(*addr);
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
        return 1;
    }
    char* hostname = argv[1];
    char* port = argv[2];

    char* host_ip = get_host_ip(hostname);
    if (!host_ip) {
        fprintf(stderr, "Invalid hostname\n");
        return 1;
    }

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return 1;
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port));
    serv_addr.sin_addr.s_addr = inet_addr(host_ip);

    int connect_status = connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
    if (connect_status == -1) {
        perror("connect");
        return 1;
    }

    char* request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
    char request_buffer[MAX_BUFFER_SIZE];
    snprintf(request_buffer, MAX_BUFFER_SIZE, request, hostname);

    int sent_bytes = send(sockfd, request_buffer, strlen(request_buffer), 0);
    if (sent_bytes == -1) {
        perror("send");
        return 1;
    }

    char response_buffer[MAX_BUFFER_SIZE];
    memset(response_buffer, 0, MAX_BUFFER_SIZE);
    int received_bytes = recv(sockfd, response_buffer, MAX_BUFFER_SIZE, 0);
    if (received_bytes == -1) {
        perror("recv");
        return 1;
    }

    printf("HTTP response:\n%s\n", response_buffer);

    close(sockfd);

    return 0;
}