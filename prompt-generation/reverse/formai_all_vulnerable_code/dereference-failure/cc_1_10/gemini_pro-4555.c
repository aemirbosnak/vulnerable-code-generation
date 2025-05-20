//GEMINI-pro DATASET v1.0 Category: Intrusion detection system ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pcap.h>
#include <netinet/in.h>

#define SNAPLEN 65535
#define MAX_RULES 100

struct rule {
  char *pattern;
  int mask;
  int action;
};

struct pcap_pkthdr *header;
const u_char *pkt_data;
int pkt_len;

struct rule rules[MAX_RULES];
int num_rules = 0;

int load_rules(char *filename) {
  FILE *fp;
  char line[1024];
  char *pattern, *mask, *action;
  int i;

  fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("fopen");
    return -1;
  }

  while (fgets(line, sizeof(line), fp) != NULL) {
    if (line[0] == '#') {
      continue;
    }

    pattern = strtok(line, " ");
    mask = strtok(NULL, " ");
    action = strtok(NULL, "\n");

    rules[num_rules].pattern = strdup(pattern);
    rules[num_rules].mask = strtol(mask, NULL, 10);
    rules[num_rules].action = atoi(action);

    num_rules++;
  }

  fclose(fp);

  return 0;
}

int match_rule(struct rule *rule) {
  int i;

  for (i = 0; i < pkt_len; i++) {
    if ((pkt_data[i] & rule->mask) != (rule->pattern[i] & rule->mask)) {
      return 0;
    }
  }

  return 1;
}

int process_packet(u_char *user, const struct pcap_pkthdr *header, const u_char *pkt_data) {
  int i;

  for (i = 0; i < num_rules; i++) {
    if (match_rule(&rules[i])) {
      switch (rules[i].action) {
        case 0:
          printf("Dropping packet.\n");
          return 1;
        case 1:
          printf("Allowing packet.\n");
          return 0;
        default:
          fprintf(stderr, "Invalid action %d.\n", rules[i].action);
          return -1;
      }
    }
  }

  return 0;
}

int main(int argc, char *argv[]) {
  char *filename;
  char errbuf[PCAP_ERRBUF_SIZE];
  pcap_t *handle;

  if (argc != 2) {
    fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
    return -1;
  }

  filename = argv[1];

  if (load_rules(filename) < 0) {
    return -1;
  }

  handle = pcap_open_live("eth0", SNAPLEN, 1, 1000, errbuf);
  if (handle == NULL) {
    fprintf(stderr, "pcap_open_live: %s\n", errbuf);
    return -1;
  }

  pcap_loop(handle, -1, process_packet, NULL);

  pcap_close(handle);

  return 0;
}