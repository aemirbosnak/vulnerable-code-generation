//Falcon-180B DATASET v1.0 Category: Network Ping Test ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024
#define SERVER_PORT 8080
#define SERVER_IP "127.0.0.1"

void handle_error(const char* msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
    if (argc!= 4) {
        fprintf(stderr, "Usage: %s <IP address> <port number> <number of pings>\n", argv[0]);
        return 1;
    }

    char* ip_address = argv[1];
    int port_number = atoi(argv[2]);
    int num_pings = atoi(argv[3]);

    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        handle_error("socket");
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port_number);
    inet_pton(AF_INET, ip_address, &server_addr.sin_addr);

    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
        handle_error("connect");
    }

    char* buffer = malloc(BUFFER_SIZE);
    memset(buffer, 'A', BUFFER_SIZE);

    for (int i = 0; i < num_pings; i++) {
        send(sockfd, buffer, BUFFER_SIZE, 0);
        usleep(100000); // 100ms delay between pings
    }

    close(sockfd);
    free(buffer);

    return 0;
}