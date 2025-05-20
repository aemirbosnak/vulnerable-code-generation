//FormAI DATASET v1.0 Category: Network Ping Test ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <unistd.h>

#define MAX_HOST_LENGTH 512
#define MAX_PACKET_LENGTH 65536
#define DEFAULT_PORT 80
#define MAX_PING_COUNT 10

void printUsage() {
    printf("Usage: network-ping-test <hostname> [-p port]\n");
    exit(1);
}

int main(int argc, char *argv[]) {
    char *hostname;
    int port = DEFAULT_PORT;
    int i, j;
    struct hostent *hostinfo;
    struct timeval send_time, recv_time, elapsed_time;
    struct sockaddr_in server_address;
    int sockfd;
    char packet[MAX_PACKET_LENGTH], *p;
    int ping_count = 0;

    if (argc < 2) {
        printUsage();
    }

    hostname = argv[1];

    for (i = 2; i < argc; i++) {
        if (strcmp(argv[i], "-p") == 0) {
            if (i+1 >= argc) {
                printUsage();
            }
            port = atoi(argv[i+1]);
            if (port <= 0) {
                printf("Invalid port specified: %s\n", argv[i+1]);
                printUsage();
            }
        }
    }

    hostinfo = gethostbyname(hostname);
    if (hostinfo == NULL) {
        printf("Cannot resolve hostname: %s\n", hostname);
        exit(1);
    }

    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    memcpy(&server_address.sin_addr.s_addr, hostinfo->h_addr, hostinfo->h_length);
    server_address.sin_port = htons(port);

    sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        perror("Could not create socket");
        exit(1);
    }

    memset(packet, 0, sizeof(packet));
    p = packet;
    for (i = 0; i < sizeof(packet) - 1; i++) {
        *p++ = i % 128;
    }

    printf("Pinging %s:%d\n", inet_ntoa(server_address.sin_addr), port);

    while (ping_count < MAX_PING_COUNT) {
        gettimeofday(&send_time, NULL);

        if (sendto(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
            perror("sendto failed");
            exit(1);
        }

        memset(packet, 0, sizeof(packet));

        socklen_t len = sizeof(server_address);
        if (recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *)&server_address, &len) == -1) {
            perror("recvfrom failed");
            exit(1);
        }

        gettimeofday(&recv_time, NULL);

        timersub(&recv_time, &send_time, &elapsed_time);
        int elapsed_ms = elapsed_time.tv_sec * 1000 + elapsed_time.tv_usec / 1000;

        printf("Received reply from %s:%d in %dms (payload size=%d bytes)\n", 
            inet_ntoa(server_address.sin_addr), 
            ntohs(server_address.sin_port), 
            elapsed_ms, 
            len);

        ping_count++;
    }

    close(sockfd);

    return 0;
}