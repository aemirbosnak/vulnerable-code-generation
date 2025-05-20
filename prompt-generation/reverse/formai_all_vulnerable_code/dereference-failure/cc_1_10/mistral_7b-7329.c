//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>

#define SERVER_PORT 80
#define BUFFER_SIZE 1024
#define PACKET_SIZE 64
#define TIMEOUT 500

typedef struct {
    char ip[INET_ADDRSTRLEN];
    int ttl;
    int rtt;
} target_t;

void die(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <target>\n", argv[0]);
        return EXIT_FAILURE;
    }

    target_t target;
    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_IP);
    if (sockfd == -1) die("socket");

    struct hostent *he = gethostbyname(argv[1]);
    if (!he) {
        herror("gethostbyname");
        close(sockfd);
        return EXIT_FAILURE;
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    inet_pton(AF_INET, he->h_addr_list[0], &server_addr.sin_addr);

    char icmp_echo[] = "\x08\x00\x2e\x00\xff\xff\xff\xff\x00\x54\x78\x69\x6e\x20\x67\x65\x6e\x00";

    int bytes_sent;
    int timeout = alarm(TIMEOUT / 1000.0);

    for (int i = 0; i < 4; i++) {
        target.ttl = 64;
        bytes_sent = sendto(sockfd, icmp_echo, sizeof(icmp_echo), 0,
                            (struct sockaddr *)&server_addr, sizeof(server_addr));
        if (bytes_sent == -1) {
            perror("sendto");
            close(sockfd);
            return EXIT_FAILURE;
        }

        char buffer[BUFFER_SIZE];
        int bytes_received = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);
        alarm(0);

        if (bytes_received > 0) {
            int rtt = (int)(time(NULL) - timeout);
            if (rtt > 0) {
                target.rtt = rtt;
                strcpy(target.ip, inet_ntoa(*(struct in_addr *) &server_addr.sin_addr));
                printf("\033[32m[+] Target: %s\tTTL: %d\tRTT: %dms\033[0m\n", target.ip, target.ttl, target.rtt);
            } else {
                printf("\033[31m[!] Error: Timeout\033[0m\n");
            }
            i--; // retry if successful
        } else {
            printf("\033[31m[!] Error: No response\033[0m\n");
            close(sockfd);
            return EXIT_FAILURE;
        }

        if (i < 3) {
            target.ttl--;
            if (target.ttl < 1) target.ttl = 1;
        }
    }

    close(sockfd);
    return EXIT_SUCCESS;
}