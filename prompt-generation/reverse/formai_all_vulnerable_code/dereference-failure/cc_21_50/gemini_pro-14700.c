//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>

#define POP3_PORT 110

int main(int argc, char **argv) {
  // Check if the user provided the server's hostname and username
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server hostname> <username>\n", argv[0]);
    return 1;
  }

  // Resolve the server's hostname to an IP address
  struct hostent *server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "Error resolving hostname: %s\n", argv[1]);
    return 1;
  }

  // Create a socket to connect to the server
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Error creating socket");
    return 1;
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(POP3_PORT);
  server_addr.sin_addr = *((struct in_addr *)server->h_addr);
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Error connecting to server");
    return 1;
  }

  // Read the welcome message from the server
  char buf[1024];
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("Error receiving welcome message");
    return 1;
  }

  // Send the USER command to the server
  snprintf(buf, sizeof(buf), "USER %s\r\n", argv[2]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("Error sending USER command");
    return 1;
  }

  // Read the response from the server
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("Error receiving response to USER command");
    return 1;
  }

  // Check if the USER command was successful
  if (strncmp(buf, "+OK", 3) != 0) {
    fprintf(stderr, "Error: Invalid username\n");
    return 1;
  }

  // Send the PASS command to the server
  snprintf(buf, sizeof(buf), "PASS %s\r\n", argv[3]);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("Error sending PASS command");
    return 1;
  }

  // Read the response from the server
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("Error receiving response to PASS command");
    return 1;
  }

  // Check if the PASS command was successful
  if (strncmp(buf, "+OK", 3) != 0) {
    fprintf(stderr, "Error: Invalid password\n");
    return 1;
  }

  // Send the STAT command to the server
  snprintf(buf, sizeof(buf), "STAT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("Error sending STAT command");
    return 1;
  }

  // Read the response from the server
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("Error receiving response to STAT command");
    return 1;
  }

  // Parse the response from the server to get the number of messages and the total size of the messages
  int num_messages, total_size;
  if (sscanf(buf, "+OK %d %d", &num_messages, &total_size) != 2) {
    fprintf(stderr, "Error parsing STAT response\n");
    return 1;
  }

  // Print the number of messages and the total size of the messages
  printf("Number of messages: %d\n", num_messages);
  printf("Total size of messages: %d bytes\n", total_size);

  // Send the LIST command to the server
  snprintf(buf, sizeof(buf), "LIST\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("Error sending LIST command");
    return 1;
  }

  // Read the response from the server
  while (1) {
    if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
      perror("Error receiving response to LIST command");
      return 1;
    }

    // Check if the server has sent the end of the list
    if (strcmp(buf, ".\r\n") == 0) {
      break;
    }

    // Parse the response from the server to get the message number and size
    int message_number, message_size;
    if (sscanf(buf, "%d %d", &message_number, &message_size) != 2) {
      fprintf(stderr, "Error parsing LIST response\n");
      return 1;
    }

    // Print the message number and size
    printf("Message %d: %d bytes\n", message_number, message_size);
  }

  // Send the QUIT command to the server
  snprintf(buf, sizeof(buf), "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("Error sending QUIT command");
    return 1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}