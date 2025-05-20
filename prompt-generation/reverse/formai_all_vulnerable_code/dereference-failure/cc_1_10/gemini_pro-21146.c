//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

// Define the maximum number of URLs to monitor
#define MAX_URLS 100

// Define the maximum length of a URL
#define MAX_URL_LENGTH 255

// Define the time interval between checks (in seconds)
#define CHECK_INTERVAL 60

// Define the number of threads to use for monitoring
#define NUM_THREADS 4

// Define the structure of a URL to monitor
typedef struct url_monitor {
    char url[MAX_URL_LENGTH];
    int status;
} url_monitor;

// Define the structure of a thread argument
typedef struct thread_arg {
    url_monitor *urls;
    int num_urls;
} thread_arg;

// Define the thread function
void *thread_function(void *arg) {
    thread_arg *ta = (thread_arg *)arg;
    url_monitor *urls = ta->urls;
    int num_urls = ta->num_urls;

    // Loop through the URLs and check their status
    for (int i = 0; i < num_urls; i++) {
        // Create a socket
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd == -1) {
            perror("socket");
            exit(1);
        }

        // Parse the URL
        struct sockaddr_in addr;
        memset(&addr, 0, sizeof(addr));
        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);
        if (inet_pton(AF_INET, urls[i].url, &addr.sin_addr) <= 0) {
            perror("inet_pton");
            exit(1);
        }

        // Connect to the URL
        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
            perror("connect");
            urls[i].status = -1;
        } else {
            urls[i].status = 0;
        }

        // Close the socket
        close(sockfd);

        // Sleep for the specified interval
        sleep(CHECK_INTERVAL);
    }

    return NULL;
}

// Main function
int main(int argc, char *argv[]) {
    // Check if the number of arguments is valid
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <URL1> <URL2> ... <URLN>\n", argv[0]);
        exit(1);
    }

    // Get the number of URLs to monitor
    int num_urls = argc - 1;

    // Check if the number of URLs is valid
    if (num_urls > MAX_URLS) {
        fprintf(stderr, "Error: Too many URLs to monitor (maximum: %d)\n", MAX_URLS);
        exit(1);
    }

    // Create an array of URLs to monitor
    url_monitor urls[num_urls];
    for (int i = 0; i < num_urls; i++) {
        strcpy(urls[i].url, argv[i + 1]);
        urls[i].status = -1;
    }

    // Create an array of thread arguments
    thread_arg ta[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        ta[i].urls = urls;
        ta[i].num_urls = num_urls / NUM_THREADS;
        if (i == NUM_THREADS - 1) {
            ta[i].num_urls += num_urls % NUM_THREADS;
        }
    }

    // Create the threads
    pthread_t threads[NUM_THREADS];
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_create(&threads[i], NULL, thread_function, &ta[i]) != 0) {
            perror("pthread_create");
            exit(1);
        }
    }

    // Join the threads
    for (int i = 0; i < NUM_THREADS; i++) {
        if (pthread_join(threads[i], NULL) != 0) {
            perror("pthread_join");
            exit(1);
        }
    }

    // Print the status of each URL
    for (int i = 0; i < num_urls; i++) {
        printf("%s: %d\n", urls[i].url, urls[i].status);
    }

    return 0;
}