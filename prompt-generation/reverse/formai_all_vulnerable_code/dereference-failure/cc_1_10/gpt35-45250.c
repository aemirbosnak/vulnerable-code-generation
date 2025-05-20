//FormAI DATASET v1.0 Category: Building a FTP Client ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(int argc, char **argv) {

  // Check for correct number of arguments
  if (argc != 3) {
    printf("Usage: %s <server_ip> <port_number>\n", argv[0]);
    exit(1);
  }

  // Create socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if(sockfd < 0) {
    perror("Failed to create socket");
    exit(1);
  }

  // Set up server address
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(atoi(argv[2]));
  if(inet_pton(AF_INET, argv[1], &servaddr.sin_addr) <= 0) {
    perror("Invalid server IP address");
    exit(1);
  }

  // Connect to server
  if(connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0) {
    perror("Failed to connect to server");
    exit(1);
  }

  // Receive welcome message from server
  char buffer[BUFFER_SIZE];
  memset(buffer, 0, BUFFER_SIZE);
  read(sockfd, buffer, BUFFER_SIZE-1);
  printf("%s\n", buffer);

  // Send username
  char username[BUFFER_SIZE];
  printf("Username: ");
  scanf("%s", username);
  write(sockfd, username, strlen(username));

  // Receive password prompt
  memset(buffer, 0, BUFFER_SIZE);
  read(sockfd, buffer, BUFFER_SIZE-1);
  printf("%s", buffer);

  // Send password
  char password[BUFFER_SIZE];
  printf("Password: ");
  scanf("%s", password);
  write(sockfd, password, strlen(password));

  // Receive login confirmation
  memset(buffer, 0, BUFFER_SIZE);
  read(sockfd, buffer, BUFFER_SIZE-1);
  if (strcmp(buffer, "Login successful") != 0) {
    perror("Login failed");
    exit(1);
  }
  printf("%s\n", buffer);

  // Loop to send commands and receive responses
  while (1) {

    // Send command
    printf("Command: ");
    char command[BUFFER_SIZE];
    scanf("%s", command);
    write(sockfd, command, strlen(command));

    // Quit if command is "quit"
    if (strcmp(command, "quit") == 0) {
      exit(0);
    }

    // Receive response
    memset(buffer, 0, BUFFER_SIZE);
    read(sockfd, buffer, BUFFER_SIZE-1);
    printf("%s", buffer);
  }

  return 0;
}