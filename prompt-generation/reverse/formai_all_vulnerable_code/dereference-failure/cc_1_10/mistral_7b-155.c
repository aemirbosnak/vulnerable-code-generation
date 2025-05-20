//MISTRAL-7B DATASET v1.0 Category: Network Ping Test ; Style: future-proof
#include <arpa/inet.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 64
#define TIMEOUT 1000
#define SERVER_ADDRESS "8.8.8.8"
#define BUFFER_SIZE 1024

int main() {
    int sockfd, i, j, status;
    char buffer[BUFFER_SIZE];
    struct sockaddr_in server_addr;
    struct hostent *server;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    if ((server = gethostbyname(SERVER_ADDRESS)) == NULL) {
        fprintf(stderr, "gethostbyname: %s\n", gai_strerror(h_errno));
        exit(EXIT_FAILURE);
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    inet_pton(AF_INET, server->h_addr_list[0], &server_addr.sin_addr);

    for (i = 0; i < 4; i++) {
        sendto(sockfd, "\x08\x00", 2, 0, (struct sockaddr *)&server_addr, sizeof(server_addr));

        memset(buffer, 0, BUFFER_SIZE);
        ssize_t len = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, NULL, NULL);

        if (len > 0) {
            for (j = 0; j < len && buffer[j] != '\n'; j++) {}
            if (buffer[j] == '\n') {
                if (strncmp(buffer, "ping:", 4) == 0) {
                    sscanf(buffer + 4, "%*d%d", &status);
                    printf("Reply received: %d\n", status);
                }
            }
        }

        usleep(TIMEOUT);
    }

    close(sockfd);
    return EXIT_SUCCESS;
}