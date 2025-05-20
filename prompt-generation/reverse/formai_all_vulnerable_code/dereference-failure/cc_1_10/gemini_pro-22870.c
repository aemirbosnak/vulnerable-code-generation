//GEMINI-pro DATASET v1.0 Category: Port Scanner ; Style: irregular
//Wubba Lubba Dub Dub, an Irregular C Port Scanner

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>

//Interdimensional constants
#define PORT_START 1
#define PORT_END 65535
#define MAX_PORTS 100
#define BUFSIZE 1024

//Globglogabgalab dance party
int main(int argc, char **argv) {
  //Check our parameters, one please
  if (argc < 2) {
    printf("Usage: %s <target>\n", argv[0]);
    return -1;
  }

  //Let's get schwifty with the target
  char *target = argv[1];

  //Establish the quantum connection
  struct addrinfo *res;
  if (getaddrinfo(target, NULL, NULL, &res) != 0) {
    printf("Error: getaddrinfo failed.\n");
    return -1;
  }

  //Prepare for the port scan-dventure
  int socks[MAX_PORTS];
  int num_socks = 0;

  //Time to get schwifty with the ports
  for (int port = PORT_START; port <= PORT_END; port++) {
    //Create a unified sock dimension
    int sockfd = socket(res->ai_family, res->ai_socktype, res->ai_protocol);
    if (sockfd < 0) {
      printf("Error: socket() failed (%d).\n", errno);
      continue;
    }

    //Set up the socket address
    struct sockaddr *addr = res->ai_addr;
    socklen_t addrlen = res->ai_addrlen;
    addr->sa_data[0] = port >> 8;
    addr->sa_data[1] = port & 0xff;

    //Attempt the connection
    if (connect(sockfd, addr, addrlen) < 0) {
      //Failure is not an option, but it's a reality
      close(sockfd);
      continue;
    }

    //Success, we found an open port!
    socks[num_socks++] = sockfd;
    printf("Found open port: %d\n", port);
  }

  //Close all the open socks
  for (int i = 0; i < num_socks; i++) {
    close(socks[i]);
  }

  //Mission accomplished, let's go home
  printf("Scan complete.\n");
  return 0;
}