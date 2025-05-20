//FormAI DATASET v1.0 Category: Port Scanner ; Style: interoperable
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<errno.h>
#include<netinet/in.h>
#include<string.h>
#include<arpa/inet.h>
#include<ctype.h>
#include<unistd.h>
#include<netdb.h>

void scanner(const char *host, int start_port, int end_port) {
  int sockfd, connfd;
  struct sockaddr_in target_addr;

  memset(&target_addr, 0, sizeof(target_addr));
  target_addr.sin_family = AF_INET;
  target_addr.sin_addr.s_addr = inet_addr(host);

  for(int port = start_port; port <= end_port; port++) {
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    target_addr.sin_port = htons(port);

    if(connect(sockfd, (struct sockaddr *)&target_addr, sizeof(target_addr)) == 0) {
      printf("Port %d is open.\n", port);
    }

    close(sockfd);
  }
}

int main(int argc, char* argv[]) {
  if(argc < 4) {
    printf("Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  if(start_port < 1 || end_port > 65535 || start_port > end_port) {
    printf("Invalid port range.\n");
    exit(1);
  }

  scanner(hostname, start_port, end_port);
  
  return 0;
}