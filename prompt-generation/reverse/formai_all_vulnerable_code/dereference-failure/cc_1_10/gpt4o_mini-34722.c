//GPT-4o-mini DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/time.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <fcntl.h>

#define HOSTNAME "speed.hetzner.de"
#define PORT 8080
#define BUFFER_SIZE 1048576  // 1 MB
#define TIME_LIMIT 10         // seconds

void task_report(const char *label, double time_taken, size_t data_size) {
    double speed_mbps = (data_size * 8) / (time_taken * 1000000.0); // Convert to Mbps
    printf("%s Speed: %.2f Mbps (Data size: %zu bytes, Time: %.2f seconds)\n", label, speed_mbps, data_size, time_taken);
}

void progress_bar(int percentage) {
    printf("\r[");
    int bar_width = 70;
    int pos = bar_width * percentage / 100;
    for (int i = 0; i < bar_width; ++i) {
        if (i < pos)
            printf("=");
        else
            printf(" ");
    }
    printf("] %d%%", percentage);
    fflush(stdout);
}

size_t read_data(int socket_fd) {
    char buffer[BUFFER_SIZE];
    size_t total_read = 0;
    ssize_t bytes_read;

    while ((bytes_read = read(socket_fd, buffer, BUFFER_SIZE)) > 0) {
        total_read += bytes_read;
        progress_bar((total_read * 100) / (BUFFER_SIZE * 5)); // Report progress as we read
        usleep(10000); // Simulating network delay for visuals
    }
    return total_read;
}

int setup_connection(struct sockaddr_in *server_addr) {
    int sock_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (sock_fd < 0) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    struct hostent *host = gethostbyname(HOSTNAME);
    if (host == NULL) {
        fprintf(stderr, "Error: Unable to resolve hostname %s\n", HOSTNAME);
        close(sock_fd);
        exit(EXIT_FAILURE);
    }

    memset(server_addr, 0, sizeof(*server_addr));
    server_addr->sin_family = AF_INET;
    memcpy(&server_addr->sin_addr, host->h_addr_list[0], host->h_length);
    server_addr->sin_port = htons(PORT);

    if (connect(sock_fd, (struct sockaddr *)server_addr, sizeof(*server_addr)) < 0) {
        perror("Connection to server failed");
        close(sock_fd);
        exit(EXIT_FAILURE);
    }
    return sock_fd;
}

void speed_test() {
    struct sockaddr_in server_addr;
    int sock_fd = setup_connection(&server_addr);

    char send_buffer[BUFFER_SIZE];
    memset(send_buffer, 'A', sizeof(send_buffer)); // Fill buffer with dummy data

    // Start the test
    struct timeval start, end;
    gettimeofday(&start, NULL);
    
    // Send dummy data
    for (int i = 0; i < 5; i++) {
        write(sock_fd, send_buffer, sizeof(send_buffer));
    }

    // Read data
    size_t total_read = read_data(sock_fd);

    gettimeofday(&end, NULL);
    close(sock_fd);

    double elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    task_report("Upload", elapsed_time, sizeof(send_buffer) * 5);
}

int main() {
    printf("Welcome to the C Internet Speed Test Application\n");
    printf("Please wait while we test your internet speed...\n");

    speed_test();
    
    printf("\nSpeed test completed.\n");
    return 0;
}