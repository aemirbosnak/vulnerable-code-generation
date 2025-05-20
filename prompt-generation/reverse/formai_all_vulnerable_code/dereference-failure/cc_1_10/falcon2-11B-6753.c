//Falcon2-11B DATASET v1.0 Category: Network Ping Test ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char **argv) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buf[256];

  // Parse command line arguments
  if (argc!= 3) {
    fprintf(stderr, "Usage: %s <IP Address> <Port Number>\n", argv[0]);
    exit(1);
  }

  // Convert IP address and port number to integers
  portno = atoi(argv[2]);

  // Create a socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Set up address struct for connecting to server
  server = gethostbyname(argv[1]);
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  // Copy address struct to serv_addr
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);

  // Set up port number
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(portno);

  // Connect to server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Send ping request
  printf("Pinging %s through port %d...\n", argv[1], portno);
  sprintf(buf, "PING %s (%s) %d bytes of data.\r\n", argv[1], argv[1], 28);
  write(sockfd, buf, strlen(buf));

  // Receive response
  n = read(sockfd, buf, 28);
  if (n < 0) {
    perror("ERROR reading response");
    exit(1);
  }

  // Close socket
  printf("Response from %s: %s\n", argv[1], buf);
  close(sockfd);

  return 0;
}