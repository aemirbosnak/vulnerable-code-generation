//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <time.h>

#define MAX_URLS 10
#define TIMEOUT 5

typedef struct {
    char *url;
    int status;
} Website;

Website websites[MAX_URLS];
int website_count = 0;

void *check_website(void *arg) {
    Website *site = (Website *)arg;
    // Resolve hostname
    struct sockaddr_in serv_addr;
    int sockfd;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        site->status = -1;
        return NULL;
    }

    // Set socket to non-blocking
    fcntl(sockfd, F_SETFL, O_NONBLOCK);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80); // Use HTTP port

    // Convert IP address from text to binary form
    if (inet_pton(AF_INET, site->url, &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        site->status = -1;
        close(sockfd);
        return NULL;
    }

    // Try to connect
    int connect_status = connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr));
    if (connect_status < 0) {
        if (errno == EINPROGRESS) {
            // Connection is still progressing, wait and check
            fd_set writefds;
            FD_ZERO(&writefds);
            FD_SET(sockfd, &writefds);

            struct timeval tv;
            tv.tv_sec = TIMEOUT;
            tv.tv_usec = 0;

            if (select(sockfd + 1, NULL, &writefds, NULL, &tv) > 0) {
                // Check if the socket is writable
                int so_error;
                socklen_t len = sizeof(so_error);
                getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &so_error, &len);
                
                if (so_error == 0) {
                    site->status = 1; // Website is up
                } else {
                    site->status = 0; // Website is down
                }
            } else {
                site->status = 0; // Timeout, website is down
            }
        } else {
            site->status = 0; // Connection failed
        }
    } else {
        site->status = 1; // Website is up
    }
    
    close(sockfd);
    return NULL;
}

void monitor_websites() {
    pthread_t threads[MAX_URLS];
    
    for (int i = 0; i < website_count; i++) {
        // Create a thread to check each website
        if (pthread_create(&threads[i], NULL, check_website, (void *)&websites[i]) != 0) {
            perror("Error in creating thread");
            exit(EXIT_FAILURE);
        }
    }

    // Wait for all threads to finish
    for (int i = 0; i < website_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print results
    for (int i = 0; i < website_count; i++) {
        printf("Website %s is %s\n", websites[i].url, websites[i].status == 1 ? "UP" : "DOWN");
    }
}

int main() {
    // Example URLs (replace with your URLs/IPs)
    websites[0].url = "8.8.8.8"; // Google DNS
    websites[1].url = "1.1.1.1"; // Cloudflare DNS
    websites[2].url = "192.0.2.1"; // Example domain (not real)
    websites[3].url = "203.0.113.1"; // Another non-existent domain
    
    website_count = 4;

    monitor_websites();

    return 0;
}