//GEMINI-pro DATASET v1.0 Category: CPU usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/sysinfo.h>
#include <sys/types.h>

const char *PROC_CPU_USAGE = "/proc/stat";

int main() {
  FILE *fp;
  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  fp = fopen(PROC_CPU_USAGE, "r");
  if (!fp) {
    perror("fopen");
    return -1;
  }

  while ((read = getline(&line, &len, fp)) != -1) {
    if (strstr(line, "cpu") != NULL) {

      char *start = line;
      char *end = start;
      unsigned long idle = 0;
      unsigned long total = 0;

      while (*end != '\0') {
        if (*end == ' ') {
          *end = '\0';
          total += strtoul(start, NULL, 10);
          start = end + 1;
        }
        end++;
      }
      total += strtoul(start, NULL, 10);

      idle = strtoul(start, NULL, 10);
      float cpu_usage = 100.0 * (total - idle) / total;
      printf(
          "\nOh my gosh, you're using %.2f%% of your CPU right now! That's incredible!\n",
          cpu_usage);

      printf(
          "Golly, looks like you're doing some serious number crunching! I'm impressed!\n");
    }
  }

  fclose(fp);
  free(line);
  return 0;
}