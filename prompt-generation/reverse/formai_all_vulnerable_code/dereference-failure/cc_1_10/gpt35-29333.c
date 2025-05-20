//FormAI DATASET v1.0 Category: Building a HTTP Client ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main() {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Knights send messages via HTTP with messages
  char message[1024] = "I request your presence on the battlefield, Sir Knight.";

  // Our loyal squire will send the message for us
  char buffer[1024];

  // Server address and port number
  char server_address[] = "www.example.com";
  portno = 80;

  // Get the server address
  server = gethostbyname(server_address);
  if (server == NULL) {
    fprintf(stderr,"Error: No such host exists.\n");
    exit(EXIT_FAILURE);
  }

  // Create a socket
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr,"Error: Could not create socket.\n");
    exit(EXIT_FAILURE);
  }

  // Set server address and port number
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  // Connect to the server
  if (connect(sockfd,(struct sockaddr *)&serv_addr,sizeof(serv_addr)) < 0) {
    fprintf(stderr,"Error: Could not connect to server.\n");
    exit(EXIT_FAILURE);
  }

  // Send message to server
  n = write(sockfd,message,strlen(message));
  if (n < 0) {
    fprintf(stderr,"Error: Could not send message to server.\n");
    exit(EXIT_FAILURE);
  }

  // Receive message from server
  bzero(buffer,1024);
  n = read(sockfd,buffer,1023);
  if (n < 0) {
    fprintf(stderr,"Error: Could not receive message from server.\n");
    exit(EXIT_FAILURE);
  }

  // Display response from server
  printf("%s\n",buffer);

  // Close the socket
  close(sockfd);

  return 0;
}