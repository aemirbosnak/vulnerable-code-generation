//GEMINI-pro DATASET v1.0 Category: Building a POP3 Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

#define BUFFSIZE 1024

// Function to get the IP address of a hostname
char *get_ip_address(char *hostname) {
  struct hostent *host_info;
  if ((host_info = gethostbyname(hostname)) == NULL) {
    perror("gethostbyname");
    exit(EXIT_FAILURE);
  }
  return inet_ntoa(*((struct in_addr *)host_info->h_addr_list[0]));
}

// Function to send a command to the POP3 server
int send_command(int sockfd, char *command) {
  int bytes_sent;
  if ((bytes_sent = send(sockfd, command, strlen(command), 0)) < 0) {
    perror("send");
    return -1;
  }
  return bytes_sent;
}

// Function to receive a response from the POP3 server
int receive_response(int sockfd, char *buffer) {
  int bytes_received;
  if ((bytes_received = recv(sockfd, buffer, BUFFSIZE - 1, 0)) < 0) {
    perror("recv");
    return -1;
  }
  buffer[bytes_received] = '\0';
  return bytes_received;
}

// Function to fetch a message from the POP3 server
int fetch_message(int sockfd, int message_number) {
  char command[BUFFSIZE];
  char buffer[BUFFSIZE];
  int bytes_received;

  // Send the RETR command
  snprintf(command, BUFFSIZE, "RETR %d\r\n", message_number);
  if (send_command(sockfd, command) < 0) {
    return -1;
  }

  // Receive the response
  if ((bytes_received = receive_response(sockfd, buffer)) < 0) {
    return -1;
  }

  // Output the message
  printf("%s", buffer);

  return 0;
}

int main(int argc, char *argv[]) {
  int sockfd;
  int bytes_received;
  char buffer[BUFFSIZE];
  char *hostname;
  char *username;
  char *password;
  int port;

  // Check for the required arguments
  if (argc != 5) {
    fprintf(stderr, "Usage: %s <hostname> <username> <password> <port>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  // Get the hostname, username, password, and port
  hostname = argv[1];
  username = argv[2];
  password = argv[3];
  port = atoi(argv[4]);

  // Get the IP address of the hostname
  char *ip_address = get_ip_address(hostname);

  // Create the socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  // Connect to the POP3 server
  struct sockaddr_in server_address;
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(port);
  server_address.sin_addr.s_addr = inet_addr(ip_address);
  if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(server_address)) < 0) {
    perror("connect");
    exit(EXIT_FAILURE);
  }

  // Receive the welcome message
  if ((bytes_received = receive_response(sockfd, buffer)) < 0) {
    return -1;
  }

  // Authenticate with the POP3 server
  // Send the USER command
  snprintf(buffer, BUFFSIZE, "USER %s\r\n", username);
  if (send_command(sockfd, buffer) < 0) {
    return -1;
  }

  // Receive the response
  if ((bytes_received = receive_response(sockfd, buffer)) < 0) {
    return -1;
  }

  // Send the PASS command
  snprintf(buffer, BUFFSIZE, "PASS %s\r\n", password);
  if (send_command(sockfd, buffer) < 0) {
    return -1;
  }

  // Receive the response
  if ((bytes_received = receive_response(sockfd, buffer)) < 0) {
    return -1;
  }

  // Check if the authentication was successful
  if (strncmp(buffer, "+OK", 3) != 0) {
    fprintf(stderr, "Authentication failed: %s", buffer);
    exit(EXIT_FAILURE);
  }

  // Get the number of messages in the mailbox
  snprintf(buffer, BUFFSIZE, "STAT\r\n");
  if (send_command(sockfd, buffer) < 0) {
    return -1;
  }

  // Receive the response
  if ((bytes_received = receive_response(sockfd, buffer)) < 0) {
    return -1;
  }

  // Extract the number of messages
  int num_messages;
  sscanf(buffer, "+OK %d %d", &num_messages, &bytes_received);

  // Fetch the first message
  if (fetch_message(sockfd, 1) < 0) {
    return -1;
  }

  // Quit the POP3 server
  snprintf(buffer, BUFFSIZE, "QUIT\r\n");
  if (send_command(sockfd, buffer) < 0) {
    return -1;
  }

  // Close the socket
  close(sockfd);

  return 0;
}