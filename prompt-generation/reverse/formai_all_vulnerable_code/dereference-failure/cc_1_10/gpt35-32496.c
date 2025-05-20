//FormAI DATASET v1.0 Category: Building a SMTP Client ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 25 // Port number for SMTP server

int main(int argc, char *argv[]) {

  if (argc != 2) { // Check if the user has provided the email address as an argument
    printf("Usage: %s <email_address>\n", argv[0]);
    exit(1);
  }

  int sock = socket(AF_INET, SOCK_STREAM, 0); // Create a TCP socket
  if (sock < 0) {
    perror("Failed to create socket");
    exit(1);
  }

  struct hostent *server = gethostbyname("smtp.gmail.com"); // Get the IP address of the Gmail SMTP server
  if (server == NULL) {
    perror("Failed to get server IP address");
    exit(1);
  }

  struct sockaddr_in server_addr;
  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(PORT);
  memcpy(&server_addr.sin_addr.s_addr, server->h_addr, server->h_length); // Set the server address

  if (connect(sock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) { // Connect to the SMTP server
    perror("Failed to connect to server");
    exit(1);
  }

  char recv_buf[1024];
  recv(sock, recv_buf, sizeof(recv_buf), 0); // Receive the banner message from the server (should be 220)

  char helo_msg[1024];
  sprintf(helo_msg, "HELO %s\r\n", argv[1]); // Send the HELO message with the email address as a parameter
  send(sock, helo_msg, strlen(helo_msg), 0); // Send the message
  recv(sock, recv_buf, sizeof(recv_buf), 0); // Receive the server's response (should be 250)

  char mail_from[1024] = "MAIL FROM:<sender@gmail.com>\r\n"; // Replace this with the sender's email address
  send(sock, mail_from, strlen(mail_from), 0); // Send the MAIL FROM message
  recv(sock, recv_buf, sizeof(recv_buf), 0); // Receive the server's response (should be 250)

  char rcpt_to[1024];
  printf("Recipient address: ");
  fgets(rcpt_to, sizeof(rcpt_to), stdin);
  char *newline = strchr(rcpt_to, '\n'); // Remove the newline character at the end of the input
  if (newline != NULL) {
    *newline = '\0';
  }
  char rcpt_msg[1024];
  sprintf(rcpt_msg, "RCPT TO:<%s>\r\n", rcpt_to); // Send the RCPT TO message with the recipient's email address as a parameter
  send(sock, rcpt_msg, strlen(rcpt_msg), 0); // Send the message
  recv(sock, recv_buf, sizeof(recv_buf), 0); // Receive the server's response (should be 250)

  char data_msg[1024] = "DATA\r\n"; // Send the DATA message to start the data section
  send(sock, data_msg, strlen(data_msg), 0); // Send the message
  recv(sock, recv_buf, sizeof(recv_buf), 0); // Receive the server's response (should be 354)

  char msg[1024];
  printf("Enter your message:\n");
  fgets(msg, sizeof(msg), stdin);
  char *dot = strrchr(msg, '.'); // Add a period at the beginning of any line that starts with a period
  while (dot != NULL) {
    dot--;
    memmove(dot+2, dot+1, strlen(dot)+1);
    *dot = '.';
    dot = strrchr(msg, '.');
  }
  char end_msg[1024] = ".\r\n"; // End the data section with a period on a line by itself
  char full_msg[2048];
  sprintf(full_msg, "%s%s", msg, end_msg);
  send(sock, full_msg, strlen(full_msg), 0); // Send the message
  recv(sock, recv_buf, sizeof(recv_buf), 0); // Receive the server's response (should be 250)

  char quit_msg[1024] = "QUIT\r\n"; // Send the QUIT message to close the connection
  send(sock, quit_msg, strlen(quit_msg), 0); // Send the message
  recv(sock, recv_buf, sizeof(recv_buf), 0); // Receive the server's response (should be 221)

  close(sock); // Close the socket

  printf("Message sent successfully!\n");

  return 0;
}