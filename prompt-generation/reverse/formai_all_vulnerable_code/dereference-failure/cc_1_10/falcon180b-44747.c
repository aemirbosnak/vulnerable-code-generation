//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define MAX 100

// Function to print error messages
void error(char *message) {
    perror(message);
    exit(1);
}

// Function to print usage instructions
void usage() {
    printf("Usage:./ping <ip address> <port number>\n");
}

// Function to send a ping packet
void send_ping(int sock, struct sockaddr *addr, int addrlen) {
    char buffer[MAX];
    int len;
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    len = sendto(sock, "PING", strlen("PING"), 0, addr, addrlen);
    if (len == -1) {
        error("sendto");
    }

    gettimeofday(&tv, NULL);
    printf("Ping sent %ld.%06ld\n", tv.tv_sec, tv.tv_usec);
}

// Function to receive a pong packet
void receive_pong(int sock, struct sockaddr *addr, int addrlen) {
    char buffer[MAX];
    int len;
    struct timeval tv;

    tv.tv_sec = 0;
    tv.tv_usec = 0;

    len = recvfrom(sock, buffer, MAX, 0, addr, &addrlen);
    if (len == -1) {
        error("recvfrom");
    }

    gettimeofday(&tv, NULL);
    printf("Pong received %ld.%06ld\n", tv.tv_sec, tv.tv_usec);

    if (strcmp(buffer, "PONG") == 0) {
        printf("Server is alive\n");
    } else {
        printf("Server is not responding\n");
    }
}

int main(int argc, char *argv[]) {
    int sock;
    struct sockaddr_in server_addr;
    int addrlen;
    int port;

    if (argc!= 3) {
        usage();
        exit(1);
    }

    port = atoi(argv[2]);

    // Create socket
    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock == -1) {
        error("socket");
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    inet_pton(AF_INET, argv[1], &server_addr.sin_addr);
    addrlen = sizeof(server_addr);

    // Send ping packet
    send_ping(sock, (struct sockaddr *)&server_addr, addrlen);

    // Receive pong packet
    receive_pong(sock, (struct sockaddr *)&server_addr, addrlen);

    close(sock);
    return 0;
}