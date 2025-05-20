//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

// Define the server address and port
#define SERVER_ADDR "google.com"
#define SERVER_PORT 80

// Define the buffer size
#define BUF_SIZE 4096

// Function to create a socket
int create_socket() {
    int sockfd;
    struct sockaddr_in servaddr;

    // Create a socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(EXIT_FAILURE);
    }

    // Get the server address
    struct hostent *host = gethostbyname(SERVER_ADDR);
    if (host == NULL) {
        perror("gethostbyname");
        exit(EXIT_FAILURE);
    }

    // Set the server address and port
    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(SERVER_PORT);
    memcpy(&servaddr.sin_addr, host->h_addr_list[0], host->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect");
        exit(EXIT_FAILURE);
    }

    return sockfd;
}

// Function to send data to the server
void send_data(int sockfd, char *buf, int size) {
    int sent = 0;
    while (sent < size) {
        int n = send(sockfd, buf + sent, size - sent, 0);
        if (n == -1) {
            perror("send");
            exit(EXIT_FAILURE);
        }
        sent += n;
    }
}

// Function to receive data from the server
int receive_data(int sockfd, char *buf, int size) {
    int received = 0;
    while (received < size) {
        int n = recv(sockfd, buf + received, size - received, 0);
        if (n == -1) {
            perror("recv");
            exit(EXIT_FAILURE);
        } else if (n == 0) {
            break;
        }
        received += n;
    }
    return received;
}

// Function to measure the internet speed
double measure_speed(int sockfd) {
    char buf[BUF_SIZE];
    int size = sizeof(buf);

    // Send a request to the server
    send_data(sockfd, buf, size);

    // Start the timer
    clock_t start = clock();

    // Receive the response from the server
    int received = receive_data(sockfd, buf, size);

    // Stop the timer
    clock_t end = clock();

    // Calculate the elapsed time
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    // Calculate the internet speed
    double speed = (double)received / elapsed_time / 1024 / 1024;

    return speed;
}

int main() {
    int sockfd = create_socket();

    // Measure the internet speed
    double speed = measure_speed(sockfd);

    // Print the internet speed
    printf("Internet speed: %.2f Mbps\n", speed);

    // Close the socket
    close(sockfd);

    return 0;
}