//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_URLS 1000
#define MAX_URL_LEN 256
#define DEFAULT_INTERVAL 60

// Structure to store website data
typedef struct website {
    char url[MAX_URL_LEN];
    int status;
    time_t last_checked;
} website_t;

// Function to check website status
int check_website(char *url) {
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    char buffer[256];

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("ERROR opening socket");
        return -1;
    }

    // Set the server address
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(80);
    serv_addr.sin_addr.s_addr = inet_addr(url);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        return -1;
    }

    // Send the HTTP request
    sprintf(buffer, "GET / HTTP/1.1\r\nHost: %s\r\n\r\n", url);
    n = write(sockfd, buffer, strlen(buffer));
    if (n < 0) {
        perror("ERROR writing to socket");
        return -1;
    }

    // Read the HTTP response
    n = read(sockfd, buffer, sizeof(buffer) - 1);
    if (n < 0) {
        perror("ERROR reading from socket");
        return -1;
    }

    // Close the socket
    close(sockfd);

    // Check the HTTP status code
    if (strncmp(buffer, "HTTP/1.1 200 OK", 15) == 0) {
        return 1;
    } else {
        return 0;
    }
}

// Function to print website status
void print_website_status(website_t website) {
    printf("URL: %s\n", website.url);
    printf("Status: %s\n", website.status ? "Up" : "Down");
    printf("Last checked: %s\n", ctime(&website.last_checked));
    printf("\n");
}

// Main function
int main(int argc, char **argv) {
    // Define the array of websites
    website_t websites[MAX_URLS];

    // Get the list of websites from the command line
    int num_websites = 0;
    for (int i = 1; i < argc; i++) {
        if (num_websites < MAX_URLS) {
            strncpy(websites[num_websites].url, argv[i], MAX_URL_LEN);
            websites[num_websites].status = -1;
            websites[num_websites].last_checked = 0;
            num_websites++;
        }
    }

    // Check the websites every 60 seconds
    int interval = DEFAULT_INTERVAL;
    while (1) {
        // Check each website
        for (int i = 0; i < num_websites; i++) {
            // Check the website status
            websites[i].status = check_website(websites[i].url);

            // Update the last checked time
            websites[i].last_checked = time(NULL);
        }

        // Print the website status
        for (int i = 0; i < num_websites; i++) {
            print_website_status(websites[i]);
        }

        // Sleep for 60 seconds
        sleep(interval);
    }

    return 0;
}