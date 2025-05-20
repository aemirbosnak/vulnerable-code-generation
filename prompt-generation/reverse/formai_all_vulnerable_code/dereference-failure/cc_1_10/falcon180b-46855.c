//Falcon-180B DATASET v1.0 Category: Networking ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char *argv[]) {
  int sockfd;
  struct sockaddr_in serv_addr;
  char buffer[1024];
  int n;

  time_t ticks;
  struct tm *tm_struct;

  if (argc!= 3) {
    printf("usage: %s <server_ip> <port_number>\n", argv[0]);
    exit(1);
  }

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1) {
    printf("socket failed\n");
    exit(1);
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
  serv_addr.sin_port = htons(atoi(argv[2]));

  if (connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) == -1) {
    printf("connect failed\n");
    exit(1);
  }

  ticks = time(NULL);
  tm_struct = localtime(&ticks);

  strftime(buffer, 1024, "Current date and time: %d-%m-%Y %H:%M:%S\n", tm_struct);

  write(sockfd, buffer, strlen(buffer));

  while (1) {
    bzero(buffer, 1024);
    n = read(sockfd, buffer, 1024);
    if (n == 0) {
      printf("Connection closed by server\n");
      exit(1);
    }
    buffer[n] = '\0';
    printf("%s", buffer);
  }

  close(sockfd);

  return 0;
}