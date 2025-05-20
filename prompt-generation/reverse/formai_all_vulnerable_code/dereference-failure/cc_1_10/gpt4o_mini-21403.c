//GPT-4o-mini DATASET v1.0 Category: Website Uptime Monitor ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define BUFFER_SIZE 1024

void check_website(const char *hostname);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <hostname>\n", argv[0]);
        return 1;
    }
    
    const char *hostname = argv[1];
    while (1) {
        check_website(hostname);
        sleep(5); // Check every 5 seconds
    }
    
    return 0;
}

void check_website(const char *hostname) {
    struct sockaddr_in server;
    struct hostent *host;
    
    host = gethostbyname(hostname);
    if (host == NULL) {
        printf("[%s] Domain resolution failed\n", hostname);
        return;
    }

    server.sin_family = AF_INET;
    server.sin_port = htons(80);
    memcpy(&server.sin_addr.s_addr, host->h_addr, host->h_length);
    
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        printf("[%s] Socket creation failed\n", hostname);
        return;
    }
    
    if (connect(sockfd, (struct sockaddr*)&server, sizeof(server)) < 0) {
        printf("[%s] DOWN\n", hostname);
    } else {
        printf("[%s] UP\n", hostname);
    }
    
    close(sockfd);
}