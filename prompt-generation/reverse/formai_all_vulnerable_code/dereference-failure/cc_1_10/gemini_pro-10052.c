//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

// Romeo and Juliet function to send a message to the POP3 server
void send_message(int sock, char *msg) {
  int len = strlen(msg);
  if (send(sock, msg, len, 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }
  printf("Romeo: %s\n", msg);
}

// Romeo and Juliet function to receive a message from the POP3 server
char *receive_message(int sock) {
  char buf[BUFSIZE];
  int len = recv(sock, buf, BUFSIZE, 0);
  if (len < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  buf[len] = '\0';
  printf("Juliet: %s\n", buf);
  return strdup(buf);
}

// Romeo and Juliet function to connect to the POP3 server
int connect_to_server(char *host, int port) {
  int sock;
  struct sockaddr_in server_addr;

  // Create a socket
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Set up the server address
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr.s_addr = inet_addr(host);

  // Connect to the server
  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  return sock;
}

int main(int argc, char **argv) {
  int sock;
  char *host;
  int port;
  char *user;
  char *pass;

  // Check the command line arguments
  if (argc != 5) {
    fprintf(stderr, "Usage: %s host port user pass\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  host = argv[1];
  port = atoi(argv[2]);
  user = argv[3];
  pass = argv[4];

  // Connect to the POP3 server
  sock = connect_to_server(host, port);

  // Send the USER command
  send_message(sock, "USER ");
  send_message(sock, user);
  send_message(sock, "\r\n");

  // Receive the response from the server
  char *response = receive_message(sock);
  if (strncmp(response, "+OK", 3) != 0) {
    fprintf(stderr, "Error: %s\n", response);
    exit(EXIT_FAILURE);
  }

  // Send the PASS command
  send_message(sock, "PASS ");
  send_message(sock, pass);
  send_message(sock, "\r\n");

  // Receive the response from the server
  response = receive_message(sock);
  if (strncmp(response, "+OK", 3) != 0) {
    fprintf(stderr, "Error: %s\n", response);
    exit(EXIT_FAILURE);
  }

  // Send the LIST command
  send_message(sock, "LIST");
  send_message(sock, "\r\n");

  // Receive the response from the server
  response = receive_message(sock);
  if (strncmp(response, "+OK", 3) != 0) {
    fprintf(stderr, "Error: %s\n", response);
    exit(EXIT_FAILURE);
  }

  // Print the list of messages
  while (1) {
    response = receive_message(sock);
    if (strncmp(response, ".", 1) == 0) {
      break;
    }
    printf("%s\n", response);
  }

  // Send the QUIT command
  send_message(sock, "QUIT");
  send_message(sock, "\r\n");

  // Receive the response from the server
  response = receive_message(sock);
  if (strncmp(response, "+OK", 3) != 0) {
    fprintf(stderr, "Error: %s\n", response);
    exit(EXIT_FAILURE);
  }

  // Close the socket
  close(sock);

  return 0;
}