//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>

#define MAX_URL_LENGTH 100
#define PING_INTERVAL 5

int check_website_status(const char *url) {
    struct sockaddr_in server_addr;
    struct hostent *host;

    // Get the host information
    host = gethostbyname(url);
    if (host == NULL) {
        printf("Error: Unable to resolve hostname %s\n", url);
        return 0; // Indicates website is down
    }

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error: Unable to create socket");
        return 0; // Indicates website is down
    }

    // Set up the server address struct
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80); // HTTP port
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Attempt to connect to the server
    int connection_status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));
    close(sockfd); // Closing socket after check

    // Return the status
    return connection_status == 0; // 0 means success (up)
}

void monitor_websites(char **urls, int url_count) {
    while (1) {
        printf("\n\n=== Website Uptime Monitor ===\n");
        
        for (int i = 0; i < url_count; i++) {
            int status = check_website_status(urls[i]);
            if (status) {
                printf("✅ %s is UP 🚀\n", urls[i]);
            } else {
                printf("❌ %s is DOWN 😱\n", urls[i]);
            }
        }

        printf("\nNext check in %d seconds...\n", PING_INTERVAL);
        sleep(PING_INTERVAL);
    }
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <url1> <url2> ... <urlN>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int url_count = argc - 1;
    char **urls = &argv[1];

    printf("Welcome to the 🌐 Website Uptime Monitor! 🌟\n");
    printf("Monitoring %d websites...\n", url_count);
    
    monitor_websites(urls, url_count);

    return EXIT_SUCCESS;
}