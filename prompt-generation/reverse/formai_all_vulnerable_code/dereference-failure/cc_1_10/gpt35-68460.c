//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_HOST_NAME_LEN 256
#define MAX_IP_ADDR_LEN 16
#define MAX_HOP_COUNT 30

void ping_host(char* host) {
  char command[256];
  sprintf(command, "ping -c 1 %s > /dev/null 2>&1", host);
  system(command);
}

int traceroute(char* host, char* ip_addr) {
  char command[256];
  sprintf(command, "traceroute %s > /dev/null 2>&1", host);
  FILE *fp = popen(command, "r");

  char line[256];
  int hop_count = 0;
  while (fgets(line, sizeof(line), fp) != NULL) {
    hop_count++;
    if (hop_count == 2) {
      char* ip_addr_ptr = strstr(line, " (");
      if (ip_addr_ptr != NULL) {
        ip_addr_ptr += 2;
        strncpy(ip_addr, ip_addr_ptr, MAX_IP_ADDR_LEN);
        ip_addr[MAX_IP_ADDR_LEN-1] = '\0';
      }
    }
  }

  pclose(fp);
  return hop_count;
}

int main(int argc, char* argv[]) {
  if (argc != 2) {
    printf("Usage: %s <host>\n", argv[0]);
    exit(1);
  }

  char host_name[MAX_HOST_NAME_LEN];
  char ip_addr[MAX_IP_ADDR_LEN];
  strncpy(host_name, argv[1], MAX_HOST_NAME_LEN);
  host_name[MAX_HOST_NAME_LEN-1] = '\0';

  printf("Host: %s\n", host_name);
  ping_host(host_name);
  printf("PING %s: successful\n", host_name);

  int hop_count = traceroute(host_name, ip_addr);
  printf("Traceroute to %s (%s), %d hops max\n", host_name, ip_addr, hop_count);

  return 0;
}