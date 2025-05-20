//GEMINI-pro DATASET v1.0 Category: Drone Remote Control ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <stdint.h>

#define PORT 5000
#define BUFSIZE 1024

struct command {
    uint8_t type;
    uint8_t length;
    uint8_t data[BUFSIZE];
};

int main(int argc, char **argv) {
    int sockfd, n;
    struct sockaddr_in serv_addr;
    struct command cmd;

    if (argc < 3) {
        fprintf(stderr, "Usage: %s <IP address> <command>\n", argv[0]);
        return EXIT_FAILURE;
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket");
        return EXIT_FAILURE;
    }

    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    if (inet_pton(AF_INET, argv[1], &serv_addr.sin_addr) <= 0) {
        perror("inet_pton");
        return EXIT_FAILURE;
    }

    cmd.type = 0;
    cmd.length = strlen(argv[2]);
    strcpy(cmd.data, argv[2]);

    if (sendto(sockfd, &cmd, sizeof(cmd), 0, (struct sockaddr *) &serv_addr,
                sizeof(serv_addr)) < 0) {
        perror("sendto");
        return EXIT_FAILURE;
    }

    if ((n = recvfrom(sockfd, &cmd, sizeof(cmd), 0, NULL, NULL)) < 0) {
        perror("recvfrom");
        return EXIT_FAILURE;
    }

    if (cmd.type == 1) {
        printf("Command acknowledged\n");
    } else {
        printf("Command not acknowledged\n");
    }

    close(sockfd);
    return EXIT_SUCCESS;
}