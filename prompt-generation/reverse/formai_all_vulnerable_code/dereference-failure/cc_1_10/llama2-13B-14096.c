//LLAMA2-13B DATASET v1.0 Category: Port Scanner ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT_RANGE 1024

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(0);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);

    int i = 0;
    for (i = 0; i < PORT_RANGE; i++) {
        char buffer[INET_ADDRSTRLEN];
        socklen_t addrlen = sizeof(server_addr);
        getsockname(sock, (struct sockaddr *)&server_addr, &addrlen);
        printf("Listening on port %d...\n", ntohs(server_addr.sin_port));

        // Send SYN packet to the target port
        struct sockaddr_in target_addr;
        memset(&target_addr, 0, sizeof(target_addr));
        target_addr.sin_family = AF_INET;
        target_addr.sin_port = htons(i + 1);
        inet_pton(AF_INET, "127.0.0.1", &target_addr.sin_addr);

        int result = sendto(sock, "SYN", 1, 0, (struct sockaddr *)&target_addr, sizeof(target_addr));
        if (result < 0) {
            perror("sendto failed");
            exit(EXIT_FAILURE);
        }

        // Wait for the response (or timeout)
        fd_set read_fds;
        FD_ZERO(&read_fds);
        FD_SET(sock, &read_fds);
        struct timeval timeout;
        timeout.tv_sec = 2;
        timeout.tv_usec = 0;

        select(sock + 1, &read_fds, NULL, NULL, &timeout);

        // Check if there is a response
        if (FD_ISSET(sock, &read_fds)) {
            char buffer[INET_ADDRSTRLEN];
            socklen_t addrlen = sizeof(server_addr);
            int result = recvfrom(sock, buffer, INET_ADDRSTRLEN, 0, (struct sockaddr *)&server_addr, &addrlen);
            if (result < 0) {
                perror("recvfrom failed");
                exit(EXIT_FAILURE);
            }
            printf("Received packet from %s on port %d\n", inet_ntoa(server_addr.sin_addr), ntohs(server_addr.sin_port));
        }
    }

    close(sock);
    return 0;
}