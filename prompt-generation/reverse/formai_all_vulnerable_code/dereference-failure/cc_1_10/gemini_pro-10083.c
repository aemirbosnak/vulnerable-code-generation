//GEMINI-pro DATASET v1.0 Category: Building a HTTP Client ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char **argv) {
  // Prepare our ship for launch
  int sockfd, portno;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  // Set our destination and prepare the voyage
  portno = atoi(argv[2]);
  server = gethostbyname(argv[1]);

  // Raise the sails and set course
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Socket creation failed, matey!");
    exit(1);
  }

  // Plot our course and chart our path
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr = *((struct in_addr *)server->h_addr);
  serv_addr.sin_port = htons(portno);

  // Signal our intent to the server
  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) {
    perror("Connection failed, shiver me timbers!");
    exit(1);
  }

  // Time to plunder and pillage! (Request some treasure)
  char request[] = "GET /treasure.txt HTTP/1.1\r\nHost: www.treasureisland.com\r\n\r\n";
  write(sockfd, request, strlen(request));

  // Haul in the loot! (Receive the treasure)
  char buffer[1024];
  int n = read(sockfd, buffer, sizeof(buffer) - 1);
  if (n < 0) {
    perror("Treasure hunt failed, barnacles!");
    exit(1);
  }

  // Decipher the ancient map (Parse the response)
  printf("DAVY JONES' LOCKER: %s", buffer);

  // Close the voyage and return to port
  close(sockfd);

  return 0;
}