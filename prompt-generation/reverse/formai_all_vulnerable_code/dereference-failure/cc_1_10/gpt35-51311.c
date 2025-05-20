//FormAI DATASET v1.0 Category: System administration ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    // Check if user has root access
    if (geteuid() != 0) {
        printf("This program must be run as root.\n");
        exit(EXIT_FAILURE);
    }

    // Display system information
    printf("System Name: %s\n", argv[0]);
    printf("Kernel Version: %s\n", uname());

    // Display system uptime
    FILE *uptime_file;
    char uptime_buf[BUFSIZ];
    uptime_file = fopen("/proc/uptime", "r");
    if (!uptime_file) {
        printf("Error opening /proc/uptime: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (fgets(uptime_buf, BUFSIZ, uptime_file)) {
        double uptime;
        sscanf(uptime_buf, "%lf", &uptime);
        printf("Uptime: %.0f seconds\n", uptime);

        int hours = uptime / 3600;
        int minutes = ((int)uptime % 3600) / 60;
        int seconds = (int)uptime % 60;
        printf("  or %d hours, %d minutes, and %d seconds\n", hours, minutes, seconds);
    }
    fclose(uptime_file);

    // Display current users and load average
    FILE *w_file;
    char w_buf[BUFSIZ];
    w_file = popen("/usr/bin/w", "r");
    if (!w_file) {
        printf("Error opening /usr/bin/w: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    while (fgets(w_buf, BUFSIZ, w_file)) {
        printf("%s", w_buf);
    }
    pclose(w_file);
    printf("\n");

    // Display disk space usage for /
    FILE *df_file;
    char df_buf[BUFSIZ];
    df_file = popen("/bin/df -h /", "r");
    if (!df_file) {
        printf("Error opening /bin/df: %s", strerror(errno));
        exit(EXIT_FAILURE);
    }
    if (fgets(df_buf, BUFSIZ, df_file)) {
        printf("Disk Space Usage for /:\n%s", df_buf);
    }
    pclose(df_file);
}