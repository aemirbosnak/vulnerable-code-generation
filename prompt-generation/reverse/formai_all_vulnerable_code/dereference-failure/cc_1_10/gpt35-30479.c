//FormAI DATASET v1.0 Category: System event logger ; Style: automated
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    FILE *fp;
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    char filename[50];
    sprintf(filename, "event_logs_%d-%02d-%02d.txt", (tm.tm_year + 1900), tm.tm_mon + 1, tm.tm_mday);

    fp = fopen(filename, "a");

    if (fp == NULL) {
        printf("Error opening file.\n");
        return 1;
    }

    fprintf(fp, "\n\nSystem Event Log for %d-%02d-%02d\n\n", (tm.tm_year + 1900), tm.tm_mon + 1, tm.tm_mday);
    fprintf(fp, "%02d:%02d:%02d - Program Started\n", tm.tm_hour, tm.tm_min, tm.tm_sec);

    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int event = rand() % 4;

        switch(event) {
            case 0:
                fprintf(fp, "%02d:%02d:%02d - System booted.\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
                break;
            case 1:
                fprintf(fp, "%02d:%02d:%02d - User logged in.\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
                break;
            case 2:
                fprintf(fp, "%02d:%02d:%02d - File accessed.\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
                break;
            case 3:
                fprintf(fp, "%02d:%02d:%02d - Program closed.\n", tm.tm_hour, tm.tm_min, tm.tm_sec);
                break;
            default:
                break;
        }

        sleep(1);
    }

    fprintf(fp, "\n%02d:%02d:%02d - Program Ended\n", tm.tm_hour, tm.tm_min, tm.tm_sec);

    fclose(fp);

    return 0;
}