//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024
#define SERVER_IP "192.168.1.1"

void print_intro() {
    printf("========================================\n");
    printf("  Post-Apocalyptic Internet Speed Test  \n");
    printf("  The Last Connection to the Wasteland    \n");
    printf("========================================\n");
    printf("Finding the last thread of civilization...\n");
    printf("Establishing connection...\n\n");
}

long long get_current_time_millis() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
}

int connect_to_server() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Failed to create socket!");
        exit(EXIT_FAILURE);
    }

    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
        perror("Invalid address/ Address not supported!");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed! The wasteland claims another one...");
        exit(EXIT_FAILURE);
    }

    return sock;
}

void send_data(int sock) {
    char *data = (char *)malloc(BUFFER_SIZE);
    strcpy(data, "DATA: Send me your speed, human!");

    long long start_time = get_current_time_millis();
    send(sock, data, strlen(data), 0);
    free(data);

    printf("Data sent! Waiting for response...\n");
}

void receive_data(int sock) {
    char buffer[BUFFER_SIZE];
    long long start_time = get_current_time_millis();
    
    int bytes_received = recv(sock, buffer, BUFFER_SIZE, 0);
    long long end_time = get_current_time_millis();

    if (bytes_received < 0) {
        perror("Failed to receive data!");
    } else {
        buffer[bytes_received] = '\0';
        printf("Response received: %s\n", buffer);

        long long elapsed_time = end_time - start_time;
        printf("Time taken to receive response: %lld ms\n", elapsed_time);
    }
}

void cleanup(int sock) {
    close(sock);
    printf("Connection severed. The last signal fades...\n");
}

int main() {
    print_intro();

    int sock = connect_to_server();
    send_data(sock);
    receive_data(sock);
    cleanup(sock);

    return 0;
}