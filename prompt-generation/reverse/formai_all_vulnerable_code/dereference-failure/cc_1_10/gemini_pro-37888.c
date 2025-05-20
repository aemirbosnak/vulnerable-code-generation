//GEMINI-pro DATASET v1.0 Category: Network Topology Mapper ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <stdbool.h>
#include <pthread.h>

// Network topology mapper using threads

// Structure to hold network device information
struct device {
  char name[32];
  char ip_address[32];
  char mac_address[32];
  struct device *next;
};

// Structure to hold thread information
struct thread_info {
  int tid;
  struct device *device_list;
  pthread_mutex_t lock;
};

// Function to get the device name
void get_device_name(char *device_name, char *ifname) {
  struct ifaddrs *ifaddr, *ifa;
  int family, s;

  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    exit(EXIT_FAILURE);
  }

  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
    if (ifa->ifa_addr == NULL) continue;
    family = ifa->ifa_addr->sa_family;

    if (family == AF_PACKET && strncmp(ifa->ifa_name, ifname, strlen(ifname)) == 0) {
      strcpy(device_name, ifa->ifa_name);
      break;
    }
  }

  freeifaddrs(ifaddr);
}

// Function to get the IP address
void get_ip_address(char *ip_address, char *device_name) {
  struct ifaddrs *ifaddr, *ifa;
  int family, s;

  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    exit(EXIT_FAILURE);
  }

  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
    if (ifa->ifa_addr == NULL) continue;
    family = ifa->ifa_addr->sa_family;

    if (family == AF_PACKET && strncmp(ifa->ifa_name, device_name, strlen(device_name)) == 0) {
      s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), ip_address, 32, NULL, 0, NI_NUMERICHOST);
      if (s != 0) {
        printf("getnameinfo() failed: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
      }
      break;
    }
  }

  freeifaddrs(ifaddr);
}

// Function to get the MAC address
void get_mac_address(char *mac_address, char *device_name) {
  struct ifaddrs *ifaddr, *ifa;
  int family, s;

  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    exit(EXIT_FAILURE);
  }

  for (ifa = ifaddr; ifa != NULL; ifa = ifa->ifa_next) {
    if (ifa->ifa_addr == NULL) continue;
    family = ifa->ifa_addr->sa_family;

    if (family == AF_PACKET && strncmp(ifa->ifa_name, device_name, strlen(device_name)) == 0) {
      s = getnameinfo(ifa->ifa_addr, sizeof(struct sockaddr_in), mac_address, 32, NULL, 0, NI_NUMERICHOST);
      if (s != 0) {
        printf("getnameinfo() failed: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
      }
      break;
    }
  }

  freeifaddrs(ifaddr);
}

// Function to add a device to the list
void add_device(struct device **device_list, char *device_name, char *ip_address, char *mac_address) {
  struct device *new_device = malloc(sizeof(struct device));

  strcpy(new_device->name, device_name);
  strcpy(new_device->ip_address, ip_address);
  strcpy(new_device->mac_address, mac_address);

  new_device->next = *device_list;
  *device_list = new_device;
}

// Function to print the device list
void print_device_list(struct device *device_list) {
  struct device *device;

  for (device = device_list; device != NULL; device = device->next) {
    printf("%s %s %s\n", device->name, device->ip_address, device->mac_address);
  }
}

// Function to map the network topology
void *map_network_topology(void *arg) {
  struct thread_info *info = (struct thread_info *)arg;

  char device_name[32];
  char ip_address[32];
  char mac_address[32];

  // Get the device name
  get_device_name(device_name, info->tid);

  // Get the IP address
  get_ip_address(ip_address, device_name);

  // Get the MAC address
  get_mac_address(mac_address, device_name);

  // Add the device to the list
  pthread_mutex_lock(&info->lock);
  add_device(&info->device_list, device_name, ip_address, mac_address);
  pthread_mutex_unlock(&info->lock);

  return NULL;
}

int main(int argc, char *argv[]) {
  struct thread_info info[10];

  // Create the threads
  for (int i = 0; i < 10; i++) {
    info[i].tid = i;
    info[i].device_list = NULL;
    pthread_mutex_init(&info[i].lock, NULL);
    pthread_create(&info[i].tid, NULL, map_network_topology, &info[i]);
  }

  // Join the threads
  for (int i = 0; i < 10; i++) {
    pthread_join(info[i].tid, NULL);
  }

  // Print the device list
  for (int i = 0; i < 10; i++) {
    print_device_list(info[i].device_list);
  }

  return EXIT_SUCCESS;
}