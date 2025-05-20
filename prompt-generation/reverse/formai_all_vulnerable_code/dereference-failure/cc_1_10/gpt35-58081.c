//FormAI DATASET v1.0 Category: Wireless Network Scanner ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <net/if.h>
#include <unistd.h>
#include <errno.h>
#include <ctype.h>

#define MAX_INTERFACE_LEN 10
#define MAX_BUF_SIZE 1024

void scan_wireless_network() {
   struct ifaddrs *ifaddr, *ifa;
   int family, s, ret;
   char interface_name[MAX_INTERFACE_LEN];
   
   if (getifaddrs(&ifaddr) == -1) {
      perror("getifaddrs");
      exit(EXIT_FAILURE);
   }
   
   for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
      if (ifa->ifa_addr == NULL) continue;
      
      family = ifa->ifa_addr->sa_family;
      if (family == AF_INET || family == AF_INET6) {
         s = socket(family, SOCK_DGRAM, IPPROTO_UDP);
         if (s == -1) {
            perror("socket");
            continue;
         }
         
         ret = snprintf(interface_name, MAX_INTERFACE_LEN, "%s", ifa->ifa_name);
         if (ret < 0 || ret >= MAX_INTERFACE_LEN) {
            fprintf(stderr, "Error in interface name\n");
            close(s);
            continue;
         }
         
         if (setsockopt(s, SOL_SOCKET, SO_BINDTODEVICE, interface_name, strlen(interface_name)) == -1) {
            perror("setsockopt");
            close(s);
            continue;
         }
         
         struct sockaddr_in broadcast_addr;
         memset(&broadcast_addr, 0, sizeof(broadcast_addr));
         broadcast_addr.sin_family = AF_INET;
         broadcast_addr.sin_addr.s_addr = htonl(INADDR_BROADCAST);
         broadcast_addr.sin_port = htons(1900);
         
         char *message = "M-SEARCH * HTTP/1.1\r\n"
                         "HOST: 239.255.255.250:1900\r\n"
                         "MAN: \"ssdp:discover\"\r\n"
                         "MX: 2\r\n"
                         "ST: ssdp:all\r\n\r\n";
                         
         int len = strlen(message);
         if (sendto(s, message, len, 0, (struct sockaddr *)&broadcast_addr, sizeof(broadcast_addr)) == -1) {
            perror("sendto");
            close(s);
            continue;
         }
         
         char buf[MAX_BUF_SIZE];
         struct timeval tv;
         tv.tv_sec = 2;
         tv.tv_usec = 0;
         if (setsockopt(s, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv)) == -1) {
            perror("setsockopt");
            close(s);
            continue;
         }
         
         while (1) {
            memset(buf, 0, MAX_BUF_SIZE);
            struct sockaddr_in from_addr;
            socklen_t addrlen = sizeof(from_addr);
            ret = recvfrom(s, buf, MAX_BUF_SIZE, 0, (struct sockaddr *)&from_addr, &addrlen);
            if (ret == -1 && errno == EAGAIN) {
               break;
            }
            printf("---> Found wireless network %s on interface %s\n", buf, interface_name);
         }
         
         close(s);
      }
   }
   
   freeifaddrs(ifaddr);
}

int main() {
   scan_wireless_network();
   return 0;
}