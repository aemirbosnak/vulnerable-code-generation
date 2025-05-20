//FormAI DATASET v1.0 Category: Port Scanner ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <errno.h>

// Function to scan a single port
int scan_port(char *ip, int port){
  int sockfd = socket(AF_INET, SOCK_STREAM, 0); // create socket
  struct sockaddr_in addr;
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = inet_addr(ip);
  addr.sin_port = htons(port);

  int status = connect(sockfd, (struct sockaddr *)&addr, sizeof(addr)); // attempt connection
  close(sockfd); // close socket

  if(status == 0) return 1; // port opened
  else return 0; // port closed
}

// Function to print results
int print_result(char *ip, int start_port, int end_port){
  int open_ports = 0;
  printf("Scanning %s from port %d to %d...\n", ip, start_port, end_port);

  // Scan ports
  for(int i = start_port; i <= end_port; i++){
    int result = scan_port(ip, i);
    if(result == 1){
      printf("Port %d is open!\n", i);
      open_ports++;
    }
  }

  if(open_ports == 0) printf("No open ports found.\n");
  else if(open_ports == 1) printf("Found 1 open port.\n");
  else printf("Found %d open ports.\n", open_ports);

  return 0;
}

int main(int argc, char *argv[]){
  if(argc != 4){
    printf("Usage: %s <ip> <start_port> <end_port>\n", argv[0]);
    return 1;
  }

  char *ip = argv[1];
  int start_port = atoi(argv[2]);
  int end_port = atoi(argv[3]);

  if(end_port < start_port){
    printf("Error: end_port must be greater than or equal to start_port.\n");
    return 1;
  }

  return print_result(ip, start_port, end_port);
}