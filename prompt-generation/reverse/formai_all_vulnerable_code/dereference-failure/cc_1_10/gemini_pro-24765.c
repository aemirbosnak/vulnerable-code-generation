//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>

// Ahoy there, landlubber! Let's build ourselves a sturdy FTP client.
int main(int argc, char *argv[]) {
  // Let's grab our server's address and port.
  char *host = argv[1];
  int port = atoi(argv[2]);

  // We'll need a seaworthy socket to connect to the server.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("Socket error!");
    return 1;
  }

  // Now let's set sail for the server.
  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(host);

  // Time to drop anchor at the server.
  if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) == -1) {
    perror("Connection error!");
    return 1;
  }

  // Let's greet the server with a hearty "hello there!"
  char *greeting = "USER anonymous\r\n";
  send(sockfd, greeting, strlen(greeting), 0);

  // Now let's see what the server has to say.
  char buffer[1024];
  int bytes_received = recv(sockfd, buffer, sizeof(buffer), 0);
  if (bytes_received == -1) {
    perror("Receive error!");
    return 1;
  }

  // Ah, the server responds with a warm "password please!"
  printf("%s", buffer);

  // We'll send the server our secret password (of course, it's not really a secret).
  char *password = "anonymous\r\n";
  send(sockfd, password, strlen(password), 0);

  // Let's inquire about the server's treasure trove of files.
  char *list_command = "LIST\r\n";
  send(sockfd, list_command, strlen(list_command), 0);

  // Now let's treasure hunt!
  while ((bytes_received = recv(sockfd, buffer, sizeof(buffer), 0)) > 0) {
    // Looky here, we found some treasure!
    printf("%s", buffer);
  }

  if (bytes_received == -1) {
    perror("Receive error!");
    return 1;
  }

  // Time to bid the server farewell and set sail for home.
  close(sockfd);

  return 0;
}