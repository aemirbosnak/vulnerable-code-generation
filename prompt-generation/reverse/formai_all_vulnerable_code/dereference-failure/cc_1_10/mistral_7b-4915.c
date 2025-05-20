//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUF_SIZE 1024
#define TIMEOUT 500
#define PACKET_SIZE 64

void print_usage(char *name) {
    printf("Usage: %s [IP_ADDRESS]\n", name);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        exit(1);
    }

    const char *ip_address = argv[1];
    struct hostent *host = gethostbyname(ip_address);

    if (!host) {
        herror("gethostbyname");
        exit(2);
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(3);
    }

    struct sockaddr_in serv_addr;
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(0);
    serv_addr.sin_addr = *((struct in_addr *)host->h_addr);

    char packet[PACKET_SIZE] = "0x" ""; /* Fill with random data */
    int sent_bytes = sendto(sockfd, packet, PACKET_SIZE, 0,
                            (struct sockaddr *)&serv_addr, sizeof(serv_addr));

    if (sent_bytes < 0) {
        perror("sendto");
        close(sockfd);
        exit(4);
    }

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    fd_set master_fds, read_fds;
    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);
    FD_SET(sockfd, &master_fds);

    int max_fd = sockfd;

    while (1) {
        read_fds = master_fds;
        int select_result = select(max_fd + 1, &read_fds, NULL, NULL, NULL);

        if (select_result < 0) {
            perror("select");
            close(sockfd);
            exit(5);
        }

        if (FD_ISSET(sockfd, &read_fds)) {
            int received_bytes;
            socklen_t addr_len = sizeof(serv_addr);

            received_bytes = recvfrom(sockfd, packet, PACKET_SIZE, 0,
                                      (struct sockaddr *)&serv_addr, &addr_len);

            if (received_bytes > 0) {
                gettimeofday(&end_time, NULL);
                long long elapsed_time = ((end_time.tv_sec * 1000000 + end_time.tv_usec)
                                          - (start_time.tv_sec * 1000000 + start_time.tv_usec));

                printf("Response received from %s in %lld us.\n",
                       inet_ntoa(serv_addr.sin_addr), elapsed_time);
                break;
            }
        }

        usleep(TIMEOUT);
    }

    close(sockfd);
    return 0;
}