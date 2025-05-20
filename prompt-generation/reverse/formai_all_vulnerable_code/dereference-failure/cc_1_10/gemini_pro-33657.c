//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/socket.h>

// A curious function to print a banner
void print_banner() {
  printf("\n");
  printf("   _____                                _          \n");
  printf("  / ____|                              | |         \n");
  printf(" | (___   _ __    ___   _ __ ___   _ __ | |_  __ _  \n");
  printf("  \\___ \\ | '_ \\  / _ \\ | '__/ _ \\ | '_ \\| __|/ _` | \n");
  printf("  ____) || |_) || (_) || | | (_) || | | | |_| (_| | \n");
  printf(" |_____/ | .__/  \\___/ |_|  \\___/ |_| |_|\__|\\__,_| \n");
  printf("         | |                                       \n");
  printf("         |_|                                       \n");
  printf("\n");
}

// A curious function to scan a port
int scan_port(char* hostname, int port) {
  int sockfd, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    return -1;
  }

  // Get the server's IP address
  server = gethostbyname(hostname);
  if (server == NULL) {
    fprintf(stderr,"ERROR, no such host\n");
    return -1;
  }

  // Set up the server's address
  memset(&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  memcpy(&serv_addr.sin_addr.s_addr, server->h_addr, server->h_length);
  serv_addr.sin_port = htons(port);

  // Connect to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    return -1;
  }

  // Send a message to the server
  char *message = "Hello world!\n";
  n = write(sockfd, message, strlen(message));
  if (n < 0) {
    perror("ERROR writing to socket");
    return -1;
  }

  // Read a message from the server
  char buffer[256];
  n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("ERROR reading from socket");
    return -1;
  }

  // Print the message from the server
  printf("The server says: %s", buffer);

  // Close the socket
  close(sockfd);

  return 0;
}

// The main function
int main(int argc, char *argv[]) {
  // Print the banner
  print_banner();

  // Check if the user has provided enough arguments
  if (argc < 3) {
    fprintf(stderr,"Usage: %s <hostname> <port>\n", argv[0]);
    return -1;
  }

  // Get the hostname and port number from the command line
  char *hostname = argv[1];
  int port = atoi(argv[2]);

  // Scan the port
  int result = scan_port(hostname, port);

  // Print the result
  if (result == 0) {
    printf("The port is open.\n");
  } else {
    printf("The port is closed.\n");
  }

  return 0;
}