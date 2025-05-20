//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

// Custom data structure to store website information
typedef struct website {
    char *url;
    int port;
    time_t last_checked;
    int status_code;
} website_t;

// Function to create a new website object
website_t *website_new(char *url, int port) {
    website_t *website = malloc(sizeof(website_t));
    website->url = strdup(url);
    website->port = port;
    website->last_checked = time(NULL);
    website->status_code = -1;
    return website;
}

// Function to free the memory allocated for a website object
void website_free(website_t *website) {
    free(website->url);
    free(website);
}

// Function to check the uptime of a website
int website_check_uptime(website_t *website) {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        return -1;
    }

    // Resolve the hostname
    struct hostent *host = gethostbyname(website->url);
    if (host == NULL) {
        herror("gethostbyname");
        return -1;
    }

    // Create a sockaddr_in structure
    struct sockaddr_in addr;
    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_port = htons(website->port);
    addr.sin_addr = *(struct in_addr *)host->h_addr;

    // Connect to the website
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        perror("connect");
        return -1;
    }

    // Send an HTTP request
    char request[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("send");
        return -1;
    }

    // Receive the HTTP response
    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("recv");
        return -1;
    }

    // Parse the HTTP response
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL) {
        fprintf(stderr, "Invalid HTTP response\n");
        return -1;
    }

    // Extract the status code from the status line
    char *status_code = strtok(status_line, " ");
    if (status_code == NULL) {
        fprintf(stderr, "Invalid HTTP response\n");
        return -1;
    }

    // Convert the status code to an integer
    website->status_code = atoi(status_code);

    // Close the socket
    close(sockfd);

    // Return the status code
    return website->status_code;
}

// Function to print the uptime of a website
void website_print_uptime(website_t *website) {
    // Get the current time
    time_t now = time(NULL);

    // Calculate the uptime
    long uptime = now - website->last_checked;

    // Print the uptime
    printf("%s: %ld seconds\n", website->url, uptime);
}

// Main function
int main(int argc, char *argv[]) {
    // Create a list of websites to monitor
    website_t *websites[] = {
        website_new("www.example.com", 80),
        website_new("www.google.com", 80),
        website_new("www.facebook.com", 80),
    };

    // Check the uptime of each website
    for (int i = 0; i < sizeof(websites) / sizeof(website_t *); i++) {
        website_check_uptime(websites[i]);
    }

    // Print the uptime of each website
    for (int i = 0; i < sizeof(websites) / sizeof(website_t *); i++) {
        website_print_uptime(websites[i]);
    }

    // Free the memory allocated for each website
    for (int i = 0; i < sizeof(websites) / sizeof(website_t *); i++) {
        website_free(websites[i]);
    }

    return 0;
}