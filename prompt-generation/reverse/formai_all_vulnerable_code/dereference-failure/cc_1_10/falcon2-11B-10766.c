//Falcon2-11B DATASET v1.0 Category: Email Client ; Style: complete
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

void sendmail(char *message, char *recipient, char *sender) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buffer[100];
  int i;
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(25);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  portno = htons(serv_addr.sin_port);
  connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
  for (i = 0; message[i]!= '\0'; i++) {
    n = write(sockfd, message + i, 1);
    if (n == -1) {
      perror("write");
      exit(EXIT_FAILURE);
    }
  }
  n = write(sockfd, "\r\n", 2);
  if (n == -1) {
    perror("write");
    exit(EXIT_FAILURE);
  }
  close(sockfd);
}

void recvmail(char *recipient, char *sender) {
  int sockfd, portno, n;
  struct sockaddr_in serv_addr;
  char buffer[100];
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  bzero((char *) &serv_addr, sizeof(serv_addr));
  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = htons(25);
  serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  portno = htons(serv_addr.sin_port);
  connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr));
  while (1) {
    bzero(buffer, 100);
    n = read(sockfd, buffer, 100);
    if (n == 0) {
      perror("read");
      exit(EXIT_FAILURE);
    }
    if (buffer[0] == '.') {
      break;
    }
    printf("%s", buffer);
  }
  close(sockfd);
}

int main(int argc, char *argv[]) {
  char *recipient = argv[1];
  char *message = argv[2];
  sendmail(message, recipient, argv[3]);
  recvmail(recipient, argv[4]);
  return 0;
}