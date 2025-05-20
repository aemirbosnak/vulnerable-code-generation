//GEMINI-pro DATASET v1.0 Category: Building a SMTP Client ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define BUFSIZE 1024

int main(int argc, char **argv) {
  // Check if the number of arguments is correct
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <hostname> <port> <sender> <recipient>\n", argv[0]);
    return EXIT_FAILURE;
  }

  // Parse the arguments
  char *hostname = argv[1];
  int port = atoi(argv[2]);
  char *sender = argv[3];
  char *recipient = argv[4];

  // Create a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    return EXIT_FAILURE;
  }

  // Resolve the hostname
  struct hostent *hostent = gethostbyname(hostname);
  if (hostent == NULL) {
    perror("gethostbyname");
    return EXIT_FAILURE;
  }

  // Create a sockaddr_in structure
  struct sockaddr_in sockaddr;
  memset(&sockaddr, 0, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_port = htons(port);
  sockaddr.sin_addr = *((struct in_addr *)hostent->h_addr_list[0]);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&sockaddr, sizeof(sockaddr)) == -1) {
    perror("connect");
    return EXIT_FAILURE;
  }

  // Send the EHLO command
  char ehlo_command[BUFSIZE];
  snprintf(ehlo_command, BUFSIZE, "EHLO %s\r\n", hostname);
  if (send(sockfd, ehlo_command, strlen(ehlo_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server response
  char server_response[BUFSIZE];
  int num_bytes_received = recv(sockfd, server_response, BUFSIZE, 0);
  if (num_bytes_received == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the server responded with a 250 OK
  if (strncmp(server_response, "250 OK", 6) != 0) {
    fprintf(stderr, "Error: Server did not respond with a 250 OK\n");
    return EXIT_FAILURE;
  }

  // Send the MAIL FROM command
  char mail_from_command[BUFSIZE];
  snprintf(mail_from_command, BUFSIZE, "MAIL FROM: <%s>\r\n", sender);
  if (send(sockfd, mail_from_command, strlen(mail_from_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server response
  num_bytes_received = recv(sockfd, server_response, BUFSIZE, 0);
  if (num_bytes_received == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the server responded with a 250 OK
  if (strncmp(server_response, "250 OK", 6) != 0) {
    fprintf(stderr, "Error: Server did not respond with a 250 OK\n");
    return EXIT_FAILURE;
  }

  // Send the RCPT TO command
  char rcpt_to_command[BUFSIZE];
  snprintf(rcpt_to_command, BUFSIZE, "RCPT TO: <%s>\r\n", recipient);
  if (send(sockfd, rcpt_to_command, strlen(rcpt_to_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server response
  num_bytes_received = recv(sockfd, server_response, BUFSIZE, 0);
  if (num_bytes_received == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the server responded with a 250 OK
  if (strncmp(server_response, "250 OK", 6) != 0) {
    fprintf(stderr, "Error: Server did not respond with a 250 OK\n");
    return EXIT_FAILURE;
  }

  // Send the DATA command
  char data_command[BUFSIZE] = "DATA\r\n";
  if (send(sockfd, data_command, strlen(data_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server response
  num_bytes_received = recv(sockfd, server_response, BUFSIZE, 0);
  if (num_bytes_received == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the server responded with a 354 Start mail input
  if (strncmp(server_response, "354 Start mail input", 20) != 0) {
    fprintf(stderr, "Error: Server did not respond with a 354 Start mail input\n");
    return EXIT_FAILURE;
  }

  // Send the email body
  char email_body[] = "Hello world!\nThis is an email sent from a SMTP client written in C.\n";
  if (send(sockfd, email_body, strlen(email_body), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Send the dot (.) to indicate the end of the email body
  char dot_command[BUFSIZE] = ".\r\n";
  if (send(sockfd, dot_command, strlen(dot_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server response
  num_bytes_received = recv(sockfd, server_response, BUFSIZE, 0);
  if (num_bytes_received == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the server responded with a 250 OK
  if (strncmp(server_response, "250 OK", 6) != 0) {
    fprintf(stderr, "Error: Server did not respond with a 250 OK\n");
    return EXIT_FAILURE;
  }

  // Send the QUIT command
  char quit_command[BUFSIZE] = "QUIT\r\n";
  if (send(sockfd, quit_command, strlen(quit_command), 0) == -1) {
    perror("send");
    return EXIT_FAILURE;
  }

  // Receive the server response
  num_bytes_received = recv(sockfd, server_response, BUFSIZE, 0);
  if (num_bytes_received == -1) {
    perror("recv");
    return EXIT_FAILURE;
  }

  // Check if the server responded with a 221 Bye
  if (strncmp(server_response, "221 Bye", 6) != 0) {
    fprintf(stderr, "Error: Server did not respond with a 221 Bye\n");
    return EXIT_FAILURE;
  }

  // Close the socket
  close(sockfd);

  return EXIT_SUCCESS;
}