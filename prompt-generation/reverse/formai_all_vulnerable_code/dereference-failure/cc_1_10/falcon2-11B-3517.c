//Falcon2-11B DATASET v1.0 Category: Client Server Application ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

int main(int argc, char* argv[]) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buffer[100];

  if (argc < 2) {
    fprintf(stderr, "Usage %s <port number>\n", argv[0]);
    exit(1);
  }

  portno = atoi(argv[1]);

  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd < 0) {
    fprintf(stderr, "Error opening socket\n");
    exit(1);
  }

  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = INADDR_ANY;
  serv_addr.sin_port = htons(portno);

  if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
    perror("bind");
    exit(1);
  }

  listen(sockfd, 5);

  while (1) {
    socklen_t clilen = sizeof(struct sockaddr_in);
    n = accept(sockfd, (struct sockaddr *) &serv_addr, &clilen);
    if (n < 0) {
      perror("accept");
      exit(1);
    }

    while (1) {
      bzero(buffer, sizeof(buffer));
      n = read(n, buffer, sizeof(buffer));
      if (n <= 0) {
        perror("read");
        close(n);
        break;
      }
      printf("%s", buffer);
      bzero(buffer, sizeof(buffer));
      n = write(n, buffer, sizeof(buffer));
      if (n <= 0) {
        perror("write");
        close(n);
        break;
      }
    }
    close(n);
  }
  return 0;
}