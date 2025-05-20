//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>

// Maximum number of URLs to monitor
#define MAX_URLS 10

// URL structure
typedef struct {
    char *url;
    int port;
} url_t;

// Global variables
url_t urls[MAX_URLS];
int num_urls = 0;

// Function to add a URL to the monitoring list
void add_url(char *url, int port) {
    if (num_urls >= MAX_URLS) {
        fprintf(stderr, "Error: Maximum number of URLs reached\n");
        return;
    }

    urls[num_urls].url = strdup(url);
    urls[num_urls].port = port;
    num_urls++;
}

// Function to check the uptime of a URL
int check_uptime(url_t *url) {
    struct sockaddr_in server_addr;
    int sockfd;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        return -1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(url->url);
    if (host == NULL) {
        perror("gethostbyname");
        close(sockfd);
        return -1;
    }

    // Set up the server address
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(url->port);
    memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("connect");
        close(sockfd);
        return -1;
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: ";
    strncat(request, url->url, sizeof(request) - strlen(request) - 1);
    strncat(request, "\r\n\r\n", sizeof(request) - strlen(request) - 1);
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("send");
        close(sockfd);
        return -1;
    }

    // Receive the response from the server
    char response[4096];
    int bytes_received = recv(sockfd, response, sizeof(response) - 1, 0);
    if (bytes_received < 0) {
        perror("recv");
        close(sockfd);
        return -1;
    }

    // Close the socket
    close(sockfd);

    // Check the response code
    if (bytes_received >= 9 && strncmp(response, "HTTP/1.1 200 OK", 15) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main(int argc, char **argv) {
    // Add URLs to the monitoring list
    add_url("www.example.com", 80);
    add_url("www.google.com", 443);
    add_url("www.facebook.com", 443);

    // Check the uptime of each URL
    for (int i = 0; i < num_urls; i++) {
        int uptime = check_uptime(&urls[i]);
        if (uptime) {
            printf("URL %s is up\n", urls[i].url);
        } else {
            printf("URL %s is down\n", urls[i].url);
        }
    }

    // Free the allocated memory
    for (int i = 0; i < num_urls; i++) {
        free(urls[i].url);
    }

    return 0;
}