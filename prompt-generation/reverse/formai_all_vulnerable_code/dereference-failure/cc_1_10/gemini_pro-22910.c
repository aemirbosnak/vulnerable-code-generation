//GEMINI-pro DATASET v1.0 Category: Log analysis ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Decoding the mysterious runes
#define IP_ADDR_MASK 0xFFFFFFFF
#define PORT_MASK 0xFFFF

// Our magic decoder ring
typedef struct {
  unsigned int ip_addr;
  unsigned short port;
  char *timestamp;
  char *log_entry;
} log_record;

// The secret incantation to open the log file
FILE *open_log(char *filename) {
  FILE *fp = fopen(filename, "r");
  if (fp == NULL) {
    perror("Unable to open log file");
    exit(EXIT_FAILURE);
  }
  return fp;
}

// Parsing the cryptic messages
log_record *parse_log_line(char *line) {
  log_record *record = malloc(sizeof(log_record));
  if (record == NULL) {
    perror("Unable to allocate memory for log record");
    exit(EXIT_FAILURE);
  }

  // Splitting the line into timestamp, IP address, port, and log entry
  char *timestamp_end = strchr(line, ' ');
  if (timestamp_end == NULL) {
    fprintf(stderr, "Invalid log line: %s", line);
    exit(EXIT_FAILURE);
  }
  char *timestamp = strndup(line, timestamp_end - line);
  record->timestamp = timestamp;

  char *ip_addr_end = strchr(timestamp_end + 1, ' ');
  if (ip_addr_end == NULL) {
    fprintf(stderr, "Invalid log line: %s", line);
    exit(EXIT_FAILURE);
  }
  char *ip_addr = strndup(timestamp_end + 1, ip_addr_end - timestamp_end - 1);
  record->ip_addr = inet_addr(ip_addr);

  char *port_end = strchr(ip_addr_end + 1, ' ');
  if (port_end == NULL) {
    fprintf(stderr, "Invalid log line: %s", line);
    exit(EXIT_FAILURE);
  }
  char *port = strndup(ip_addr_end + 1, port_end - ip_addr_end - 1);
  record->port = htons(atoi(port));

  char *log_entry = strdup(port_end + 1);
  record->log_entry = log_entry;

  return record;
}

// Unraveling the secrets of the log file
void analyze_log(FILE *fp) {
  char buffer[1024];

  // Looping through the log file line by line
  while (fgets(buffer, sizeof(buffer), fp) != NULL) {
    log_record *record = parse_log_line(buffer);

    // Unmasking the hidden IP address and port
    printf("IP Address: %u.%u.%u.%u\n",
           (record->ip_addr & IP_ADDR_MASK) >> 24,
           (record->ip_addr & IP_ADDR_MASK) >> 16,
           (record->ip_addr & IP_ADDR_MASK) >> 8,
           (record->ip_addr & IP_ADDR_MASK));
    printf("Port: %u\n", ntohs(record->port));

    // Revealing the timestamp and log entry
    printf("Timestamp: %s\n", record->timestamp);
    printf("Log Entry: %s\n\n", record->log_entry);

    free(record->timestamp);
    free(record->log_entry);
    free(record);
  }
}

int main(int argc, char **argv) {
  if (argc < 2) {
    fprintf(stderr, "Usage: %s <log_file>\n", argv[0]);
    exit(EXIT_FAILURE);
  }

  FILE *fp = open_log(argv[1]);
  analyze_log(fp);
  fclose(fp);

  return EXIT_SUCCESS;
}