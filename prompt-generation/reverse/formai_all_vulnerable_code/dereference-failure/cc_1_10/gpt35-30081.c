//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define BUF_SIZE 512

void print_usage(char *name);
void map_topology(char *ip, int port);
int check_packet(const char *buf, int len, struct sockaddr_in *addr);

int main(int argc, char *argv[])
{
    if (argc < 3) {
        print_usage(argv[0]);
        return 1;
    }

    char *ip = argv[1];
    int port = atoi(argv[2]);

    printf("Mapping topology @ %s:%d\n", ip, port);
    map_topology(ip, port);

    printf("Done.\n");
    return 0;
}

void print_usage(char *name)
{
    printf("Usage: %s [IP address] [port number]\n", name);
}

void map_topology(char *ip, int port)
{
    struct sockaddr_in addr;

    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd == -1) {
        perror("socket()");
        return;
    }

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = htonl(INADDR_ANY);
    addr.sin_port = htons(0);
    if (bind(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("bind()");
        close(sockfd);
        return;
    }

    int ttl = 1;
    setsockopt(sockfd, IPPROTO_IP, IP_MULTICAST_TTL, &ttl, sizeof(ttl));

    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    if (inet_aton(ip, &addr.sin_addr) == 0) {
        fprintf(stderr, "Invalid IP address: %s\n", ip);
        close(sockfd);
        return;
    }

    char buf[BUF_SIZE];
    socklen_t addrlen = sizeof(struct sockaddr_in);
    int len;

    if (sendto(sockfd, buf, 0, 0, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("sendto()");
        close(sockfd);
        return;
    }

    printf("Waiting for response...\n");

    while ((len = recvfrom(sockfd, buf, BUF_SIZE, 0, (struct sockaddr *)&addr, &addrlen)) != -1) {
        if (check_packet(buf, len, &addr) == 1) {
            printf("Received response from %s\n", inet_ntoa(addr.sin_addr));
        }
    }

    close(sockfd);
}

int check_packet(const char *buf, int len, struct sockaddr_in *addr)
{
    if (len < 3) { return 0; }
    if (buf[0] != 0xEE || buf[1] != 0xEE || buf[2] != 0xEE) { return 0; }

    printf("%s\n", inet_ntoa(addr->sin_addr));

    while (len >= 6) {
        int type = (int)buf[3], size = (int)buf[4];
        if (len < size + 6) { return 1; }

        switch (type) {
            case 1: printf("\tHostname: %.*s\n", size, buf+5); break;
            case 2: printf("\tMAC Address: %02X:%02X:%02X:%02X:%02X:%02X\n",buf[5],buf[6],buf[7],buf[8],buf[9],buf[10]); break;
            case 3: printf("\tIP Address: %d.%d.%d.%d\n",buf[5],buf[6],buf[7],buf[8]); break;
            default: printf("\tType %d, Length %d\n", type, size); break;
        }

        buf += size + 6;
        len -= size + 6;
    }

    return 1;
}