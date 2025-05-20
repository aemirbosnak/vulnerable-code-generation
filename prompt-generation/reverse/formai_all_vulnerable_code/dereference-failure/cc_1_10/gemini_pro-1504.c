//GEMINI-pro DATASET v1.0 Category: RAM usage monitor ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>

#define BUFF_SIZE 1024

char *file_name = "/proc/meminfo";

void print_usage(void)
{
  printf("Usage: %s [interval]\n", "ram_usage");
  printf("  interval: Update interval in seconds (default: 1)\n");
}

void parse_meminfo(void)
{
  FILE *fp;
  char buff[BUFF_SIZE];
  char *line;
  unsigned long total, free, used;

  fp = fopen(file_name, "r");
  if (fp == NULL) {
    perror("fopen");
    exit(1);
  }

  while (fgets(buff, BUFF_SIZE, fp) != NULL) {
    line = strtok(buff, ":");
    if (line == NULL) {
      continue;
    }

    if (strcmp(line, "MemTotal") == 0) {
      total = strtoul(strtok(NULL, " "), NULL, 10);
    } else if (strcmp(line, "MemFree") == 0) {
      free = strtoul(strtok(NULL, " "), NULL, 10);
    } else if (strcmp(line, "MemAvailable") == 0) {
      used = total - strtoul(strtok(NULL, " "), NULL, 10);
    }
  }

  printf("Total: %ld kB\n", total);
  printf("Free: %ld kB\n", free);
  printf("Used: %ld kB\n", used);

  fclose(fp);
}

void signal_handler(int signum)
{
  if (signum == SIGINT) {
    printf("Exiting...\n");
    exit(0);
  }
}

int main(int argc, char **argv)
{
  struct sigaction sa;
  int interval = 1;
  struct timeval tv;
  fd_set rfds;

  if (argc == 2) {
    interval = atoi(argv[1]);
  } else if (argc > 2) {
    print_usage();
    exit(1);
  }

  sa.sa_handler = signal_handler;
  sigemptyset(&sa.sa_mask);
  sa.sa_flags = 0;
  if (sigaction(SIGINT, &sa, NULL) == -1) {
    perror("sigaction");
    exit(1);
  }

  FD_ZERO(&rfds);
  FD_SET(STDIN_FILENO, &rfds);

  while (1) {
    tv.tv_sec = interval;
    tv.tv_usec = 0;

    if (select(STDIN_FILENO + 1, &rfds, NULL, NULL, &tv) == -1) {
      perror("select");
      exit(1);
    }

    if (FD_ISSET(STDIN_FILENO, &rfds)) {
      char buff[BUFF_SIZE];
      int rc;

      rc = read(STDIN_FILENO, buff, BUFF_SIZE);
      if (rc == -1) {
        perror("read");
        exit(1);
      } else if (rc == 0) {
        printf("Exiting...\n");
        exit(0);
      }
    } else {
      parse_meminfo();
    }
  }

  return 0;
}