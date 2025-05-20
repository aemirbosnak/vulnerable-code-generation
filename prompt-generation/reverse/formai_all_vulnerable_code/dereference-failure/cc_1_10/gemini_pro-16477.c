//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <time.h>

#define MAX_URLS 100
#define MAX_URL_LENGTH 256
#define MAX_CHECK_INTERVAL 3600

typedef struct {
    char url[MAX_URL_LENGTH];
    int check_interval;
    time_t last_checked;
    int status_code;
} url_monitor;

url_monitor urls[MAX_URLS];
int num_urls;

void sig_handler(int signum) {
    if (signum == SIGINT) {
        printf("Received SIGINT, exiting...\n");
        exit(0);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <url> [<check_interval>]\n", argv[0]);
        return 1;
    }

    // Load URLs from command line arguments
    num_urls = argc - 1;
    for (int i = 1; i < argc; i++) {
        strncpy(urls[i - 1].url, argv[i], MAX_URL_LENGTH);
        urls[i - 1].check_interval = MAX_CHECK_INTERVAL;
        urls[i - 1].last_checked = time(NULL);
        urls[i - 1].status_code = 0;
    }

    // Initialize signal handler
    struct sigaction sa;
    sa.sa_handler = sig_handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    if (sigaction(SIGINT, &sa, NULL) == -1) {
        perror("sigaction");
        return 1;
    }

    // Main loop
    while (1) {
        // Check URLs
        for (int i = 0; i < num_urls; i++) {
            if (time(NULL) - urls[i].last_checked >= urls[i].check_interval) {
                // Get host IP address
                struct hostent *host = gethostbyname(urls[i].url);
                if (host == NULL) {
                    printf("Error: Could not resolve host %s\n", urls[i].url);
                    continue;
                }

                // Create socket
                int sockfd = socket(AF_INET, SOCK_STREAM, 0);
                if (sockfd == -1) {
                    perror("socket");
                    continue;
                }

                // Connect to host
                struct sockaddr_in addr;
                addr.sin_family = AF_INET;
                addr.sin_port = htons(80);
                addr.sin_addr = *(struct in_addr *)host->h_addr;
                if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
                    perror("connect");
                    close(sockfd);
                    continue;
                }

                // Send HTTP request
                char request[1024];
                sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", urls[i].url);
                if (send(sockfd, request, strlen(request), 0) == -1) {
                    perror("send");
                    close(sockfd);
                    continue;
                }

                // Receive HTTP response
                char response[1024];
                int bytes_received = recv(sockfd, response, sizeof(response), 0);
                if (bytes_received == -1) {
                    perror("recv");
                    close(sockfd);
                    continue;
                }

                // Parse HTTP response
                char *status_line = strtok(response, "\r\n");
                if (status_line == NULL) {
                    printf("Error: Could not parse HTTP response\n");
                    close(sockfd);
                    continue;
                }

                // Get status code
                char *status_code_str = strtok(status_line, " ");
                if (status_code_str == NULL) {
                    printf("Error: Could not get status code from HTTP response\n");
                    close(sockfd);
                    continue;
                }

                // Convert status code to integer
                urls[i].status_code = atoi(status_code_str);

                // Close socket
                close(sockfd);

                // Update last checked time
                urls[i].last_checked = time(NULL);
            }
        }

        // Print status report
        printf("URL Monitoring Report:\n");
        for (int i = 0; i < num_urls; i++) {
            printf("%s: %d\n", urls[i].url, urls[i].status_code);
        }

        // Sleep for 1 minute
        sleep(60);
    }

    return 0;
}