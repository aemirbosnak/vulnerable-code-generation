//GEMINI-pro DATASET v1.0 Category: Socket programming ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

// Declare our own custom data types
typedef struct {
  char name[32];
  int age;
} Peasant;

// Function to send a message to the socket
void send_message(int sockfd, const char *message) {
  int len = strlen(message);
  if (send(sockfd, message, len, 0) < 0) {
    perror("Error sending message");
    exit(1);
  }
}

// Function to receive a message from the socket
char *receive_message(int sockfd) {
  char *message = (char *)malloc(1024);
  int len = recv(sockfd, message, 1024, 0);
  if (len < 0) {
    perror("Error receiving message");
    exit(1);
  }
  return message;
}

int main() {
  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(1);
  }

  // Set up the server address
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8080);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Error connecting to server");
    exit(1);
  }

  // Send a greeting to the server
  send_message(sockfd, "Greetings, fair server!");

  // Receive a greeting from the server
  char *message = receive_message(sockfd);
  printf("Server: %s\n", message);

  // Send a peasant to the server
  Peasant peasant = {"John", 25};
  if (send(sockfd, &peasant, sizeof(peasant), 0) < 0) {
    perror("Error sending peasant");
    exit(1);
  }

  // Receive a peasant from the server
  Peasant received_peasant;
  if (recv(sockfd, &received_peasant, sizeof(received_peasant), 0) < 0) {
    perror("Error receiving peasant");
    exit(1);
  }

  // Print the received peasant's information
  printf("Received peasant: %s, age: %d\n", received_peasant.name, received_peasant.age);

  // Close the socket
  close(sockfd);

  return 0;
}