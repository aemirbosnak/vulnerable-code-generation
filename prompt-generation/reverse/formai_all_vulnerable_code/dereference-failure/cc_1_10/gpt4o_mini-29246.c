//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define PING_COUNT 10

void start_server() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE] = {0};

    // Create socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Bind the socket to PORT
    if (bind(server_fd, (struct sockaddr*)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    while (1) {
        int len = recvfrom(server_fd, buffer, BUFFER_SIZE, 0, (struct sockaddr*)&address, &addrlen);
        buffer[len] = '\0';
        printf("Received: %s\n", buffer);
        sendto(server_fd, buffer, len, 0, (struct sockaddr*)&address, addrlen);
    }

    close(server_fd);
}

void start_client(const char* server_ip) {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE] = {0};
    struct timespec start, end;
    double total_time = 0.0;
    int packet_loss = 0;

    // Create socket
    if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
    inet_pton(AF_INET, server_ip, &serv_addr.sin_addr);

    printf("Pinging %s:%d...\n", server_ip, PORT);

    for (int i = 0; i < PING_COUNT; i++) {
        sprintf(buffer, "Ping %d", i + 1);
        clock_gettime(CLOCK_MONOTONIC, &start);

        // Send ping
        sendto(sock, buffer, strlen(buffer), 0, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

        // Wait for response
        int len = recvfrom(sock, buffer, BUFFER_SIZE, 0, NULL, NULL);
        clock_gettime(CLOCK_MONOTONIC, &end);

        if (len >= 0) {
            buffer[len] = '\0';
            double elapsed = (end.tv_sec - start.tv_sec) * 1e9;
            elapsed = (elapsed + (end.tv_nsec - start.tv_nsec)) * 1e-6;
            total_time += elapsed;
            printf("Received: %s (RTT: %.2f ms)\n", buffer, elapsed);
        } else {
            printf("Request timed out.\n");
            packet_loss++;
        }
        
        // Small delay to prevent overwhelming the server
        usleep(100000);
    }

    close(sock);

    // Statistics
    printf("\n--- Ping statistics ---\n");
    printf("%d packets transmitted, %d received, %.2f%% packet loss\n", PING_COUNT, PING_COUNT - packet_loss, (packet_loss * 100.0) / PING_COUNT);
    
    if (PING_COUNT - packet_loss > 0) {
        printf("Average RTT: %.2f ms\n", total_time / (PING_COUNT - packet_loss));
    } else {
        printf("No reply received.\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <server/client> [IP address]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if (strcmp(argv[1], "server") == 0) {
        start_server();
    } else if (strcmp(argv[1], "client") == 0) {
        if (argc < 3) {
            printf("Usage: %s client <server_ip>\n", argv[0]);
            exit(EXIT_FAILURE);
        }
        start_client(argv[2]);
    } else {
        printf("Invalid argument. Use 'server' or 'client'.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}