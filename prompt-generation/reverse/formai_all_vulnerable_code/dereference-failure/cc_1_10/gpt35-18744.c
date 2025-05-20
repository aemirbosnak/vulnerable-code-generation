//FormAI DATASET v1.0 Category: Building a POP3 Client ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <ctype.h>

#define BUFFER_SIZE 4096
#define POP3_PORT 110

int connect_to_pop3(char* server_name) {
  struct hostent* server_address;
  struct sockaddr_in server_socket_address;
  int sockfd;

  server_address = gethostbyname(server_name);
  if (server_address == NULL) {
    fprintf(stderr, "Error: Unable to locate POP3 server %s.\n", server_name);
    exit(1);
  }

  memset(&server_socket_address, 0, sizeof(server_socket_address));
  server_socket_address.sin_family = AF_INET;
  server_socket_address.sin_port = htons(POP3_PORT);
  memcpy(&server_socket_address.sin_addr, server_address->h_addr_list[0], server_address->h_length);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error: Unable to create socket.\n");
    exit(1);
  }

  if (connect(sockfd, (struct sockaddr*)&server_socket_address, sizeof(server_socket_address)) < 0) {
    fprintf(stderr, "Error: Unable to connect to POP3 server %s.\n", server_name);
    exit(1);
  }

  char buffer[BUFFER_SIZE];
  int bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (bytes_received < 0) {
    fprintf(stderr, "Error: Unable to read message from server.\n");
    exit(1);
  }
  buffer[bytes_received] = '\0';
  printf("Server response: %s", buffer);

  return sockfd;
}

int send_command(int sockfd, char* command, char* expected_response_code) {
  char buffer[BUFFER_SIZE];
  int bytes_sent, bytes_received;

  bytes_sent = send(sockfd, command, strlen(command), 0);
  if (bytes_sent < 0) {
    fprintf(stderr, "Error: Unable to send command: %s\n", command);
    exit(1);
  }

  bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0);
  if (bytes_received < 0) {
    fprintf(stderr, "Error: Unable to read server response.\n");
    exit(1);
  }
  buffer[bytes_received] = '\0';
  printf("Server response: %s", buffer);

  if (strncmp(buffer, expected_response_code, 3) != 0) {
    fprintf(stderr, "Error: Response code %s not received from server.\n", expected_response_code);
    exit(1);
  }

  return bytes_received;
}

void retrieve_emails(int sockfd) {
  int bytes_received;
  char buffer[BUFFER_SIZE];
  int email_count = 0;
  int total_email_size = 0;

  // Retrieve number of emails
  send_command(sockfd, "STAT\r\n", "+OK");
  sscanf(buffer, "+OK %d %d", &email_count, &total_email_size);
  printf("%d emails, %d total size.\n", email_count, total_email_size);

  // Retrieve email UIDLs
  send_command(sockfd, "UIDL\r\n", "+OK");
  while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
    buffer[bytes_received] = '\0';
    printf("Email UIDL: %s", buffer);
  }

  // Retrieve first email
  if (email_count > 0) {
    send_command(sockfd, "RETR 1\r\n", "+OK");
    while ((bytes_received = recv(sockfd, buffer, BUFFER_SIZE - 1, 0)) > 0) {
      buffer[bytes_received] = '\0';
      printf("%s", buffer);
    }
  }
}

int main(int argc, char* argv[]) {
  int sockfd;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <POP3 server name>\n", argv[0]);
    exit(1);
  }

  sockfd = connect_to_pop3(argv[1]);

  send_command(sockfd, "USER myusername\r\n", "+OK");
  send_command(sockfd, "PASS mypassword\r\n", "+OK");

  retrieve_emails(sockfd);

  send_command(sockfd, "QUIT\r\n", "+OK");

  close(sockfd);

  return 0;
}