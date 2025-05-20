//FormAI DATASET v1.0 Category: Building a IMAP Client ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

#define BUFFER_SIZE 1024
#define IMAP_PORT 143

int main(int argc, char *argv[])
{
  struct hostent *server;
  struct sockaddr_in imap_server_address;
  char username[BUFFER_SIZE], password[BUFFER_SIZE], server_response[BUFFER_SIZE], command[BUFFER_SIZE];

  if (argc < 2)
  {
    printf("Please provide the hostname of the IMAP server.\n");
    return 1;
  }

  server = gethostbyname(argv[1]);
  if (!server)
  {
    printf("Could not resolve hostname.\n");
    return 1;
  }

  int socket_descriptor = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_descriptor < 0)
  {
    printf("Could not create socket.\n");
    return 1;
  }

  memset((char *)&imap_server_address, 0, sizeof(imap_server_address));
  imap_server_address.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&imap_server_address.sin_addr.s_addr, server->h_length);
  imap_server_address.sin_port = htons(IMAP_PORT);

  if (connect(socket_descriptor, (struct sockaddr *)&imap_server_address, sizeof(imap_server_address)) < 0)
  {
    printf("Could not connect to IMAP server.\n");
    return 1;
  }

  recv(socket_descriptor, server_response, BUFFER_SIZE, 0);
  printf("%s", server_response);

  printf("Username: ");
  fgets(username, BUFFER_SIZE, stdin);
  printf("Password: ");
  fgets(password, BUFFER_SIZE, stdin);

  snprintf(command, BUFFER_SIZE, "1 LOGIN %s %s\r\n", username, password);
  send(socket_descriptor, command, strlen(command), 0);
  memset(server_response, 0, BUFFER_SIZE);
  recv(socket_descriptor, server_response, BUFFER_SIZE, 0);
  printf("%s", server_response);

  snprintf(command, BUFFER_SIZE, "2 SELECT INBOX\r\n");
  send(socket_descriptor, command, strlen(command), 0);
  memset(server_response, 0, BUFFER_SIZE);
  recv(socket_descriptor, server_response, BUFFER_SIZE, 0);
  printf("%s", server_response);

  snprintf(command, BUFFER_SIZE, "3 LOGOUT\r\n");
  send(socket_descriptor, command, strlen(command), 0);

  close(socket_descriptor);
  return 0;
}