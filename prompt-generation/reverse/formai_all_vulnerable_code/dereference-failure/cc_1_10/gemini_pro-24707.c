//GEMINI-pro DATASET v1.0 Category: Client Server Application ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <sys/socket.h>

// Server side
int main(int argc, char* argv[]) {
  int sfd, cfd, portno, n;
  struct sockaddr_in serv_addr, cli_addr;
  socklen_t clilen;
  char buffer[256];
  
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <port>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[1]);
  
  sfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sfd < 0) 
    error("Error opening socket");

  memset((char*)&serv_addr, 0, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0) 
    error("Error on binding");

  listen(sfd, 5);
  
  clilen = sizeof(cli_addr);
  cfd = accept(sfd, (struct sockaddr *)&cli_addr, &clilen);
  if (cfd < 0) 
    error("Error on accepting");

  // Client side
  memset(buffer, 0, sizeof(buffer));
  n = read(cfd, buffer, sizeof(buffer));
  if (n < 0) 
    error("Error on reading");

  printf("Received message: %s\n", buffer);
  
  n = write(cfd, "Hello World!", strlen("Hello World!"));
  if (n < 0) 
    error("Error on writing");

  close(cfd);
  close(sfd);
  
  return 0;
}