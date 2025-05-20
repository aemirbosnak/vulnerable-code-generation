//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAX_HOST_NAME 256
#define DEFAULT_PORT 21

// Function to establish a connection to the FTP server
int connect_to_server(char *hostname, int port) {
  // Get the IP address of the hostname
  struct hostent *host = gethostbyname(hostname);
  if (host == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  // Create a socket
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  if (sock < 0) {
    perror("socket");
    exit(1);
  }

  // Connect to the server
  struct sockaddr_in server_addr;
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(port);
  server_addr.sin_addr = *(struct in_addr *) host->h_addr;

  if (connect(sock, (struct sockaddr *) &server_addr, sizeof(server_addr)) < 0) {
    perror("connect");
    exit(1);
  }

  return sock;
}

// Function to send a command to the FTP server
void send_command(int sock, char *command) {
  // Send the command to the server
  if (send(sock, command, strlen(command), 0) < 0) {
    perror("send");
    exit(1);
  }

  // Receive the response from the server
  char response[512];
  if (recv(sock, response, sizeof(response), 0) < 0) {
    perror("recv");
    exit(1);
  }

  // Print the response from the server
  printf("%s", response);
}

// Function to retrieve a file from the FTP server
void retrieve_file(int sock, char *filename) {
  // Send the RETR command to the server
  send_command(sock, "RETR ");
  send_command(sock, filename);

  // Open a file to save the retrieved data
  FILE *fp = fopen(filename, "w");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  // Receive the data from the server and write it to the file
  char buffer[512];
  while (recv(sock, buffer, sizeof(buffer), 0) > 0) {
    fwrite(buffer, sizeof(buffer), 1, fp);
  }

  // Close the file
  fclose(fp);
}

// Main function
int main(int argc, char *argv[]) {
  // Check if the user has provided enough arguments
  if (argc < 3) {
    printf("Usage: %s <hostname> <port> <filename>\n", argv[0]);
    exit(1);
  }

  // Get the hostname, port, and filename from the command line arguments
  char *hostname = argv[1];
  int port = atoi(argv[2]);
  char *filename = argv[3];

  // Connect to the FTP server
  int sock = connect_to_server(hostname, port);

  // Retrieve the file from the FTP server
  retrieve_file(sock, filename);

  // Close the connection to the FTP server
  close(sock);

  return 0;
}