//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_URL_LENGTH 256
#define RETRY_INTERVAL 5 // seconds
#define MAX_RETRIES 5
#define UPTIME_LOG "uptime_log.txt"

void log_uptime(const char *url, int status) {
    FILE *file = fopen(UPTIME_LOG, "a");
    if (file) {
        time_t now = time(NULL);
        fprintf(file, "[%s] %s is %s\n", ctime(&now), url, (status == 0) ? "UP" : "DOWN");
        fclose(file);
    } else {
        perror("Error opening log file");
    }
}

int check_url(const char *url) {
    struct addrinfo hints, *res;
    int sockfd;

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET; // IPv4
    hints.ai_socktype = SOCK_STREAM;

    if (getaddrinfo(url, "80", &hints, &res) != 0) {
        return -1; // DNS resolution failed
    }

    if ((sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol)) < 0) {
        freeaddrinfo(res);
        return -1; // Socket creation failed
    }

    if (connect(sockfd, res->ai_addr, res->ai_addrlen) < 0) {
        freeaddrinfo(res);
        close(sockfd);
        return -1; // Connection failed
    }

    freeaddrinfo(res);
    close(sockfd);
    return 0; // Connection successful
}

void monitor_website(const char *url) {
    int retry_count = 0;

    printf("Monitoring website: %s\n", url);
    
    while (retry_count < MAX_RETRIES) {
        int result = check_url(url);

        if (result == 0) {
            printf("Status: %s is UP\n", url);
            log_uptime(url, 0);
            break; // Exit loop if up
        } else {
            printf("Status: %s is DOWN\n", url);
            log_uptime(url, 1);
            sleep(RETRY_INTERVAL);
            retry_count++;
        }
    }

    if (retry_count == MAX_RETRIES) {
        printf("Max retries reached. Exiting...\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    monitor_website(argv[1]);

    return 0;
}