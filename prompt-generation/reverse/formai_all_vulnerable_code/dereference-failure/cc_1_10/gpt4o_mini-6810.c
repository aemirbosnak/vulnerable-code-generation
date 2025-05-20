//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/time.h>
#include <netdb.h>

#define BUFFER_SIZE 1024
#define PORT 80
#define PING_INTERVAL 2
#define TIMEOUT 2
#define MAX_RETRIES 3

void log_status(const char *url, int status) {
    const char *status_message = status == 1 ? "UP" : "DOWN";
    printf("Status of %s: %s\n", url, status_message);
}

int ping_website(const char *url) {
    struct sockaddr_in server_addr;
    int sockfd;
    struct hostent *host;
    
    // Resolve the hostname to an IP address
    host = gethostbyname(url);
    if (host == NULL) {
        fprintf(stderr, "Could not resolve hostname: %s\n", url);
        return 0; // Assume down if unable to resolve
    }

    // Create a TCP socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        return 0; // Connection failed
    }

    // Set server address structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(PORT);
    bcopy((char *)host->h_addr, (char *)&server_addr.sin_addr.s_addr, host->h_length);

    // Set a timeout for the connection
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof timeout);

    // Attempt to connect to the server
    if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        close(sockfd);
        return 0; // Connection failed
    }

    // Successfully connected
    close(sockfd);
    return 1; // Connection succeeded
}

void monitor_website(const char *url) {
    int retries = 0;

    while (1) {
        int status = ping_website(url);
        log_status(url, status);

        // Wait before pinging again
        sleep(PING_INTERVAL);

        // Optionally keep track of retries
        if (status == 0) {
            retries++;
            if (retries >= MAX_RETRIES) {
                printf("%s is down. Notifying the administrator...\n", url);
                // Add notification logic here if necessary
            }
        } else {
            retries = 0; // Reset on success
        }
    }
}

int main(int argc, char *argv[]) {
    // Ensure proper usage
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <url>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *url = argv[1];
    printf("Starting website uptime monitor for: %s\n", url);
    monitor_website(url);

    return 0;
}