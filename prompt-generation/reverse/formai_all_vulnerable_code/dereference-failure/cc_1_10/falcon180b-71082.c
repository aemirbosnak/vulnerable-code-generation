//Falcon-180B DATASET v1.0 Category: Internet Speed Test Application ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define SERVER_PORT 8080
#define SERVER_IP "speedtest.net"
#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    int sockfd;
    struct sockaddr_in server_addr;
    char send_buffer[BUFFER_SIZE];
    char recv_buffer[BUFFER_SIZE];
    int total_bytes_sent = 0;
    int total_bytes_recv = 0;
    double start_time, end_time;
    double elapsed_time;
    int bytes_sent, bytes_recv;
    double speed;

    if (argc!= 2) {
        printf("Usage:./speedtest <file_size_in_bytes>\n");
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        exit(1);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        printf("Error connecting to server\n");
        exit(1);
    }

    start_time = time(NULL);

    while (total_bytes_sent < atoi(argv[1])) {
        bytes_sent = send(sockfd, send_buffer, BUFFER_SIZE, 0);
        if (bytes_sent == -1) {
            printf("Error sending data\n");
            exit(1);
        }
        total_bytes_sent += bytes_sent;
    }

    close(sockfd);

    end_time = time(NULL);
    elapsed_time = difftime(end_time, start_time);
    speed = (double)total_bytes_sent / elapsed_time;

    printf("Total bytes sent: %d\n", total_bytes_sent);
    printf("Elapsed time: %f seconds\n", elapsed_time);
    printf("Speed: %f bytes/second\n", speed);

    return 0;
}