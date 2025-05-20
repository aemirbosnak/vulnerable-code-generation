//GEMINI-pro DATASET v1.0 Category: System event logger ; Style: post-apocalyptic
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/syslog.h>
#include <time.h>

static const char *progname = "apoc-logger";

static void usage(void) {
  fprintf(stderr, "usage: %s <msg>\n", progname);
  fprintf(stderr, "logs the specified message using syslog.\n");
  exit(1);
}

static char * trim(char * str)
{
    int len = strlen(str);
    int i = 0;

    while(str[i] == ' ' && i < len)
        i++;

    while(str[len - 1] == ' ' && len > 0)
        len--;

    return strndup(str + i, len - i);
}

int main(int argc, char *argv[]) {
  if (argc != 2)
    usage();

  openlog(progname, LOG_PID, LOG_USER);

  char *msg = trim(argv[1]);

  int pri = LOG_INFO;

  if (strstr(msg, "warning") != NULL)
    pri = LOG_WARNING;
  else if (strstr(msg, "error") != NULL)
    pri = LOG_ERR;
  else if (strstr(msg, "debug") != NULL)
    pri = LOG_DEBUG;

  syslog(pri, "%s", msg);
  closelog();

  free(msg);

  return 0;
}