//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>
#include <time.h>

#define BUFSIZE 1024

volatile sig_atomic_t stop;

void handle_signal(int sig) {
    stop = 1;
}

void check_uptime(char* host) {
    struct addrinfo hints, *result;
    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_DGRAM;
    hints.ai_protocol = IPPROTO_UDP;

    if (getaddrinfo(host, "http", &hints, &result) != 0) {
        printf("Error: invalid host\n");
        exit(1);
    }

    int sockfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sockfd < 0) {
        printf("Error: could not create socket\n");
        exit(1);
    }

    char* message = "ping";
    if (sendto(sockfd, message, strlen(message), 0, result->ai_addr, result->ai_addrlen) < 0) {
        printf("Error: could not send ping\n");
        exit(1);
    }

    char buffer[BUFSIZE];
    socklen_t addrlen = sizeof(struct sockaddr_in);
    struct timeval timeout = {0, 100000}; // set timeout to 100ms
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(struct timeval));
    int bytes_received = recvfrom(sockfd, buffer, BUFSIZE, 0, result->ai_addr, &addrlen);
    if (bytes_received < 0) {
        printf("%s seems to be down\n", host);
        exit(0);
    }

    printf("%s is up!\n", host);
    close(sockfd);
}

void check_websites(char** hosts, int num_hosts) {
    for (int i = 0; i < num_hosts; i++) {
        check_uptime(hosts[i]);
    }
}

int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Usage: %s [website1] [website2] ...\n", argv[0]);
        return 1;
    }

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (!stop) {
        printf("Checking uptime at %s\n", asctime(localtime(&(time_t){time(NULL)})));
        check_websites(argv + 1, argc - 1);
        sleep(10); // check every 10 seconds
    }

    printf("Program stopped by user\n");
    return 0;
}