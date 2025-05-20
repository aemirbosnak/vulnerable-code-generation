//GPT-4o-mini DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/ip.h>
#include <netinet/tcp.h>
#include <sys/socket.h>
#include <netdb.h>
#include <errno.h>

#define BUFFER_SIZE 4096
#define MONITOR_INTERVAL 2
#define MAX_ATTEMPTS 3

void panic(const char *msg) {
    perror(msg);
    exit(EXIT_FAILURE);
}

void print_ip(const char *ip) {
    printf(">>> Monitoring IP: %s <<<\n", ip);
}

void log_event(const char *event) {
    FILE *log_file = fopen("network_monitor.log", "a");
    if (log_file == NULL) {
        panic("Could not open log file");
    }
    fprintf(log_file, "%s\n", event);
    fclose(log_file);
}

int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        panic("Socket creation failed");
    }
    return sock;
}

void connect_to_server(int sock, const char *ip, int port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    if (inet_pton(AF_INET, ip, &server_addr.sin_addr) <= 0) {
        panic("Invalid address/ Address not supported");
    }
    
    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        panic("Connection Failed");
    }
}

void monitor_qos(const char *target_ip, int port) {
    int attempts = 0;
    
    while (attempts < MAX_ATTEMPTS) {
        int sock = create_socket();
        connect_to_server(sock, target_ip, port);
        
        char buffer[BUFFER_SIZE];
        ssize_t bytes_received = recv(sock, buffer, sizeof(buffer), 0);
        
        if (bytes_received < 0) {
            log_event("Failed to receive data, attempting to reconnect...");
            attempts++;
            close(sock);
            sleep(MONITOR_INTERVAL);
            continue;
        }

        buffer[bytes_received] = '\0';  // Null-terminate string
        printf("Received Data: %s\n", buffer);
        log_event("Data received successfully.");
        
        close(sock);
        sleep(MONITOR_INTERVAL);
        attempts = 0;  // Reset attempts on successful read
    }

    log_event("Maximum connection attempts exceeded. Disconnecting...");
}

void show_help() {
    printf("Usage: network_monitor <target_ip> <port>\n");
    printf("Example: network_monitor 192.168.1.1 80\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        show_help();
        return EXIT_FAILURE;
    }

    const char *target_ip = argv[1];
    int port = atoi(argv[2]);

    print_ip(target_ip);
    log_event("Starting Quality of Service monitor...");
    monitor_qos(target_ip, port);

    log_event("Exiting Quality of Service monitor...");
    return EXIT_SUCCESS;
}