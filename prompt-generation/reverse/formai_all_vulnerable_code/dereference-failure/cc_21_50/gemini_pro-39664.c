//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

// A puzzling journey through the Post Office Protocol (POP3)
int main(void) {
  // Establishing a connection with the mail server
  struct sockaddr_in server_address;
  struct hostent *server;
  int sockfd;
  char *server_name = "mail.example.com"; // Replace with the actual server name
  server = gethostbyname(server_name);
  if (server == NULL) {
    perror("gethostbyname");
    exit(EXIT_FAILURE);
  }
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }
  memset(&server_address, 0, sizeof(server_address));
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(110); // POP3 port
  memcpy(&server_address.sin_addr.s_addr, server->h_addr, server->h_length);
  if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Sending the USER command to identify the user
  char username[] = "username"; // Replace with the actual username
  char user_command[strlen(username) + 6];
  sprintf(user_command, "USER %s\r\n", username);
  if (send(sockfd, user_command, strlen(user_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }
  char server_response[512];
  if (recv(sockfd, server_response, sizeof(server_response), 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  if (strncmp(server_response, "+OK", 3) != 0) {
    printf("Error: %s\n", server_response);
    exit(EXIT_FAILURE);
  }

  // Sending the PASS command to provide the password
  char password[] = "password"; // Replace with the actual password
  char pass_command[strlen(password) + 6];
  sprintf(pass_command, "PASS %s\r\n", password);
  if (send(sockfd, pass_command, strlen(pass_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }
  if (recv(sockfd, server_response, sizeof(server_response), 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  if (strncmp(server_response, "+OK", 3) != 0) {
    printf("Error: %s\n", server_response);
    exit(EXIT_FAILURE);
  }

  // Sending the STAT command to fetch the number of emails
  char stat_command[] = "STAT\r\n";
  if (send(sockfd, stat_command, strlen(stat_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }
  if (recv(sockfd, server_response, sizeof(server_response), 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  if (strncmp(server_response, "+OK", 3) != 0) {
    printf("Error: %s\n", server_response);
    exit(EXIT_FAILURE);
  }
  char *num_emails = strtok(server_response, " "); // Extracting the number of emails
  if (num_emails == NULL) {
    printf("Error: Invalid STAT response\n");
    exit(EXIT_FAILURE);
  }

  // Printing the number of emails
  printf("Number of emails: %s\n", num_emails);

  // Sending the LIST command to fetch the email details
  char list_command[] = "LIST\r\n";
  if (send(sockfd, list_command, strlen(list_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }
  int email_count = 1;
  while (recv(sockfd, server_response, sizeof(server_response), 0) > 0) {
    if (strncmp(server_response, "+OK", 3) != 0) {
      printf("Error: %s\n", server_response);
      exit(EXIT_FAILURE);
    }
    char *email_details = strtok(server_response, " "); // Extracting email details
    if (email_details == NULL) {
      printf("Error: Invalid LIST response\n");
      exit(EXIT_FAILURE);
    }
    printf("Email %d: %s bytes\n", email_count, email_details);
    email_count++;
  }

  // Sending the QUIT command to end the session
  char quit_command[] = "QUIT\r\n";
  if (send(sockfd, quit_command, strlen(quit_command), 0) < 0) {
    perror("send");
    exit(EXIT_FAILURE);
  }
  if (recv(sockfd, server_response, sizeof(server_response), 0) < 0) {
    perror("recv");
    exit(EXIT_FAILURE);
  }
  if (strncmp(server_response, "+OK", 3) != 0) {
    printf("Error: %s\n", server_response);
    exit(EXIT_FAILURE);
  }

  // Closing the socket connection
  close(sockfd);
  return 0;
}