//FormAI DATASET v1.0 Category: Port Scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <errno.h>

#define MAX_PORT 65535

int sockfd;

typedef struct port_data {
  int port;
  int is_open;
} port_data;

void scan_port(struct sockaddr_in address, int port) {
  struct timeval tv;
  tv.tv_sec = 0;
  tv.tv_usec = 10000;
  port_data* data = (port_data*)malloc(sizeof(port_data));
  data->port = port;
  data->is_open = 0;
  
  int sock = socket(AF_INET, SOCK_STREAM, 0);
  fcntl(sock, F_SETFL, O_NONBLOCK);
  
  if (connect(sock, (struct sockaddr*)&address, sizeof(address)) == -1) {
    if (errno != EINPROGRESS) {
      close(sock);
      return;
    }
  }
  
  fd_set set;
  FD_ZERO(&set);
  FD_SET(sock, &set);
  
  if (select(sock+1, NULL, &set, NULL, &tv) > 0) {
    int val;
    socklen_t lon = sizeof(val);
    getsockopt(sock, SOL_SOCKET, SO_ERROR, (void*)(&val), &lon);
    if (val) {
      close(sock);
      return;
    }
    data->is_open = 1;
  }
  close(sock);
  
  char* status;
  if (data->is_open) {
    status = "open";
  } else {
    status = "closed";
  }
  
  printf("Port %d is %s\n", data->port, status);
  free(data);
}

void scan_ports(struct sockaddr_in address, int lower, int upper) {
  #pragma omp parallel for
  for (int i = lower; i <= upper; i++) {
    scan_port(address, i);
  }
}

int main(int argc, char** argv) {
  if (argc < 2) {
    printf("Usage: %s [ip address]\n", argv[0]);
    return 1;
  }
  
  char* ip = argv[1];
  struct hostent* host = gethostbyname(ip);
  if (host == NULL) {
    printf("Error resolving host %s\n", ip);
    return 1;
  }
  
  sockfd = socket(AF_INET, SOCK_STREAM, 0);
  if (sockfd == -1) {
    printf("Error creating socket\n");
    return 1;
  }
  
  struct sockaddr_in address;
  memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(0);
  address.sin_addr.s_addr = inet_addr(ip);
  
  if (bind(sockfd, (struct sockaddr*)&address, sizeof(address)) == -1) {
    printf("Error binding socket\n");
    return 1;
  }
  
  int lower = 1;
  int upper = MAX_PORT / 4;
  scan_ports(address, lower, upper);
  
  lower = upper + 1;
  upper = lower + (MAX_PORT / 4) - 1;
  scan_ports(address, lower, upper);
  
  lower = upper + 1;
  upper = lower + (MAX_PORT / 4) - 1;
  scan_ports(address, lower, upper);
  
  lower = upper + 1;
  upper = MAX_PORT;
  scan_ports(address, lower, upper);
  
  return 0;
}