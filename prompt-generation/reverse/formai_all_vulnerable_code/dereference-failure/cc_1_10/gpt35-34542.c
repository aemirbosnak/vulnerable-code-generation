//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <signal.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>
#include <fcntl.h>
#include <sys/time.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024
#define MAX_PORTS 100000

// Priority enum
enum {
    LOW,
    MEDIUM,
    HIGH,
};

// Struct to store QoS settings
typedef struct qos_settings {
    int bandwidth;
    int latency;
    int jitter_buffer;
} qos_settings;

// Struct to store ping result
typedef struct ping_result {
    char ip_address[20];
    double latency;
} ping_result;

// Global arrays to store QoS settings and ping results
qos_settings qos[MAX_PORTS];
ping_result ping_results[MAX_PORTS];

// Thread function to ping IP address and calculate latency
void *ping_thread(void *arg) {
    char *ip_address = (char *)arg;
    struct timeval start_time, end_time;
    int sockfd, n;
    struct sockaddr_in servaddr;
    char buffer[BUFFER_SIZE];

    // Create socket
    sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        pthread_exit(NULL);
    }

    // Set timeout of 1 second for ping response
    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));

    // Set IP address and port
    bzero(&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(0);
    inet_pton(AF_INET, ip_address, &(servaddr.sin_addr));

    // Send ping request 10 times and calculate average latency
    double total_latency = 0;
    for (int i = 0; i < 10; i++) {
        memset(buffer, 0, sizeof(buffer));
        gettimeofday(&start_time, NULL);
        sendto(sockfd, (const char *)buffer, sizeof(buffer), MSG_CONFIRM, (const struct sockaddr *)&servaddr, sizeof(servaddr));
        n = recvfrom(sockfd, (char *)buffer, sizeof(buffer), MSG_WAITALL, (struct sockaddr *)&servaddr, &(socklen_t){sizeof(servaddr)});
        gettimeofday(&end_time, NULL);

        // Calculate latency in milliseconds
        double latency = ((end_time.tv_sec * 1000000 + end_time.tv_usec) - (start_time.tv_sec * 1000000 + start_time.tv_usec)) / 1000.0;
        if (n < 0 || latency > 1000) {
            latency = 1000;
        }
        total_latency += latency;
    }
    double average_latency = total_latency / 10;

    // Store ping result in global array
    ping_result result;
    strncpy(result.ip_address, ip_address, sizeof(result.ip_address));
    result.latency = average_latency;
    for (int i = 0; i < MAX_PORTS; i++) {
        if (strcmp(ping_results[i].ip_address, "") == 0) {
            ping_results[i] = result;
            break;
        }
    }

    close(sockfd);
    pthread_exit(NULL);
}

// Function to read QoS settings from file
void read_qos_settings() {
    FILE *fp;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;

    fp = fopen("qos_settings.txt", "r");
    if (fp == NULL) {
        perror("Error opening file");
        exit(1);
    }

    int i = 0;
    while ((read = getline(&line, &len, fp)) != -1) {
        char *token = strtok(line, ",");
        qos[i].bandwidth = atoi(token);

        token = strtok(NULL, ",");
        qos[i].latency = atoi(token);

        token = strtok(NULL, ",");
        qos[i].jitter_buffer = atoi(token);

        i++;
    }
    fclose(fp);
    if (line) {
        free(line);
    }
}

int main(int argc, char *argv[]) {
    // Read QoS settings from file
    read_qos_settings();

    // Scan network for active IP addresses
    char base_ip[20];
    printf("Enter base IP address: ");
    scanf("%s", base_ip);
    int port_num = 0;
    int num_threads = 0;
    pthread_t tid[MAX_PORTS];
    for (int i = 0; i < 255; i++) {
        char ip_address[20];
        sprintf(ip_address, "%s%d", base_ip, i);
        if (strcmp(ip_address, "localhost") == 0) {
            continue;
        }

        // Start ping thread for each IP address
        if (num_threads < MAX_PORTS) {
            pthread_create(&tid[num_threads], NULL, ping_thread, ip_address);
            num_threads++;
        }
    }

    // Wait for all ping threads to complete
    for (int i = 0; i < num_threads; i++) {
        pthread_join(tid[i], NULL);
    }

    // Calculate QoS for each port based on ping results and QoS settings
    for (int i = 0; i < MAX_PORTS; i++) {
        if (strcmp(ping_results[i].ip_address, "") != 0) {
            double latency = ping_results[i].latency;
            int bandwidth = qos[i].bandwidth;
            int jitter_buffer = qos[i].jitter_buffer;
            int priority = LOW;

            // Calculate priority based on QoS settings
            if (latency < bandwidth) {
                priority = HIGH;
            } else if (latency < (bandwidth + jitter_buffer)) {
                priority = MEDIUM;
            }

            // Print QoS for each port
            printf("IP Address: %s Bandwidth: %d Latency: %d Jitter Buffer: %d Priority: %d\n", ping_results[i].ip_address, bandwidth, (int)latency, jitter_buffer, priority);
        }
    }
    return 0;
}