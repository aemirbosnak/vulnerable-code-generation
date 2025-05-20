//FormAI DATASET v1.0 Category: Port Scanner ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <pthread.h>

#define MAX_THREADS 100

struct thread_info {
    pthread_t thread_id;       
    int sockfd;
    struct sockaddr_in* server_addr;
    int port;
};

struct thread_info thread_pool[MAX_THREADS];
int num_threads = 0;

char* get_banner(int sockfd) {
    char* banner = (char*)malloc(sizeof(char) * 1000);
    int nbytes;
    memset(banner, 0, sizeof(char) * 1000);

    // Receive banner from the server
    if ((nbytes = recv(sockfd, banner, 1000, 0)) != -1) {
        return banner;
    }

    free(banner);
    return NULL;
}

void scan_port(int sockfd, struct sockaddr_in* server_addr, int port) {
    int result;

    // Connect to the server
    if ((result = connect(sockfd, (struct sockaddr*) server_addr, sizeof(struct sockaddr_in))) == -1) {
        close(sockfd);
        pthread_exit(NULL);
    }

    // Get the banner from the server
    char* banner = get_banner(sockfd);

    // Print the result
    printf("\nPort %d is open on %s\n", port, inet_ntoa(server_addr->sin_addr));
    if (banner != NULL) {
        printf("%s\n", banner);
        free(banner);
    }

    close(sockfd);
    pthread_exit(NULL);
}

void start_scanner(char* ip, int start_port, int end_port, int num_threads) {
    int sockfd;

    // Create a socket for the scanner
    if ((sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP)) == -1) {
        printf("Error creating socket.\n");
        exit(1);
    }

    // Set up the server address structure
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(start_port);
    inet_pton(AF_INET, ip, &server_addr.sin_addr);

    // Create threads
    while (start_port <= end_port) {
        if (num_threads == MAX_THREADS) {
            printf("Cannot create more threads.\n");
            break;
        }

        struct thread_info* thread = &thread_pool[num_threads];

        // Setup thread information
        thread->sockfd = sockfd;
        thread->server_addr = &server_addr;
        thread->port = start_port;

        // Create the thread
        pthread_create(&thread->thread_id, NULL, (void*) &scan_port, (void*) thread);

        num_threads++;
        start_port++;
    } 

    // Wait for all threads to finish
    for (int i = 0; i < num_threads; i++) {
        pthread_join(thread_pool[i].thread_id, NULL);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 4) {
        printf("Usage: ./scanner <IP> <starting_port> <ending_port>\n");
        exit(1);
    }

    char* ip = argv[1];
    int start_port = atoi(argv[2]);
    int end_port = atoi(argv[3]);

    if (start_port >= end_port) {
        printf("Invalid port range.\n");
        exit(1);
    }

    start_scanner(ip, start_port, end_port, num_threads);

    return 0;
}