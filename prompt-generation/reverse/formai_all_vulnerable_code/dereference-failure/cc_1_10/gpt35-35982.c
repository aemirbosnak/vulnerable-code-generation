//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>

#define PORT 80
#define HOST "google.com"
#define TIMEOUT 5
#define BUFFER_SIZE 4096

volatile sig_atomic_t flag = 0;

void sig_handler(int sig) {
    flag = 1;
}

int create_socket(char *host, int port) {
    struct hostent *he;
    struct sockaddr_in server_addr;
    int sockfd;

    if ((he = gethostbyname(host)) == NULL) {
        return -1;
    }

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        return -1;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr = *((struct in_addr *)he->h_addr);
    memset(&(server_addr.sin_zero), 0, 8);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr)) == -1) {
        return -1;
    }

    return sockfd;
}

float calculate_packet_loss(int sockfd) {
    char buffer[BUFFER_SIZE];
    int total_packets = 0;
    int lost_packets = 0;

    struct timeval tv;
    tv.tv_sec = TIMEOUT;
    tv.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) < 0) {
        return -1;
    }

    for (int i = 0; i < 10; i++) {
        memset(buffer, 0, BUFFER_SIZE);
        sprintf(buffer, "PING %d\n", i);
        int bytes_sent = send(sockfd, buffer, strlen(buffer), 0);

        if (bytes_sent == -1) {
            return -1;
        }

        total_packets++;

        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            lost_packets++;
        }
    }

    return (float)(lost_packets * 100) / total_packets;
}

float calculate_bandwidth(int sockfd) {
    char buffer[BUFFER_SIZE];
    int total_bytes_sent = 0;
    int total_bytes_received = 0;

    struct timeval start_tv, end_tv;
    start_tv.tv_sec = end_tv.tv_sec = TIMEOUT;
    start_tv.tv_usec = end_tv.tv_usec = 0;

    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &start_tv, sizeof(start_tv)) < 0) {
        return -1;
    }

    if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, &start_tv, sizeof(start_tv)) < 0) {
        return -1;
    }

    gettimeofday(&start_tv, NULL);

    do {
        memset(buffer, 'a', BUFFER_SIZE);
        int bytes_sent = send(sockfd, buffer, BUFFER_SIZE, 0);

        if (bytes_sent == -1) {
            return -1;
        }

        total_bytes_sent += bytes_sent;

        if (recv(sockfd, buffer, BUFFER_SIZE, 0) == -1) {
            return -1;
        }

        total_bytes_received += BUFFER_SIZE;

        gettimeofday(&end_tv, NULL);
    } while (end_tv.tv_sec - start_tv.tv_sec < TIMEOUT);

    long int elapsed_time_us = (end_tv.tv_sec - start_tv.tv_sec) * 1000000 + (end_tv.tv_usec - start_tv.tv_usec);
    float bandwidth = (float)(total_bytes_sent + total_bytes_received) * 8 / elapsed_time_us;

    return bandwidth;
}

int main() {
    signal(SIGINT, sig_handler);

    int sockfd = create_socket(HOST, PORT);

    if (sockfd < 0) {
        perror("Couldn't connect to the remote host");
        exit(EXIT_FAILURE);
    }

    while (!flag) {
        float packet_loss = calculate_packet_loss(sockfd);
        float bandwidth = calculate_bandwidth(sockfd);

        printf("Packet Loss: %.2f%%\n", packet_loss);
        printf("Bandwidth: %.2f Mbps\n", bandwidth / 1000000);

        sleep(1);
    }

    close(sockfd);

    return 0;
}