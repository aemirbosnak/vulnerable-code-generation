//FormAI DATASET v1.0 Category: Port Scanner ; Style: ultraprecise
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <arpa/inet.h> 
#include <unistd.h>

#define MAX_THREAD 65535

struct sockaddr_in server; 

int main(int argc , char *argv[]) 
{ 
  int sock, start_port, end_port, i, j, result; 

  if (argc != 4) { 
    printf("usage: %s <ip_address> <start_port> <end_port>\n", argv[0]); 
    exit(1); 
  }

  start_port = atoi(argv[2]); 
  end_port = atoi(argv[3]); 

  if (start_port < 1 || end_port > 65535) { 
    printf("Invalid port range.\n"); 
    exit(1); 
  }

  if ((sock = socket(AF_INET , SOCK_STREAM , 0)) < 0) { 
    perror("socket() failed"); 
    exit(1); 
  }

  memset(&server, 0, sizeof server); 
  server.sin_addr.s_addr = inet_addr(argv[1]); 
  server.sin_family = AF_INET; 
  result = 0; 

  for (i = start_port; i <= end_port; i++) { 
    server.sin_port = htons(i); 

    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) == 0) { 
      printf("Port %d is open.\n", i); 
      result++; 
    } 
  } 

  printf("%d ports are open.\n", result); 
  close(sock); 
  return 0; 
}