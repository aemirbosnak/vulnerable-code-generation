//Falcon2-11B DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: rigorous
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>

#define PORT 8080

int main(int argc, char *argv[]) {
  int sockfd, valread;
  struct sockaddr_in serv_addr;
  struct hostent *server;

  if (argc!= 2) {
    fprintf(stderr, "usage: %s hostname\n", argv[0]);
    exit(1);
  }

  server = gethostbyname(argv[1]);

  if (server == NULL) {
    fprintf(stderr, "no such host\n");
    exit(2);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd < 0) {
    perror("socket failed");
    exit(3);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr, server->h_length);
  serv_addr.sin_port = htons(PORT);

  if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("connect failed");
    exit(4);
  }

  printf("Connected to %s\n", argv[1]);

  while (1) {
    valread = read(sockfd, &valread, sizeof(valread));
    printf("%d\n", valread);
  }

  close(sockfd);
  return 0;
}