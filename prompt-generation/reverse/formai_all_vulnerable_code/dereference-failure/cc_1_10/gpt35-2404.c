//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: cheerful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_LOGS 100

typedef struct {
  char *ip_address;
  char *timestamp;
  char *message;
} Log;

Log logs[MAX_LOGS];
int num_logs = 0;

void add_log(char *ip, char *ts, char *msg) {
  if(num_logs < MAX_LOGS) {
    logs[num_logs].ip_address = malloc(strlen(ip) + 1);
    strcpy(logs[num_logs].ip_address, ip);
    
    logs[num_logs].timestamp = malloc(strlen(ts) + 1);
    strcpy(logs[num_logs].timestamp, ts);
    
    logs[num_logs].message = malloc(strlen(msg) + 1);
    strcpy(logs[num_logs].message, msg);
    
    num_logs++;
  }
}

void check_logs() {
  int count = 0;
  for(int i = 0; i < num_logs; i++) {
    if(strcmp(logs[i].message, "Invalid login attempt") == 0) {
      printf("ALERT: %s attempted an invalid login at %s.\n", logs[i].ip_address, logs[i].timestamp);
      count++;
    }
  }
  
  if(count == 0) {
    printf("No invalid login attempts recorded.\n");
  }
}

int main() {
  add_log("10.0.0.1", "2/8/2022 12:13:45", "User 'admin' attempted to login unsuccessfully.");
  add_log("10.0.0.2", "2/8/2022 13:45:56", "Invalid login attempt");
  add_log("10.0.0.3", "2/8/2022 16:22:31", "User 'user1' successfully logged in.");
  add_log("10.0.0.4", "2/9/2022 9:01:12", "Invalid login attempt");
  
  check_logs();
  
  return 0;
}