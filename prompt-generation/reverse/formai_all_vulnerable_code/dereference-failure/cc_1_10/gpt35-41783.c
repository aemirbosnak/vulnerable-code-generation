//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <string.h>

#define MAX_BUF_LEN 1024
#define TIMEOUT_SEC 5
#define TIMEOUT_USEC 0

int main(int argc, char *argv[]) {

  const char *hostname = "example.com"; // sample hostname
  const char *message = "GET / HTTP/1.1\r\n\r\n"; // HTTP request 
  struct hostent *host;
  struct sockaddr_in server_address;
  int sockfd, numbytes, server_port;
  char read_buffer[MAX_BUF_LEN];
  fd_set read_set;
  struct timeval timeout;

  // check for valid arguments
  if(argc != 2) {
    fprintf(stderr, "Usage: %s <portnumber>\n", argv[0]);
    exit(1);
  }

  server_port = atoi(argv[1]);

  // create socket
  if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
    perror("socket");
    exit(1);
  }

  // get host information
  if ((host = gethostbyname(hostname)) == NULL) {
    perror("gethostbyname");
    exit(1);
  }

  // set server address structure
  server_address.sin_family = AF_INET;
  server_address.sin_port = htons(server_port);
  server_address.sin_addr = *((struct in_addr *)host->h_addr);
  memset(&(server_address.sin_zero), '\0', 8);

  // connect to server
  if (connect(sockfd, (struct sockaddr *)&server_address, sizeof(struct sockaddr)) == -1) {
    perror("connect");
    exit(1);
  }

  // send HTTP request
  if (send(sockfd, message, strlen(message), 0) == -1) {
    perror("send");
    close(sockfd);
    exit(1);
  }

  FD_ZERO(&read_set);
  FD_SET(sockfd, &read_set);

  timeout.tv_sec = TIMEOUT_SEC;
  timeout.tv_usec = TIMEOUT_USEC;

  // wait for response from server
  if (select(sockfd+1, &read_set, NULL, NULL, &timeout) == -1) {
    perror("select");
    close(sockfd);
    exit(1);
  }
  else if (FD_ISSET(sockfd, &read_set)) {
    if ((numbytes = recv(sockfd, read_buffer, MAX_BUF_LEN-1, 0)) == -1) {
      perror("recv");
      close(sockfd);
      exit(1);
    }
    else {
      read_buffer[numbytes] = '\0';

      // check for expected response from server
      if (strncmp(read_buffer, "HTTP/1.1 200 OK", 15) == 0) {
        printf("Server is online and responding to requests.\n");
      }
      else {
        printf("Server returned unexpected response: %s\n", read_buffer);
      }
    }
  }
  else {
    printf("The server did not respond in the specified time.\n");
  }

  close(sockfd);

  return 0;
}