//GEMINI-pro DATASET v1.0 Category: TCP/IP Programming ; Style: scalable
#define _POSIX_C_SOURCE 200112L 
#include <stdio.h>
#include <stdlib.h>   // for exit()
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h> // for inet_addr()
#include <unistd.h>    // for close()

void error(const char *msg) {
  perror(msg);
  exit(1); // terminate the program
}

int main(void) {
  // creating a socket
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0)
    error("ERROR opening socket");
  
  // setting address parameters
  struct sockaddr_in serv_addr;
  memset(&serv_addr, 0, sizeof(serv_addr)); 
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(8080); // assign a port number
  serv_addr.sin_addr.s_addr = INADDR_ANY;

  // connect the socket to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
    error("ERROR connecting");

  // allocating memory for the message
  char *message = malloc(1024);

  while (1) {
    // get the message from the user
    printf("Enter a message: ");
    fgets(message, 1024, stdin);

    // send the message to the server
    if (send(sockfd, message, strlen(message), 0) < 0)
      error("ERROR writing to socket");

    // receive the response from the server
    char buffer[1024];
    if (recv(sockfd, buffer, 1024, 0) < 0)
      error("ERROR reading from socket");

    // print the message from the server
    printf("Received: %s\n", buffer);
    
    if (!strcmp(message, "exit"))
      break;
  }

  // close the socket
  close(sockfd);

  return 0;
}