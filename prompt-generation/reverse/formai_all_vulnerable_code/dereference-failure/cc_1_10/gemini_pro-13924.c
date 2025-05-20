//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define MAX_URL_LENGTH 256
#define MAX_RESPONSE_LENGTH 4096

// Function to get the IP address of a given hostname
char *get_ip_address(char *hostname) {
    struct hostent *host_info = gethostbyname(hostname);
    if (host_info == NULL) {
        return NULL;
    }

    char *ip_address = inet_ntoa(*((struct in_addr *) host_info->h_addr));
    return strdup(ip_address);
}

// Function to send an HTTP GET request to a given URL
int send_http_get_request(char *url, char *response) {
    char *hostname;
    char *path;
    char *port;
    char *request;

    // Parse the URL
    hostname = strtok(url, ":");
    path = strtok(NULL, ":");
    port = strtok(NULL, "/");

    // Create the HTTP GET request
    request = malloc(strlen(hostname) + strlen(path) + strlen(port) + 100);
    sprintf(request, "GET %s HTTP/1.1\r\n"
                     "Host: %s\r\n"
                     "Connection: Keep-Alive\r\n"
                     "\r\n",
                     path, hostname);

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return -1;
    }

    // Connect to the server
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(atoi(port));
    server_addr.sin_addr.s_addr = inet_addr(hostname);

    if (connect(sockfd, (struct sockaddr *) &server_addr, sizeof(server_addr)) == -1) {
        return -1;
    }

    // Send the HTTP GET request
    if (send(sockfd, request, strlen(request), 0) == -1) {
        return -1;
    }

    // Receive the response
    int bytes_received = recv(sockfd, response, MAX_RESPONSE_LENGTH, 0);
    if (bytes_received == -1) {
        return -1;
    }

    // Close the socket
    close(sockfd);

    return bytes_received;
}

// Function to check if a website is up
int is_website_up(char *url) {
    char response[MAX_RESPONSE_LENGTH];

    // Send an HTTP GET request to the website
    int bytes_received = send_http_get_request(url, response);
    if (bytes_received == -1) {
        return 0;
    }

    // Check the response code
    char *status_line = strtok(response, "\r\n");
    if (status_line == NULL) {
        return 0;
    }

    char *status_code = strtok(status_line, " ");
    if (status_code == NULL) {
        return 0;
    }

    if (atoi(status_code) >= 200 && atoi(status_code) < 300) {
        return 1;
    } else {
        return 0;
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <url>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];

    // Get the current time
    time_t now = time(NULL);

    // Check if the website is up
    int is_up = is_website_up(url);

    // Print the results
    if (is_up) {
        printf("%s is up at %s\n", url, ctime(&now));
    } else {
        printf("%s is down at %s\n", url, ctime(&now));
    }

    return 0;
}