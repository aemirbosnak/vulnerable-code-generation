//Falcon2-11B DATASET v1.0 Category: Building a POP3 Client ; Style: genius
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define SERVER_NAME "pop.gmail.com"
#define SERVER_PORT "995"
#define BUFFER_SIZE 1024

int main() {
  int socket_fd, n;
  struct sockaddr_in server_address;
  char buffer[BUFFER_SIZE];
  char username[] = "your_username";
  char password[] = "your_password";

  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    perror("Error opening socket");
    return 1;
  }

  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(SERVER_PORT);
  server_address.sin_addr.s_addr = inet_addr(SERVER_NAME);

  if (connect(socket_fd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("Error connecting to server");
    return 1;
  }

  printf("Connected to server\n");
  printf("Enter username: ");
  fgets(buffer, BUFFER_SIZE, stdin);
  strncpy(username, buffer, BUFFER_SIZE);
  username[BUFFER_SIZE - 1] = '\0';

  printf("Enter password: ");
  fgets(buffer, BUFFER_SIZE, stdin);
  strncpy(password, buffer, BUFFER_SIZE);
  password[BUFFER_SIZE - 1] = '\0';

  n = write(socket_fd, username, strlen(username));
  if (n < 0) {
    perror("Error writing username");
    return 1;
  }

  n = write(socket_fd, password, strlen(password));
  if (n < 0) {
    perror("Error writing password");
    return 1;
  }

  n = read(socket_fd, buffer, BUFFER_SIZE);
  if (n < 0) {
    perror("Error reading response");
    return 1;
  }

  printf("Response: %s\n", buffer);

  return 0;
}