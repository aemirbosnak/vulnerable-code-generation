//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_HOSTNAME 256
#define MAX_DATA 1024

int ping(char* hostname, int port) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    char send_data[MAX_DATA];
    char recv_data[MAX_DATA];
    memset(send_data, 'A', MAX_DATA);
    memset(recv_data, 0, MAX_DATA);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        return 0;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    inet_pton(AF_INET, hostname, &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
        printf("Error connecting to host\n");
        return 0;
    }

    send(sockfd, send_data, MAX_DATA, 0);
    n = recv(sockfd, recv_data, MAX_DATA, 0);
    close(sockfd);

    if (n > 0 && strncmp(send_data, recv_data, MAX_DATA) == 0) {
        printf("Host is alive\n");
        return 1;
    } else {
        printf("Host is not alive\n");
        return 0;
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s hostname port\n", argv[0]);
        exit(1);
    }

    char* hostname = argv[1];
    int port = atoi(argv[2]);

    ping(hostname, port);

    return 0;
}