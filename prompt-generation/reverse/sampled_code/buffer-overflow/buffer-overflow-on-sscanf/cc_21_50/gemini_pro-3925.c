//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <unistd.h>

#define POP3_PORT 110

int main(int argc, char *argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <user>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *server = argv[1];
  char *user = argv[2];

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(POP3_PORT);

  struct hostent *host = gethostbyname(server);
  if (host == NULL) {
    fprintf(stderr, "Error: could not resolve server address\n");
    return EXIT_FAILURE;
  }

  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error: could not create socket");
    return EXIT_FAILURE;
  }

  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error: could not connect to server");
    close(sockfd);
    return EXIT_FAILURE;
  }

  char buffer[1024];
  int n;

  // Send the USER command
  snprintf(buffer, sizeof(buffer), "USER %s\r\n", user);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("Error: could not send USER command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the server response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("Error: could not receive server response");
    close(sockfd);
    return EXIT_FAILURE;
  }

  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: server did not accept USER command\n");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Send the PASS command
  snprintf(buffer, sizeof(buffer), "PASS %s\r\n", argv[3]);
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("Error: could not send PASS command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the server response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("Error: could not receive server response");
    close(sockfd);
    return EXIT_FAILURE;
  }

  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: server did not accept PASS command\n");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Send the STAT command
  snprintf(buffer, sizeof(buffer), "STAT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("Error: could not send STAT command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the server response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("Error: could not receive server response");
    close(sockfd);
    return EXIT_FAILURE;
  }

  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: server did not accept STAT command\n");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Parse the STAT response
  int num_messages;
  int total_size;
  sscanf(buffer, "+OK %d %d", &num_messages, &total_size);

  // Print the STAT response
  printf("Number of messages: %d\n", num_messages);
  printf("Total size of messages: %d\n", total_size);

  // Send the LIST command
  snprintf(buffer, sizeof(buffer), "LIST\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("Error: could not send LIST command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the server response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("Error: could not receive server response");
    close(sockfd);
    return EXIT_FAILURE;
  }

  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: server did not accept LIST command\n");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Parse the LIST response
  int i;
  for (i = 0; i < num_messages; i++) {
    n = recv(sockfd, buffer, sizeof(buffer), 0);
    if (n == -1) {
      perror("Error: could not receive server response");
      close(sockfd);
      return EXIT_FAILURE;
    }

    int message_number;
    int message_size;
    sscanf(buffer, "%d %d", &message_number, &message_size);

    printf("Message %d: size %d\n", message_number, message_size);
  }

  // Send the QUIT command
  snprintf(buffer, sizeof(buffer), "QUIT\r\n");
  if (send(sockfd, buffer, strlen(buffer), 0) == -1) {
    perror("Error: could not send QUIT command");
    close(sockfd);
    return EXIT_FAILURE;
  }

  // Receive the server response
  n = recv(sockfd, buffer, sizeof(buffer), 0);
  if (n == -1) {
    perror("Error: could not receive server response");
    close(sockfd);
    return EXIT_FAILURE;
  }

  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Error: server did not accept QUIT command\n");
    close(sockfd);
    return EXIT_FAILURE;
  }

  close(sockfd);
  return EXIT_SUCCESS;
}