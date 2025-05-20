//GEMINI-pro DATASET v1.0 Category: Building a FTP Client ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAXHOSTNAMELEN 256
#define MAXMSGSIZE 1024

int main(int argc, char* argv[]) {
  if (argc != 3) {
    fprintf(stderr, "Usage: %s <hostname> <port>\n", argv[0]);
    exit(1);
  }

  // Get the hostname and port number from the command line arguments.
  char hostname[MAXHOSTNAMELEN];
  strncpy(hostname, argv[1], MAXHOSTNAMELEN);
  int port = atoi(argv[2]);

  // Create a socket for communication with the FTP server.
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    perror("socket");
    exit(1);
  }

  // Get the IP address of the FTP server.
  struct hostent* hostinfo = gethostbyname(hostname);
  if (hostinfo == NULL) {
    fprintf(stderr, "Unknown host: %s\n", hostname);
    exit(1);
  }

  // Connect to the FTP server.
  struct sockaddr_in servaddr;
  memset(&servaddr, 0, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(port);
  memcpy(&servaddr.sin_addr.s_addr, hostinfo->h_addr, hostinfo->h_length);
  if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  // Send the FTP command to the server.
  char command[MAXMSGSIZE];
  snprintf(command, MAXMSGSIZE, "USER anonymous\r\n");
  if (send(sockfd, command, strlen(command), 0) == -1) {
    perror("send");
    exit(1);
  }

  // Receive the response from the server.
  char response[MAXMSGSIZE];
  if (recv(sockfd, response, MAXMSGSIZE, 0) == -1) {
    perror("recv");
    exit(1);
  }

  // Print the response from the server to the console.
  printf("%s", response);

  // Close the socket.
  close(sockfd);

  return 0;
}