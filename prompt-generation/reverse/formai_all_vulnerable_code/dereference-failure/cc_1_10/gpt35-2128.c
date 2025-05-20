//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 1024

void handle_error(const char* error_message) {
  perror(error_message);
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
  if (argc != 4) {
    printf("Invalid arguments. Usage: ./pop3 <server_address> <username> <password>\n");
    exit(EXIT_FAILURE);
  }

  const char* server_address = argv[1];
  const char* username = argv[2];
  const char* password = argv[3];

  // Create the socket
  int client_socket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

  struct sockaddr_in server_address_info;
  memset(&server_address_info, 0, sizeof(server_address_info));
  server_address_info.sin_family = AF_INET;
  server_address_info.sin_port = htons(110);
  if (inet_pton(AF_INET, server_address, &server_address_info.sin_addr) <= 0) {
    handle_error("inet_pton() failed");
  }

  // Connect to the server
  if (connect(client_socket, (struct sockaddr*) &server_address_info, sizeof(server_address_info)) < 0) {
    handle_error("connect() failed");
  }

  // Receive the greeting from the server
  char server_buffer[MAX_BUFFER_SIZE];
  if (recv(client_socket, server_buffer, MAX_BUFFER_SIZE-1, 0) < 0) {
    handle_error("recv() failed");
  }
  printf("%s", server_buffer);

  // Send login request
  const size_t max_login_request_size = 100 + strlen(username) + strlen(password); // "USER <username>\r\nPASS <password>\r\n"
  char login_request[max_login_request_size];
  sprintf(login_request, "USER %s\r\nPASS %s\r\n", username, password);
  if (send(client_socket, login_request, strlen(login_request), 0) < 0) {
    handle_error("send() failed");
  }

  // Receive login response
  if (recv(client_socket, server_buffer, MAX_BUFFER_SIZE-1, 0) < 0) {
    handle_error("recv() failed");
  }
  printf("%s", server_buffer);

  // Send STAT command
  const char* stat_command = "STAT\r\n";
  if (send(client_socket, stat_command, strlen(stat_command), 0) < 0) {
    handle_error("send() failed");
  }

  // Receive STAT response
  if (recv(client_socket, server_buffer, MAX_BUFFER_SIZE-1, 0) < 0) {
    handle_error("recv() failed");
  }
  printf("%s", server_buffer);

  // Send QUIT command
  const char* quit_command = "QUIT\r\n";
  if (send(client_socket, quit_command, strlen(quit_command), 0) < 0) {
    handle_error("send() failed");
  }

  // Close the socket
  close(client_socket);

  return 0;
}