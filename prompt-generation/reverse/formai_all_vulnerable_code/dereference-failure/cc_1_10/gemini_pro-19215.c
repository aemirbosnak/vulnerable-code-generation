//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <signal.h>
#include <unistd.h>
#include <time.h>

#define BUFF_SIZE 1024

// Function to handle SIGINT signal
void sigint_handler(int signum) {
    printf("\nSIGINT received, exiting...\n");
    exit(0);
}

// Function to print usage information
void print_usage(char *program_name) {
    printf("Usage: %s <server_ip> <server_port>\n", program_name);
    printf("Example: %s 127.0.0.1 5000\n", program_name);
}

// Function to monitor network QoS metrics
void monitor_qos(char *server_ip, int server_port) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("socket() failed");
        exit(1);
    }

    // Set socket options
    int val = 1;
    if (setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val)) < 0) {
        perror("setsockopt() failed");
        exit(1);
    }

    // Get the server's address
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(struct sockaddr_in));
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr(server_ip);
    server_addr.sin_port = htons(server_port);

    // Bind the socket to a local address
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) < 0) {
        perror("bind() failed");
        exit(1);
    }

    // Receive data from the server
    char buffer[BUFF_SIZE];
    int num_packets = 0;
    int num_lost_packets = 0;
    time_t start_time, end_time;
    double elapsed_time;

    while (1) {
        start_time = time(NULL);

        ssize_t bytes_recv = recvfrom(sockfd, buffer, BUFF_SIZE, 0, NULL, NULL);
        if (bytes_recv < 0) {
            perror("recvfrom() failed");
            continue;
        }

        end_time = time(NULL);
        elapsed_time = difftime(end_time, start_time);

        // Update QoS metrics
        num_packets++;
        if (bytes_recv == 0) {
            num_lost_packets++;
        }

        // Print QoS metrics
        printf("Packet %d received, %d total, %d lost, RTT: %.3f seconds\n", num_packets, num_packets, num_lost_packets, elapsed_time);
    }

    // Close the socket
    close(sockfd);
}

int main(int argc, char *argv[]) {
    // Check command line arguments
    if (argc != 3) {
        print_usage(argv[0]);
        return 1;
    }

    // Register SIGINT signal handler
    signal(SIGINT, sigint_handler);

    // Monitor network QoS metrics
    monitor_qos(argv[1], atoi(argv[2]));

    return 0;
}