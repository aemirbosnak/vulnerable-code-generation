//Gemma-7B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_PACKET_SIZE 1024

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[MAX_PACKET_SIZE];
    int packet_size;
    long long total_bytes = 0;
    long long start_time, end_time;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, htons(80));

    // Bind the socket to a port
    server_addr.sin_port = htons(5000);
    bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    // Listen for connections
    newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, NULL);

    // Start the timer
    start_time = time(NULL);

    // Receive packets
    while ((packet_size = recv(newsockfd, buffer, MAX_PACKET_SIZE, 0)) > 0) {
        total_bytes += packet_size;
    }

    // End the timer
    end_time = time(NULL);

    // Calculate the average packet size
    long long average_packet_size = (total_bytes * 8) / packet_size;

    // Print the results
    printf("Total bytes received: %lld\n", total_bytes);
    printf("Average packet size: %lld bytes\n", average_packet_size);
    printf("Time taken: %lld seconds\n", end_time - start_time);

    // Close the socket
    close(newsockfd);
    close(sockfd);

    return 0;
}