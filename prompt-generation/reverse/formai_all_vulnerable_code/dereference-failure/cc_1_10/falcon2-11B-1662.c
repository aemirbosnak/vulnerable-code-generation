//Falcon2-11B DATASET v1.0 Category: Interprocess communication ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[1024];

  if (argc!= 2) {
    fprintf(stderr, "Usage %s port\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[1]);

  server = gethostbyname("localhost");
  if (server == NULL) {
    fprintf(stderr, "ERROR, no such host\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(portno);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  printf("Connected to server\n");

  while (1) {
    n = read(sockfd, buffer, sizeof(buffer));
    if (n <= 0)
      break;
    printf("Received message: %s\n", buffer);
    write(sockfd, buffer, n);
  }

  close(sockfd);
  return 0;
}