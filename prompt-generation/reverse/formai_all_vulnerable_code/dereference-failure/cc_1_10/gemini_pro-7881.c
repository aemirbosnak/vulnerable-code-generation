//GEMINI-pro DATASET v1.0 Category: Network Ping Test ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#define MAX_PACKET_SIZE 1024
#define DEFAULT_TIMEOUT_MS 1000

char *host_name;
int sockfd;
struct sockaddr_in servaddr;

void sigalrm_handler(int signum) {
    printf("Timeout occurred while waiting for reply from %s\n", host_name);
    exit(1);
}

void send_ping(void) {
    int n;
    char packet[MAX_PACKET_SIZE];

    // Set the packet data
    memset(packet, 0, sizeof(packet));
    strcpy(packet, "PING");

    // Send the packet
    n = sendto(sockfd, packet, strlen(packet), 0, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (n < 0) {
        perror("sendto");
        exit(1);
    }
}

void receive_ping(void) {
    int n;
    char packet[MAX_PACKET_SIZE];
    socklen_t addrlen;

    // Set the timeout
    struct timeval timeout;
    timeout.tv_sec = DEFAULT_TIMEOUT_MS / 1000;
    timeout.tv_usec = (DEFAULT_TIMEOUT_MS % 1000) * 1000;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));

    // Receive the packet
    addrlen = sizeof(servaddr);
    n = recvfrom(sockfd, packet, sizeof(packet), 0, (struct sockaddr *) &servaddr, &addrlen);
    if (n < 0) {
        if (errno == EAGAIN || errno == EWOULDBLOCK) {
            printf("Timeout occurred while waiting for reply from %s\n", host_name);
        } else {
            perror("recvfrom");
            exit(1);
        }
    } else {
        printf("Received reply from %s: %s\n", host_name, packet);
    }
}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <host_name>\n", argv[0]);
        exit(1);
    }

    host_name = argv[1];

    // Create the socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(1);
    }

    // Set the server address
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(host_name);
    servaddr.sin_port = htons(80);

    // Set the signal handler for SIGALRM
    signal(SIGALRM, sigalrm_handler);

    // Send the ping
    send_ping();

    // Receive the ping
    receive_ping();

    // Close the socket
    close(sockfd);

    return 0;
}