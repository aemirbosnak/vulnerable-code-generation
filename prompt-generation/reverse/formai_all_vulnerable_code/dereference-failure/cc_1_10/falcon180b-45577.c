//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define SERVER_ADDRESS "speedtest.net"
#define SERVER_PORT 80

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    int bytes_sent, bytes_received;
    double start_time, end_time;
    char send_buffer[BUFFER_SIZE];
    char receive_buffer[BUFFER_SIZE];

    if (argc!= 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    server_addr.sin_addr.s_addr = inet_addr(SERVER_ADDRESS);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(0);
    bytes_sent = send(sockfd, argv[1], strlen(argv[1]), 0);
    end_time = time(0);

    if (bytes_sent <= 0) {
        printf("Error sending data\n");
        exit(1);
    }

    bytes_received = recv(sockfd, receive_buffer, BUFFER_SIZE, 0);
    if (bytes_received <= 0) {
        printf("Error receiving data\n");
        exit(1);
    }

    close(sockfd);

    double speed = (double)bytes_sent / (end_time - start_time);
    printf("Internet speed: %.2lf bytes/second\n", speed);

    return 0;
}