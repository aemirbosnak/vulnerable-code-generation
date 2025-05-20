//FormAI DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/ip_icmp.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define PACKET_SIZE 64
#define MAX_PACKET_SIZE 65536
#define MAX_WAIT_TIME 5

struct Packet
{
    struct icmphdr hdr;
    char msg[PACKET_SIZE - sizeof(struct icmphdr)];
};

int ping(int sock, struct sockaddr *ping_addr, int count)
{
    int i, pack_count = 0, success = 0;
    struct Packet packet;
    struct sockaddr_in from;
    socklen_t fromlen = sizeof(from);
    struct timeval timeout;
    fd_set readfds;

    memset(&packet, 0, sizeof(packet));
    packet.hdr.type = ICMP_ECHO;
    packet.hdr.un.echo.id = getpid();

    for (i = 0; i < count || count == -1; i++)
    {
        pack_count++;
        packet.hdr.un.echo.sequence = pack_count;

        gettimeofday(&timeout, NULL);
        sendto(sock, &packet, sizeof(packet), 0, ping_addr, sizeof(*ping_addr));

        FD_ZERO(&readfds);
        FD_SET(sock, &readfds);

        timeout.tv_sec = MAX_WAIT_TIME;
        timeout.tv_usec = 0;

        if (select(sock + 1, &readfds, NULL, NULL, &timeout) > 0)
        {
            ssize_t packet_size = recvfrom(sock, &packet, sizeof(packet), 0, (struct sockaddr *)&from, &fromlen);
            if (packet_size >= sizeof(struct icmphdr))
            {
                success++;
                printf("Ping successful\n");
            }
        }
        else
        {
            printf("Ping timed out\n");
        }

        sleep(1);
    }

    return success;
}

int main(int argc, char *argv[])
{
    int sock, count;
    char *hostname, ip[100];
    struct hostent *host;
    struct sockaddr_in ping_addr;

    if (argc != 3)
    {
        printf("Usage: %s hostname count\n", argv[0]);
        return -1;
    }

    hostname = argv[1];
    count = atoi(argv[2]);

    if ((host = gethostbyname(hostname)) == NULL)
    {
        printf("Error: Invalid hostname\n");
        return -1;
    }

    sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0)
    {
        printf("Error: Unable to create socket\n");
        return -1;
    }

    ping_addr.sin_family = AF_INET;
    ping_addr.sin_addr = *((struct in_addr *)host->h_addr);

    printf("Pinging %s [%s] with %d bytes of data:\n", hostname, inet_ntoa(ping_addr.sin_addr), PACKET_SIZE);

    int success = ping(sock, (struct sockaddr *)&ping_addr, count);

    printf("\nPing statistics for %s:\n", hostname);
    printf("\tPackets: Sent = %d, Received = %d, Lost = %d (%.2f%% loss)\n", count, success, count - success, ((count - success) * 1.0 / count) * 100);

    return 0;
}