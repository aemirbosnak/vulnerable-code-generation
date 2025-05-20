//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/socket.h>
#include <pthread.h>

// A shape-shifting thread that resolves and prints hostnames.
typedef struct shape_shifter {
    char *hostname;
    struct sockaddr_in addr;
} shape_shifter;

void *shift_shape(void *arg) {
    struct shape_shifter *shape = (struct shape_shifter *)arg;
    struct hostent *host = gethostbyname(shape->hostname);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }
    memcpy(&shape->addr.sin_addr, host->h_addr, host->h_length);
    printf("Resolved hostname %s to IP address %s.\n", shape->hostname, inet_ntoa(shape->addr.sin_addr));
    return NULL;
}

int main(int argc, char **argv) {
    // Create a thread pool of shape-shifting threads.
    int num_threads = 10;
    pthread_t *threads = malloc(num_threads * sizeof(pthread_t));

    // Assign each thread a hostname to resolve.
    char *hostnames[] = {"www.google.com", "www.amazon.com", "www.facebook.com", "www.microsoft.com", "www.apple.com",
                         "www.ibm.com", "www.oracle.com", "www.sap.com", "www.salesforce.com", "www.cisco.com"};
    struct shape_shifter shapes[num_threads];
    for (int i = 0; i < num_threads; i++) {
        shapes[i].hostname = hostnames[i];
    }

    // Start the shape-shifting threads.
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, shift_shape, &shapes[i]);
    }

    // Wait for the shape-shifting threads to finish.
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Cleanup.
    free(threads);

    return EXIT_SUCCESS;
}