//Gemma-7B DATASET v1.0 Category: Simple Web Server ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER_PORT 8080
#define BUFFER_SIZE 1024

typedef struct {
  char name[256];
  int age;
  char occupation[256];
} user_data;

user_data users[10] = {
  {"John Doe", 25, "Software Engineer"},
  {"Jane Doe", 22, "Artist"},
  {"Peter Pan", 12, "Student"},
  {"Mary Poppins", 32, "Teacher"},
  {"Captain Hook", 50, "Pirate"}
};

int main() {
  int sockfd, newsockfd;
  struct sockaddr_in server_addr, client_addr;
  char buffer[BUFFER_SIZE];
  int client_len;

  // Bind socket to port
  sockfd = socket(AF_INET, SOCK_STREAM, htons(SERVER_PORT));
  if (sockfd < 0) {
    perror("Error binding socket");
    exit(1);
  }

  // Listen for connections
  listen(sockfd, 10);

  // Accept connection
  newsockfd = accept(sockfd, (struct sockaddr *)&client_addr, (int *)&client_len);
  if (newsockfd < 0) {
    perror("Error accepting connection");
    exit(1);
  }

  // Read client message
  read(newsockfd, buffer, BUFFER_SIZE);
  printf("Client: %s\n", buffer);

  // Send response
  sprintf(buffer, "Hello, %s!", users[0].name);
  write(newsockfd, buffer, strlen(buffer) + 1);

  // Close connection
  close(newsockfd);

  return 0;
}