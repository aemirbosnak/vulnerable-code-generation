//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 512

void handle_error(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
    int sockfd, bytes_sent, bytes_received;
    struct sockaddr_in server_address;

    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <target IP address> <message>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        handle_error("ERROR opening socket");
    }

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80); // HTTP port
    server_address.sin_addr.s_addr = inet_addr(argv[1]); // Target IP address

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        handle_error("ERROR connecting to server");
    }

    bytes_sent = send(sockfd, argv[2], strlen(argv[2]), 0);
    if (bytes_sent < 0) {
        handle_error("ERROR sending data to server");
    }

    bytes_received = recv(sockfd, argv[2], MAX_PACKET_SIZE, 0);
    if (bytes_received < 0) {
        handle_error("ERROR receiving data from server");
    }

    printf("Received %d bytes from server: %s\n", bytes_received, argv[2]);

    close(sockfd);

    return 0;
}