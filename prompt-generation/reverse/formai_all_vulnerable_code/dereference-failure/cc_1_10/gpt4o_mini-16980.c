//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define LOG_FILE "qos_log.txt"

void log_qos_data(const char *data) {
    FILE *log_file = fopen(LOG_FILE, "a");
    if (log_file == NULL) {
        perror("Could not open log file");
        return;
    }
    fprintf(log_file, "%s\n", data);
    fclose(log_file);
}

void record_qos_metrics(const char *ip_address, int response_time) {
    time_t now;
    time(&now);
    char *time_str = ctime(&now);
    time_str[strlen(time_str) - 1] = '\0'; // Trim the newline character

    char log_entry[BUFFER_SIZE];
    snprintf(log_entry, sizeof(log_entry), 
             "[%s] QoS metrics - IP: %s, Response time: %d ms", 
             time_str, ip_address, response_time);
    
    log_qos_data(log_entry);
}

int ping_host(const char *ip_address) {
    struct sockaddr_in addr;
    struct timeval start, end;
    int sock, result;
    socklen_t addr_len = sizeof(addr);

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(PORT);
    inet_pton(AF_INET, ip_address, &addr.sin_addr);

    sock = socket(AF_INET, SOCK_DGRAM, 0);
    if (sock < 0) {
        perror("Socket creation failed");
        return -1;
    }

    gettimeofday(&start, NULL);
    result = sendto(sock, "ping", strlen("ping"), 0, (struct sockaddr *)&addr, addr_len);
    if (result < 0) {
        perror("Sendto failed");
        close(sock);
        return -1;
    }

    char buffer[BUFFER_SIZE];
    result = recvfrom(sock, buffer, BUFFER_SIZE, 0, (struct sockaddr *)&addr, &addr_len);
    gettimeofday(&end, NULL);

    close(sock);

    if (result < 0) {
        perror("Recvfrom failed");
        return -1;
    }

    int response_time = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
    return response_time;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <IP Address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *ip_address = argv[1];

    while (1) {
        int response_time = ping_host(ip_address);
        if (response_time >= 0) {
            printf("Response from %s: %d ms\n", ip_address, response_time);
            record_qos_metrics(ip_address, response_time);
        } else {
            printf("Failed to ping %s\n", ip_address);
        }

        sleep(5); // Wait for 5 seconds before next ping
    }

    return EXIT_SUCCESS;
}