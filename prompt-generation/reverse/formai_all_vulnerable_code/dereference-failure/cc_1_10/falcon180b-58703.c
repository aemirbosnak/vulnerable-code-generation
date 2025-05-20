//Falcon-180B DATASET v1.0 Category: RAM usage monitor ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <sys/resource.h>
#include <unistd.h>

#define INTERVAL 5

void print_usage(char *prog)
{
    printf("Usage: %s [-h]\n", prog);
    printf("       %s [-v]\n", prog);
    printf("       %s [-i INTERVAL]\n", prog);
    printf("Options:\n");
    printf("  -h : Help\n");
    printf("  -v : Version\n");
    printf("  -i : Interval (in seconds)\n");
}

void print_version()
{
    printf("RAM Usage Monitor v1.0\n");
}

void monitor_ram_usage(int interval)
{
    struct rusage usage;
    int i = 0;

    while (1) {
        getrusage(RUSAGE_SELF, &usage);

        printf("\r%d%%", (int) (((double) usage.ru_maxrss / (double) usage.ru_maxrss) * 100.0));

        if (++i == interval) {
            printf("\n");
            i = 0;
        }

        sleep(1);
    }
}

int main(int argc, char *argv[])
{
    int interval = INTERVAL;

    if (argc < 2) {
        print_usage(argv[0]);
        return 1;
    }

    while ((argc > 1) && (*argv[1] == '-')) {
        switch (*++argv[1]) {
            case 'h':
                print_usage(argv[0]);
                return 0;

            case 'v':
                print_version();
                return 0;

            case 'i':
                if (argc > 2) {
                    interval = atoi(argv[2]);
                    if (interval <= 0) {
                        fprintf(stderr, "Invalid interval.\n");
                        return 1;
                    }
                    argv += 2;
                    argc -= 2;
                } else {
                    fprintf(stderr, "Missing argument for option -i.\n");
                    return 1;
                }
                break;

            default:
                fprintf(stderr, "Invalid option: -%c\n", *argv[1]);
                return 1;
        }
    }

    monitor_ram_usage(interval);

    return 0;
}