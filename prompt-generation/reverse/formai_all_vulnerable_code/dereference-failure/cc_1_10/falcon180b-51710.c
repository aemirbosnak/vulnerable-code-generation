//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int sockfd, retval;
    struct sockaddr_in dest;
    char *dest_ip;
    int dest_port;
    int timeout;
    int max_tries;
    int tries;
    int bytes_sent, bytes_received;
    char buffer[100];

    if (argc!= 5) {
        printf("Usage: %s <dest_ip> <dest_port> <timeout_ms> <max_tries>\n", argv[0]);
        return 1;
    }

    dest_ip = argv[1];
    dest_port = atoi(argv[2]);
    timeout = atoi(argv[3]);
    max_tries = atoi(argv[4]);

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return 1;
    }

    memset(&dest, 0, sizeof(dest));
    dest.sin_family = AF_INET;
    dest.sin_port = htons(dest_port);
    inet_pton(AF_INET, dest_ip, &dest.sin_addr);

    retval = connect(sockfd, (struct sockaddr *)&dest, sizeof(dest));
    if (retval == -1) {
        printf("Error connecting to %s:%d\n", dest_ip, dest_port);
        close(sockfd);
        return 1;
    }

    for (tries = 0; tries < max_tries; tries++) {
        bytes_sent = send(sockfd, "PING", strlen("PING"), 0);
        if (bytes_sent == -1) {
            printf("Error sending PING\n");
            close(sockfd);
            return 1;
        }

        bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
        if (bytes_received == -1) {
            printf("Error receiving response\n");
            close(sockfd);
            return 1;
        }

        if (bytes_received == 0) {
            printf("No response received\n");
            close(sockfd);
            return 1;
        }

        if (strncmp(buffer, "PONG", strlen("PONG")) == 0) {
            printf("PONG received\n");
            close(sockfd);
            return 0;
        }
    }

    printf("Max tries reached\n");
    close(sockfd);
    return 1;
}