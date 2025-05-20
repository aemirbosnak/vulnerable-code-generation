//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: surrealist
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <server> <port>\n", argv[0]);
    return 1;
  }

  // Resolve the server's address
  struct hostent *host = gethostbyname(argv[1]);
  if (host == NULL) {
    printf("Error: could not resolve server address\n");
    return 1;
  }

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock == -1) {
    printf("Error: could not create socket\n");
    return 1;
  }

  // Connect to the server
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_port = htons(atoi(argv[2]));
  addr.sin_addr = *(struct in_addr *)host->h_addr;
  if (connect(sock, (struct sockaddr *)&addr, sizeof(addr)) == -1) {
    printf("Error: could not connect to server\n");
    return 1;
  }

  // Send the POP3 greeting
  char greeting[512];
  recv(sock, greeting, sizeof(greeting), 0);
  printf("%s", greeting);

  // Send the USER command
  char user[512];
  sprintf(user, "USER %s\r\n", "your_username");
  send(sock, user, strlen(user), 0);

  // Receive the USER response
  char response[512];
  recv(sock, response, sizeof(response), 0);
  printf("%s", response);

  // Send the PASS command
  char pass[512];
  sprintf(pass, "PASS %s\r\n", "your_password");
  send(sock, pass, strlen(pass), 0);

  // Receive the PASS response
  recv(sock, response, sizeof(response), 0);
  printf("%s", response);

  // Send the LIST command
  char list[512];
  strcpy(list, "LIST\r\n");
  send(sock, list, strlen(list), 0);

  // Receive the LIST response
  char listResponse[512];
  recv(sock, listResponse, sizeof(listResponse), 0);
  printf("%s", listResponse);

  // Send the RETR command
  char retr[512];
  sprintf(retr, "RETR %d\r\n", 1);
  send(sock, retr, strlen(retr), 0);

  // Receive the RETR response
  char retrResponse[512];
  recv(sock, retrResponse, sizeof(retrResponse), 0);
  printf("%s", retrResponse);

  // Send the QUIT command
  char quit[512];
  strcpy(quit, "QUIT\r\n");
  send(sock, quit, strlen(quit), 0);

  // Receive the QUIT response
  recv(sock, response, sizeof(response), 0);
  printf("%s", response);

  // Close the socket
  close(sock);

  return 0;
}