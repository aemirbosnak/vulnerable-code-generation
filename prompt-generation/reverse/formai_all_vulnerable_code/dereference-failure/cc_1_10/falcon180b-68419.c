//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>

#define MAX_DATA_SIZE 1024

struct sockaddr_in server_addr;
int server_socket;
int client_socket;
int opt = 1;
char buffer[MAX_DATA_SIZE];

void init_socket(int sock) {
    setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char *)&opt, sizeof(opt));
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        printf("Usage: %s <IP address> <port number>\n", argv[0]);
        exit(1);
    }

    char *ip_addr = argv[1];
    int port_num = atoi(argv[2]);

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(ip_addr);
    server_addr.sin_port = htons(port_num);

    if ((server_socket = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("socket failed");
        exit(1);
    }

    if (connect(server_socket, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect failed");
        exit(1);
    }

    printf("Connected to %s:%d\n", ip_addr, port_num);

    init_socket(server_socket);

    while(1) {
        bzero(buffer, MAX_DATA_SIZE);
        if(recv(server_socket, buffer, MAX_DATA_SIZE, 0) <= 0) {
            printf("Connection closed by server\n");
            break;
        }
        printf("%s", buffer);
    }

    close(server_socket);
    return 0;
}