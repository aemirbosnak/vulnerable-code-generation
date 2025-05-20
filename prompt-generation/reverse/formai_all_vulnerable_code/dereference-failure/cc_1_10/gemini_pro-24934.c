//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 10

// Structure to store thread-specific data
typedef struct thread_data {
    int sockfd;
    struct sockaddr_in servaddr;
    int num_hops;
} thread_data;

// Function to perform network topology mapping
void* map_topology(void* arg) {
    thread_data* data = (thread_data*)arg;

    // Send a probe message to the destination IP address
    char probe_msg[] = "PROBE";
    sendto(data->sockfd, probe_msg, strlen(probe_msg), 0, (struct sockaddr*)&data->servaddr, sizeof(data->servaddr));

    // Receive the probe response and process it
    char resp_msg[1024];
    socklen_t resp_len = sizeof(data->servaddr);
    recvfrom(data->sockfd, resp_msg, sizeof(resp_msg), 0, (struct sockaddr*)&data->servaddr, &resp_len);

    // Extract the hop count from the response message
    char* hop_count_str = strstr(resp_msg, "HOP_COUNT=");
    if (hop_count_str != NULL) {
        hop_count_str += strlen("HOP_COUNT=");
        data->num_hops = atoi(hop_count_str);
    }

    // Print the number of hops to the destination
    printf("Number of hops to %s: %d\n", inet_ntoa(data->servaddr.sin_addr), data->num_hops);

    // Close the socket
    close(data->sockfd);

    // Free the thread-specific data
    free(data);

    return NULL;
}

int main() {
    // Create a socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set up the server address and port
    struct sockaddr_in servaddr;
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(5000);

    // Create a thread pool
    pthread_t threads[MAX_THREADS];

    // Create threads to map the network topology
    for (int i = 0; i < MAX_THREADS; i++) {
        // Set up thread-specific data
        thread_data* data = malloc(sizeof(thread_data));
        data->sockfd = sockfd;
        data->servaddr = servaddr;
        data->num_hops = 0;

        // Create a new thread
        if (pthread_create(&threads[i], NULL, map_topology, (void*)data) != 0) {
            perror("pthread_create");
            exit(EXIT_FAILURE);
        }
    }

    // Join all threads
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    // Close the socket
    close(sockfd);

    return EXIT_SUCCESS;
}