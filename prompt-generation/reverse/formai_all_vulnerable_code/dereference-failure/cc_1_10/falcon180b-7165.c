//Falcon-180B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

#define TRUE 1
#define FALSE 0
#define MAX_DATA_SIZE 1024
#define QOS_PORT 5000

typedef struct {
    int sock;
    struct sockaddr_in server_addr;
    char data[MAX_DATA_SIZE];
} qos_client;

int main(int argc, char *argv[]) {
    qos_client client;
    int opt = TRUE;
    int maxfd;
    fd_set master_fds;
    fd_set read_fds;
    struct timeval tv;

    // Initialize client structure
    client.sock = 0;
    memset(&client.server_addr, 0, sizeof(client.server_addr));
    memset(client.data, 0, MAX_DATA_SIZE);

    // Create socket
    if ((client.sock = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        printf("Error creating socket\n");
        exit(1);
    }

    // Set server address
    client.server_addr.sin_family = AF_INET;
    client.server_addr.sin_port = htons(QOS_PORT);
    inet_pton(AF_INET, "127.0.0.1", &client.server_addr.sin_addr);

    // Connect to server
    if (connect(client.sock, (struct sockaddr *)&client.server_addr, sizeof(client.server_addr))!= 0) {
        printf("Error connecting to server\n");
        exit(1);
    }

    // Initialize file descriptor sets
    FD_ZERO(&master_fds);
    FD_ZERO(&read_fds);

    // Add socket to master set
    FD_SET(client.sock, &master_fds);

    // Set maximum file descriptor
    maxfd = client.sock;

    while (opt) {
        // Copy master set to read set
        read_fds = master_fds;

        // Wait for activity on one or more sockets
        if (select(maxfd + 1, &read_fds, NULL, NULL, &tv) < 0) {
            printf("Error selecting\n");
            exit(1);
        }

        // Check if data is available on socket
        if (FD_ISSET(client.sock, &read_fds)) {
            // Receive data from server
            if (recv(client.sock, client.data, MAX_DATA_SIZE, 0) <= 0) {
                printf("Error receiving data\n");
                exit(1);
            }

            // Print received data
            printf("Received data: %s\n", client.data);
        }
    }

    // Close socket
    close(client.sock);

    return 0;
}