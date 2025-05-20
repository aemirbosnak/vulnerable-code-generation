//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_RULES 100
#define MAX_EVENTS 1000

typedef struct {
  char *pattern;
  int priority;
} rule_t;

typedef struct {
  time_t timestamp;
  char *source;
  char *destination;
  char *payload;
} event_t;

rule_t rules[MAX_RULES];
event_t events[MAX_EVENTS];

int num_rules = 0;
int num_events = 0;

void load_rules(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char *pattern = strtok(line, ",");
    char *priority = strtok(NULL, ",");

    rules[num_rules].pattern = strdup(pattern);
    rules[num_rules].priority = atoi(priority);

    num_rules++;
  }

  fclose(fp);
}

void load_events(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp) != NULL) {
    char *timestamp = strtok(line, ",");
    char *source = strtok(NULL, ",");
    char *destination = strtok(NULL, ",");
    char *payload = strtok(NULL, ",");

    events[num_events].timestamp = atol(timestamp);
    events[num_events].source = strdup(source);
    events[num_events].destination = strdup(destination);
    events[num_events].payload = strdup(payload);

    num_events++;
  }

  fclose(fp);
}

void detect_intrusions() {
  for (int i = 0; i < num_events; i++) {
    for (int j = 0; j < num_rules; j++) {
      if (strstr(events[i].payload, rules[j].pattern) != NULL) {
        printf("Intrusion detected: %s\n", events[i].payload);
        break;
      }
    }
  }
}

int main(int argc, char *argv[]) {
  if (argc != 3) {
    printf("Usage: %s <rules file> <events file>\n", argv[0]);
    exit(1);
  }

  load_rules(argv[1]);
  load_events(argv[2]);
  detect_intrusions();

  return 0;
}