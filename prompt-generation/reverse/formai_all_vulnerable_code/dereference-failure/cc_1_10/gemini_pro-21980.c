//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <signal.h>

#define MAX_RULES 10
#define MAX_INTERFACES 10

struct rule {
  char *src_ip;
  char *dst_ip;
  char *protocol;
  char *src_port;
  char *dst_port;
  int action;
};

struct interface {
  char *name;
  int fd;
};

struct firewall {
  struct rule rules[MAX_RULES];
  struct interface interfaces[MAX_INTERFACES];
  int num_rules;
  int num_interfaces;
};

int init_firewall(struct firewall *firewall) {
  firewall->num_rules = 0;
  firewall->num_interfaces = 0;

  int i;
  for (i = 0; i < MAX_RULES; i++) {
    firewall->rules[i].src_ip = NULL;
    firewall->rules[i].dst_ip = NULL;
    firewall->rules[i].protocol = NULL;
    firewall->rules[i].src_port = NULL;
    firewall->rules[i].dst_port = NULL;
    firewall->rules[i].action = -1;
  }

  for (i = 0; i < MAX_INTERFACES; i++) {
    firewall->interfaces[i].name = NULL;
    firewall->interfaces[i].fd = -1;
  }

  return 0;
}

int add_rule(struct firewall *firewall, char *src_ip, char *dst_ip, char *protocol, char *src_port, char *dst_port, int action) {
  if (firewall->num_rules >= MAX_RULES) {
    return -1;
  }

  struct rule *rule = &firewall->rules[firewall->num_rules++];

  rule->src_ip = strdup(src_ip);
  rule->dst_ip = strdup(dst_ip);
  rule->protocol = strdup(protocol);
  rule->src_port = strdup(src_port);
  rule->dst_port = strdup(dst_port);
  rule->action = action;

  return 0;
}

int add_interface(struct firewall *firewall, char *name, int fd) {
  if (firewall->num_interfaces >= MAX_INTERFACES) {
    return -1;
  }

  struct interface *interface = &firewall->interfaces[firewall->num_interfaces++];

  interface->name = strdup(name);
  interface->fd = fd;

  return 0;
}

int main(int argc, char **argv) {
  struct firewall firewall;

  init_firewall(&firewall);

  add_rule(&firewall, "192.168.0.1", "192.168.0.2", "tcp", "80", "8080", 1);
  add_rule(&firewall, "192.168.0.2", "192.168.0.1", "tcp", "8080", "80", 1);
  add_rule(&firewall, "192.168.0.3", "192.168.0.4", "udp", "53", "53", 1);
  add_rule(&firewall, "192.168.0.4", "192.168.0.3", "udp", "53", "53", 1);

  add_interface(&firewall, "eth0", 0);
  add_interface(&firewall, "eth1", 1);

  int i;
  for (i = 0; i < firewall.num_rules; i++) {
    printf("Rule %d:\n", i);
    printf("  src_ip: %s\n", firewall.rules[i].src_ip);
    printf("  dst_ip: %s\n", firewall.rules[i].dst_ip);
    printf("  protocol: %s\n", firewall.rules[i].protocol);
    printf("  src_port: %s\n", firewall.rules[i].src_port);
    printf("  dst_port: %s\n", firewall.rules[i].dst_port);
    printf("  action: %d\n\n", firewall.rules[i].action);
  }

  for (i = 0; i < firewall.num_interfaces; i++) {
    printf("Interface %d:\n", i);
    printf("  name: %s\n", firewall.interfaces[i].name);
    printf("  fd: %d\n\n", firewall.interfaces[i].fd);
  }

  return 0;
}