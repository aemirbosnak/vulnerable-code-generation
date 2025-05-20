//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

// Our very own website uptime monitor!
// Let's keep an eye on those precious servers.

// Function to check if a website is up
int is_website_up(char *hostname) {
    // Step 1: Resolve hostname to IP address
    struct hostent *host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        fprintf(stderr, "Couldn't resolve hostname: %s\n", hostname);
        return -1;
    }

    // Step 2: Create a socket to connect to the website
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("Couldn't create socket");
        return -1;
    }

    // Step 3: Connect to the website
    struct sockaddr_in server_address;
    memset(&server_address, 0, sizeof(server_address));
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(80); // HTTP port
    memcpy(&server_address.sin_addr.s_addr, host_info->h_addr_list[0], host_info->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) == -1) {
        perror("Couldn't connect to website");
        close(sockfd);
        return -1;
    }

    // Step 4: Send a request to the website
    char request[] = "GET / HTTP/1.1\r\nHost: example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) == -1) {
        perror("Couldn't send request to website");
        close(sockfd);
        return -1;
    }

    // Step 5: Receive a response from the website
    char response[1024];
    if (recv(sockfd, response, sizeof(response), 0) == -1) {
        perror("Couldn't receive response from website");
        close(sockfd);
        return -1;
    }

    // Step 6: Check the response code
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL || strncmp(status_line, "HTTP/1.1 200 OK", 16) != 0) {
        fprintf(stderr, "Website not responding with 200 OK: %s\n", status_line);
        close(sockfd);
        return -1;
    }

    // Website is up!
    close(sockfd);
    return 0;
}

// Function to monitor a website and print the status
void monitor_website(char *hostname) {
    while (1) {
        int status = is_website_up(hostname);
        if (status == 0) {
            printf("%s is up!\n", hostname);
        } else {
            printf("%s is down!\n", hostname);
        }

        // Let's wait a bit before checking again
        sleep(60);
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
        return 1;
    }

    // Start monitoring the website
    monitor_website(argv[1]);

    return 0;
}