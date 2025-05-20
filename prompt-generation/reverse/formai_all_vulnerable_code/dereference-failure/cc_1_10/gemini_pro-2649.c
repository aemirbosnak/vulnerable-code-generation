//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: Claude Shannon
// Claude Shannon's Shannon Firewall

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>

// Define the firewall rules.
struct rule {
  char *src_ip;
  char *dst_ip;
  int src_port;
  int dst_port;
  char *protocol;
  int action;
};

// Define the firewall state.
struct state {
  int num_rules;
  struct rule *rules;
};

// Create a new firewall state.
struct state *new_state() {
  struct state *state = malloc(sizeof(struct state));
  state->num_rules = 0;
  state->rules = NULL;
  return state;
}

// Add a rule to the firewall state.
void add_rule(struct state *state, char *src_ip, char *dst_ip, int src_port, int dst_port, char *protocol, int action) {
  struct rule *rule = malloc(sizeof(struct rule));
  rule->src_ip = strdup(src_ip);
  rule->dst_ip = strdup(dst_ip);
  rule->src_port = src_port;
  rule->dst_port = dst_port;
  rule->protocol = strdup(protocol);
  rule->action = action;
  state->rules = realloc(state->rules, sizeof(struct rule) * (state->num_rules + 1));
  state->rules[state->num_rules++] = *rule;
}

// Check if a packet is allowed by the firewall.
int check_packet(struct state *state, char *src_ip, char *dst_ip, int src_port, int dst_port, char *protocol) {
  for (int i = 0; i < state->num_rules; i++) {
    struct rule *rule = &state->rules[i];
    if (strcmp(src_ip, rule->src_ip) == 0 &&
        strcmp(dst_ip, rule->dst_ip) == 0 &&
        src_port == rule->src_port &&
        dst_port == rule->dst_port &&
        strcmp(protocol, rule->protocol) == 0) {
      return rule->action;
    }
  }
  return -1;
}

// Start the firewall.
void start_firewall(struct state *state) {
  int server_fd, new_socket;
  struct sockaddr_in server_addr, client_addr;
  socklen_t client_addr_len;

  // Create a new socket.
  server_fd = socket(AF_INET, SOCK_STREAM, 0);

  // Set the server address.
  server_addr.sin_family = AF_INET;
  server_addr.sin_addr.s_addr = INADDR_ANY;
  server_addr.sin_port = htons(80);

  // Bind the socket to the server address.
  bind(server_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));

  // Listen for incoming connections.
  listen(server_fd, 5);

  // Accept incoming connections.
  while (1) {
    // Accept a new connection.
    client_addr_len = sizeof(client_addr);
    new_socket = accept(server_fd, (struct sockaddr *)&client_addr, &client_addr_len);

    // Get the source IP address, destination IP address, source port, destination port, and protocol from the packet.
    char src_ip[INET_ADDRSTRLEN];
    char dst_ip[INET_ADDRSTRLEN];
    int src_port;
    int dst_port;
    char protocol[10];
    inet_ntop(AF_INET, &client_addr.sin_addr, src_ip, INET_ADDRSTRLEN);
    inet_ntop(AF_INET, &server_addr.sin_addr, dst_ip, INET_ADDRSTRLEN);
    src_port = ntohs(client_addr.sin_port);
    dst_port = ntohs(server_addr.sin_port);
    strcpy(protocol, "TCP");

    // Check if the packet is allowed by the firewall.
    int action = check_packet(state, src_ip, dst_ip, src_port, dst_port, protocol);

    // Send the packet to the destination.
    if (action == 1) {
      send(new_socket, "Packet allowed", strlen("Packet allowed"), 0);
    } else {
      send(new_socket, "Packet denied", strlen("Packet denied"), 0);
    }

    // Close the connection.
    close(new_socket);
  }
}

// Main function.
int main() {
  // Create a new firewall state.
  struct state *state = new_state();

  // Add some rules to the firewall state.
  add_rule(state, "192.168.1.1", "192.168.1.2", 80, 80, "TCP", 1);
  add_rule(state, "192.168.1.2", "192.168.1.1", 80, 80, "TCP", -1);
  add_rule(state, "192.168.1.1", "192.168.1.3", 443, 443, "TCP", 1);
  add_rule(state, "192.168.1.3", "192.168.1.1", 443, 443, "TCP", -1);

  // Start the firewall.
  start_firewall(state);

  return 0;
}