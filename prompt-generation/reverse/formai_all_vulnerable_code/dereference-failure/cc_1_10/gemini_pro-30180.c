//GEMINI-pro DATASET v1.0 Category: Temperature monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>

#define SYSFS_THERMAL_PATH "/sys/class/thermal/"

int main() {
  int fd, n, i;
  char buf[1024];
  char *tz_path, *temp_path;
  float temp;

  // Scan for thermal zones
  for (i = 0; i < 100; i++) {
    snprintf(buf, sizeof(buf), "%s/thermal_zone%d", SYSFS_THERMAL_PATH, i);
    if (access(buf, F_OK) == 0) {
      // Found a valid zone
      tz_path = strdup(buf);
      break;
    }
  }

  if (tz_path == NULL) {
    fprintf(stderr, "No thermal zones found\n");
    return 1;
  }

  // Open the temp file for reading
  snprintf(buf, sizeof(buf), "%s/temp", tz_path);
  fd = open(buf, O_RDONLY);
  if (fd < 0) {
    perror("open");
    return 1;
  }

  // Read the temperature
  n = read(fd, buf, sizeof(buf) - 1);
  if (n < 0) {
    perror("read");
    return 1;
  }
  buf[n] = '\0';
  temp = strtof(buf, NULL);

  // Print the temperature
  printf("Temperature: %.2f°C\n", temp);

  // Close the file
  close(fd);

  // Free the path
  free(tz_path);

  return 0;
}