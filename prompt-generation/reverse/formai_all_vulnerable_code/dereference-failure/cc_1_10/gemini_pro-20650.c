//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// Our trusty firewall, defender of the digital realm!
#define FIREWALL_PORT 42069

// Ban list: Only the bravest dare enter!
struct BanList {
  char **ips;
  int size;
  int capacity;
};

// Create a new ban list
struct BanList* ban_list_new() {
  struct BanList* list = malloc(sizeof(struct BanList));
  list->ips = malloc(sizeof(char*) * 10);
  list->size = 0;
  list->capacity = 10;
  return list;
}

// Add an IP to the ban list
void ban_list_add(struct BanList* list, char* ip) {
  if (list->size == list->capacity) {
    list->capacity *= 2;
    list->ips = realloc(list->ips, sizeof(char*) * list->capacity);
  }
  list->ips[list->size++] = strdup(ip);
}

// Check if an IP is banned
int ban_list_contains(struct BanList* list, char* ip) {
  for (int i = 0; i < list->size; i++) {
    if (strcmp(list->ips[i], ip) == 0) {
      return 1;
    }
  }
  return 0;
}

// Free the ban list
void ban_list_free(struct BanList* list) {
  for (int i = 0; i < list->size; i++) {
    free(list->ips[i]);
  }
  free(list->ips);
  free(list);
}

// Our main firewall function, guarding the gates of our network!
int main() {
  // Create a new socket, our gateway to the world
  int sock = socket(AF_INET, SOCK_DGRAM, 0);
  if (sock == -1) {
    perror("Socket creation failed");
    return 1;
  }

  // Bind the socket to our port, like a bouncer at the door
  struct sockaddr_in addr;
  memset(&addr, 0, sizeof(addr));
  addr.sin_family = AF_INET;
  addr.sin_addr.s_addr = INADDR_ANY;
  addr.sin_port = htons(FIREWALL_PORT);
  if (bind(sock, (struct sockaddr*)&addr, sizeof(addr)) == -1) {
    perror("Socket binding failed");
    close(sock);
    return 1;
  }

  // Create a ban list, our blacklist of troublemakers
  struct BanList* ban_list = ban_list_new();

  // Our firewall loop, eternally vigilant
  while (1) {
    char buffer[1024];
    struct sockaddr_in from_addr;
    socklen_t from_len = sizeof(from_addr);

    // Receive a message, a potential request for entry
    int recv_len = recvfrom(sock, buffer, sizeof(buffer), 0, (struct sockaddr*)&from_addr, &from_len);
    if (recv_len == -1) {
      perror("Message reception failed");
      continue;
    }

    // Convert the IP address of the sender to a string
    char ip_str[INET_ADDRSTRLEN];
    inet_ntop(AF_INET, &from_addr.sin_addr, ip_str, INET_ADDRSTRLEN);

    // Check if the sender is on our ban list
    if (ban_list_contains(ban_list, ip_str)) {
      // If they're banned, send a rejection message and boot them out!
      char* reject_msg = "ACCESS DENIED: You're on the naughty list!\n";
      sendto(sock, reject_msg, strlen(reject_msg), 0, (struct sockaddr*)&from_addr, from_len);
      continue;
    }

    // Welcome the guest and let them in!
    char* welcome_msg = "WELCOME: You're clear to enter!\n";
    sendto(sock, welcome_msg, strlen(welcome_msg), 0, (struct sockaddr*)&from_addr, from_len);
  }

  // Free the ban list before we leave
  ban_list_free(ban_list);

  return 0;
}