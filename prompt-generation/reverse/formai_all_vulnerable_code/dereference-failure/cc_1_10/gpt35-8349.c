//FormAI DATASET v1.0 Category: Port Scanner ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

#define MAX_PORT 65535
#define MAX_TCP_THREADS 100
#define MAX_UDP_THREADS 10

int tcp_ports[MAX_PORT] = {0};
int udp_ports[MAX_PORT] = {0};

void tcp_scan(char *ip_address) {
  struct sockaddr_in target;

  memset(&target, 0, sizeof(target));
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = inet_addr(ip_address);
  
  for (int i = 0; i < MAX_PORT; i++) {
    if (tcp_ports[i]) {
      target.sin_port = htons(i);
      int sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
      if (connect(sock, (struct sockaddr *)&target, sizeof(target)) < 0) {
        printf("TCP Port %d is closed.\n", i);
      } else {
        printf("TCP Port %d is open.\n", i);
      }
      close(sock);
    }
  }
}

void udp_scan(char *ip_address) {
  struct sockaddr_in target;

  memset(&target, 0, sizeof(target));
  target.sin_family = AF_INET;
  target.sin_addr.s_addr = inet_addr(ip_address);
  
  for (int i = 0; i < MAX_PORT; i++) {
    if (udp_ports[i]) {
      target.sin_port = htons(i);
      int sock = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
      sendto(sock, NULL, 0, 0, (struct sockaddr *)&target, sizeof(target));
      struct timeval timeout;
      timeout.tv_sec = 1;
      timeout.tv_usec = 0;
      fd_set fds;
      FD_ZERO(&fds);
      FD_SET(sock, &fds);
      if (select(sock+1, &fds, NULL, NULL, &timeout) == 1) {
        printf("UDP Port %d is open\n", i);
      } else {
        printf("UDP Port %d is closed\n", i);
      }
      close(sock);
    }
  }
}

void help(char *progname) {
  printf("Usage: %s <ip_address> [-t <ports>] [-u <ports>]\n", progname);
  printf("\t-t <ports>: specify TCP ports to scan (e.g. \"-t 21,80,443\")\n");
  printf("\t-u <ports>: specify UDP ports to scan\n");
}

int main(int argc, char** argv) {
  int tcp_count = 0, udp_count = 0;

  if (argc < 2) {
    help(argv[0]);
    exit(-1);
  }

  char *ip_address = argv[1];
  for (int i = 2; i < argc; i++) {
    if (strcmp(argv[i], "-t") == 0) {
      char *tcp_ports_str = strtok(argv[i+1], ",");
      while (tcp_ports_str != NULL) {
        int port = atoi(tcp_ports_str);
        tcp_ports[port] = 1;
        tcp_count++;
        tcp_ports_str = strtok(NULL, ",");
      }
    } else if (strcmp(argv[i], "-u") == 0) {
      char *udp_ports_str = strtok(argv[i+1], ",");
      while (udp_ports_str != NULL) {
        int port = atoi(udp_ports_str);
        udp_ports[port] = 1;
        udp_count++;
        udp_ports_str = strtok(NULL, ",");
      }
    }
  }

  printf("Scanning %s...\n", ip_address);

  if (tcp_count > 0) {
    printf("Scanning TCP ports...\n");
    tcp_scan(ip_address);
  }

  if (udp_count > 0) {
    printf("Scanning UDP ports...\n");
    udp_scan(ip_address);
  }

  return 0;
}