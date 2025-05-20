//FormAI DATASET v1.0 Category: Network Ping Test ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define PING_PKT_S 64
#define PORT_NO 0
#define PING_SLEEP_RATE 1000000
#define RECV_TIMEOUT 1

int pingcont = 0;

// Function to calculate checksum
unsigned short checksum(void *b, int len)
{
    unsigned short *buf = b;
    unsigned int sum = 0;
    unsigned short result;

    for (sum = 0; len > 1; len -= 2)
        sum += *buf++;

    if (len == 1)
        sum += *(unsigned char *)buf;

    sum = (sum >> 16) + (sum & 0xFFFF);
    sum += (sum >> 16);
    result = ~sum;
    return result;
}

// Interrupt handler for ping program
void intHandler(int dummy)
{
    printf("\n--- ping statistics ---\n");
    printf("%d packets transmitted, %d packets received, %d%% packet loss\n", pingcont, pingcont, 0);
    exit(0);
}

// Send pinging requests repeatedly to given IP address
void send_ping(int ping_sockfd, struct sockaddr_in *ping_addr, char *ping_ip)
{
    char ping_pkt[PING_PKT_S];
    int dest_addr_len = sizeof(struct sockaddr_in), sent, recv, recv_status;
    struct timespec time_start, time_end, tfs, tfe;
    struct timeval tv_out;
    tv_out.tv_sec = RECV_TIMEOUT;
    tv_out.tv_usec = 0;
    pingcont = 0;

    signal(SIGINT, intHandler);

    memset(&ping_pkt, 0, sizeof(ping_pkt));
    memset(&tfs, 0, sizeof(tfs));
    memset(&tfe, 0, sizeof(tfe));

    while (1)
    {
        // Generate ping request packet
        clock_gettime(CLOCK_MONOTONIC, &time_start);
        *((unsigned short *)ping_pkt) = htons(0x0800);
        memset(ping_pkt + 2, 0x55, PING_PKT_S - 4);
        *((unsigned short *)(ping_pkt + PING_PKT_S - 4)) = htons(checksum(ping_pkt, PING_PKT_S));

        // Send the ping request packet
        sendto(ping_sockfd, ping_pkt, sizeof(ping_pkt), 0, (struct sockaddr *)ping_addr, sizeof(struct sockaddr));
        pingcont++;

        // Receive the ping response packet
        setsockopt(ping_sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char *)&tv_out, sizeof tv_out);
        memset(&ping_pkt, 0, sizeof(ping_pkt));
        recv_status = recvfrom(ping_sockfd, ping_pkt, sizeof(ping_pkt), 0, (struct sockaddr *)ping_addr, &dest_addr_len);

        if (recv_status >= 0)
        {
            clock_gettime(CLOCK_MONOTONIC, &time_end);

            double elapsedTime = (time_end.tv_nsec - time_start.tv_nsec) / 1000000.0;
            printf("ping to %s, seq = %d, time = %fms\n", ping_ip, pingcont, elapsedTime);

            sleep(1);
        }
        else
        {
            sleep(1);
            continue;
        }
    }
}

int main(int argc, char *argv[])
{
    int ping_sockfd;
    char *ping_ip;
    struct sockaddr_in ping_addr;
    struct hostent *host;

    if (argc < 2 || argc > 2)
    {
        printf("\nError: Invalid arguments\n");
        printf("\nUsage: %s hostname/IP address\n", argv[0]);
        return 0;
    }

    ping_ip = argv[1];

    memset(&ping_addr, 0, sizeof(ping_addr));
    ping_addr.sin_family = AF_INET;

    if ((ping_sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP)) == -1)
    {
        perror("\nSocket error");
        return 0;
    }

    if (inet_aton(ping_ip, &ping_addr.sin_addr) == 0)
    {
        host = gethostbyname(ping_ip);

        if (host == NULL)
        {
            perror("\nCouldn't resolve hostname");
            return 0;
        }

        memcpy(&(ping_addr.sin_addr), host->h_addr, host->h_length);
    }

    printf("\nPING %s:\n", ping_ip);

    // Send the pinging requests repeatedly
    send_ping(ping_sockfd, &ping_addr, ping_ip);
    return 0;
}