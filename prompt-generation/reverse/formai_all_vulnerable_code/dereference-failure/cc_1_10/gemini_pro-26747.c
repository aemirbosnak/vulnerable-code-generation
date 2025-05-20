//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define TEST_SIZE 10240000
#define TEST_COUNT 10

struct timeval start_time, end_time;

void error(char *message)
{
    perror(message);
    exit(1);
}

int main(int argc, char *argv[])
{
    int sockfd, bytes_sent, bytes_received, total_bytes_sent, total_bytes_received;
    struct hostent *server;
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    int i, j;
    float elapsed_seconds;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        exit(1);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("socket");
    }

    server = gethostbyname(argv[1]);
    if (server == NULL) {
        error("gethostbyname");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);
    server_addr.sin_port = htons(80);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        error("connect");
    }

    total_bytes_sent = 0;
    total_bytes_received = 0;
    for (i = 0; i < TEST_COUNT; i++) {
        gettimeofday(&start_time, NULL);
        for (j = 0; j < TEST_SIZE; j++) {
            bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_sent < 0) {
                error("send");
            }
            total_bytes_sent += bytes_sent;
        }
        gettimeofday(&end_time, NULL);
        elapsed_seconds = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        printf("Upload: %.2f MBps\n", (total_bytes_sent / elapsed_seconds) / 1024.0 / 1024.0);

        gettimeofday(&start_time, NULL);
        for (j = 0; j < TEST_SIZE; j++) {
            bytes_received = recv(sockfd, buffer, BUFFER_SIZE, 0);
            if (bytes_received < 0) {
                error("recv");
            }
            total_bytes_received += bytes_received;
        }
        gettimeofday(&end_time, NULL);
        elapsed_seconds = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
        printf("Download: %.2f MBps\n", (total_bytes_received / elapsed_seconds) / 1024.0 / 1024.0);
    }

    close(sockfd);

    return 0;
}