//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <ifaddrs.h>

#define MAX_INTERFACE_NAME_LEN 128
#define MAX_IP_ADDR_LEN 16

int main(void) {
  struct ifaddrs *ifaddr, *ifa;
  int family, s, n;
  char host[MAX_INTERFACE_NAME_LEN], ip[MAX_IP_ADDR_LEN];

  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    return -1;
  }

  // iterate over all interfaces
  for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
    if (ifa->ifa_addr == NULL) continue;

    family = ifa->ifa_addr->sa_family;

    // check if interface is of type AF_INET (IPv4) or AF_INET6 (IPv6)
    if (family == AF_INET || family == AF_INET6) {
      s = getnameinfo(ifa->ifa_addr,
                      (family == AF_INET) ? sizeof(struct sockaddr_in) :
                                            sizeof(struct sockaddr_in6),
                      host, MAX_INTERFACE_NAME_LEN, NULL, 0, NI_NUMERICHOST);

      if (s != 0) {
        printf("getnameinfo() failed: %s\n", gai_strerror(s));
        return -1;
      }

      if (family == AF_INET) {
        printf("%-10s : %s\n", ifa->ifa_name, host);
      } else {
        printf("%-10s : [%s]\n", ifa->ifa_name, host);
      }
    }
  }

  freeifaddrs(ifaddr);
  return 0;
}