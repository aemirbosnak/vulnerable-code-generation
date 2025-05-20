//Falcon2-11B DATASET v1.0 Category: Socket programming ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc!= 3) {
        fprintf(stderr, "Usage: %s <ip address> <port number>\n", argv[0]);
        return 1;
    }

    struct sockaddr_in server_address;
    int sockfd, len;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket");
        return 1;
    }

    bzero(&server_address, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(atoi(argv[2]));

    if (inet_pton(AF_INET, argv[1], &server_address.sin_addr) <= 0) {
        fprintf(stderr, "Invalid IP address\n");
        return 1;
    }

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
        perror("connect");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int num_bytes_read;

    while (1) {
        bzero(buffer, BUFFER_SIZE);
        num_bytes_read = read(sockfd, buffer, BUFFER_SIZE);
        if (num_bytes_read <= 0) {
            perror("read");
            return 1;
        }

        printf("Received: %s\n", buffer);

        char *input = "Hello from client";
        send(sockfd, input, strlen(input), 0);
    }

    return 0;
}