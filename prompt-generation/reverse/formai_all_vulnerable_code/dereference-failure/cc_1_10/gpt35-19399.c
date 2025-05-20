//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <netinet/ip_icmp.h>
#include <netinet/tcp.h>
#include <netinet/udp.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <errno.h>
#include <netdb.h>

#define BUFF_SIZE 1024
#define TIMEOUT 2
#define MAX_RETRY 3

char *get_protocol_string(u_int8_t protocol) {
    switch (protocol) {
        case IPPROTO_ICMP: return "ICMP";
        case IPPROTO_TCP: return "TCP";
        case IPPROTO_UDP: return "UDP";
        default: return "Unknown Protocol";
    }
}

void sigint_handler(int signal) {
    printf("Exiting...\n");
    exit(0);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Usage: %s <IP address> <port>\n", argv[0]);
        exit(0);
    }

    signal(SIGINT, sigint_handler);

    struct addrinfo *result, *rp;
    struct addrinfo hints = {0};
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_protocol = IPPROTO_TCP;

    int status = getaddrinfo(argv[1], NULL, &hints, &result);
    if (status != 0) {
        printf("Error: %s\n", gai_strerror(status));
        exit(0);
    }

    int sockfd;
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sockfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (sockfd == -1) {
            continue;
        }
        if (connect(sockfd, rp->ai_addr, rp->ai_addrlen) != -1) {
            break;
        }
        close(sockfd);
    }
    freeaddrinfo(result);

    if (rp == NULL) {
        printf("Error: Could not connect\n");
        exit(0);
    }

    int retry = 0;
    while (1) {
        char data[BUFF_SIZE] = {0};
        snprintf(data, BUFF_SIZE-1, "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", argv[1]);

        ssize_t send_status = send(sockfd, data, strlen(data), 0);
        if (send_status == -1) {
            printf("Error: Could not send data - %s\n", strerror(errno));
            exit(0);
        }

        struct timeval tv;
        tv.tv_sec = TIMEOUT;
        tv.tv_usec = 0;

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sockfd, &read_fds);

        int select_status = select(sockfd + 1, &read_fds, NULL, NULL, &tv);
        if (select_status == -1) {
            printf("Error: Select failed - %s\n", strerror(errno));
            exit(0);
        } else if (select_status == 0) {
            printf("Error: Timeout - %d attempts remaining\n", MAX_RETRY - retry);
            retry++;
            if (retry == MAX_RETRY) {
                printf("Maximum attempts reached. Exiting...\n");
                exit(0);
            }
        } else {
            char recv_data[BUFF_SIZE] = {0};
            ssize_t recv_status = recv(sockfd, &recv_data, BUFF_SIZE - 1, 0);
            if (recv_status == -1) {
                printf("Error: Could not receive data - %s\n", strerror(errno));
                exit(0);
            } else if (recv_status == 0) {
                printf("Error: Connection closed by remote host\n");
                exit(0);
            }
            printf("\nQoS of %s on port %s: \n", argv[1], argv[2]);
            printf("Protocol: %s\n", get_protocol_string(rp->ai_protocol));
            printf("Packet Size: %zd bytes\n", recv_status);
            printf("Content: %s\n", recv_data);
            retry = 0;
        }
        sleep(1);
    }
    return 0;
}