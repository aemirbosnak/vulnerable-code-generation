//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <arpa/inet.h>
#include <ifaddrs.h>
#include <unistd.h>
#include <netdb.h>
#include <sys/ioctl.h>
#include <net/if.h>

#define MAX_DEVICES 128
#define MAX_IFACE_NAME_LENGTH 32
#define MAX_IP_LENGTH 16

struct Device {
  char name[MAX_IFACE_NAME_LENGTH];
  char ip[MAX_IP_LENGTH];
};

char *get_interface_ip(char *interface) {
  struct ifaddrs *ifaddr, *ifa;
  int family, s;
  static char host[NI_MAXHOST];

  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    exit(EXIT_FAILURE);
  }

  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
    if (strcmp(ifa->ifa_name, interface) != 0) {
      continue;
    }

    family = ifa->ifa_addr->sa_family;
    if (family == AF_INET) {
      s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
      if (s != 0) {
        printf("getnameinfo() failed: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
      }

      freeifaddrs(ifaddr);
      return host;
    }
  }

  freeifaddrs(ifaddr);
  return NULL;
}

void *scan_devices(void *arg) {
  char *interface = (char *) arg;
  struct Device *devices = malloc(MAX_DEVICES * sizeof(struct Device));
  int num_devices = 0;

  int sock;
  struct ifreq ifr;
  struct sockaddr_in *sin;
  char buffer[512];

  if ((sock = socket(AF_INET, SOCK_DGRAM, 0)) == -1) {
    perror("socket");
    exit(EXIT_FAILURE);
  }

  memset(&ifr, 0, sizeof(ifr));
  strncpy(ifr.ifr_name, interface, sizeof(ifr.ifr_name) - 1);
  ifr.ifr_addr.sa_family = AF_INET;

  if (ioctl(sock, SIOCGIFADDR, &ifr) == -1) {
    perror("SIOCGIFADDR");
    exit(EXIT_FAILURE);
  }

  sin = (struct sockaddr_in *) &ifr.ifr_addr;
  memcpy(devices[num_devices].ip, inet_ntoa(sin->sin_addr), MAX_IP_LENGTH);
  strcpy(devices[num_devices].name, interface);
  num_devices++;

  close(sock);

  FILE *fp = popen("arp -a", "r");
  if (fp == NULL) {
    printf("Failed to open arp -a pipe\n");
    exit(EXIT_FAILURE);
  }

  while (fgets(buffer, sizeof(buffer), fp)) {
    char *found_ip = strstr(buffer, "(");
    if (!found_ip) {
      continue;
    }

    strncpy(devices[num_devices].ip, found_ip + 1, MAX_IP_LENGTH - 1);
    devices[num_devices].ip[strlen(devices[num_devices].ip) - 1] = '\0';
    strcpy(devices[num_devices].name, "Unknown");
    num_devices++;
  }

  pclose(fp);

  printf("Devices on %s interface:\n", interface);
  for (int i = 0; i < num_devices; i++) {
    printf("Device %d: %s - %s\n", i + 1, devices[i].name, devices[i].ip);
  }

  free(devices);

  return NULL;
}

int main() {
  struct ifaddrs *interfaces, *iface;
  char *interface_names[MAX_DEVICES];
  int num_interfaces = 0;

  if (getifaddrs(&interfaces) == -1) {
    perror("getifaddrs");
    exit(EXIT_FAILURE);
  }

  printf("Available interfaces:\n");
  for (iface = interfaces; iface != NULL; iface = iface->ifa_next) {
    if (iface->ifa_addr == NULL) {
      continue;
    }

    if (iface->ifa_addr->sa_family == AF_INET) {
      printf("- %s\n", iface->ifa_name);
      interface_names[num_interfaces] = malloc(MAX_IFACE_NAME_LENGTH * sizeof(char));
      strcpy(interface_names[num_interfaces], iface->ifa_name);
      num_interfaces++;
    }
  }

  freeifaddrs(interfaces);

  printf("\n");

  pthread_t threads[num_interfaces];
  for (int i = 0; i < num_interfaces; i++) {
    pthread_create(&threads[i], NULL, &scan_devices, (void *) interface_names[i]);
  }

  for (int i = 0; i < num_interfaces; i++) {
    pthread_join(threads[i], NULL);
  }

  for (int i = 0; i < num_interfaces; i++) {
    free(interface_names[i]);
  }

  return 0;
}