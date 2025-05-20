//Falcon-180B DATASET v1.0 Category: Wireless Network Scanner ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define MAX_BUF_SIZE 1024

struct sockaddr_in server_addr;
struct sockaddr_in client_addr;
int sockfd;
char buffer[MAX_BUF_SIZE];

void error_handling(char *message) {
    perror(message);
    exit(1);
}

void broadcast(int port) {
    char *message = "Hello, is anyone there?";
    int len = strlen(message);
    sendto(sockfd, message, len, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
}

int main(int argc, char *argv[]) {
    int port = 1234;
    int opt = 1;
    int addrlen = sizeof(struct sockaddr_in);
    char *ip = "255.255.255.255";

    if (argc > 1) {
        port = atoi(argv[1]);
    }

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        error_handling("socket failed");
    }

    setsockopt(sockfd, SOL_SOCKET, SO_BROADCAST, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip);
    server_addr.sin_port = htons(port);

    while (1) {
        memset(buffer, 0, sizeof(buffer));
        recvfrom(sockfd, buffer, MAX_BUF_SIZE, 0, (struct sockaddr *)&client_addr, &addrlen);
        printf("Message from %s:%d - %s\n", inet_ntoa(client_addr.sin_addr), ntohs(client_addr.sin_port), buffer);
    }

    close(sockfd);
    return 0;
}