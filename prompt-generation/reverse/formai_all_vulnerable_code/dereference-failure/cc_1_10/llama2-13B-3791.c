//LLAMA2-13B DATASET v1.0 Category: System event logger ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <syslog.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_EVENT_LENGTH 1024
#define MAX_CLIENTS 10

struct client_info {
    int sock;
    char name[100];
};

void log_event(const char* event, int severity) {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    char timestamp[30];
    strftime(timestamp, sizeof(timestamp), "%Y-%m-%d %H:%M:%S", localtime(&tv.tv_sec));
    printf("%s [%d] %s\n", timestamp, severity, event);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <log_level>\n", argv[0]);
        return 1;
    }

    int log_level = atoi(argv[1]);

    // Create a socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("socket creation failed");
        return 1;
    }

    // Set up the event logging socket
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(1234);
    inet_pton(AF_INET, "127.0.0.1", &server_addr.sin_addr);
    if (connect(sock, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("connection failed");
        return 1;
    }

    // Create a list of client sockets
    struct client_info clients[MAX_CLIENTS];
    for (int i = 0; i < MAX_CLIENTS; i++) {
        clients[i].sock = -1;
    }

    // Loop forever to handle events
    while (1) {
        // Wait for an event from a client
        struct client_info* client = NULL;
        for (int i = 0; i < MAX_CLIENTS; i++) {
            if (clients[i].sock != -1) {
                client = &clients[i];
                break;
            }
        }

        if (client == NULL) {
            // No clients to handle, sleep for a bit
            usleep(100000);
            continue;
        }

        // Handle the event from the client
        char event_buffer[MAX_EVENT_LENGTH];
        recv(client->sock, event_buffer, MAX_EVENT_LENGTH, 0);
        log_event(event_buffer, client->sock);

        // Send the event to the server
        send(sock, event_buffer, strlen(event_buffer), 0);

        // Close the client socket
        close(client->sock);
        client->sock = -1;
    }

    return 0;
}