//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>
#include <unistd.h>

// Custom data structure to hold website information
typedef struct website {
    char *url;
    char *ip_address;
    int port;
    int status_code;
    time_t last_checked;
} website;

// Function to create a new website object
website *create_website(char *url, char *ip_address, int port) {
    website *new_website = malloc(sizeof(website));
    new_website->url = strdup(url);
    new_website->ip_address = strdup(ip_address);
    new_website->port = port;
    new_website->status_code = 0;
    new_website->last_checked = 0;
    return new_website;
}

// Function to check the status code of a website
int check_status_code(website *website) {
    int sockfd, n;
    struct sockaddr_in servaddr;

    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr(website->ip_address);
    servaddr.sin_port = htons(website->port);

    if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
        perror("ERROR connecting");
        return -1;
    }

    char request[1024];
    sprintf(request, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", website->url);

    n = write(sockfd, request, strlen(request));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }

    char response[1024];
    n = read(sockfd, response, sizeof(response) - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }

    // Parse the HTTP response and extract the status code
    char *status_line = strtok(response, "\r\n");
    if (!status_line) {
        fprintf(stderr, "ERROR parsing HTTP response\n");
        return -1;
    }

    char *status_code_str = strtok(status_line, " ");
    if (!status_code_str) {
        fprintf(stderr, "ERROR parsing HTTP status code\n");
        return -1;
    }

    int status_code = atoi(status_code_str);

    close(sockfd);

    return status_code;
}

// Function to monitor the uptime of a website
void monitor_website(website *website) {
    int status_code = check_status_code(website);
    if (status_code == 200) {
        printf("%s is up and running\n", website->url);
    } else {
        printf("%s is down! Status code: %d\n", website->url, status_code);
    }

    website->status_code = status_code;
    website->last_checked = time(NULL);
}

// Main function
int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <website URL>\n", argv[0]);
        return 1;
    }

    char *url = argv[1];

    // Get the IP address of the website
    struct hostent *host_info = gethostbyname(url);
    if (!host_info) {
        fprintf(stderr, "ERROR resolving hostname\n");
        return 1;
    }

    char *ip_address = inet_ntoa(*((struct in_addr *) host_info->h_addr));

    // Create a new website object
    website *website = create_website(url, ip_address, 80);

    // Monitor the website every 5 seconds
    while (1) {
        monitor_website(website);
        sleep(5);
    }

    return 0;
}