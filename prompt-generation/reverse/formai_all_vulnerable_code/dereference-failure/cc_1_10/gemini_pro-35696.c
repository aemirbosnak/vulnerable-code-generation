//GEMINI-pro DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>

// Function to calculate the entropy of a given string
double calculate_entropy(char *string) {
  int length = strlen(string);
  double entropy = 0.0;

  int character_counts[256] = {0};
  for (int i = 0; i < length; i++) {
    character_counts[string[i]]++;
  }

  for (int i = 0; i < 256; i++) {
    if (character_counts[i] > 0) {
      double probability = (double)character_counts[i] / length;
      entropy -= probability * log2(probability);
    }
  }

  return entropy;
}

// Function to monitor the quality of service (QoS) of a network connection
void monitor_qos(char *hostname, int port) {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }
  
  // Lookup host information
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    herror("Error resolving hostname");
    exit(EXIT_FAILURE);
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  memcpy(&server_addr.sin_addr, host->h_addr, host->h_length);

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting to server");
    exit(EXIT_FAILURE);
  }

  // Send a message to the server
  char *message = "Hello, world!";
  if (send(sockfd, message, strlen(message), 0) < 0) {
    perror("Error sending message");
    exit(EXIT_FAILURE);
  }

  // Receive a response from the server
  char buffer[1024] = {0};
  if (recv(sockfd, buffer, sizeof(buffer), 0) < 0) {
    perror("Error receiving message");
    exit(EXIT_FAILURE);
  }

  // Calculate the entropy of the response
  double entropy = calculate_entropy(buffer);
  
  // Print the entropy to the console
  printf("Entropy: %f\n", entropy);

  // Close the socket
  close(sockfd);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user provided the correct number of arguments
  if (argc != 3) {
    printf("Usage: %s <hostname> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Parse the hostname and port from the command line arguments
  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Monitor the QoS of the network connection
  monitor_qos(hostname, port);

  return 0;
}