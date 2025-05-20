//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <errno.h>

#define MAX_URLS 100
#define MAX_THREADS 10
#define TIMEOUT_SECONDS 10

typedef struct {
    char *url;
    int port;
} url_info;

typedef struct {
    int sockfd;
    url_info *url;
} thread_args;

void *thread_function(void *arg) {
    thread_args *args = (thread_args *)arg;
    int sockfd = args->sockfd;
    url_info *url = args->url;
    
    struct sockaddr_in dest_addr;
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(url->port);
    dest_addr.sin_addr.s_addr = inet_addr(url->url);
    
    if (connect(sockfd, (struct sockaddr *)&dest_addr, sizeof(dest_addr)) < 0) {
        printf("Error connecting to %s:%d: %s\n", url->url, url->port, strerror(errno));
        close(sockfd);
        return NULL;
    }
    
    // Send HTTP GET request
    char request[] = "GET / HTTP/1.1\r\nHost: ";
    strcat(request, url->url);
    strcat(request, "\r\n\r\n");
    if (send(sockfd, request, strlen(request), 0) < 0) {
        printf("Error sending request to %s:%d: %s\n", url->url, url->port, strerror(errno));
        close(sockfd);
        return NULL;
    }
    
    // Receive HTTP response
    char buffer[1024];
    int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
    if (bytes_received < 0) {
        printf("Error receiving response from %s:%d: %s\n", url->url, url->port, strerror(errno));
        close(sockfd);
        return NULL;
    }
    
    // Check HTTP response code
    char *status_line = strstr(buffer, "HTTP/1.1 ");
    if (status_line == NULL) {
        printf("Error parsing response from %s:%d: Invalid HTTP response\n", url->url, url->port);
        close(sockfd);
        return NULL;
    }
    
    int status_code = atoi(status_line + 9);
    if (status_code != 200) {
        printf("Error: %s:%d returned HTTP status code %d\n", url->url, url->port, status_code);
        close(sockfd);
        return NULL;
    }
    
    // Success!
    printf("%s:%d is up and running!\n", url->url, url->port);
    close(sockfd);
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <URL1> [URL2] ... [URLN]\n", argv[0]);
        return 1;
    }
    
    int num_urls = argc - 1;
    if (num_urls > MAX_URLS) {
        printf("Error: Maximum number of URLs exceeded (%d)\n", MAX_URLS);
        return 1;
    }
    
    url_info urls[MAX_URLS];
    for (int i = 0; i < num_urls; i++) {
        char *url = argv[i + 1];
        char *port_str = strchr(url, ':');
        if (port_str == NULL) {
            urls[i].url = malloc(strlen(url) + 1);
            strcpy(urls[i].url, url);
            urls[i].port = 80;
        } else {
            *port_str = '\0';
            urls[i].url = malloc(strlen(url) + 1);
            strcpy(urls[i].url, url);
            urls[i].port = atoi(port_str + 1);
        }
    }
    
    pthread_t threads[MAX_THREADS];
    thread_args args[MAX_THREADS];
    int num_threads = num_urls < MAX_THREADS ? num_urls : MAX_THREADS;
    
    for (int i = 0; i < num_threads; i++) {
        int sockfd = socket(AF_INET, SOCK_STREAM, 0);
        if (sockfd < 0) {
            printf("Error creating socket: %s\n", strerror(errno));
            return 1;
        }
        
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT_SECONDS;
        timeout.tv_usec = 0;
        if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char *)&timeout, sizeof(timeout)) < 0) {
            printf("Error setting socket timeout: %s\n", strerror(errno));
            close(sockfd);
            return 1;
        }
        
        args[i].sockfd = sockfd;
        args[i].url = &urls[i];
        if (pthread_create(&threads[i], NULL, thread_function, &args[i]) != 0) {
            printf("Error creating thread: %s\n", strerror(errno));
            close(sockfd);
            return 1;
        }
    }
    
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    for (int i = 0; i < num_urls; i++) {
        free(urls[i].url);
    }
    
    return 0;
}