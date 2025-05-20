//Falcon-180B DATASET v1.0 Category: CPU usage monitor ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <string.h>

#define BUF_SIZE 1024
#define INTERVAL 1

char filename[BUF_SIZE];
int fd;

struct rusage usage;

void get_cpu_usage(void)
{
    if (getrusage(RUSAGE_SELF, &usage) == -1)
    {
        printf("Error getting CPU usage\n");
        exit(1);
    }

    double cpu_percent = (double)usage.ru_utime.tv_sec + (double)usage.ru_utime.tv_usec / 1000000.0;
    cpu_percent /= (double)usage.ru_stime.tv_sec + (double)usage.ru_stime.tv_usec / 1000000.0;

    printf("CPU usage: %.2f%%\n", cpu_percent * 100.0);
}

void read_file(void)
{
    char buffer[BUF_SIZE];
    int bytes_read;

    while ((bytes_read = read(fd, buffer, BUF_SIZE)) > 0)
    {
        write(1, buffer, bytes_read);
    }
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        printf("Usage: %s <filename>\n", argv[0]);
        exit(1);
    }

    strcpy(filename, argv[1]);

    if ((fd = open(filename, O_RDONLY)) == -1)
    {
        printf("Error opening file\n");
        exit(1);
    }

    while (1)
    {
        get_cpu_usage();
        read_file();

        if (feof(stdin))
        {
            break;
        }

        usleep(INTERVAL * 1000);
    }

    close(fd);
    exit(0);
}