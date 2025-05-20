//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

// Welcome to the POP3 Post Office!
// Let's grab our mail together!

// Our mail server's address and port
#define HOST "pop.example.com"
#define PORT 110

// Prototypes to keep our code organized
void error(char *msg);
int connect_to_server(char *host, int port);
void send_command(int sock, char *cmd);
void receive_response(int sock);

int main() {

  // Let's start by connecting to the mail server
  int sock = connect_to_server(HOST, PORT);
  if (sock < 0) {
    error("Connection failed");
  }

  // Time to say hello and introduce ourselves
  send_command(sock, "USER your_username");
  receive_response(sock);

  // Next, we need our magic password
  send_command(sock, "PASS your_password");
  receive_response(sock);

  // Awesome! We're in. Let's check our inbox
  send_command(sock, "LIST");
  receive_response(sock);

  // Now, let's retrieve a specific email
  send_command(sock, "RETR 1");
  receive_response(sock);

  // Finally, let's say goodbye and close the connection
  send_command(sock, "QUIT");
  receive_response(sock);
  close(sock);

  return 0;
}

// Error handling - let's print out what went wrong
void error(char *msg) {
  printf("%s\n", msg);
  exit(1);
}

// Connecting to the mail server - like ringing a doorbell
int connect_to_server(char *host, int port) {
  struct sockaddr_in serv_addr;
  struct hostent *server;
  int sock;

  sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    error("Socket creation failed");
  }

  server = gethostbyname(host);
  if (server == NULL) {
    error("Host not found");
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(port);

  if (connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    error("Couldn't connect to the server");
  }

  return sock;
}

// Sending commands to the mail server - like talking to a friend
void send_command(int sock, char *cmd) {
  int n;

  n = write(sock, cmd, strlen(cmd));
  if (n < 0) {
    error("Error sending command");
  }
}

// Receiving responses from the mail server - like listening to our friend's reply
void receive_response(int sock) {
  char buffer[256];
  int n;

  bzero(buffer, 256);
  n = read(sock, buffer, 255);
  if (n < 0) {
    error("Error receiving response");
  }

  printf("%s", buffer);
}