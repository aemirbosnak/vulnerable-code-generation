//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <net/if.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>
#include <errno.h>

#define MAX_HOSTS 100
#define MAX_HOPS 20

struct host_info {
  char hostname[NI_MAXHOST];
  char ipaddr[NI_MAXHOST];
  int port;
};

struct route_info {
  char hops[MAX_HOPS][NI_MAXHOST];
  int num_hops;
};

int main(int argc, char *argv[]) {
  // First, let's parse the command line arguments
  if(argc != 2) {
    printf("Usage: %s [host]\n", argv[0]);
    exit(1);
  }

  char *hostname = argv[1];

  // We need to resolve the IP address of the host we're looking for
  struct host_info target_host;
  struct addrinfo hints, *res;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  int rc = getaddrinfo(hostname, NULL, &hints, &res);
  if(rc != 0) {
    printf("Error resolving '%s': %s\n", hostname, gai_strerror(rc));
    exit(1);
  }
  char target_ip[NI_MAXHOST];
  inet_ntop(AF_INET, &((struct sockaddr_in *)(res->ai_addr))->sin_addr, target_ip, sizeof target_ip);
  strncpy(target_host.ipaddr, target_ip, NI_MAXHOST);

  // Now we can start scanning the network
  printf("Scanning network...\n");
  struct host_info hosts[MAX_HOSTS];
  int num_hosts = 0;
  struct ifreq ifr;
  char iface[] = "eth0";
  int sockfd = socket(AF_INET, SOCK_DGRAM, 0); // UDP socket for scanning
  if(sockfd == -1) {
    perror("socket");
    exit(1);
  }
  strncpy(ifr.ifr_name, iface, IFNAMSIZ-1);
  if(ioctl(sockfd, SIOCGIFADDR, &ifr) < 0) {
    perror("ioctl");
    exit(1);
  }
  close(sockfd);
  char *local_ip = inet_ntoa(((struct sockaddr_in *)&ifr.ifr_addr)->sin_addr);
  char local_subnet[NI_MAXHOST];
  strncpy(local_subnet, local_ip, sizeof(local_subnet));
  char *last_dot = strrchr(local_subnet, '.');
  *last_dot = '\0';
  strcat(local_subnet, ".0/24");
  struct addrinfo *result, *rp;
  memset(&hints, 0, sizeof hints);
  hints.ai_family = AF_INET;
  hints.ai_socktype = SOCK_STREAM;
  rc = getaddrinfo(local_subnet, NULL, &hints, &result);
  if(rc != 0) {
    printf("Error resolving local subnet: %s\n", gai_strerror(rc));
    exit(1);
  }
  for(rp = result; rp != NULL; rp = rp->ai_next) {
    struct sockaddr_in *addr = (struct sockaddr_in *)rp->ai_addr;
    char ipaddr[NI_MAXHOST];
    inet_ntop(rp->ai_family, &(addr->sin_addr), ipaddr, sizeof ipaddr);
    if(strcmp(ipaddr, local_ip) == 0) {
      continue; // Don't scan our own IP
    }
    strncpy(hosts[num_hosts].ipaddr, ipaddr, NI_MAXHOST);
    // We want to resolve the hostnames if possible
    rc = getnameinfo((struct sockaddr *)addr, sizeof(struct sockaddr_in), hosts[num_hosts].hostname, NI_MAXHOST, NULL, 0, 0);
    if(rc != 0) {
      strncpy(hosts[num_hosts].hostname, ipaddr, NI_MAXHOST);
    }
    hosts[num_hosts].port = 22; // SSH default port
    num_hosts++;
    if(num_hosts >= MAX_HOSTS) {
      break;
    }
  }
  freeaddrinfo(result);
  printf("Found %d hosts\n", num_hosts);

  // Now we need to find the route to the target host
  printf("Finding route...\n");
  struct route_info route;
  route.num_hops = 0;
  bool found_target = false;
  for(int i = 0; i < num_hosts; i++) {
    if(strcmp(hosts[i].ipaddr, target_host.ipaddr) == 0) {
      strncpy(route.hops[route.num_hops], hosts[i].ipaddr, NI_MAXHOST);
      route.num_hops++;
      found_target = true;
      break;
    }
    // Check if we can connect to this host
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if(sockfd == -1) {
      perror("socket");
      exit(1);
    }
    struct sockaddr_in sa;
    memset(&sa, 0, sizeof sa);
    sa.sin_family = AF_INET;
    sa.sin_port = htons(hosts[i].port);
    inet_pton(AF_INET, hosts[i].ipaddr, &sa.sin_addr);
    rc = connect(sockfd, (struct sockaddr *)&sa, sizeof sa);
    if(rc == -1) {
      // Host unreachable
      close(sockfd);
      continue;
    }
    // We're connected, now let's find the route to the target host
    char command[NI_MAXHOST];
    snprintf(command, sizeof(command), "traceroute -m %d %s", MAX_HOPS, target_host.ipaddr);
    FILE *fp = popen(command, "r");
    if(fp == NULL) {
      perror("popen");
      exit(1);
    }
    char line[NI_MAXHOST*2];
    fgets(line, sizeof line, fp); // First line is just a header, ignore it
    while(fgets(line, sizeof line, fp) != NULL) {
      char *ip_pos = strchr(line, '(');
      if(ip_pos == NULL) {
        // This hop is unreachable
        continue;
      }
      ip_pos++;
      char *ip_end_pos = strchr(ip_pos, ')');
      if(ip_end_pos == NULL) {
        continue;
      }
      *ip_end_pos = '\0';
      if(strcmp(ip_pos, target_host.ipaddr) == 0) {
        // We've found the target! Add this host to the route
        strncpy(route.hops[route.num_hops], hosts[i].ipaddr, NI_MAXHOST);
        route.num_hops++;
        found_target = true;
        break;
      }
    }
    pclose(fp);
    if(found_target) {
      break;
    }
    close(sockfd);
  }
  if(!found_target) {
    printf("Could not find route to '%s'", target_host.hostname);
    exit(1);
  }
  printf("Found route to '%s' (%s) via:\n", target_host.hostname, target_host.ipaddr);
  for(int i = 0; i < route.num_hops; i++) {
    printf("- %s\n", route.hops[i]);
  }

  return 0;
}