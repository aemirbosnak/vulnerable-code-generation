//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/queue.h>

// Structure to hold a port and its status
typedef struct port_info {
    int port;
    int status;
    TAILQ_ENTRY(port_info) entries;
} port_info_t;

// Queue to hold the port_info structures
TAILQ_HEAD(port_queue, port_info) port_queue;

// Function to add a port to the queue
void add_port(int port) {
    port_info_t *new_port = malloc(sizeof(port_info_t));
    if (new_port == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }
    new_port->port = port;
    new_port->status = 0;
    TAILQ_INSERT_TAIL(&port_queue, new_port, entries);
}

// Function to remove a port from the queue
void remove_port(int port) {
    port_info_t *port_to_remove;
    TAILQ_FOREACH(port_to_remove, &port_queue, entries) {
        if (port_to_remove->port == port) {
            TAILQ_REMOVE(&port_queue, port_to_remove, entries);
            free(port_to_remove);
            break;
        }
    }
}

// Function to scan a port
void scan_port(int port) {
    int sockfd;
    struct sockaddr_in serv_addr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Set the server address
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    serv_addr.sin_port = htons(port);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == 0) {
        port_info_t *port_info = TAILQ_FIRST(&port_queue);
        while (port_info != NULL) {
            if (port_info->port == port) {
                port_info->status = 1;
                break;
            }
            port_info = TAILQ_NEXT(port_info, entries);
        }
    }

    // Close the socket
    close(sockfd);
}

// Function to print the results of the scan
void print_results() {
    port_info_t *port_info;
    TAILQ_FOREACH(port_info, &port_queue, entries) {
        printf("Port %d: %s\n", port_info->port, port_info->status == 1 ? "open" : "closed");
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <port1> <port2> ... <portn>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Initialize the port queue
    TAILQ_INIT(&port_queue);

    // Add the ports to the queue
    for (int i = 1; i < argc; i++) {
        int port = atoi(argv[i]);
        add_port(port);
    }

    // Scan the ports
    for (int i = 1; i < argc; i++) {
        int port = atoi(argv[i]);
        scan_port(port);
    }

    // Print the results of the scan
    print_results();

    return EXIT_SUCCESS;
}