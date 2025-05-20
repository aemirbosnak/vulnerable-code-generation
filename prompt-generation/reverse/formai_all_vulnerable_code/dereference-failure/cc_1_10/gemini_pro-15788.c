//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 110

int main(int argc, char **argv) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <server> <username>\n", argv[0]);
    return EXIT_FAILURE;
  }

  char *server = argv[1];
  char *username = argv[2];

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(struct sockaddr_in));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  struct hostent *host = gethostbyname(server);
  if (host == NULL) {
    fprintf(stderr, "Error: could not resolve hostname %s\n", server);
    return EXIT_FAILURE;
  }
  memcpy(&server_addr.sin_addr, host->h_addr_list[0], host->h_length);

  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    perror("Error: could not create socket");
    return EXIT_FAILURE;
  }

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(struct sockaddr_in)) == -1) {
    perror("Error: could not connect to server");
    return EXIT_FAILURE;
  }

  char buffer[1024];

  // Receive welcome message
  recv(sock, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  // Send USER command
  snprintf(buffer, sizeof(buffer), "USER %s\r\n", username);
  send(sock, buffer, strlen(buffer), 0);

  // Receive USER response
  recv(sock, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  // Send PASS command
  snprintf(buffer, sizeof(buffer), "PASS\r\n");
  send(sock, buffer, strlen(buffer), 0);

  // Receive PASS response
  recv(sock, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  // Send LIST command
  snprintf(buffer, sizeof(buffer), "LIST\r\n");
  send(sock, buffer, strlen(buffer), 0);

  // Receive LIST response
  while (1) {
    recv(sock, buffer, sizeof(buffer), 0);
    printf("%s", buffer);
    if (strcmp(buffer, ".\r\n") == 0) {
      break;
    }
  }

  // Send QUIT command
  snprintf(buffer, sizeof(buffer), "QUIT\r\n");
  send(sock, buffer, strlen(buffer), 0);

  // Receive QUIT response
  recv(sock, buffer, sizeof(buffer), 0);
  printf("%s", buffer);

  close(sock);

  return EXIT_SUCCESS;
}