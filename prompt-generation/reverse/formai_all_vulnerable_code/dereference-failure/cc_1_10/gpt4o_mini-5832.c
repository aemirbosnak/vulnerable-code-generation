//GPT-4o-mini DATASET v1.0 Category: Port Scanner ; Style: irregular
#include <stdio.h>      // For standard input/output
#include <stdlib.h>     // For malloc, free, exit
#include <string.h>     // For memset
#include <unistd.h>     // For close
#include <arpa/inet.h>  // For sockaddr_in
#include <sys/socket.h> // For socket functions
#include <pthread.h>    // For threading

#define MAX_THREADS 10  // Max threads for scanning
#define MAX_PORT 65535   // Maximum port number
#define MIN_PORT 1      // Minimum port number
#define TIMEOUT 1       // Timeout for socket connection

// Structure to pass arguments to threads
typedef struct {
    char *ip;        // IP address to scan
    int start_port;  // Starting port
    int end_port;    // Ending port
} thread_arg;

// Function to check a single port
void *check_port(void *arg) {
    int sock;                  // Socket descriptor
    struct sockaddr_in target; // Target sockaddr_in struct
    thread_arg *t_arg = (thread_arg *)arg; // Cast arg to thread_arg struct
    const char *ip = t_arg->ip; // Extract ip
    int port;                  // Port to check
    char *port_status;         // Port status message

    // Loop through all ports assigned to this thread
    for (port = t_arg->start_port; port <= t_arg->end_port; port++) {
        // Create the socket
        sock = socket(AF_INET, SOCK_STREAM, 0);
        if (sock < 0) {
            perror("Socket creation error");
            pthread_exit(NULL);
        }

        // Prepare the target address
        memset(&target, 0, sizeof(target)); // Clear memory
        target.sin_family = AF_INET;
        target.sin_port = htons(port); // Convert port to network byte order
        target.sin_addr.s_addr = inet_addr(ip); // Convert IP to binary format

        // Set a timeout for the socket
        struct timeval timeout;
        timeout.tv_sec = TIMEOUT;
        timeout.tv_usec = 0;
        setsockopt(sock, SOL_SOCKET, SO_RCVTIMEO, (const char*)&timeout, sizeof(timeout));
        setsockopt(sock, SOL_SOCKET, SO_SNDTIMEO, (const char*)&timeout, sizeof(timeout));

        // Attempt to connect to the port
        if (connect(sock, (struct sockaddr *)&target, sizeof(target)) == 0) {
            port_status = "OPEN"; // Port is open
        } else {
            port_status = "CLOSED"; // Port is closed
        }

        // Display the result
        printf("Port %d: %s\n", port, port_status);
        close(sock); // Close the socket
    }

    pthread_exit(NULL); // Exit thread
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Usage: %s <IP> <Start Port> <End Port>\n", argv[0]);
        return 1;
    }

    char *target_ip = argv[1]; // Target IP address
    int start_port = atoi(argv[2]); // Start port
    int end_port = atoi(argv[3]); // End port

    // Input validation
    if (start_port < MIN_PORT || end_port > MAX_PORT || start_port > end_port) {
        printf("Invalid port range. Please enter ports between %d and %d.\n", MIN_PORT, MAX_PORT);
        return 1;
    }

    // Thread variables
    pthread_t threads[MAX_THREADS];
    thread_arg args[MAX_THREADS];
    int thread_count = 0;
    int ports_per_thread = (end_port - start_port + 1) / MAX_THREADS; // Split ports among threads

    // Launch threads for scanning
    for (int i = 0; i < MAX_THREADS; i++) {
        args[i].ip = target_ip;
        args[i].start_port = start_port + i * ports_per_thread;
        args[i].end_port = (i == MAX_THREADS - 1) ? end_port : (args[i].start_port + ports_per_thread - 1);

        if (pthread_create(&threads[i], NULL, check_port, (void *)&args[i]) != 0) {
            printf("Error creating thread.\n");
            return 1;
        }
        thread_count++;
    }

    // Wait for all threads to complete
    for (int i = 0; i < thread_count; i++) {
        pthread_join(threads[i], NULL);
    }

    printf("Port scanning completed for %s.\n", target_ip);
    return 0;
}