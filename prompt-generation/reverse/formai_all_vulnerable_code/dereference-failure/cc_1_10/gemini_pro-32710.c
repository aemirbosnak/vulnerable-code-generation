//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Define the maximum number of websites to monitor
#define MAX_WEBSITES 10

// Define the maximum length of a website URL
#define MAX_URL_LENGTH 256

// Define the default port number for HTTP
#define DEFAULT_PORT 80

// Define the timeout for connecting to a website in seconds
#define TIMEOUT 5

// Define the interval between checks in seconds
#define INTERVAL 60

// Create a structure to store the information about each website
typedef struct website {
    char *url;
    int port;
    int status;
    time_t last_checked;
} website;

// Create an array to store the websites to monitor
website websites[MAX_WEBSITES];

// Create a socket for connecting to websites
int sockfd;

// Function to check if a website is up
int is_up(website *website) {
    // Create a sockaddr_in structure to store the address of the website
    struct sockaddr_in addr;
    
    // Set the address family to AF_INET
    addr.sin_family = AF_INET;
    
    // Set the port number
    addr.sin_port = htons(website->port);
    
    // Get the IP address of the website
    struct hostent *host = gethostbyname(website->url);
    if (host == NULL) {
        return 0;
    }
    addr.sin_addr = *((struct in_addr *)host->h_addr);
    
    // Create a socket for connecting to the website
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        return 0;
    }
    
    // Set a timeout for connecting to the website
    struct timeval timeout;
    timeout.tv_sec = TIMEOUT;
    timeout.tv_usec = 0;
    setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &timeout, sizeof(timeout));
    
    // Connect to the website
    if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
        close(sockfd);
        return 0;
    }
    
    // Close the socket
    close(sockfd);
    
    // The website is up
    return 1;
}

// Function to check the status of all websites
void check_websites() {
    // Loop through all the websites
    for (int i = 0; i < MAX_WEBSITES; i++) {
        // Check if the website is up
        int status = is_up(&websites[i]);
        
        // Update the website's status
        websites[i].status = status;
        
        // Update the website's last checked time
        websites[i].last_checked = time(NULL);
    }
}

// Function to print the status of all websites
void print_status() {
    // Loop through all the websites
    for (int i = 0; i < MAX_WEBSITES; i++) {
        // Print the website's URL
        printf("%s\n", websites[i].url);
        
        // Print the website's status
        if (websites[i].status) {
            printf("  Status: Up\n");
        } else {
            printf("  Status: Down\n");
        }
        
        // Print the website's last checked time
        printf("  Last checked: %s\n", ctime(&websites[i].last_checked));
    }
}

// Main function
int main() {
    // Create a socket for connecting to websites
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }
    
    // Set the websites to monitor
    websites[0].url = "www.google.com";
    websites[0].port = DEFAULT_PORT;
    websites[1].url = "www.facebook.com";
    websites[1].port = DEFAULT_PORT;
    websites[2].url = "www.amazon.com";
    websites[2].port = DEFAULT_PORT;
    
    // Check the status of the websites
    check_websites();
    
    // Print the status of the websites
    print_status();
    
    // Loop forever
    while (1) {
        // Sleep for the interval
        sleep(INTERVAL);
        
        // Check the status of the websites
        check_websites();
        
        // Print the status of the websites
        print_status();
    }
    
    // Close the socket
    close(sockfd);
    
    return EXIT_SUCCESS;
}