//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>
#include <time.h>

#define PORT 8080
#define MAX_BUFFER 1024
#define MAX_LOG 100

// Struct to hold log entries
typedef struct {
    char timestamp[20];
    char ip_address[INET_ADDRSTRLEN];
    char action[100];
} LogEntry;

LogEntry logs[MAX_LOG];
int log_count = 0;

void log_action(const char *ip, const char *action) {
    if (log_count < MAX_LOG) {
        time_t t = time(NULL);
        struct tm tm = *localtime(&t);
        snprintf(logs[log_count].timestamp, 20, "%04d-%02d-%02d %02d:%02d:%02d",
                 tm.tm_year + 1900, tm.tm_mon + 1, tm.tm_mday,
                 tm.tm_hour, tm.tm_min, tm.tm_sec);
        strncpy(logs[log_count].ip_address, ip, INET_ADDRSTRLEN);
        strncpy(logs[log_count].action, action, 100);
        log_count++;
    }
}

void signal_handler(int signal) {
    printf("\nCaught signal %d. Exiting...\n", signal);
    exit(0);
}

void display_logs() {
    printf("\n---- Intrusion Detection Logs ----\n");
    for (int i = 0; i < log_count; i++) {
        printf("%s | %s | %s\n", logs[i].timestamp, logs[i].ip_address, logs[i].action);
    }
    printf("-----------------------------------\n");
}

int main() {
    signal(SIGINT, signal_handler);

    int server_fd, new_socket;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[MAX_BUFFER] = {0};

    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
        perror("Socket failed");
        exit(EXIT_FAILURE);
    }

    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind the socket
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(server_fd, 3) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Intrusion Detection System running on port %d\n", PORT);

    while (1) {
        // Accept incoming connection
        if ((new_socket = accept(server_fd, (struct sockaddr *)&address, (socklen_t*)&addrlen)) < 0) {
            perror("Accept failed");
            exit(EXIT_FAILURE);
        }

        // Log the incoming connection
        char ip_address[INET_ADDRSTRLEN];
        inet_ntop(AF_INET, &address.sin_addr, ip_address, sizeof(ip_address));
        log_action(ip_address, "Connection established");

        // Read data from the socket
        read(new_socket, buffer, MAX_BUFFER);
        printf("Received: %s\n", buffer);

        // Detect simple intrusion (any unauthorized command)
        if (strstr(buffer, "DROP") || strstr(buffer, "DELETE")) {
            log_action(ip_address, "Possible intrusion detected!");
            printf("Possible intrusion from %s detected!\n", ip_address);
        }

        // Send acknowledgment
        send(new_socket, "ACK", strlen("ACK"), 0);
        close(new_socket);
    }

    display_logs();
    return 0;
}