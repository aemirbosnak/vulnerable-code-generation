//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <errno.h>
#include <time.h>

#define MAX_DATA_SIZE 1024
#define TIMEOUT_SECONDS 5

void usage(char *prog) {
    printf("Usage: %s <host> <port>\n", prog);
    exit(1);
}

int ping(char *host, int port) {
    int sockfd, ret;
    struct sockaddr_in serveraddr;
    char send_data[MAX_DATA_SIZE] = "PING";
    char recv_data[MAX_DATA_SIZE] = {0};
    int data_size = strlen(send_data);
    struct timeval timeout = {TIMEOUT_SECONDS, 0};

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error: Could not create socket.\n");
        return -1;
    }

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_port = htons(port);
    inet_pton(AF_INET, host, &serveraddr.sin_addr);

    ret = connect(sockfd, (struct sockaddr *)&serveraddr, sizeof(serveraddr));
    if (ret == -1) {
        printf("Error: Could not connect to server.\n");
        close(sockfd);
        return -1;
    }

    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char *)&timeout, sizeof(timeout));
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout));

    send(sockfd, send_data, data_size, 0);
    ret = recv(sockfd, recv_data, MAX_DATA_SIZE, 0);

    if (ret == -1) {
        printf("Error: Could not receive data.\n");
        close(sockfd);
        return -1;
    } else if (ret == 0) {
        printf("Server is not responding.\n");
        close(sockfd);
        return -1;
    } else {
        printf("Server is responding.\n");
        close(sockfd);
        return 0;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        usage(argv[0]);
    }

    char *host = argv[1];
    int port = atoi(argv[2]);

    ping(host, port);

    return 0;
}