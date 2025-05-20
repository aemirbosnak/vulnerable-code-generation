//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: Ada Lovelace
/* Oh, hello there! Welcome to my Ada Lovelace inspired HTTP client program! */

/* First, let's include our necessary headers */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <errno.h>
#include <netdb.h>
#include <unistd.h>

/* Now, we'll define our main function */

int main(int argc, char* argv[]) {

  /* Let's define some variables to use in our program */

  int port = 80; /* Default HTTP port */
  struct addrinfo hints, *res;
  int sockfd;

  /* We'll want to check if the user inputted any command line arguments */

  if(argc != 2) {
    printf("Please enter a valid website URL.\n");
    exit(1);
  }

  /* Let's create a socket for our program to use */

  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_UNSPEC;
  hints.ai_socktype = SOCK_STREAM;

  /* We'll use the getaddrinfo function to get the IP address for the website URL */

  if(getaddrinfo(argv[1], "80", &hints, &res) != 0) {
    perror("Error getting address information");
    exit(1);
  }

  /* Now, we'll create our socket and check for errors */

  sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
  if(sockfd == -1) {
    perror("Error creating socket");
    exit(1);
  }

  /* We'll use the connect function to connect to the website */

  if(connect(sockfd, res->ai_addr, res->ai_addrlen) == -1) {
    perror("Error connecting to website");
    close(sockfd);
    exit(1);
  }

  /* Now, we'll send our HTTP request to the website */

  char* request = "GET / HTTP/1.1\r\nHost: %s\r\n\r\n";
  char buf[512];

  sprintf(buf, request, argv[1]);

  if(send(sockfd, buf, strlen(buf), 0) == -1) {
    perror("Error sending request to website");
    close(sockfd);
    exit(1);
  }

  /* Finally, we'll print out the response from the website */

  int bytes_received;

  while((bytes_received = recv(sockfd, buf, 512, 0)) > 0) {
    printf("%.*s", bytes_received, buf);
  }

  /* And we're done! Let's close our socket and exit the program. */

  close(sockfd);
  return 0;
}