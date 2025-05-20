//FormAI DATASET v1.0 Category: Website Uptime Monitor ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define URL_SIZE 1024

int main(int argc, char **argv) {

  if (argc != 3) {
    printf("Usage: %s <URL> <interval in seconds>\n", argv[0]);
    exit(1);
  }

  char *url = argv[1];
  int interval = atoi(argv[2]);
  int status_code;
  time_t current_time;
  char time_buffer[30];

  while (1) {
    // Collect current time
    time(&current_time);
    strftime(time_buffer, 30, "%Y-%m-%d %H:%M:%S", localtime(&current_time));
    printf("[%s] ", time_buffer);

    // Ping the website
    char command[URL_SIZE + 32];
    sprintf(command, "curl -I %s -s | head -n 1 | cut -d ' ' -f2", url);
    FILE *fp = popen(command, "r");
    fscanf(fp, "%d", &status_code);
    pclose(fp);

    switch (status_code) {
      case 200:
        printf("%s is UP and running smoothly\n", url);
        break;
      case 301:
        printf("%s has MOVED permanently\n", url);
        break;
      case 302:
        printf("%s has MOVED temporarily\n", url);
        break;
      case 403:
        printf("ACCESS to %s is FORBIDDEN\n", url);
        break;
      case 404:
        printf("The requested page of %s is NOT FOUND\n", url);
        break;
      case 500:
        printf("%s is not working as INTERNAL SERVER ERROR occurred\n", url);
        break;
      default:
        printf("%s status code is %d\n", url, status_code);
        break;
    }

    // Wait for specified interval before pinging again
    sleep(interval);
  }

  return 0;
}