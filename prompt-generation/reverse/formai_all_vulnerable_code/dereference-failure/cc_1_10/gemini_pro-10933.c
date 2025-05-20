//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFF_SIZE 1024
#define NUM_TESTS 10
#define MAX_WAIT_TIME 5
#define SPEED_UNIT "Mbps"

// Function prototypes
double calculate_speed(double bytes_received, double elapsed_time);
void print_speed(double speed);
void print_error(char *message);

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create a socket
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        print_error("Error creating socket");
        return EXIT_FAILURE;
    }

    // Get the IP address of the server
    struct hostent *server = gethostbyname("www.example.com");
    if (server == NULL) {
        print_error("Error getting server IP address");
        return EXIT_FAILURE;
    }

    // Create a server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        print_error("Error connecting to server");
        return EXIT_FAILURE;
    }

    // Send a request to the server
    char request[] = "GET / HTTP/1.1\r\nHost: www.example.com\r\n\r\n";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        print_error("Error sending request to server");
        return EXIT_FAILURE;
    }

    // Receive the response from the server
    char buffer[BUFF_SIZE];
    int bytes_received = 0;
    double elapsed_time = 0;
    time_t start_time = time(NULL);

    while (bytes_received < BUFF_SIZE && elapsed_time < MAX_WAIT_TIME) {
        int bytes_read = recv(sockfd, buffer, BUFF_SIZE, 0);
        if (bytes_read < 0) {
            print_error("Error receiving response from server");
            return EXIT_FAILURE;
        }
        bytes_received += bytes_read;
        elapsed_time = time(NULL) - start_time;
    }

    // Close the socket
    close(sockfd);

    // Calculate the speed
    double speed = calculate_speed(bytes_received, elapsed_time);

    // Print the speed
    print_speed(speed);

    return EXIT_SUCCESS;
}

// Function to calculate the speed
double calculate_speed(double bytes_received, double elapsed_time) {
    return (bytes_received * 8) / (elapsed_time * 1024 * 1024);
}

// Function to print the speed
void print_speed(double speed) {
    printf("Your internet speed is %.2f %s\n", speed, SPEED_UNIT);
}

// Function to print an error message
void print_error(char *message) {
    fprintf(stderr, "%s\n", message);
}