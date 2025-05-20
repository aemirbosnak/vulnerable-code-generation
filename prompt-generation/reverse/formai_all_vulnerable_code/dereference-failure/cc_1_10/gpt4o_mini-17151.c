//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <errno.h>

#define BUFFER_SIZE 1024
#define DEST_IP "8.8.8.8" // Google's public DNS for testing
#define DEST_PORT 53
#define INTERVAL 5 // seconds between pings
#define TIMEOUT 2 // seconds timeout period

void print_usage(char *prog_name) {
    printf("Usage: %s <num_pings>\n", prog_name);
    printf("Example: %s 5\n", prog_name);
}

void log_to_file(const char *message) {
    FILE *log_file = fopen("qos_log.txt", "a");
    if (log_file) {
        fprintf(log_file, "%s\n", message);
        fclose(log_file);
    } else {
        perror("Unable to open log file");
    }
}

void ping_server(int num_pings) {
    struct sockaddr_in server_addr;
    char buffer[BUFFER_SIZE];
    struct timeval timeout;
    int sockfd, result;
    socklen_t addr_len = sizeof(server_addr);
    
    // Create a UDP socket
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    // Set server address
    memset(&server_addr, 0, addr_len);
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(DEST_PORT);
    server_addr.sin_addr.s_addr = inet_addr(DEST_IP);

    // Prepare timeout
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;

    // Set socket timeout
    if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout)) < 0) {
        perror("Set socket option failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start pinging
    for (int i = 0; i < num_pings; i++) {
        snprintf(buffer, BUFFER_SIZE, "Ping %d", i + 1);
        ssize_t sent_bytes = sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr *)&server_addr, addr_len);
        
        if (sent_bytes < 0) {
            perror("Send failed");
            log_to_file("Send failed");
            continue;
        }
        
        printf("Sent: %s\n", buffer);
        
        // Wait for a reply
        ssize_t recv_bytes = recvfrom(sockfd, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_addr, &addr_len);
        if (recv_bytes < 0) {
            perror("Receive failed");
            log_to_file("Receive failed, host unreachable");
        } else {
            buffer[recv_bytes] = '\0'; // Null-terminate the received data
            printf("Received: %s\n", buffer);
            log_to_file(buffer);
        }

        sleep(INTERVAL);
    }

    close(sockfd);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        print_usage(argv[0]);
        return EXIT_FAILURE;
    }

    int num_pings = atoi(argv[1]);
    if (num_pings <= 0) {
        printf("Number of pings must be greater than 0.\n");
        return EXIT_FAILURE;
    }

    printf("Starting QoS monitor for %d pings...\n", num_pings);
    ping_server(num_pings);
    printf("QoS monitor finished.\n");

    return EXIT_SUCCESS;
}