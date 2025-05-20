//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>
#include <signal.h>
#include <time.h>

#define PORT 8080
#define MAX_BUFFER_SIZE 1024

volatile sig_atomic_t stop_flag = 0;

void handle_sigint(int sig)
{
    stop_flag = 1;
}

int main(int argc, char const *argv[])
{
    struct sigaction sigint_action;
    sigint_action.sa_handler = handle_sigint;
    sigaction(SIGINT, &sigint_action, NULL);

    int sockfd;
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in server_addr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("socket creation failed");
        return EXIT_FAILURE;
    }

    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (const struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("bind failed");
        return EXIT_FAILURE;
    }

    printf("Listening on port %d...\n", PORT);

    while (!stop_flag) {
        struct sockaddr_in client_addr;
        socklen_t client_addr_len = sizeof(client_addr);
        int bytes_received = recvfrom(sockfd, (char *)buffer, MAX_BUFFER_SIZE, MSG_WAITALL, (struct sockaddr *)&client_addr, &client_addr_len);
        if (bytes_received == -1 && errno == EINTR) {
            // interrupted by signal, continue loop
            continue;
        } else if (bytes_received == -1) {
            perror("recvfrom error");
            return EXIT_FAILURE;
        }

        buffer[bytes_received] = '\0';

        printf("Received: %s", buffer);
    }

    printf("Exiting...\n");

    close(sockfd);
    return EXIT_SUCCESS;
}