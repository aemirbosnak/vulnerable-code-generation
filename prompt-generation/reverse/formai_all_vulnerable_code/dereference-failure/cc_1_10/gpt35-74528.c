//FormAI DATASET v1.0 Category: Firewall ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/types.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <signal.h>

/* global variables */
int sockfd;
struct sockaddr_in servaddr;
fd_set readfd;
char* keyword = "attack";

/* function prototypes */
void sigint_handler(int sig);
void die_with_error(char* error_message);
void check_packet(char* buffer, int size, struct sockaddr_in src);

int main(int argc, char** argv) {
    // check argument validity
    if (argc != 2) {
        printf("Usage: %s <port_number>\n", argv[0]);
        exit(1);
    }

    // create socket
    sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_TCP);
    if (sockfd < 0) {
        die_with_error("Error creating socket");
    }

    // set server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(atoi(argv[1]));

    // bind socket to server address
    if (bind(sockfd, (struct sockaddr*) &servaddr, sizeof(servaddr)) < 0) {
        die_with_error("Error binding socket");
    }

    // set signal handler for SIGINT
    signal(SIGINT, sigint_handler);
    
    // start listening for incoming packets
    while (1) {
        FD_ZERO(&readfd);
        FD_SET(sockfd, &readfd);
        if (select(sockfd + 1, &readfd, NULL, NULL, NULL) > 0) {
            if (FD_ISSET(sockfd, &readfd)) {
                char buffer[65536];
                struct sockaddr_in src_addr;
                socklen_t addrlen = sizeof(src_addr);
                int recvlen = recvfrom(sockfd, buffer, sizeof(buffer), 0, (struct sockaddr*) &src_addr, &addrlen);
                if (recvlen > 0) {
                    check_packet(buffer, recvlen, src_addr);
                }
            }
        }
    }

    // close socket and exit
    close(sockfd);
    return 0;
}

/* function to handle SIGINT signal */
void sigint_handler(int sig) {
    printf("Interrupted by user. Closing socket...\n");
    close(sockfd);
    exit(0);
}

/* function to print error message and exit */
void die_with_error(char* error_message) {
    perror(error_message);
    exit(1);
}

/* function to check incoming packets */
void check_packet(char* buffer, int size, struct sockaddr_in src) {
    struct iphdr* ip_header;
    struct tcphdr* tcp_header;
    char* payload;

    // parse IP header
    ip_header = (struct iphdr*) buffer;

    // check if TCP packet
    if (ip_header->protocol == IPPROTO_TCP) {
        // parse TCP header
        tcp_header = (struct tcphdr*) (buffer + ip_header->ihl * 4);

        // get payload (if any)
        payload = buffer + ip_header->ihl * 4 + tcp_header->doff * 4;

        // check if payload contains keyword
        if (strstr(payload, keyword) != NULL) {
            printf("Attack detected from %s\n", inet_ntoa(src.sin_addr));

            // block the attacker's IP address
            char* cmd = (char*) malloc(1024);
            sprintf(cmd, "iptables -A INPUT -s %s -j DROP", inet_ntoa(src.sin_addr));
            system(cmd);
            free(cmd);
        }
    }
}