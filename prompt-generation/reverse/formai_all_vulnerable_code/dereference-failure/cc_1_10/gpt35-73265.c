//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: calm
// C Network Quality of Service (QoS) Monitor Example Program
// Author: [Your Name Here]
// Date: [Current Date]

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {
    int port, sockfd, send_size, recv_size, recv_total, elapsed_time;
    struct sockaddr_in server;
    char buffer[BUFFER_SIZE], message[BUFFER_SIZE];
    struct timeval start_time, end_time;

    if (argc < 2) {
        printf("Usage: %s [port]\n", argv[0]);
        return EXIT_FAILURE;
    }

    port = atoi(argv[1]);

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation error");
        return EXIT_FAILURE;
    }

    // Configure server address
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = inet_addr("127.0.0.1");

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&server, sizeof(server)) < 0) {
        perror("Connection error");
        return EXIT_FAILURE;
    }

    // Send test message
    strcpy(message, "QoS Test Message");
    gettimeofday(&start_time, NULL);
    send_size = send(sockfd, message, strlen(message), 0);
    if (send_size < 0) {
        perror("Send error");
        return EXIT_FAILURE;
    }

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    recv_total = 0;
    while ((recv_size = recv(sockfd, buffer, BUFFER_SIZE, 0)) > 0) {
        recv_total += recv_size;
        memset(buffer, 0, BUFFER_SIZE);
    }
    gettimeofday(&end_time, NULL);

    // Calculate elapsed time
    elapsed_time = (end_time.tv_sec - start_time.tv_sec) * 1000;
    elapsed_time += (end_time.tv_usec - start_time.tv_usec) / 1000;

    printf("Received %d bytes in %dms\n", recv_total, elapsed_time);

    // Close socket
    close(sockfd);

    return EXIT_SUCCESS;
}