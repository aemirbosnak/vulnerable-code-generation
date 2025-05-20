//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <errno.h>
#include <stdbool.h>
#include <pthread.h>

#define MAX_PORT 65535
#define MAX_IP_LEN 15

// Function to scan for open ports on a given IP address
void *scan_ip(void *args) {
    char *ip = (char *) args;

    // Create a TCP socket
    int sock;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        fprintf(stderr, "Socket creation error: %s\n", strerror(errno));
        pthread_exit(NULL);
    }

    // Specify the IP address and port number to connect to
    struct sockaddr_in dest_addr;
    memset(&dest_addr, 0, sizeof(dest_addr));
    dest_addr.sin_family = AF_INET;
    dest_addr.sin_port = htons(80); // Default port
    if (inet_pton(AF_INET, ip, &dest_addr.sin_addr) <= 0) {
        fprintf(stderr, "Invalid address: %s\n", ip);
        close(sock);
        pthread_exit(NULL);
    }

    // Attempt to connect to each port number individually
    for (int port = 1; port <= MAX_PORT; port++) {
        dest_addr.sin_port = htons(port);
        if (connect(sock, (struct sockaddr *) &dest_addr, sizeof(dest_addr)) == 0) {
            printf("%s:%d is open!\n", ip, port);
        }
    }

    // Close the socket
    close(sock);
    pthread_exit(NULL);
}

int main() {
    // Allocate memory for the IP addresses to scan
    char **ips = malloc(sizeof(char *) * 256);
    for (int i = 0; i < 256; i++) {
        ips[i] = malloc(sizeof(char) * (MAX_IP_LEN + 1));
        sprintf(ips[i], "192.168.0.%d", i);
    }

    // Create a thread for each IP address to scan
    pthread_t threads[256];
    for (int i = 0; i < 256; i++) {
        pthread_create(&threads[i], NULL, scan_ip, (void *) ips[i]);
    }

    // Wait for all threads to finish
    for (int i = 0; i < 256; i++) {
        pthread_join(threads[i], NULL);
    }

    // Free memory
    for (int i = 0; i < 256; i++) {
        free(ips[i]);
    }
    free(ips);

    return 0;
}