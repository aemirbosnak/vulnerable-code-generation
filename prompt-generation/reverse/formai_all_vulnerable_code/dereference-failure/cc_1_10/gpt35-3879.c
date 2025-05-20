//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOG_SIZE 100
#define MAX_IPS 10
#define MAX_FAILED_LOGIN 5

struct ip_info {
  int id;
  char* ip_address;
  int failed_login_count;
  int is_blocked;
};

struct log_entry {
  int id;
  char* timestamp;
  char* ip_address;
  char* username;
  int is_login_success;
};

struct ip_info* initialize_ips() {
  struct ip_info* ips = (struct ip_info*) malloc(MAX_IPS * sizeof(struct ip_info));

  int i;
  for (i = 0; i < MAX_IPS; i++) {
    ips[i].id = i;
    ips[i].ip_address = malloc(20);
    ips[i].failed_login_count = 0;
    ips[i].is_blocked = 0;
  }

  strcpy(ips[0].ip_address, "192.168.1.100");
  strcpy(ips[1].ip_address, "10.0.0.2");
  strcpy(ips[2].ip_address, "172.16.0.200");

  return ips;
}

void block_ip(struct ip_info* ips, char* ip_address) {
  int i;
  for (i = 0; i < MAX_IPS; i++) {
    if (strcmp(ips[i].ip_address, ip_address) == 0) {
      ips[i].is_blocked = 1;
      printf("IP Address %s is now blocked.\n", ip_address);
      break;
    }
  }
}

int is_ip_blocked(struct ip_info* ips, char* ip_address) {
  int i;
  for (i = 0; i < MAX_IPS; i++) {
    if (strcmp(ips[i].ip_address, ip_address) == 0) {
      return ips[i].is_blocked;
    }
  }
  return 0;
}

int is_login_valid(struct ip_info* ips, struct log_entry le) {
  if (is_ip_blocked(ips, le.ip_address)) {
    printf("IP Address %s is blocked.\n", le.ip_address);
    return 0;
  }

  int i;
  for (i = 0; i < MAX_IPS; i++) {
    if (strcmp(ips[i].ip_address, le.ip_address) == 0) {
      if (le.is_login_success == 0) {
        ips[i].failed_login_count++;
        printf("Invalid login for IP Address %s. Failed login count: %d\n", le.ip_address, ips[i].failed_login_count);

        if (ips[i].failed_login_count >= MAX_FAILED_LOGIN) {
          block_ip(ips, le.ip_address);
        }
      }
      else {
        ips[i].failed_login_count = 0;
      }
      break;
    }
  }

  return 1;
}

int main() {
  struct ip_info* ips = initialize_ips();

  struct log_entry log[MAX_LOG_SIZE];
  int log_size = 0;

  // Simulating log entries
  struct log_entry le1 = {1, "2019-10-17 12:00:00", "192.168.1.100", "user1", 1};
  log[log_size++] = le1;

  struct log_entry le2 = {2, "2019-10-17 12:00:01", "192.168.1.100", "user1", 0};
  log[log_size++] = le2;

  struct log_entry le3 = {3, "2019-10-17 12:00:02", "192.168.1.100", "user1", 0};
  log[log_size++] = le3;

  struct log_entry le4 = {4, "2019-10-17 12:00:03", "192.168.1.100", "user1", 0};
  log[log_size++] = le4;

  struct log_entry le5 = {5, "2019-10-17 12:00:04", "192.168.1.100", "user1", 0};
  log[log_size++] = le5;

  struct log_entry le6 = {6, "2019-10-17 12:00:05", "192.168.1.100", "user1", 0};
  log[log_size++] = le6;

  // Checking if the log entries are valid
  int i;
  for (i = 0; i < log_size; i++) {
    if (is_login_valid(ips, log[i]) == 0) {
      printf("Invalid log entry %d\n", log[i].id);
    }
  }

  return 0;
}