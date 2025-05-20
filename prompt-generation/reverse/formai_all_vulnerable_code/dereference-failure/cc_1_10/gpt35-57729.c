//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <pthread.h>

#define MAX_THREADS 64
#define SCAN_TIMEOUT 5 // seconds
#define MAX_HOSTS 1024

struct scanner_data {
    char* hostname;
    int portnum;
};

void* scan_host(void* arg) {
    struct scanner_data* s_data = (struct scanner_data*)arg;
    struct sockaddr_in addr;
    struct hostent* host_entry;
    int sockfd, status;

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    if ((host_entry = gethostbyname(s_data->hostname)) == NULL) {
        printf("Error: Cannot resolve hostname '%s'\n", s_data->hostname);
        return NULL;
    }
    addr.sin_addr = *((struct in_addr*)host_entry->h_addr_list[0]);
    addr.sin_port = htons(s_data->portnum);

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Error: Cannot create socket");
        return NULL;
    }

    // Set socket timeout
    struct timeval timeout;
    timeout.tv_sec = SCAN_TIMEOUT;
    timeout.tv_usec = 0;
    if (setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, (char*)&timeout, sizeof(timeout)) < 0) {
        perror("Error: Cannot set socket timeout");
    }
    if (setsockopt(sockfd, SOL_SOCKET, SO_SNDTIMEO, (char*)&timeout, sizeof(timeout)) < 0) {
        perror("Error: Cannot set socket timeout");
    }

    status = connect(sockfd, (struct sockaddr*)&addr, sizeof(addr));
    if (status == 0) {
        printf("[+] Port %d is open on host %s\n", s_data->portnum, s_data->hostname);
    }

    close(sockfd);

    return NULL;
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Usage: %s <IP address>\n", argv[0]);
        return EXIT_FAILURE;
    }

    char* hostname = argv[1];
    pthread_t threads[MAX_THREADS];
    int num_threads = 0, i, portnum;
    struct scanner_data s_data[MAX_HOSTS];

    printf("Scanning host %s...\n", hostname);

    for (portnum = 1; portnum <= 65535; portnum++) {
        s_data[num_threads].portnum = portnum;
        s_data[num_threads].hostname = hostname;
        if (pthread_create(&threads[num_threads], NULL, scan_host, (void*)&s_data[num_threads])) {
            printf("Error: Cannot create thread for port %d\n", portnum);
            continue;
        }
        // Wait for threads to be created before spawning new ones
        if (++num_threads == MAX_THREADS) {
            for (i = 0; i < num_threads; i++) {
                pthread_join(threads[i], NULL);
            }
            num_threads = 0;
        }
    }

    // Join remaining threads
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Scanning finished.\n");

    return EXIT_SUCCESS;
}