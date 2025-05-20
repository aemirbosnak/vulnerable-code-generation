//Gemma-7B DATASET v1.0 Category: Intrusion detection system ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

#define SYSLOG "/var/log/intrusion_detection.log"

void log_event(char *event)
{
    FILE *fp = fopen(SYSLOG, "a");
    fprintf(fp, "%s\n", event);
    fclose(fp);
}

int main()
{
    char filename[256];
    char *ptr;
    int size;

    printf("Enter the filename: ");
    scanf("%s", filename);

    if (stat(filename, NULL) == -1)
    {
        perror("Error stat()ing file");
        exit(1);
    }

    size = read(fileno(filename), ptr, 1024);

    if (size > 0)
    {
        ptr = (char *)malloc(size);
        read(fileno(filename), ptr, size);

        for (int i = 0; i < size; i++)
        {
            if (ptr[i] < 0 || ptr[i] > 127)
            {
                log_event("Suspicious character detected in file");
                break;
            }
        }

        free(ptr);
    }

    return 0;
}