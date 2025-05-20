//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <netdb.h>
#include <sys/time.h>
#include <unistd.h>

#define BUFFER_SIZE 65535

int main(int argc, char **argv) {
    int sock, ret;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int buffer_len;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <server_ip> <port>\n", argv[0]);
        exit(1);
    }

    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("socket");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(argv[2]));
    if (inet_pton(AF_INET, argv[1], &server_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid server IP address\n");
        exit(1);
    }

    ret = connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        perror("connect");
        exit(1);
    }

    while (1) {
        buffer_len = recv(sock, buffer, BUFFER_SIZE, 0);
        if (buffer_len <= 0) {
            break;
        }
        buffer[buffer_len] = '\0';
        printf("Received data: %s\n", buffer);
    }

    close(sock);
    return 0;
}