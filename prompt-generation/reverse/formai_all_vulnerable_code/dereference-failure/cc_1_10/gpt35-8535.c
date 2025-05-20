//FormAI DATASET v1.0 Category: Port Scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <pthread.h>

#define MAX_THREADS 100
#define MAX_PORTS 1000
#define MAX_IP_LENGTH 16

int open_ports[MAX_PORTS];
pthread_mutex_t mutex;

void *scan_port(void *port_ptr) {
    int sock, port, result;
    char ip[MAX_IP_LENGTH];
    struct sockaddr_in server_address;

    strcpy(ip, (char*) port_ptr);
    port = *((int*) (port_ptr + MAX_IP_LENGTH));

    // Create a TCP socket
    sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    server_address.sin_family = AF_INET;
    server_address.sin_addr.s_addr = inet_addr(ip);
    server_address.sin_port = htons(port);

    result = connect(sock, (struct sockaddr*) &server_address, sizeof(server_address));
    if (result == 0) {
        pthread_mutex_lock(&mutex);
        printf("[+] Port %d on %s is open\n", port, ip);
        open_ports[port] = 1;
        pthread_mutex_unlock(&mutex);
    }

    close(sock);
    pthread_exit(NULL);
}

void start_port_scan(char *ip_address) {
    int i, j, k;
    pthread_t threads[MAX_THREADS];
    char ip[MAX_IP_LENGTH];
    int is_ip_valid, num_threads, starting_port, ending_port;

    printf("\nEnter starting port: ");
    scanf("%d", &starting_port);

    printf("\nEnter ending port: ");
    scanf("%d", &ending_port);

    for (i = starting_port; i <= ending_port; i++) {
        open_ports[i] = 0;
    }

    // Create threads
    num_threads = ending_port - starting_port + 1;
    if (num_threads > MAX_THREADS) {
        num_threads = MAX_THREADS;
    }

    j = starting_port;
    for (i = 0; i < num_threads; i++) {
        k = 0;
        while (ip_address[k] != '\0') {
            if (ip_address[k] == '.') {
                break;
            }

            k++;
        }

        strncpy(ip, ip_address, k+1);
        sprintf(ip + k+1, "%d", j);

        pthread_create(&threads[i], NULL, scan_port, ip);

        j += num_threads;
    }

    // Wait for threads to finish
    for (i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Display open ports
    printf("\nOpen ports on %s\n", ip_address);
    for (i = starting_port; i <= ending_port; i++) {
        if (open_ports[i] == 1) {
            printf("Port %d is open\n", i);
        }
    }
}

int main() {
    char ip_address[MAX_IP_LENGTH];
    struct hostent *host;

    printf("Enter IP address or hostname: ");
    scanf("%s", ip_address);

    host = gethostbyname(ip_address);
    if (host == NULL) {
        printf("Unknown host\n");
        exit(EXIT_FAILURE);
    }

    if (host->h_addrtype != AF_INET) {
        printf("Invalid address type\n");
        exit(EXIT_FAILURE);
    }

    start_port_scan(inet_ntoa(*(struct in_addr*) host->h_addr_list[0]));
    return 0;
}