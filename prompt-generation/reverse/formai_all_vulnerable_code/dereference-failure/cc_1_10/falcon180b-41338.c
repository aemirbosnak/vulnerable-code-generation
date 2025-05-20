//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_LENGTH 1024
#define TIME_OUT_SEC 5
#define TIME_OUT_USEC 0

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct sockaddr_in server_addr;
    char *server_ip;
    int port;
    char send_data[MAX_DATA_LENGTH];
    char recv_data[MAX_DATA_LENGTH];
    int data_length;
    struct timeval timeout;

    if (argc!= 4) {
        printf("Usage:./ping <server_ip> <port> <data_length>\n");
        exit(1);
    }

    server_ip = argv[1];
    port = atoi(argv[2]);
    data_length = atoi(argv[3]);

    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        printf("Error: socket failed\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, server_ip, &server_addr.sin_addr);

    timeout.tv_sec = TIME_OUT_SEC;
    timeout.tv_usec = TIME_OUT_USEC;

    while (1) {
        retval = sendto(sockfd, send_data, data_length, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (retval == -1) {
            printf("Error: sendto failed\n");
            exit(1);
        }

        memset(recv_data, 0, MAX_DATA_LENGTH);
        retval = recvfrom(sockfd, recv_data, MAX_DATA_LENGTH, 0, NULL, NULL);
        if (retval == -1) {
            printf("Error: recvfrom failed\n");
            exit(1);
        }

        if (recv_data[0] == 'P') {
            printf("Ping successful\n");
            break;
        }
    }

    close(sockfd);
    return 0;
}