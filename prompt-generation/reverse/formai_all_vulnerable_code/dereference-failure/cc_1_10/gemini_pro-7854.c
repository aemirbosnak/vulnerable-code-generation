//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <unistd.h>

// Global variables.
int sockfd;  // File descriptor for the socket.
char *host;  // Hostname or IP address of the FTP server.
char *user;  // Username for the FTP login.
char *pass;  // Password for the FTP login.

// Function to establish a connection to the FTP server.
int ftp_connect() {
  // Create a socket.
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket()");
    return -1;
  }

  // Get the host IP address.
  struct hostent *he = gethostbyname(host);
  if (he == NULL) {
    perror("gethostbyname()");
    return -1;
  }

  // Set up the sockaddr_in structure.
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(21);
  memcpy(&servaddr.sin_addr, he->h_addr, he->h_length);

  // Connect to the FTP server.
  if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect()");
    return -1;
  }

  // Receive the welcome message from the server.
  char buf[1024];
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv()");
    return -1;
  }

  // Print the welcome message.
  printf("%s", buf);

  return 0;
}

// Function to authenticate with the FTP server.
int ftp_login() {
  // Send the username to the server.
  char buf[1024];
  snprintf(buf, sizeof(buf), "USER %s\r\n", user);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send()");
    return -1;
  }

  // Receive the server's response.
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv()");
    return -1;
  }

  // Print the server's response.
  printf("%s", buf);

  // Send the password to the server.
  snprintf(buf, sizeof(buf), "PASS %s\r\n", pass);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send()");
    return -1;
  }

  // Receive the server's response.
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv()");
    return -1;
  }

  // Print the server's response.
  printf("%s", buf);

  return 0;
}

// Function to download a file from the FTP server.
int ftp_get(char *file) {
  // Send the RETR command to the server.
  char buf[1024];
  snprintf(buf, sizeof(buf), "RETR %s\r\n", file);
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send()");
    return -1;
  }

  // Receive the server's response.
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv()");
    return -1;
  }

  // Print the server's response.
  printf("%s", buf);

  // Open a file for writing.
  FILE *fp = fopen(file, "wb");
  if (fp == NULL) {
    perror("fopen()");
    return -1;
  }

  // Read the file data from the server.
  while (1) {
    int n = recv(sockfd, buf, sizeof(buf), 0);
    if (n == -1) {
      perror("recv()");
      return -1;
    } else if (n == 0) {
      break;
    }
    fwrite(buf, n, 1, fp);
  }

  // Close the file.
  fclose(fp);

  return 0;
}

// Function to disconnect from the FTP server.
int ftp_quit() {
  // Send the QUIT command to the server.
  char buf[1024];
  snprintf(buf, sizeof(buf), "QUIT\r\n");
  if (send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("send()");
    return -1;
  }

  // Receive the server's response.
  if (recv(sockfd, buf, sizeof(buf), 0) == -1) {
    perror("recv()");
    return -1;
  }

  // Print the server's response.
  printf("%s", buf);

  // Close the socket.
  close(sockfd);

  return 0;
}

// Main function.
int main(int argc, char *argv[]) {
  // Check if the user provided enough arguments.
  if (argc != 5) {
    printf("Usage: %s host user pass file\n", argv[0]);
    return -1;
  }

  // Store the host, username, password, and filename.
  host = argv[1];
  user = argv[2];
  pass = argv[3];
  char *file = argv[4];

  // Connect to the FTP server.
  if (ftp_connect() != 0) {
    return -1;
  }

  // Authenticate with the FTP server.
  if (ftp_login() != 0) {
    return -1;
  }

  // Download the file from the FTP server.
  if (ftp_get(file) != 0) {
    return -1;
  }

  // Disconnect from the FTP server.
  if (ftp_quit() != 0) {
    return -1;
  }

  return 0;
}