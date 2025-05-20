//Falcon2-11B DATASET v1.0 Category: Networking ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

int main(int argc, char* argv[]) {
  if (argc!= 2) {
    fprintf(stderr, "Usage: %s <hostname>\n", argv[0]);
    exit(EXIT_FAILURE);
  }
  
  struct hostent* host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "Error: no such host\n");
    exit(EXIT_FAILURE);
  }
  
  struct sockaddr_in server_addr;
  bzero(&server_addr, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  bcopy((char*)host->h_addr, (char*)&server_addr.sin_addr.s_addr, host->h_length);
  server_addr.sin_port = htons(80);
  
  int sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("Error creating socket");
    exit(EXIT_FAILURE);
  }
  
  if (connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
    perror("Error connecting");
    exit(EXIT_FAILURE);
  }
  
  char buffer[1024];
  int n = read(sockfd, buffer, sizeof(buffer));
  if (n < 0) {
    perror("Error reading from socket");
    exit(EXIT_FAILURE);
  }
  
  printf("%s\n", buffer);
  close(sockfd);
  
  return 0;
}