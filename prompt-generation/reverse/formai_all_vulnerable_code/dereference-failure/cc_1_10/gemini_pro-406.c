//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUF_SIZE 1024

int main(int argc, char *argv[]) {
    // Check if the user has provided the server IP address as a command-line argument
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <server IP address>\n", argv[0]);
        return 1;
    }

    // Create a socket for communication with the server
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Error creating socket");
        return 1;
    }

    // Resolve the server's IP address
    struct hostent *server = gethostbyname(argv[1]);
    if (server == NULL) {
        perror("Error resolving server address");
        return 1;
    }

    // Set up the server address structure
    struct sockaddr_in server_addr;
    memset(&server_addr, 0, sizeof(server_addr));
    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(80);
    memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error connecting to server");
        return 1;
    }

    // Send a request to the server to start the speed test
    char request[] = "START_SPEED_TEST";
    if (send(sockfd, request, strlen(request), 0) < 0) {
        perror("Error sending request to server");
        return 1;
    }

    // Receive the server's response
    char response[MAX_BUF_SIZE];
    if (recv(sockfd, response, MAX_BUF_SIZE, 0) < 0) {
        perror("Error receiving response from server");
        return 1;
    }

    // Check if the server's response indicates that the speed test is complete
    if (strcmp(response, "SPEED_TEST_COMPLETE") != 0) {
        fprintf(stderr, "Error: Unexpected response from server\n");
        return 1;
    }

    // Receive the download speed from the server
    if (recv(sockfd, response, MAX_BUF_SIZE, 0) < 0) {
        perror("Error receiving download speed from server");
        return 1;
    }

    // Convert the download speed from a string to a double
    double download_speed = atof(response);

    // Receive the upload speed from the server
    if (recv(sockfd, response, MAX_BUF_SIZE, 0) < 0) {
        perror("Error receiving upload speed from server");
        return 1;
    }

    // Convert the upload speed from a string to a double
    double upload_speed = atof(response);

    // Print the download and upload speeds to the console
    printf("Download speed: %.2f Mbps\n", download_speed);
    printf("Upload speed: %.2f Mbps\n", upload_speed);

    // Close the socket
    close(sockfd);

    return 0;
}