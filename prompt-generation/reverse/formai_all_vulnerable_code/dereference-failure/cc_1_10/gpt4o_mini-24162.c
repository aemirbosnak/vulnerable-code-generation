//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>

#define MAX_THREADS 100
#define PORT_START 1
#define PORT_END 65535

typedef struct {
    char *ip;
    int port;
} port_info;

void *check_port(void *arg) {
    port_info *info = (port_info *) arg;
    int sockfd;
    
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation failed");
        pthread_exit(NULL);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(info->port);
    inet_pton(AF_INET, info->ip, &server_addr.sin_addr);

    int connection_status = connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr));

    if (connection_status == 0) {
        printf("Port %d is open\n", info->port);
    }
    
    close(sockfd);
    free(info);
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <IP> <number_of_threads>\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    char *ip_address = argv[1];
    int num_threads = atoi(argv[2]);
    pthread_t threads[MAX_THREADS];

    if (num_threads > MAX_THREADS) {
        fprintf(stderr, "Number of threads exceeds maximum limit of %d\n", MAX_THREADS);
        exit(EXIT_FAILURE);
    }
    
    for (int port = PORT_START; port <= PORT_END; port++) {
        port_info *info = malloc(sizeof(port_info));
        info->ip = ip_address;
        info->port = port;
        
        if (pthread_create(&threads[port % num_threads], NULL, check_port, info) != 0) {
            perror("Failed to create thread");
            free(info);
            exit(EXIT_FAILURE);
        }

        if (port % num_threads == (num_threads - 1)) {
            for (int i = 0; i < num_threads; i++) {
                pthread_join(threads[i], NULL);
            }
        }
    }
    
    // Join any remaining threads
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }
    
    printf("Port scanning completed for IP: %s\n", ip_address);
    return 0;
}