//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <signal.h>

#define SERVER_PORT 8080
#define TRUE 1
#define FALSE 0

volatile int running = TRUE;

void handle_exit(int sig) {
    running = FALSE;
}

int main() {
    struct sigaction act;
    act.sa_handler = handle_exit;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_RESTART;
    sigaction(SIGINT, &act, NULL);

    int sock_fd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock_fd < 0) {
        fprintf(stderr, "Could not create socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_address, client_address;
    memset(&server_address, 0, sizeof(server_address));
    memset(&client_address, 0, sizeof(client_address));

    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(SERVER_PORT);
    server_address.sin_addr.s_addr = INADDR_ANY;

    if (bind(sock_fd, (struct sockaddr*)&server_address, sizeof(server_address)) < 0) {
        fprintf(stderr, "Could not bind socket: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
    }

    char buffer[1024];
    int read = 0;
    while (running) {
        socklen_t len = sizeof(client_address);
        read = recvfrom(sock_fd, buffer, sizeof(buffer), 0, (struct sockaddr*)&client_address, &len);
        if (read < 0) {
            fprintf(stderr, "Error receiving from socket: %s\n", strerror(errno));
            continue;
        }
        buffer[read] = '\0';
        printf("Received: %s\n", buffer);
    }

    close(sock_fd);
    exit(EXIT_SUCCESS);
}