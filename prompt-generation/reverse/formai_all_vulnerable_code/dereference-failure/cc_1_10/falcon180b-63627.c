//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_DATA_SIZE 1024

void ping(char *ip, int port, int timeout);

int main(int argc, char **argv) {
    if (argc!= 4) {
        printf("Usage: %s <IP> <port> <timeout>\n", argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);
    int timeout = atoi(argv[3]);

    ping(ip, port, timeout);

    return 0;
}

void ping(char *ip, int port, int timeout) {
    int sockfd;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    send(sockfd, "PING", strlen("PING"), 0);

    int bytes_received = 0;
    int start_time = time(NULL);

    while (bytes_received < MAX_DATA_SIZE && difftime(time(NULL), start_time) < timeout) {
        memset(data, 0, MAX_DATA_SIZE);
        int bytes_received_now = recv(sockfd, data, MAX_DATA_SIZE - 1, 0);
        if (bytes_received_now > 0) {
            bytes_received += bytes_received_now;
            data[bytes_received] = '\0';
            printf("%s", data);
        }
    }

    close(sockfd);
}