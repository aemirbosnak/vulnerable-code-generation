//FormAI DATASET v1.0 Category: Network Ping Test ; Style: light-weight
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <time.h>
#include <errno.h>

#define MAX_BUFFER_SIZE 64
#define DEFAULT_PORT 80

int main(int argc, char *argv[]) {
    char *hostname;
    int status;

    if(argc < 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    hostname = argv[1];

    struct hostent *hostent = gethostbyname(hostname);

    if(hostent == NULL) {
        printf("Error resolving hostname : %s\n", argv[1]);
        return 1;
    }

    printf("Pinging %s [%s] with 32 bytes of data:\n\n", hostname, inet_ntoa(*(struct in_addr *) hostent->h_addr));

    int sock_raw = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if(sock_raw < 0) {
        printf("Socket Error: %s\n", strerror(errno));
        return 1;
    }

    struct sockaddr_in destination;
    destination.sin_family = AF_INET;
    memcpy(&destination.sin_addr, hostent->h_addr, hostent->h_length);

    char buffer[MAX_BUFFER_SIZE] = "Hello World";

    int sequence_number = 1;
    for(int i = 0; i < 4; i++) {
        clock_t timer_start = clock();

        if(sendto(sock_raw, buffer, sizeof(buffer), 0, (struct sockaddr *) &destination, sizeof(destination)) == -1) {
            printf("Error sending request: %s\n", strerror(errno));
            return 1;
        }

        struct timeval tv;
        tv.tv_sec = 2;
        tv.tv_usec = 500000;

        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock_raw, &read_fds);

        if(select(sock_raw + 1, &read_fds, NULL, NULL, &tv)) {
            char response_buffer[MAX_BUFFER_SIZE];
            struct sockaddr_in response_host;
            socklen_t response_host_length = sizeof(response_host);

            if(recvfrom(sock_raw, response_buffer, sizeof(response_buffer), 0, (struct sockaddr *) &response_host, &response_host_length) == -1) {
                printf("Error receiving response: %s\n", strerror(errno));
                return 1;
            }

            clock_t timer_end = clock();
            double timer_elapsed = ((double) (timer_end - timer_start)) / CLOCKS_PER_SEC;

            printf("Reply from %s (%s): bytes=%d time=%.0fms TTL=%d\n", argv[1], inet_ntoa(*(struct in_addr *) &destination.sin_addr.s_addr), sizeof(buffer), timer_elapsed * 1000, 64);
        }
        else {
            printf("Request timed out.\n");
        }

        sequence_number++;
        usleep(100000);
    }

    return 0;
}