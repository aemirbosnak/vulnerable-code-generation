//GPT-4o-mini DATASET v1.0 Category: Intrusion detection system ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <pthread.h>
#include <time.h>

#define PORT 8080
#define BUFFER_SIZE 1024
#define MAX_CONNECTIONS 10

struct CyberPacket {
    char source[50];
    char destination[50];
    char payload[BUFFER_SIZE];
    time_t timestamp;
};

void *packet_handler(void *arg);
void log_attack(struct CyberPacket *packet);
int is_malicious_payload(char *payload);

int main() {
    int sockfd, client_sockfd;
    struct sockaddr_in server_addr, client_addr;
    socklen_t addr_size;
    char buffer[BUFFER_SIZE];

    // Initialize the socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Failure creating socket");
        exit(EXIT_FAILURE);
    }

    // Prepare the sockaddr_in structure
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    // Bind the socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Socket binding error");
        exit(EXIT_FAILURE);
    }
    
    // Listen for incoming connections
    if (listen(sockfd, MAX_CONNECTIONS) < 0) {
        perror("Listening error");
        exit(EXIT_FAILURE);
    }

    printf("Cyber Intrusion Detection System Active... Listening on port %d\n", PORT);

    while (1) {
        // Accept a connection
        addr_size = sizeof(client_addr);
        client_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &addr_size);
        if (client_sockfd < 0) {
            perror("Connection acceptance error");
            continue;
        }

        printf("Connection established, waiting for packets...\n");

        // Receive packets
        struct CyberPacket *packet = malloc(sizeof(struct CyberPacket));
        read(client_sockfd, packet->payload, BUFFER_SIZE);
        strcpy(packet->source, inet_ntoa(client_addr.sin_addr));
        strcpy(packet->destination, "CyberNet");
        packet->timestamp = time(NULL);

        // Create a new thread to handle the received packet
        pthread_t tid;
        if (pthread_create(&tid, NULL, packet_handler, (void *)packet) != 0) {
            perror("Thread creation error");
            free(packet);
            close(client_sockfd);
        }
        pthread_detach(tid); // Detach thread so it cleans up after itself
    }

    close(sockfd);
    return 0;
}

void *packet_handler(void *arg) {
    struct CyberPacket *packet = (struct CyberPacket *)arg;
    printf("Received packet from %s: %s\n", packet->source, packet->payload);

    // Check if the packet is malicious
    if (is_malicious_payload(packet->payload)) {
        printf("ALERT: Malicious packet detected from %s! Analyzing...\n", packet->source);
        log_attack(packet);
    } else {
        printf("Packet from %s is clean.\n", packet->source);
    }

    free(packet); // Free the packet memory
    return NULL;
}

void log_attack(struct CyberPacket *packet) {
    FILE *logfile = fopen("attack_log.txt", "a");
    if (logfile == NULL) {
        perror("Error opening log file");
        return;
    }

    char time_buffer[26];
    struct tm* tm_info;
    tm_info = localtime(&packet->timestamp);
    strftime(time_buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);

    fprintf(logfile, "Attack Detected!\n");
    fprintf(logfile, "Source: %s\n", packet->source);
    fprintf(logfile, "Destination: %s\n", packet->destination);
    fprintf(logfile, "Payload: %s\n", packet->payload);
    fprintf(logfile, "Timestamp: %s\n\n", time_buffer);

    fclose(logfile);

    // More cyberpunk flair - add a notification system
    printf("Intrusion logged! All Neon Cyborgs alerted.\n");
}

int is_malicious_payload(char *payload) {
    const char *malicious_keywords[] = {
        "hack",
        "attack",
        "exploit",
        "malware",
        "virus"
    };

    for (int i = 0; i < 5; i++) {
        if (strstr(payload, malicious_keywords[i]) != NULL) {
            return 1; // Malicious packet
        }
    }
    return 0; // Not malicious
}