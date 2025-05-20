//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>

#define MAX_PACKET_SIZE 1500
#define MAX_NUM_TRIALS 10

int ping_host(const char *host, int port) {
    struct hostent *server;
    struct sockaddr_in address;
    int sockfd, n;
    char packet[MAX_PACKET_SIZE];
    int num_tries = MAX_NUM_TRIALS;

    server = gethostbyname(host);
    if (server == NULL) {
        printf("Hostname could not be resolved\n");
        return -1;
    }

    address.sin_family = AF_INET;
    address.sin_port = htons(port);
    bcopy((char *)server->h_addr, (char *)&address.sin_addr.s_addr, server->h_length);

    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sockfd < 0) {
        printf("Error opening socket\n");
        return -1;
    }

    while (num_tries-- > 0) {
        if (sendto(sockfd, packet, MAX_PACKET_SIZE, 0, (const struct sockaddr *)&address, sizeof(address)) < 0) {
            perror("sendto");
            break;
        }

        n = recvfrom(sockfd, packet, MAX_PACKET_SIZE, 0, NULL, NULL);
        if (n < 0) {
            perror("recvfrom");
            break;
        }

        if (packet[8] == 0x11 && packet[9] == 0x00 && packet[10] == 0x01) {
            printf("Ping successful to %s:%d\n", host, port);
            break;
        }
    }

    close(sockfd);
    return 0;
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <host> <port>\n", argv[0]);
        return 1;
    }

    ping_host(argv[1], atoi(argv[2]));
    return 0;
}