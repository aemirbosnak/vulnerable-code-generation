//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>

#define SERVER_PORT 25
#define MAX_MSG_LENGTH 1024

void error(char *msg) {
  // function to handle errors and exit the program
  perror(msg);
  exit(1);
}

int main() {
  // create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  
  // check for socket creation errors
  if (sockfd < 0) {
    error("ERROR: Could not create socket");
  }
  
  // get server information from DNS
  struct hostent *server = gethostbyname("smtp.example.com");
  if (server == NULL) {
    error("ERROR: Could not resolve hostname");
  }
  
  // create server address structure
  struct sockaddr_in server_address;
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(SERVER_PORT);
  memcpy(&server_address.sin_addr.s_addr,
         server->h_addr_list[0], server->h_length);
         
  // connect to server
  if (connect(sockfd, (struct sockaddr *)&server_address,
              sizeof(server_address)) < 0) {
    error("ERROR: Could not connect to server");
  }
  
  // receive server welcome message
  char server_msg[MAX_MSG_LENGTH];
  if (recv(sockfd, server_msg, MAX_MSG_LENGTH, 0) < 0) {
    error("ERROR: Could not receive server message");
  }
  printf("%s", server_msg);
  
  // send HELO message to server
  char client_msg[MAX_MSG_LENGTH];
  sprintf(client_msg, "HELO example.com\r\n");
  if (send(sockfd, client_msg, strlen(client_msg), 0) < 0) {
    error("ERROR: Could not send client message");
  }
  
  // receive server response to HELO message
  if (recv(sockfd, server_msg, MAX_MSG_LENGTH, 0) < 0) {
    error("ERROR: Could not receive server message");
  }
  printf("%s", server_msg);
  
  // send MAIL FROM message to server
  sprintf(client_msg, "MAIL FROM:<sender@example.com>\r\n");
  if (send(sockfd, client_msg, strlen(client_msg), 0) < 0) {
    error("ERROR: Could not send client message");
  }
  
  // receive server response to MAIL FROM message
  if (recv(sockfd, server_msg, MAX_MSG_LENGTH, 0) < 0) {
    error("ERROR: Could not receive server message");
  }
  printf("%s", server_msg);
  
  // send RCPT TO message to server
  sprintf(client_msg, "RCPT TO:<recipient@example.com>\r\n");
  if (send(sockfd, client_msg, strlen(client_msg), 0) < 0) {
    error("ERROR: Could not send client message");
  }
  
  // receive server response to RCPT TO message
  if (recv(sockfd, server_msg, MAX_MSG_LENGTH, 0) < 0) {
    error("ERROR: Could not receive server message");
  }
  printf("%s", server_msg);
  
  // send DATA message to server
  sprintf(client_msg, "DATA\r\n");
  if (send(sockfd, client_msg, strlen(client_msg), 0) < 0) {
    error("ERROR: Could not send client message");
  }
  
  // receive server response to DATA message
  if (recv(sockfd, server_msg, MAX_MSG_LENGTH, 0) < 0) {
    error("ERROR: Could not receive server message");
  }
  printf("%s", server_msg);
  
  // send message content to server
  sprintf(client_msg, "Subject: Testing SMTP Client\r\n\r\nThis is a test email.\r\n.\r\n");
  if (send(sockfd, client_msg, strlen(client_msg), 0) < 0) {
    error("ERROR: Could not send client message");
  }
  
  // receive server response to message content
  if (recv(sockfd, server_msg, MAX_MSG_LENGTH, 0) < 0) {
    error("ERROR: Could not receive server message");
  }
  printf("%s", server_msg);
  
  // send QUIT message to server
  sprintf(client_msg, "QUIT\r\n");
  if (send(sockfd, client_msg, strlen(client_msg), 0) < 0) {
    error("ERROR: Could not send client message");
  }
  
  // receive server response to QUIT message
  if (recv(sockfd, server_msg, MAX_MSG_LENGTH, 0) < 0) {
    error("ERROR: Could not receive server message");
  }
  printf("%s", server_msg);
  
  // close socket and exit program
  close(sockfd);
  return 0;
}