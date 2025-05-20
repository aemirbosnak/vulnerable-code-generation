//Falcon2-11B DATASET v1.0 Category: Simple HTTP Proxy ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <netinet/tcp.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char* argv[]) {
  int sockfd, newsockfd, portno;
  struct sockaddr_in serv_addr, cli_addr;
  int yes = 1;
  char buffer[1024];
  char url[1024];

  // Step 1: Create a TCP socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  // Step 2: Specify the port number
  portno = atoi(argv[1]);

  // Step 3: Connect to the server
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  // Step 4: Send the request
  bzero(url, sizeof(url));
  strcpy(url, argv[2]);
  write(sockfd, url, strlen(url));

  // Step 5: Receive the response
  if (read(sockfd, buffer, 1024) < 0) {
    perror("ERROR reading from socket");
    exit(1);
  }

  // Step 6: Display the response
  printf("Response: %s\n", buffer);

  // Step 7: Close the socket
  close(sockfd);

  return 0;
}