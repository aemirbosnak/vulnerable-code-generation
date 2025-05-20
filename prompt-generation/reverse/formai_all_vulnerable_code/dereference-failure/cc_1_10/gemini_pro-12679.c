//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>

// POP3 commands
#define USER "USER"
#define PASS "PASS"
#define LIST "LIST"
#define RETR "RETR"
#define DELE "DELE"
#define QUIT "QUIT"

// POP3 response codes
#define OK "+OK"
#define ERR "-ERR"

// Maximum buffer size
#define BUF_SIZE 1024

// Function to send a command to the POP3 server
int send_command(int sockfd, char *cmd) {
  int len = strlen(cmd);
  int n = send(sockfd, cmd, len, 0);
  if (n < 0) {
    perror("send");
    return -1;
  }
  return 0;
}

// Function to receive a response from the POP3 server
char *recv_response(int sockfd) {
  char *buf = malloc(BUF_SIZE);
  int n = recv(sockfd, buf, BUF_SIZE-1, 0);
  if (n < 0) {
    perror("recv");
    free(buf);
    return NULL;
  }
  buf[n] = '\0';
  return buf;
}

// Function to login to the POP3 server
int login(int sockfd, char *username, char *password) {
  char cmd[BUF_SIZE];
  char *resp;

  // Send the USER command
  sprintf(cmd, "%s %s\r\n", USER, username);
  if (send_command(sockfd, cmd) < 0) {
    return -1;
  }

  // Receive the response
  resp = recv_response(sockfd);
  if (!resp) {
    return -1;
  }

  // Check the response code
  if (strncmp(resp, OK, 3) != 0) {
    printf("Login failed: %s\n", resp);
    free(resp);
    return -1;
  }

  // Send the PASS command
  sprintf(cmd, "%s %s\r\n", PASS, password);
  if (send_command(sockfd, cmd) < 0) {
    free(resp);
    return -1;
  }

  // Receive the response
  resp = recv_response(sockfd);
  if (!resp) {
    free(resp);
    return -1;
  }

  // Check the response code
  if (strncmp(resp, OK, 3) != 0) {
    printf("Login failed: %s\n", resp);
    free(resp);
    return -1;
  }

  free(resp);
  return 0;
}

// Function to list the messages on the POP3 server
int list_messages(int sockfd) {
  char cmd[BUF_SIZE];
  char *resp;

  // Send the LIST command
  if (send_command(sockfd, LIST"\r\n") < 0) {
    return -1;
  }

  // Receive the response
  resp = recv_response(sockfd);
  if (!resp) {
    return -1;
  }

  // Check the response code
  if (strncmp(resp, OK, 3) != 0) {
    printf("LIST failed: %s\n", resp);
    free(resp);
    return -1;
  }

  // Print the list of messages
  printf("%s", resp);

  free(resp);
  return 0;
}

// Function to retrieve a message from the POP3 server
int retrieve_message(int sockfd, int msg_num) {
  char cmd[BUF_SIZE];
  char *resp;

  // Send the RETR command
  sprintf(cmd, "%s %d\r\n", RETR, msg_num);
  if (send_command(sockfd, cmd) < 0) {
    return -1;
  }

  // Receive the response
  resp = recv_response(sockfd);
  if (!resp) {
    return -1;
  }

  // Check the response code
  if (strncmp(resp, OK, 3) != 0) {
    printf("RETR failed: %s\n", resp);
    free(resp);
    return -1;
  }

  // Print the message
  printf("%s", resp);

  free(resp);
  return 0;
}

// Function to delete a message from the POP3 server
int delete_message(int sockfd, int msg_num) {
  char cmd[BUF_SIZE];
  char *resp;

  // Send the DELE command
  sprintf(cmd, "%s %d\r\n", DELE, msg_num);
  if (send_command(sockfd, cmd) < 0) {
    return -1;
  }

  // Receive the response
  resp = recv_response(sockfd);
  if (!resp) {
    return -1;
  }

  // Check the response code
  if (strncmp(resp, OK, 3) != 0) {
    printf("DELE failed: %s\n", resp);
    free(resp);
    return -1;
  }

  free(resp);
  return 0;
}

// Function to quit the POP3 server
int quit(int sockfd) {
  char cmd[BUF_SIZE];
  char *resp;

  // Send the QUIT command
  if (send_command(sockfd, QUIT"\r\n") < 0) {
    return -1;
  }

  // Receive the response
  resp = recv_response(sockfd);
  if (!resp) {
    return -1;
  }

  // Check the response code
  if (strncmp(resp, OK, 3) != 0) {
    printf("QUIT failed: %s\n", resp);
    free(resp);
    return -1;
  }

  free(resp);
  return 0;
}

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in serv_addr;
  int port = 110;  // Default POP3 port

  // Check the command line arguments
  if (argc != 3) {
    printf("Usage: %s <server> <username>\n", argv[0]);
    return 1;
  }

  // Get the server address and port
  char *server = argv[1];
  char *username = argv[2];

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    return 1;
  }

  // Set the server address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(port);
  serv_addr.sin_addr.s_addr = inet_addr(server);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect");
    return 1;
  }

  // Receive the welcome message
  char *resp = recv_response(sockfd);
  if (!resp) {
    return 1;
  }

  // Check the response code
  if (strncmp(resp, OK, 3) != 0) {
    printf("Welcome message: %s\n", resp);
    free(resp);
    return 1;
  }

  // Login to the server
  if (login(sockfd, username, "password") < 0) {
    return 1;
  }

  // List the messages
  if (list_messages(sockfd) < 0) {
    return 1;
  }

  // Retrieve a message
  if (retrieve_message(sockfd, 1) < 0) {
    return 1;
  }

  // Delete a message
  if (delete_message(sockfd, 1) < 0) {
    return 1;
  }

  // Quit the server
  if (quit(sockfd) < 0) {
    return 1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}