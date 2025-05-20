//MISTRAL-7B DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define SERVER_ADDRESS "192.168.1.1"
#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define PACKET_SIZE 1460
#define NUM_PACKETS 10

struct packet {
    uint32_t id;
    char data[PACKET_SIZE - sizeof(uint32_t)];
};

int main() {
    int sockfd, n;
    struct sockaddr_in server_addr;
    struct packet *send_buf, *recv_buf;
    struct timeval start_time, end_time;
    double elapsed_time, total_time, bandwidth;
    uint32_t i;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    inet_pton(AF_INET, SERVER_ADDRESS, &server_addr.sin_addr);
    server_addr.sin_port = htons(SERVER_PORT);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    printf("Internet Speed Test - Apocalypse Edition\n");
    printf("-----------------------------------------\n");

    gettimeofday(&start_time, NULL);

    send_buf = calloc(NUM_PACKETS, sizeof(struct packet));
    recv_buf = calloc(NUM_PACKETS, sizeof(struct packet));

    for (i = 0; i < NUM_PACKETS; i++) {
        send_buf[i].id = i;
        memset(send_buf[i].data, 'A', PACKET_SIZE - sizeof(uint32_t));

        if (send(sockfd, &send_buf[i], sizeof(struct packet), 0) < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }

        if (recv(sockfd, &recv_buf[i], sizeof(struct packet), 0) < 0) {
            perror("recv");
            exit(EXIT_FAILURE);
        }
    }

    gettimeofday(&end_time, NULL);

    elapsed_time = ((end_time.tv_sec * 1000) + end_time.tv_usec / 1000.0) -
                   ((start_time.tv_sec * 1000) + start_time.tv_usec / 1000.0);
    total_time = elapsed_time * NUM_PACKETS;
    bandwidth = (double) PACKET_SIZE * 8 / total_time;

    printf("Test Completed. Calculating results...\n");
    printf("-----------------------------------------\n");
    printf("Total time for %d packets: %f ms\n", NUM_PACKETS, elapsed_time);
    printf("Total data transfered: %d bytes\n", PACKET_SIZE * NUM_PACKETS);
    printf("Estimated bandwidth: %.2f bps\n", bandwidth);

    free(send_buf);
    free(recv_buf);
    close(sockfd);

    return EXIT_SUCCESS;
}