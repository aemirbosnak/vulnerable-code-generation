//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <time.h>

#define PORT 80
#define BUFFER_SIZE 1024
#define LOG_FILE "uptime_log.txt"

void log_result(const char *url, int status) {
    FILE *file = fopen(LOG_FILE, "a");
    if (file == NULL) {
        perror("Could not open log file");
        return;
    }
    
    time_t now;
    time(&now);
    struct tm *tm_info = localtime(&now);
    char time_str[26];
    strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", tm_info);
    
    fprintf(file, "[%s] %s is %s\n", time_str, url, (status == 1) ? "UP" : "DOWN");
    fclose(file);
}

int check_website(const char *url) {
    int sockfd;
    struct sockaddr_in server_addr;
    
    char request[BUFFER_SIZE];
    char response[BUFFER_SIZE];
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 0;
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    server_addr.sin_addr.s_addr = inet_addr(url);
    
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        return 0; // Website is down
    }
    
    snprintf(request, sizeof(request), "GET / HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", url);
    send(sockfd, request, strlen(request), 0);
    
    recv(sockfd, response, sizeof(response) - 1, 0);
    close(sockfd);
    
    return (strstr(response, "200 OK") != NULL) ? 1 : 0; // Check status
}

void uptime_monitor(const char *url, int checks, int interval) {
    int up_count = 0;
    
    for (int i = 0; i < checks; i++) {
        int status = check_website(url);
        log_result(url, status);
        
        if (status) {
            up_count++;
        }
        
        sleep(interval);
    }
    
    printf("Monitoring completed for %s\n", url);
    printf("Uptime: %.2f%%\n", (up_count / (float)checks) * 100.0);
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <ip-address> <checks> <interval>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char *url = argv[1];
    int checks = atoi(argv[2]);
    int interval = atoi(argv[3]);

    if (checks <= 0 || interval <= 0) {
        fprintf(stderr, "Checks and interval must be positive integers.\n");
        return EXIT_FAILURE;
    }
    
    uptime_monitor(url, checks, interval);
    return EXIT_SUCCESS;
}