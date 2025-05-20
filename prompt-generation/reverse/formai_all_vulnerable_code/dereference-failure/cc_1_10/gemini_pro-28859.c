//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: Donald Knuth
/*
 * Donald Knuth's Internet Speed Test
 *
 * This program measures the speed of your Internet connection by
 * sending a series of packets to a remote server and measuring how
 * long it takes for the server to respond.
 *
 * The program is written in a Donald Knuth style, which is a
 * programming style that emphasizes clarity and simplicity. The
 * program is also written in a way that is easy to understand and
 * modify.
 *
 * To use the program, simply compile it and run it. The program will
 * automatically measure the speed of your Internet connection and
 * display the results on the screen.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>
#include <time.h>

#define MAX_PACKET_SIZE 1024
#define MAX_NUM_PACKETS 1000
#define SERVER_PORT 80

// Function to measure the speed of an Internet connection.
double measure_internet_speed(char *server_address) {
    // Create a socket.
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd == -1) {
        perror("socket");
        exit(1);
    }

    // Get the IP address of the server.
    struct hostent *server = gethostbyname(server_address);
    if (server == NULL) {
        perror("gethostbyname");
        exit(1);
    }

    // Connect to the server.
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(SERVER_PORT);
    memcpy(&server_addr.sin_addr, server->h_addr, server->h_length);

    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
        perror("connect");
        exit(1);
    }

    // Send a series of packets to the server.
    char packet[MAX_PACKET_SIZE];
    memset(packet, 0, MAX_PACKET_SIZE);
    for (int i = 0; i < MAX_NUM_PACKETS; i++) {
        int packet_size = rand() % MAX_PACKET_SIZE;
        if (send(sockfd, packet, packet_size, 0) == -1) {
            perror("send");
            exit(1);
        }
    }

    // Measure how long it takes for the server to respond.
    struct timeval start_time;
    struct timeval end_time;
    gettimeofday(&start_time, NULL);
    for (int i = 0; i < MAX_NUM_PACKETS; i++) {
        int packet_size = rand() % MAX_PACKET_SIZE;
        if (recv(sockfd, packet, packet_size, 0) == -1) {
            perror("recv");
            exit(1);
        }
    }
    gettimeofday(&end_time, NULL);

    // Calculate the speed of the Internet connection.
    double elapsed_time = (end_time.tv_sec - start_time.tv_sec) + (end_time.tv_usec - start_time.tv_usec) / 1000000.0;
    double speed = (MAX_NUM_PACKETS * MAX_PACKET_SIZE) / elapsed_time;

    // Close the socket.
    close(sockfd);

    // Return the speed of the Internet connection.
    return speed;
}

// Main function.
int main(int argc, char *argv[]) {
    // Check if the user specified a server address.
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server_address>\n", argv[0]);
        exit(1);
    }

    // Measure the speed of the Internet connection.
    double speed = measure_internet_speed(argv[1]);

    // Print the speed of the Internet connection.
    printf("The speed of your Internet connection is %.2f bytes/sec.\n", speed);

    // Return 0 to indicate success.
    return 0;
}