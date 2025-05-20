//Falcon-180B DATASET v1.0 Category: Client Server Application ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/time.h>

#define TRUE 1
#define FALSE 0
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

struct sockaddr_in server_addr;
int sockfd;
char buffer[BUFFER_SIZE];

void error(char* msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char** argv) {
    int opt;
    int addrlen;
    char* ip_addr;
    struct hostent* server;

    if(argc!= 3) {
        fprintf(stderr, "Usage: %s <server_ip_address> <message>\n", argv[0]);
        exit(1);
    }

    ip_addr = argv[1];
    strcpy(buffer, argv[2]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
        error("socket failed");
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, ip_addr, &server_addr.sin_addr);

    if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        error("connect failed");
    }

    send(sockfd, buffer, strlen(buffer), 0);

    while(1) {
        memset(buffer, 0, BUFFER_SIZE);
        if(recv(sockfd, buffer, BUFFER_SIZE, 0) <= 0) {
            error("recv failed");
        }
        printf("Server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}