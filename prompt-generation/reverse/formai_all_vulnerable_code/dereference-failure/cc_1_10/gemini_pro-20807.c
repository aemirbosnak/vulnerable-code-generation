//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

// A cheerful firewall program!

// Define the maximum number of firewall rules
#define MAX_FIREWALL_RULES 100

// Define the firewall rule structure
typedef struct firewall_rule {
  char *source_ip;
  char *destination_ip;
  int source_port;
  int destination_port;
  char *protocol;
  char *action;
} firewall_rule;

// Define the firewall state structure
typedef struct firewall_state {
  firewall_rule rules[MAX_FIREWALL_RULES];
  int num_rules;
} firewall_state;

// Create a new firewall state
firewall_state *firewall_new() {
  firewall_state *state = malloc(sizeof(firewall_state));
  state->num_rules = 0;
  return state;
}

// Free the memory allocated for a firewall state
void firewall_free(firewall_state *state) {
  for (int i = 0; i < state->num_rules; i++) {
    free(state->rules[i].source_ip);
    free(state->rules[i].destination_ip);
    free(state->rules[i].protocol);
    free(state->rules[i].action);
  }
  free(state);
}

// Add a new rule to the firewall state
void firewall_add_rule(firewall_state *state, char *source_ip, char *destination_ip, int source_port, int destination_port, char *protocol, char *action) {
  if (state->num_rules >= MAX_FIREWALL_RULES) {
    fprintf(stderr, "Error: Too many firewall rules\n");
    return;
  }
  state->rules[state->num_rules].source_ip = strdup(source_ip);
  state->rules[state->num_rules].destination_ip = strdup(destination_ip);
  state->rules[state->num_rules].source_port = source_port;
  state->rules[state->num_rules].destination_port = destination_port;
  state->rules[state->num_rules].protocol = strdup(protocol);
  state->rules[state->num_rules].action = strdup(action);
  state->num_rules++;
}

// Evaluate a packet against the firewall state
int firewall_evaluate(firewall_state *state, char *source_ip, char *destination_ip, int source_port, int destination_port, char *protocol) {
  for (int i = 0; i < state->num_rules; i++) {
    if (strcmp(state->rules[i].source_ip, source_ip) == 0 &&
        strcmp(state->rules[i].destination_ip, destination_ip) == 0 &&
        state->rules[i].source_port == source_port &&
        state->rules[i].destination_port == destination_port &&
        strcmp(state->rules[i].protocol, protocol) == 0) {
      return strcmp(state->rules[i].action, "allow") == 0;
    }
  }
  return 0;
}

// Print the firewall state
void firewall_print(firewall_state *state) {
  printf("Firewall state:\n");
  for (int i = 0; i < state->num_rules; i++) {
    printf("  %s %s %d %d %s %s\n",
           state->rules[i].source_ip,
           state->rules[i].destination_ip,
           state->rules[i].source_port,
           state->rules[i].destination_port,
           state->rules[i].protocol,
           state->rules[i].action);
  }
}

// Main function
int main(int argc, char **argv) {
  // Create a new firewall state
  firewall_state *state = firewall_new();

  // Add some rules to the firewall state
  firewall_add_rule(state, "192.168.1.1", "192.168.1.2", 80, 80, "tcp", "allow");
  firewall_add_rule(state, "192.168.1.2", "192.168.1.1", 80, 80, "tcp", "allow");
  firewall_add_rule(state, "192.168.1.1", "192.168.1.3", 443, 443, "tcp", "deny");
  firewall_add_rule(state, "192.168.1.3", "192.168.1.1", 443, 443, "tcp", "allow");

  // Print the firewall state
  firewall_print(state);

  // Evaluate a packet against the firewall state
  int allowed = firewall_evaluate(state, "192.168.1.1", "192.168.1.2", 80, 80, "tcp");
  printf("Packet allowed: %s\n", allowed ? "yes" : "no");

  // Free the memory allocated for the firewall state
  firewall_free(state);

  return 0;
}