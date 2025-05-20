//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define MAX_HOST_NAME_LENGTH 256
#define BUFFER_SIZE 1024

// Function to print error and exit program
void error(const char *message) {
    perror(message);
    exit(EXIT_FAILURE);
}

// Function to print usage instructions
void usage() {
    fprintf(stderr, "Usage:./ping <hostname>\n");
}

// Function to send ICMP echo request and receive response
int ping(const char *hostname) {
    int sock = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    if (sock == -1) {
        error("socket");
    }

    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(hostname);
    addr.sin_port = htons(0);

    char buffer[BUFFER_SIZE];
    int bytes_sent = sendto(sock, "PING", strlen("PING"), 0, (struct sockaddr *)&addr, sizeof(addr));
    if (bytes_sent == -1) {
        error("sendto");
    }

    int bytes_received = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
    if (bytes_received == -1) {
        error("recvfrom");
    }

    close(sock);

    if (strcmp(buffer, "PONG") == 0) {
        return 0;
    } else {
        return 1;
    }
}

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        usage();
        return 1;
    }

    char hostname[MAX_HOST_NAME_LENGTH];
    strncpy(hostname, argv[1], MAX_HOST_NAME_LENGTH - 1);
    hostname[MAX_HOST_NAME_LENGTH - 1] = '\0';

    int result = ping(hostname);

    if (result == 0) {
        printf("Host %s is alive.\n", hostname);
    } else {
        printf("Host %s is not responding.\n", hostname);
    }

    return result;
}