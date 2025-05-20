//FormAI DATASET v1.0 Category: Port Scanner ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main(int argc, char *argv[]) {
  int start_port, end_port, sock;
  struct sockaddr_in sa;
  char hostname[128], result[1024];
  
  if(argc!=2) {
    printf("\nUsage: %s <hostname>\n", argv[0]);
    exit(1);
  }
  
  //Creating socket
  if((sock=socket(AF_INET, SOCK_STREAM, 0)) < 0) {
    perror("Socket error");
    exit(1);
  }
  
  //Set hostname and port range
  strcpy(hostname, argv[1]);
  start_port = 1; 
  end_port = 65535;
  
  printf("\nBeginning scan on host %s\n\n", hostname);
  
  for(int port=start_port; port<=end_port; port++) {
    memset(&sa, 0, sizeof(sa));
    sa.sin_family = AF_INET;
    sa.sin_addr.s_addr = inet_addr(hostname);
    sa.sin_port = htons(port);
    
    //Try to connect to given port
    if(connect(sock, (struct sockaddr*)&sa, sizeof(sa)) == 0) {
      sprintf(result, "Port %d is open.\n", port);
      write(STDOUT_FILENO, result, strlen(result));
    }
    else {
      sprintf(result, "Port %d is closed.\n", port);
    }
  }
  
  printf("\nScan on host %s is complete.\n\n", hostname);
  
  close(sock);
  return 0;
}