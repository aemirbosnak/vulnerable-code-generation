//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
#include <time.h>
#include <sys/sysinfo.h>

int main(int argc, char *argv[]) {
    long double idle_time, total_time, prev_idle_time, prev_total_time;
    int cpu_num = 0;
    char buf[1024], cpu_name[20], vendor_id[20], mhz[20];
    float usage;

    FILE *fp = fopen("/proc/cpuinfo", "r");
    while (fgets(buf, sizeof(buf), fp)) {
        if (strstr(buf, "vendor_id"))
            sscanf(buf, "%*s%*s%s", vendor_id);
        else if (strstr(buf, "model name"))
            sscanf(buf, "%*s%*s%*[^\"]\"%[^\"]", cpu_name);
        else if (strstr(buf, "cpu MHz"))
            sscanf(buf, "%*s%*s%s", mhz);
        else if (strstr(buf, "processor"))
            cpu_num++;
    }
    fclose(fp);

    printf("CPU model: %s\n", cpu_name);
    printf("CPU vendor: %s\n", vendor_id);
    printf("CPU speed: %s MHz\n", mhz);
    printf("Number of CPUs: %d\n\n", cpu_num);

    printf("Calculating CPU usage...\n\n");

    while (1) {
        fp = fopen("/proc/stat", "r");
        fscanf(fp, "%*s %Lf %Lf %Lf %Lf", &total_time, &total_time, &total_time, &idle_time);
        fclose(fp);

        if (prev_idle_time != 0)
            usage = 100.0 * (1.0 - (idle_time - prev_idle_time) / (total_time - prev_total_time) / cpu_num);

        prev_idle_time = idle_time;
        prev_total_time = total_time;

        printf("CPU usage: %.2f %%\n", usage);

        sleep(1);
    }

    return 0;
}