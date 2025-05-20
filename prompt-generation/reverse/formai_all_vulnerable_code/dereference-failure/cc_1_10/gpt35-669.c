//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>
#include <netdb.h>
#include <string.h>
#include <pthread.h>

#define MAX_THREADS 10

// Define the maximum number of IP addresses to scan
#define MAX_IP_ADDRESSES 256

pthread_mutex_t mutex;

int count = 0;

char* ip_arr[MAX_IP_ADDRESSES];

// Thread function to scan a range of IP addresses
void *scan_ip_addresses(void *arg) {
    int start = *(int *)arg;
    int end = start + 15;

    for (int i = start; i <= end; i++) {
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_port = htons(80);

        char* ip_addr = ip_arr[i];

        inet_pton(AF_INET, ip_addr, &addr.sin_addr);

        int sockfd = socket(AF_INET, SOCK_STREAM, 0);

        if (connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)) == 0) {
            pthread_mutex_lock(&mutex);
            printf("Connected to IP address: %s\n", ip_addr);
            count++;
            pthread_mutex_unlock(&mutex);
        }

        close(sockfd);
    }

    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {

    pthread_t threads[MAX_THREADS];

    pthread_mutex_init(&mutex, NULL);

    // Get the IP addresses of the local machine's network interfaces
    struct ifaddrs *ifap, *ifa;

    if (getifaddrs(&ifap) == -1) {
        perror("getifaddrs");
        exit(EXIT_FAILURE);
    }

    int i = 0;

    for (ifa = ifap; ifa != NULL; ifa = ifa->ifa_next) {
        if (ifa->ifa_addr == NULL) {
            continue;
        }

        if (ifa->ifa_addr->sa_family == AF_INET) {
            struct sockaddr_in *addr = (struct sockaddr_in *)ifa->ifa_addr;
            char *ip = inet_ntoa(addr->sin_addr);

            if (strcmp(ip, "127.0.0.1") != 0) {
                ip_arr[i] = malloc(strlen(ip) * sizeof(char));
                strcpy(ip_arr[i], ip);
                i++;
            }
        }
    }

    freeifaddrs(ifap);

    // Spawn multiple threads to scan the IP addresses
    for (int i = 0; i < MAX_THREADS; i++) {
        int *arg = malloc(sizeof(*arg));
        *arg = i * 16;
        pthread_create(&threads[i], NULL, scan_ip_addresses, arg);
    }

    // Wait for all threads to complete
    for (int i = 0; i < MAX_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("\nScanned %d IP addresses\n", MAX_IP_ADDRESSES);

    for (int i = 0; i < MAX_IP_ADDRESSES; i++) {
        free(ip_arr[i]);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}