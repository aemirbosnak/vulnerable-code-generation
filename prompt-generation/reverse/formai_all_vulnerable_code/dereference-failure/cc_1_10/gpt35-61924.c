//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 1024

int main(int argc, char **argv) {
  if (argc < 4) {
    printf("Please provide the IP address, port number, username and password\n");
    return 1;
  }

  // Create socket
  int sock;
  if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    printf("Failed to create socket\n");
    return 1;
  }

  // Connect to server
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_addr.s_addr = inet_addr(argv[1]);
  server_address.sin_port = htons(atoi(argv[2]));

  if (connect(sock, (struct sockaddr *) &server_address, sizeof(server_address)) < 0) {
    printf("Failed to connect to server\n");
    return 1;
  }

  // Receive server response
  char receive_buffer[MAX_BUFFER_SIZE] = {0};
  read(sock, receive_buffer, MAX_BUFFER_SIZE);
  printf("%s", receive_buffer);

  // Login with credentials
  char user_command[MAX_BUFFER_SIZE] = {0}, pass_command[MAX_BUFFER_SIZE] = {0};
  sprintf(user_command, "USER %s\r\n", argv[3]);
  sprintf(pass_command, "PASS %s\r\n", argv[4]);

  write(sock, user_command, strlen(user_command));
  read(sock, receive_buffer, MAX_BUFFER_SIZE);
  printf("%s", receive_buffer);

  write(sock, pass_command, strlen(pass_command));
  read(sock, receive_buffer, MAX_BUFFER_SIZE);
  printf("%s", receive_buffer);

  // List emails
  char list_command[MAX_BUFFER_SIZE] = "LIST\r\n";
  write(sock, list_command, strlen(list_command));
  read(sock, receive_buffer, MAX_BUFFER_SIZE);
  printf("%s", receive_buffer);

  // Retrieve an email
  printf("Enter the number of the email you want to retrieve: ");
  char email_number[MAX_BUFFER_SIZE] = {0};
  fgets(email_number, MAX_BUFFER_SIZE, stdin);

  char retr_command[MAX_BUFFER_SIZE] = {0};
  sprintf(retr_command, "RETR %s\r\n", email_number);
  write(sock, retr_command, strlen(retr_command));
  read(sock, receive_buffer, MAX_BUFFER_SIZE);
  printf("%s", receive_buffer);

  // Quit session
  char quit_command[MAX_BUFFER_SIZE] = "QUIT\r\n";
  write(sock, quit_command, strlen(quit_command));
  read(sock, receive_buffer, MAX_BUFFER_SIZE);
  printf("%s", receive_buffer);

  close(sock);
  return 0;
}