//GEMINI-pro DATASET v1.0 Category: Website Uptime Monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdbool.h>
#include <inttypes.h>
#include <pthread.h>
#include <poll.h>

struct website {
    char *url;
    int port;
    char *path;
    size_t interval;
    struct website *next;
};

struct website *websites = NULL;

struct result {
    char *url;
    size_t duration;
    bool success;
    bool changed;
    struct result *next;
};

struct result *results = NULL;

pthread_t *threads;
size_t num_threads;

void *worker_thread(void *arg) {
    while (true) {
        struct website *website = websites;
        
        while (website != NULL) {
            struct timeval start, end;
            gettimeofday(&start, NULL);
            
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd == -1) {
                perror("socket");
                exit(1);
            }
            
            struct hostent *server = gethostbyname(website->url);
            if (server == NULL) {
                perror("gethostbyname");
                exit(1);
            }
            
            struct sockaddr_in serv_addr;
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(website->port);
            memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
            
            if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
                perror("connect");
                exit(1);
            }
            
            char request[1024];
            sprintf(request, "GET %s HTTP/1.1\r\nHost: %s\r\nConnection: close\r\n\r\n", website->path, website->url);
            
            if (send(sockfd, request, strlen(request), 0) == -1) {
                perror("send");
                exit(1);
            }
            
            char response[1024];
            int bytes_received = recv(sockfd, response, sizeof(response), 0);
            if (bytes_received == -1) {
                perror("recv");
                exit(1);
            }
            
            gettimeofday(&end, NULL);
            
            bool success = false;
            if (bytes_received > 0) {
                if (strstr(response, "HTTP/1.1 200 OK") != NULL) {
                    success = true;
                }
            }
            
            close(sockfd);
            
            size_t duration = (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000;
            
            struct result *result = malloc(sizeof(struct result));
            result->url = website->url;
            result->duration = duration;
            result->success = success;
            result->changed = false;
            result->next = results;
            results = result;
            
            website = website->next;
            
            usleep(website->interval * 1000);
        }
    }
    
    return NULL;
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <website1> <website2> ... <websiteN>\n", argv[0]);
        exit(1);
    }
    
    for (int i = 1; i < argc; i++) {
        char *url = argv[i];
        
        struct website *website = malloc(sizeof(struct website));
        website->url = url;
        website->port = 80;
        website->path = "/";
        website->interval = 60;
        website->next = websites;
        websites = website;
    }
    
    num_threads = sysconf(_SC_NPROCESSORS_ONLN);
    threads = malloc(sizeof(pthread_t) * num_threads);
    
    for (size_t i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, worker_thread, NULL);
    }
    
    while (true) {
        struct result *result = results;
        
        while (result != NULL) {
            if (result->changed) {
                printf("%s: %s (%lu ms)\n", result->url, result->success ? "up" : "down", result->duration);
            }
            
            result = result->next;
        }
        
        sleep(1);
    }
    
    return 0;
}