//FormAI DATASET v1.0 Category: Port Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
  int sockfd, port, start_port, end_port;
  long i;
  struct sockaddr_in target;
  fd_set read_fds;
  
  if(argc != 4) {
    printf("Usage: %s <start port> <end port> <IP to scan>\n", argv[0]);
    return 0;
  }
  
  memset(&target, 0, sizeof(target));
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = inet_addr(argv[3]);
  
  if(target.sin_addr.s_addr == INADDR_NONE) {
    printf("Invalid IP address: %s\n", argv[3]);
    return 0;
  }

  start_port = atoi(argv[1]);
  end_port = atoi(argv[2]);

  if(start_port > end_port || start_port < 1 || end_port > 65535) {
    printf("Invalid port range: %d-%d\n", start_port, end_port);
    return 0;
  }
  
  printf("Scanning ports %d-%d on %s...\n", start_port, end_port, argv[3]);

  for(port = start_port; port <= end_port; port++) {
    sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if(sockfd == -1) {
      printf("Cannot create socket\n");
      return 0;
    }

    target.sin_port = htons(port);

    fcntl(sockfd, F_SETFL, O_NONBLOCK);

    connect(sockfd, (struct sockaddr *)&target, sizeof(target));

    FD_ZERO(&read_fds);
    FD_SET(sockfd, &read_fds);

    struct timeval timeout;
    timeout.tv_sec = 1;
    timeout.tv_usec = 0;

    if(select(sockfd+1, NULL, &read_fds, NULL, &timeout) == 1) {
      int err;
      socklen_t len = sizeof(err);
      getsockopt(sockfd, SOL_SOCKET, SO_ERROR, &err, &len);
      if(err == 0)
        printf("Port %d is open\n", port);
      else
        printf("Port %d is closed (error: %s)\n", port, strerror(err));
    }

    close(sockfd);
  }
  return 0;
}