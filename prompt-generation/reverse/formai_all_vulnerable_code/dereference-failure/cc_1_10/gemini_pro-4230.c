//GEMINI-pro DATASET v1.0 Category: Internet Speed Test Application ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Defines the size of the buffer for receiving and sending data
#define BUFFER_SIZE 1024

// Function to measure the download speed of the internet connection
int measure_download_speed(char* server_ip, int server_port) {
  // Create a socket for communication with the server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error creating socket");
    return -1;
  }

  // Set the server address and port
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(server_port);
  server_addr.sin_addr.s_addr = inet_addr(server_ip);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error connecting to server");
    return -1;
  }

  // Send a request to the server to start the download
  char request[] = "GET /download HTTP/1.1\r\n\r\n";
  if (send(sockfd, request, strlen(request), 0) == -1) {
    perror("Error sending request to server");
    return -1;
  }

  // Receive the response from the server
  char buffer[BUFFER_SIZE];
  int total_bytes_received = 0;
  while (recv(sockfd, buffer, BUFFER_SIZE, 0) > 0) {
    total_bytes_received += BUFFER_SIZE;
  }

  // Calculate the download speed in bytes per second
  int download_speed = total_bytes_received / 1024;  // Convert to kilobytes per second

  // Close the socket
  close(sockfd);

  // Return the download speed
  return download_speed;
}

// Function to measure the upload speed of the internet connection
int measure_upload_speed(char* server_ip, int server_port) {
  // Create a socket for communication with the server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error creating socket");
    return -1;
  }

  // Set the server address and port
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(server_port);
  server_addr.sin_addr.s_addr = inet_addr(server_ip);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error connecting to server");
    return -1;
  }

  // Prepare the data to be uploaded
  char data[BUFFER_SIZE];
  for (int i = 0; i < BUFFER_SIZE; i++) {
    data[i] = 'a';
  }

  // Send the data to the server
  int total_bytes_sent = 0;
  while (total_bytes_sent < BUFFER_SIZE) {
    int bytes_sent = send(sockfd, data, BUFFER_SIZE, 0);
    if (bytes_sent == -1) {
      perror("Error sending data to server");
      return -1;
    }
    total_bytes_sent += bytes_sent;
  }

  // Calculate the upload speed in bytes per second
  int upload_speed = total_bytes_sent / 1024;  // Convert to kilobytes per second

  // Close the socket
  close(sockfd);

  // Return the upload speed
  return upload_speed;
}

// Main function
int main(int argc, char** argv) {
  // Check if the user provided the server IP and port
  if (argc != 3) {
    printf("Usage: %s <server_ip> <server_port>\n", argv[0]);
    return -1;
  }

  // Get the server IP and port from the command line arguments
  char* server_ip = argv[1];
  int server_port = atoi(argv[2]);

  // Measure the download speed
  int download_speed = measure_download_speed(server_ip, server_port);
  if (download_speed == -1) {
    printf("Error measuring download speed\n");
    return -1;
  }

  // Measure the upload speed
  int upload_speed = measure_upload_speed(server_ip, server_port);
  if (upload_speed == -1) {
    printf("Error measuring upload speed\n");
    return -1;
  }

  // Print the download and upload speeds
  printf("Download speed: %d kbps\n", download_speed);
  printf("Upload speed: %d kbps\n", upload_speed);

  return 0;
}