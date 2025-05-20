//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFFER_SIZE 1024
#define TEST_DURATION 10

void print_intro() {
    printf("============================================\n");
    printf("    Welcome to the Speed Test Initiative    \n");
    printf("            Post-Apocalyptic Edition         \n");
    printf("============================================\n");
    printf("Measuring the last remnants of connectivity...\n");
    printf("Prepare to confront the void that is the internet.\n");
    printf("============================================\n");
    sleep(2);
}

int create_socket() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("Creating socket failed");
        exit(EXIT_FAILURE);
    }
    return sock;
}

void connect_to_server(int sock, const char *server_ip, int server_port) {
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(server_port);

    if (inet_pton(AF_INET, server_ip, &server_addr.sin_addr) <= 0) {
        perror("Invalid address");
        exit(EXIT_FAILURE);
    }

    if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }
}

void measure_speed(int sock) {
    char buffer[BUFFER_SIZE];
    long bytes_sent = 0;
    long bytes_received = 0;
    time_t start_time, end_time;

    // Send data to measure upload speed
    start_time = time(NULL);
    while (difftime(time(NULL), start_time) < TEST_DURATION) {
        ssize_t sent_size = send(sock, "Ping", 4, 0);
        if (sent_size < 0) {
            perror("Send failed");
            break;
        }
        bytes_sent += sent_size;
    }

    // Receive data to measure download speed
    start_time = time(NULL);
    while (difftime(time(NULL), start_time) < TEST_DURATION) {
        ssize_t received_size = recv(sock, buffer, BUFFER_SIZE, 0);
        if (received_size < 0) {
            perror("Receive failed");
            break;
        }
        bytes_received += received_size;
    }

    end_time = time(NULL);
    double elapsed_time = difftime(end_time, start_time);
    
    printf("============================================\n");
    printf("Upload Speed: %.2lf KB/s\n", bytes_sent / 1024.0 / TEST_DURATION);
    printf("Download Speed: %.2lf KB/s\n", bytes_received / 1024.0 / TEST_DURATION);
    printf("============================================\n");
}

int main(int argc, char *argv[]) {
    print_intro();

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <server_ip> <server_port>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *server_ip = argv[1];
    int server_port = atoi(argv[2]);

    int sock = create_socket();
    connect_to_server(sock, server_ip, server_port);
    
    measure_speed(sock);

    close(sock);
    printf("The test has ended. Welcome back to the void!\n");
    return EXIT_SUCCESS;
}