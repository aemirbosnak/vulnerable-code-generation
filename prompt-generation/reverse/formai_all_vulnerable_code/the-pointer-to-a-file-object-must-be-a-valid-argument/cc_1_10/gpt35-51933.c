//FormAI DATASET v1.0 Category: RAM usage monitor ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to read current RAM usage
int readRamUsage() {
    FILE *fp;
    char ram[100];
    int usage;

    // open file
    fp = fopen("/proc/meminfo", "r");

    // read file line by line
    while(fgets(ram, 100, fp) != NULL){

        // find the line with "MemAvailable"
        if(strcmp(ram, "MemAvailable:") == 0) {

            // get the RAM usage in kilobytes
            sscanf(ram+13, "%d", &usage);
            break;
        }
    }

    // close file
    fclose(fp);

    // return RAM usage in megabytes
    return usage/1024;
}

int main() {
    int previousUsage = readRamUsage();
    int currentUsage;

    printf("Monitoring RAM usage...\n");

    while(1) {
        sleep(2);
        currentUsage = readRamUsage();

        // check for abnormal increase in RAM usage
        if (currentUsage - previousUsage > 10) {
            printf("*** WARNING - RAM USAGE HAS INCREASED ABNORMALLY ***\n");
            printf("*** PREVIOUS USAGE: %d MB ***\n", previousUsage);
            printf("*** CURRENT USAGE: %d MB ***\n", currentUsage);

            // take a screenshot
            system("gnome-screenshot -f screenshot.png");

            // send an email to the user
            system("echo 'RAM usage has increased abnormally!' | mail -s 'RAM MONITOR' user@example.com -A screenshot.png");
        }

        previousUsage = currentUsage;
    }

    return 0;
}