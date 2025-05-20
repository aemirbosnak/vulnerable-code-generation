//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/tcp.h>
#include <time.h>

#define BUFSIZE 1024

typedef struct {
    struct in_addr ipaddr;
    uint16_t port;
} EndPoint;

typedef struct {
    uint16_t pkt_id;
    uint8_t ttl;
    uint8_t tos;
    uint64_t timestamp;
} Packet;

typedef struct {
    EndPoint src_ep;
    EndPoint dst_ep;
    uint32_t num_pkts;
    Packet pkts[BUFSIZE];
} Flow;

Flow flows[BUFSIZE];
uint32_t num_flows = 0;

void error(char *msg) {
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[]) {
    int sockfd, portno, n, on = 1;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[BUFSIZE], ipstr[INET_ADDRSTRLEN];
    uint16_t pkt_id = 0;
    uint8_t ttl = 64, tos = 0;
    uint64_t timestamp = 0;
    time_t curr_time;
    struct tm *tm;
    double rtt = 0.0;
    int num_bytes_sent, num_bytes_received;
    EndPoint src_ep, dst_ep;
    Flow flow;
    uint32_t i;

    if (argc < 3) {
        fprintf(stderr,"usage: %s <hostname> <port>\n", argv[0]);
        exit(1);
    }

    portno = atoi(argv[2]);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
        error("Unable to create socket");
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    server = gethostbyname(argv[1]);

    if (server == NULL) {
        error("Unable to resolve hostname");
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(portno);
    memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &on, sizeof(on)) < 0) {
        error("Unable to set SO_REUSEADDR option on socket");
    }

    if (setsockopt(sockfd, IPPROTO_TCP, TCP_NODELAY, &on, sizeof(on)) < 0) {
        error("Unable to set TCP_NODELAY option on socket");
    }

    src_ep.ipaddr.s_addr = htonl(INADDR_ANY);
    src_ep.port = htons(0);

    if (bind(sockfd, (struct sockaddr *) &src_ep, sizeof(src_ep)) < 0) {
        error("Unable to bind socket");
    }

    printf("Listening on %s:%d\n", inet_ntop(AF_INET, &src_ep.ipaddr, ipstr, INET_ADDRSTRLEN), ntohs(src_ep.port));

    while(1) {
        memset(buffer, 0, BUFSIZE);
        num_bytes_sent = sendto(sockfd, buffer, BUFSIZE, 0, (struct sockaddr *) &serv_addr, sizeof(serv_addr));

        if (num_bytes_sent < 0) {
            error("Unable to send packet");
        }

        curr_time = time(NULL);
        tm = localtime(&curr_time);
        timestamp = (uint64_t) mktime(tm);

        flow.src_ep.ipaddr.s_addr = htonl(INADDR_ANY);
        flow.src_ep.port = htons(0);
        flow.dst_ep.ipaddr = serv_addr.sin_addr;
        flow.dst_ep.port = serv_addr.sin_port;
        flow.num_pkts = 0;

        for (i = 0; i < BUFSIZE; ++i) {
            flow.pkts[i].pkt_id = pkt_id++;
            flow.pkts[i].ttl = ttl;
            flow.pkts[i].tos = tos;
            flow.pkts[i].timestamp = timestamp;
            flow.num_pkts++;

            num_bytes_received = recvfrom(sockfd, buffer, BUFSIZE, 0, (struct sockaddr *) NULL, NULL);

            if (num_bytes_received < 0) {
                error("Unable to receive packet");
            }

            curr_time = time(NULL);
            tm = localtime(&curr_time);
            rtt = difftime(mktime(tm), timestamp);
            printf("%s -> %s: pkt_id=%d, ttl=%d, tos=%d, timestamp=%lu, rtt=%f\n", inet_ntop(AF_INET, &flow.src_ep.ipaddr, ipstr, INET_ADDRSTRLEN), inet_ntop(AF_INET, &flow.dst_ep.ipaddr, ipstr, INET_ADDRSTRLEN), flow.pkts[i].pkt_id, flow.pkts[i].ttl, flow.pkts[i].tos, flow.pkts[i].timestamp, rtt);
            timestamp = (uint64_t) mktime(tm);
        }

        flows[num_flows++] = flow;
        usleep(100000);
    }

    close(sockfd);

    return 0;
}