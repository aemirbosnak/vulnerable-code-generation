//FormAI DATASET v1.0 Category: Network Ping Test ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <sys/time.h>

#define PING_PORT_NUMBER 0
#define PING_MSG_SIZE 64
#define PING_TIMEOUT_SECONDS 1

typedef struct PingReply {
    int seqNum;
    struct timeval timestamp;
} PingReply;

int seqNum = 0;

bool isEchoReply(unsigned char *buffer, int seqNum) {
    int type = buffer[0];
    int code = buffer[1];
    if (type == 0 && code == 0) {
        int replySeqNum = buffer[6] << 8 | buffer[7];
        if (replySeqNum == seqNum) {
            return true;
        }
    }
    return false;
}

PingReply doPing(struct sockaddr_in *addr) {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    char msg[PING_MSG_SIZE];
    memset(&msg, 0, sizeof(msg));
    msg[0] = 8; // echo request
    msg[5] = seqNum >> 8; // high byte of sequence number
    msg[6] = seqNum & 0xff; // low byte of sequence number
    
    struct timeval start;
    gettimeofday(&start, NULL);

    int bytesSent = sendto(sock, &msg, sizeof(msg), 0, (struct sockaddr *) addr, sizeof(*addr));
    if (bytesSent < 0) {
        perror("sendto");
        exit(EXIT_FAILURE);
    }

    fd_set rfds;
    FD_ZERO(&rfds);
    FD_SET(sock, &rfds);

    struct timeval timeout;
    timeout.tv_sec = PING_TIMEOUT_SECONDS;
    timeout.tv_usec = 0;

    if (select(sock + 1, &rfds, NULL, NULL, &timeout) > 0) {
        struct sockaddr_in senderAddr;
        socklen_t senderAddrLen = sizeof(senderAddr);
        unsigned char buffer[2048];
        int bytesReceived = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr *) &senderAddr, &senderAddrLen);
        if (bytesReceived < 0) {
            perror("recvfrom");
            exit(EXIT_FAILURE);
        }
        struct timeval end;
        gettimeofday(&end, NULL);
        if (isEchoReply(buffer, seqNum)) {
            PingReply reply = {
                .seqNum = seqNum,
                .timestamp = end
            };
            return reply;
        }
    }

    PingReply reply = {
        .seqNum = seqNum,
        .timestamp.tv_sec = 0,
        .timestamp.tv_usec = 0
    };
    return reply;
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <hostname_or_ip>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    char *host = argv[1];
    struct hostent *hostent = gethostbyname(host);
    if (hostent == NULL) {
        fprintf(stderr, "Error: invalid hostname %s\n", host);
        exit(EXIT_FAILURE);
    }
    printf("Pinging %s ...\n", hostent->h_name);

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PING_PORT_NUMBER);
    addr.sin_addr = *(struct in_addr *) hostent->h_addr_list[0];

    int numPingsReceived = 0;
    int numPingsSent = 0;

    while (true) {
        seqNum++;
        PingReply reply = doPing(&addr);
        if (reply.timestamp.tv_sec != 0 || reply.timestamp.tv_usec != 0) {
            long usec = (reply.timestamp.tv_usec - reply.timestamp.tv_usec) % 1000000;
            printf("Ping reply from %s: icmp_seq=%d time=%.3fms\n",
                inet_ntoa(addr.sin_addr), reply.seqNum, usec / 1000.0);
            numPingsReceived++;
        } else {
            printf("No reply from %s\n", inet_ntoa(addr.sin_addr));
        }
        numPingsSent++;

        sleep(1);
    }

    return 0;
}