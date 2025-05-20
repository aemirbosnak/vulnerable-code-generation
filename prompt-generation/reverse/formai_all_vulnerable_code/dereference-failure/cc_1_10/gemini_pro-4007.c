//GEMINI-pro DATASET v1.0 Category: Firewall ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_RULES 100
#define MAX_RULE_LEN 100

struct rule {
  char *pattern;
  int allow;
};

struct firewall {
  struct rule rules[MAX_RULES];
  int num_rules;
};

int load_rules(struct firewall *fw, char *filename) {
  FILE *fp;
  char line[MAX_RULE_LEN];
  int i;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    return -1;
  }

  i = 0;
  while (fgets(line, MAX_RULE_LEN, fp) != NULL) {
    fw->rules[i].pattern = strdup(strtok(line, " "));
    if (strcmp(strtok(NULL, " "), "allow")) {
      fw->rules[i].allow = 1;
    }
    else fw->rules[i].allow=0;
    
    i++;
  }

  fclose(fp);

  fw->num_rules = i;

  return 0;
}

int check_packet(struct firewall *fw, char *packet) {
  int i;

  for (i = 0; i < fw->num_rules; i++) {
    if (strstr(packet, fw->rules[i].pattern) != NULL) {
      return fw->rules[i].allow;
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  struct firewall fw;
  char *packet;

  if (argc != 3) {
    fprintf(stderr, "Usage: %s <rules file> <packet>\n", argv[0]);
    return 1;
  }

  if (load_rules(&fw, argv[1]) == -1) {
    return 1;
  }

  packet = argv[2];

  if (check_packet(&fw, packet)) {
    printf("Packet allowed\n");
  }
  else printf("Packet denied\n");

  return 0;
}