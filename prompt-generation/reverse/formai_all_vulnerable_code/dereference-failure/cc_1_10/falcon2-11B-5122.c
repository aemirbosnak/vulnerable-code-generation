//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>

#define MAX_PACKET_SIZE 1024
#define TIMEOUT_MS 1000
#define PORT 80

void print_help() {
    printf("Usage:./ping <hostname>\n");
}

int main(int argc, char* argv[]) {
    if (argc!= 2) {
        print_help();
        exit(1);
    }

    char* hostname = argv[1];

    struct hostent* server = gethostbyname(hostname);
    if (server == NULL) {
        fprintf(stderr, "Error: No such host\n");
        exit(1);
    }

    struct sockaddr_in addr;
    addr.sin_family = AF_INET;
    memcpy(&addr.sin_addr.s_addr, server->h_addr_list[0], server->h_length);
    addr.sin_port = htons(PORT);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Failed to create socket");
        exit(1);
    }

    int connect_result = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (connect_result < 0) {
        perror("Error: Failed to connect");
        exit(1);
    }

    char buffer[MAX_PACKET_SIZE];
    int bytes_sent = send(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_sent < 0) {
        perror("Error: Failed to send packet");
        exit(1);
    }

    struct timeval timeout;
    timeout.tv_sec = TIMEOUT_MS / 1000;
    timeout.tv_usec = (TIMEOUT_MS % 1000) * 1000;

    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received <= 0) {
        perror("Error: Timeout");
        exit(1);
    }

    close(sockfd);

    printf("PING %s (%s) %d bytes of data.\n", hostname, inet_ntoa(server->h_addr_list[0]), bytes_received);

    return 0;
}