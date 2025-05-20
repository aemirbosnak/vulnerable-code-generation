//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <time.h>
#include <errno.h>

#define PING_SIZE 64
#define TIMEOUT_MS 1000

typedef struct {
    struct sockaddr_in addr;
    int seq;
    time_t sent_at;
} ping_req;

int sockfd;
struct sockaddr_in servaddr;
ping_req reqs[100];
int req_idx;
time_t last_sent;

void sigalrm_handler(int sig) {
    if (last_sent == 0) {
        last_sent = time(NULL);
        sendto(sockfd, &reqs[req_idx], PING_SIZE, 0, (struct sockaddr *) &servaddr, sizeof(servaddr));
        reqs[req_idx].sent_at = last_sent;
        req_idx = (req_idx + 1) % 100;
    }
}

double calc_rtt(ping_req *req) {
    time_t now = time(NULL);
    return difftime(now, req->sent_at) * 1000;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s hostname\n", argv[0]);
        exit(1);
    }
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    if (inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
        perror("inet_pton");
        exit(1);
    }

    struct sigaction sa;
    sa.sa_handler = sigalrm_handler;
    sa.sa_flags = SA_RESTART;
    sigaction(SIGALRM, &sa, NULL);
    alarm(1);

    while (1) {
        fd_set readfds;
        FD_ZERO(&readfds);
        FD_SET(sockfd, &readfds);
        struct timeval tv;
        tv.tv_sec = 0;
        tv.tv_usec = TIMEOUT_MS * 1000;
        int nfds = select(sockfd + 1, &readfds, NULL, NULL, &tv);
        if (nfds < 0) {
            perror("select");
            exit(1);
        } else if (nfds == 0) {
            continue;
        }
        if (FD_ISSET(sockfd, &readfds)) {
            ping_req resp;
            socklen_t len = sizeof(resp);
            if (recvfrom(sockfd, &resp, PING_SIZE, 0, (struct sockaddr *) &servaddr, &len) < 0) {
                perror("recvfrom");
                exit(1);
            }
            double rtt = calc_rtt(&resp);
            printf("seq=%d rtt=%f ms\n", resp.seq, rtt);
        }
    }

    close(sockfd);
    return 0;
}