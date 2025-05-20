//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>
#include <time.h>

#define MAX_BUFFER_SIZE 1024

int main() {
    int sockfd, sin_port, nbytes, recv_len, send_len;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_BUFFER_SIZE];
    time_t start_time, end_time;
    int packets_sent = 0, packets_received = 0, loss_ratio = 0;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(65535));
    if (sockfd < 0) {
        perror("Error creating socket");
        exit(1);
    }

    // Bind the socket to a port
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(5000);
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        exit(1);
    }

    // Listen for clients
    sin_port = ntohs(server_addr.sin_port);
    printf("Listening on port %d...\n", sin_port);

    // Start the timer
    start_time = time(NULL);

    // Receive packets
    while (1) {
        recv_len = recv(sockfd, buffer, MAX_BUFFER_SIZE, 0);
        if (recv_len > 0) {
            packets_received++;
            send_len = send(sockfd, buffer, recv_len, 0);
            if (send_len < 0) {
                perror("Error sending packet");
            } else {
                packets_sent++;
            }
        } else if (recv_len == 0) {
            end_time = time(NULL);
            loss_ratio = (packets_sent - packets_received) * 100 / packets_sent;
            printf("Number of packets sent: %d\n", packets_sent);
            printf("Number of packets received: %d\n", packets_received);
            printf("Loss ratio: %d%%\n", loss_ratio);
            printf("Time taken: %ld seconds\n", end_time - start_time);
            break;
        } else {
            perror("Error receiving packet");
        }
    }

    // Close the socket
    close(sockfd);

    return 0;
}