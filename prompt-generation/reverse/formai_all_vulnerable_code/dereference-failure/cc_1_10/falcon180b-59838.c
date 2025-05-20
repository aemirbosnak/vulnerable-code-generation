//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define MAX_DATA_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd, ret, i, n;
    struct sockaddr_in server_addr;
    char send_data[MAX_DATA_SIZE];
    char recv_data[MAX_DATA_SIZE];
    int timeout = 5; //seconds
    int time_left = timeout;
    int max_attempts = 3;
    int attempts = 0;

    if (argc!= 3) {
        printf("Usage:./ping <IP address> <port number>\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    server_addr.sin_port = htons(atoi(argv[2]));

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    ret = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    if (ret == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    printf("Connected to server\n");

    while (time_left > 0) {
        ret = send(sockfd, send_data, sizeof(send_data), 0);
        if (ret == -1) {
            printf("Error sending data\n");
            exit(1);
        }

        memset(recv_data, 0, sizeof(recv_data));
        n = recv(sockfd, recv_data, sizeof(recv_data), 0);
        if (n == -1) {
            printf("Error receiving data\n");
            exit(1);
        }

        if (n > 0) {
            printf("Received data: %s\n", recv_data);
            attempts = 0;
        } else {
            attempts++;
        }

        if (attempts == max_attempts) {
            printf("Connection timed out\n");
            exit(1);
        }

        time_left--;
        usleep(1000000); //1 second
    }

    close(sockfd);
    return 0;
}