//FormAI DATASET v1.0 Category: Network Quality of Service (QoS) monitor ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <time.h>

#define MAX_PACKET_SIZE 2048
#define DEFAULT_PORT 8888
#define DEFAULT_TIMEOUT 3
#define DEFAULT_RETRIES 3

typedef struct {
  char *ip;
  int port;
  int timeout;
  int retries;
  bool success;
  double response_time;
  int packet_loss;
} QoSResult;

QoSResult runQoSTest(char *ip, int port, int timeout, int retries) {
  struct sockaddr_in sock_addr;
  int sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
  struct timeval tv;
  tv.tv_sec = timeout;
  tv.tv_usec = 0;
  setsockopt(sock_fd, SOL_SOCKET, SO_RCVTIMEO, (const char*)&tv, sizeof tv);
  
  memset(&sock_addr, 0, sizeof(sock_addr));
  sock_addr.sin_family = AF_INET;
  sock_addr.sin_port = htons(port);
  inet_pton(AF_INET, ip, &sock_addr.sin_addr);
  
  QoSResult result;
  result.ip = ip;
  result.port = port;
  result.timeout = timeout;
  result.retries = retries;
  result.success = false;
  result.response_time = 0.0;
  result.packet_loss = 100;
  
  int i;
  for(i = 0; i < retries; i++) {
    int connect_result = connect(sock_fd, (struct sockaddr*)&sock_addr, sizeof(sock_addr));
    struct timespec start_time, end_time;
    clock_gettime(CLOCK_MONOTONIC, &start_time);
    
    if(connect_result >= 0) {
      result.success = true;
      clock_gettime(CLOCK_MONOTONIC, &end_time);
      result.response_time = (end_time.tv_nsec - start_time.tv_nsec) / 1000000.0 + (end_time.tv_sec - start_time.tv_sec) * 1000.0;
      break;
    }
  }
  
  if(result.success) {
    result.packet_loss = 0;
  }
  
  close(sock_fd);
  
  return result;
}

int main(int argc, char *argv[]) {
  char *ip = "127.0.0.1";
  int port = DEFAULT_PORT;
  int timeout = DEFAULT_TIMEOUT;
  int retries = DEFAULT_RETRIES;
  int i;
  
  if(argc > 1) {
    ip = argv[1];
  }
  
  if(argc > 2) {
    port = atoi(argv[2]);
  }
  
  if(argc > 3) {
    timeout = atoi(argv[3]);
  }
  
  if(argc > 4) {
    retries = atoi(argv[4]);
  }
  
  QoSResult result = runQoSTest(ip, port, timeout, retries);
  
  printf("QoS Test Result:\n");
  printf("IP Address: %s\n", result.ip);
  printf("Port: %d\n", result.port);
  printf("Timeout: %d seconds\n", result.timeout);
  printf("Retries: %d\n", result.retries);
  
  if(result.success) {
    printf("Success: true\n");
    printf("Response Time: %.2fms\n", result.response_time);
    printf("Packet Loss: %d%%\n", result.packet_loss);
  } else {
    printf("Success: false\n");
    printf("Response Time: N/A\n");
    printf("Packet Loss: 100%%\n");
  }
  
  return 0;
}