//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_URLS 100
#define MAX_URL_LENGTH 256
#define MAX_TIMEOUT 60

int num_urls;
char urls[MAX_URLS][MAX_URL_LENGTH];
int timeouts[MAX_URLS];

pthread_mutex_t lock;

// Function to check the uptime of a URL
void *check_uptime(void *arg)
{
    int index = *(int *)arg;
    int sockfd;
    struct sockaddr_in servaddr;
    char buf[1024];
    int n;

    // Resolve the URL to an IP address
    struct hostent *host = gethostbyname(urls[index]);
    if (host == NULL) {
        printf("Error resolving hostname %s\n", urls[index]);
        return NULL;
    }

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        printf("Error creating socket\n");
        return NULL;
    }

    // Set the socket timeout
    struct timeval tv;
    tv.tv_sec = timeouts[index];
    tv.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
        printf("Error setting socket timeout\n");
        return NULL;
    }

    // Connect to the server
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(80);
    servaddr.sin_addr = *(struct in_addr *)host->h_addr;
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        printf("Error connecting to server %s\n", urls[index]);
        return NULL;
    }

    // Send a request to the server
    const char *request = "HEAD / HTTP/1.1\r\nHost: %s\r\n\r\n";
    n = sprintf(buf, request, urls[index]);
    if (send(sockfd, buf, n, 0) == -1) {
        printf("Error sending request to server %s\n", urls[index]);
        return NULL;
    }

    // Receive the response from the server
    n = recv(sockfd, buf, sizeof(buf) - 1, 0);
    if (n == -1) {
        printf("Error receiving response from server %s\n", urls[index]);
        return NULL;
    }

    // Close the socket
    close(sockfd);

    // Check the response code
    char *status_line = strtok(buf, "\r\n");
    if (status_line == NULL) {
        printf("Error parsing response from server %s\n", urls[index]);
        return NULL;
    }

    char *status_code = strtok(status_line, " ");
    if (status_code == NULL) {
        printf("Error parsing response from server %s\n", urls[index]);
        return NULL;
    }

    // Update the uptime status
    pthread_mutex_lock(&lock);
    if (strcmp(status_code, "200") == 0) {
        timeouts[index] = MAX_TIMEOUT;
    } else {
        timeouts[index] = 0;
    }
    pthread_mutex_unlock(&lock);

    return NULL;
}

// Main function
int main(int argc, char *argv[])
{
    // Parse the command-line arguments
    if (argc < 2) {
        printf("Usage: %s <URL> [<URL> ...]\n", argv[0]);
        return 1;
    }

    num_urls = argc - 1;
    for (int i = 0; i < num_urls; i++) {
        strncpy(urls[i], argv[i + 1], MAX_URL_LENGTH);
        timeouts[i] = MAX_TIMEOUT;
    }

    // Initialize the mutex
    pthread_mutex_init(&lock, NULL);

    // Create a thread to check the uptime of each URL
    pthread_t threads[num_urls];
    for (int i = 0; i < num_urls; i++) {
        int *arg = malloc(sizeof(int));
        *arg = i;
        pthread_create(&threads[i], NULL, check_uptime, arg);
    }

    // Join all the threads
    for (int i = 0; i < num_urls; i++) {
        pthread_join(threads[i], NULL);
    }

    // Print the uptime status of each URL
    for (int i = 0; i < num_urls; i++) {
        printf("%s: %s\n", urls[i], timeouts[i] ? "Up" : "Down");
    }

    // Destroy the mutex
    pthread_mutex_destroy(&lock);

    return 0;
}