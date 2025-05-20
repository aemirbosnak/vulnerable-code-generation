//FormAI DATASET v1.0 Category: Network Ping Test ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/ip_icmp.h>
#include <sys/time.h>
#include <unistd.h>

int main(int argc, char** argv)
{
    char* host = NULL;
    struct hostent* host_info = NULL;
    struct sockaddr_in sock_addr;
    int sock_fd = -1;
    struct icmphdr icmp_hdr;
    int num_pings = 0;
    int num_recv = 0;
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if (argc != 2) {
        printf("Usage: %s <host>\n", argv[0]);
        return 1;
    }

    host = argv[1];
    host_info = gethostbyname(host);

    if (!host_info) {
        printf("Error: could not resolve '%s'\n", host);
        return 1;
    }

    sock_fd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);

    if (sock_fd < 0) {
        printf("Error: could not create socket\n");
        return 1;
    }

    memset(&sock_addr, 0, sizeof(sock_addr));
    sock_addr.sin_family = AF_INET;
    sock_addr.sin_port = 0;
    memcpy(&sock_addr.sin_addr, host_info->h_addr, sizeof(struct in_addr));

    memset(&icmp_hdr, 0, sizeof(icmp_hdr));
    icmp_hdr.type = ICMP_ECHO;
    icmp_hdr.code = 0;
    icmp_hdr.checksum = htons(~(ICMP_ECHO << 8));

    for (num_pings = 0; num_pings < 10; num_pings++) {
        struct timeval start_time;
        struct timeval curr_time;
        socklen_t addr_len = sizeof(sock_addr);
        fd_set read_fds;

        if (sendto(sock_fd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr*)&sock_addr, sizeof(sock_addr)) < 0) {
            printf("Error: could not send ping\n");
            return 1;
        }

        gettimeofday(&start_time, NULL);

        FD_ZERO(&read_fds);
        FD_SET(sock_fd, &read_fds);

        if (select(sock_fd + 1, &read_fds, NULL, NULL, &timeout) <= 0) {
            printf("Ping timed out\n");
            continue;
        }

        if (recvfrom(sock_fd, &icmp_hdr, sizeof(icmp_hdr), 0, (struct sockaddr*)&sock_addr, &addr_len) < 0) {
            printf("Error: could not receive ping reply\n");
            return 1;
        }

        gettimeofday(&curr_time, NULL);

        printf("Received ping reply from %s in %ld ms\n", host, ((curr_time.tv_sec - start_time.tv_sec) * 1000) + ((curr_time.tv_usec - start_time.tv_usec) / 1000));
        num_recv++;
        sleep(1);
    }

    printf("Ping test complete: %d pings sent, %d pings received\n", num_pings, num_recv);
    close(sock_fd);
    return 0;
}