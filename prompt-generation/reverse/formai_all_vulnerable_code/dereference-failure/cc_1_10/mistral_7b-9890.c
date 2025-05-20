//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#include <math.h>

#define PACKET_SIZE 1500
#define TIMEOUT 5000
#define BITS_PER_BYTE 8

void error(const char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, new_sockfd;
    struct sockaddr_in serv_addr, cli_addr;
    struct timeval start, end;
    double bitrate, time_elapsed;
    char *buffer, *data = "1234567890123456789012345678901234567890";
    int i, len;

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_ip>\n", argv[0]);
        exit(1);
    }

    buffer = malloc(PACKET_SIZE);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        error("ERROR opening socket");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    inet_pton(AF_INET, argv[1], &serv_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        error("ERROR connecting");
    }

    gettimeofday(&start, NULL);

    for (i = 0; i < 10; i++) {
        send(sockfd, data, strlen(data), 0);
        len = recv(sockfd, buffer, PACKET_SIZE, 0);
        if (len < 0) {
            error("ERROR receiving data");
        }
    }

    gettimeofday(&end, NULL);

    close(sockfd);

    time_elapsed = (end.tv_sec + end.tv_usec / 1000000.0) - (start.tv_sec + start.tv_usec / 1000000.0);
    bitrate = (double) (10 * strlen(data) * 8) / time_elapsed;

    printf("Approximate bitrate: %.2f bps\n", bitrate);

    free(buffer);
    return 0;
}