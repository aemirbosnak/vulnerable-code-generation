//Falcon2-11B DATASET v1.0 Category: Network Packet Monitoring ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define BUFF_SIZE 1024

int main(int argc, char *argv[]) {
  int sockfd, n;
  struct sockaddr_in servaddr;
  char buff[BUFF_SIZE];
  struct hostent *host;

  if (argc!= 2) {
    fprintf(stderr, "Usage: %s hostname\n", argv[0]);
    exit(1);
  }

  host = gethostbyname(argv[1]);
  if (host == NULL) {
    fprintf(stderr, "ERROR: no such host\n");
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    perror("ERROR opening socket");
    exit(1);
  }

  bzero((char *) &servaddr, sizeof(servaddr));
  servaddr.sin_family = AF_INET;
  bcopy((char *) host->h_addr, (char *) &servaddr.sin_addr.s_addr, host->h_length);
  servaddr.sin_port = htons(PORT);

  if (connect(sockfd, (struct sockaddr *) &servaddr, sizeof(servaddr)) < 0) {
    perror("ERROR connecting");
    exit(1);
  }

  while (1) {
    n = read(sockfd, buff, BUFF_SIZE);
    if (n <= 0) {
      perror("ERROR reading from socket");
      exit(1);
    }
    printf("%s", buff);
  }

  return 0;
}