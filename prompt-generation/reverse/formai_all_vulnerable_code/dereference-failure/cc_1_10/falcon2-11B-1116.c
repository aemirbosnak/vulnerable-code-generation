//Falcon2-11B DATASET v1.0 Category: RAM usage monitor ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

void print_usage(const char* name, int argc, char** argv) {
    printf("%s: usage error\n", name);
    printf("Usage: %s [OPTIONS]\n", argv[0]);
    printf("\nOPTIONS:\n");
    printf("  -h, --help\tPrint this message and exit\n");
    printf("  -v, --verbose\tEnable verbose output\n");
    printf("  -c, --count\tSet the number of times to run the test\n");
    printf("  -t, --time\tSet the time limit for each test\n");
    printf("  -o, --output\tSet the output file name\n");
    printf("\nExamples:\n");
    printf("  Monitor RAM usage every 5 seconds for 10 times:\n");
    printf("  %s -c 10 -t 5 > ram_usage.log\n", argv[0]);
    printf("\n");
}

void print_usage_and_exit(const char* name, int argc, char** argv, int exit_code) {
    print_usage(name, argc, argv);
    exit(exit_code);
}

int main(int argc, char** argv) {
    if (argc < 2) {
        print_usage_and_exit(argv[0], argc, argv, 1);
    }

    int count = 10;
    double time_limit = 5.0;
    char* output_file = NULL;

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            print_usage_and_exit(argv[0], argc, argv, 0);
        } else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            setvbuf(stdout, NULL, _IONBF, 0);
        } else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--count") == 0) {
            if (i + 1 < argc && sscanf(argv[i + 1], "%d", &count) == 1) {
                i++;
            } else {
                print_usage_and_exit(argv[0], argc, argv, 1);
            }
        } else if (strcmp(argv[i], "-t") == 0 || strcmp(argv[i], "--time") == 0) {
            if (i + 1 < argc && sscanf(argv[i + 1], "%lf", &time_limit) == 1) {
                i++;
            } else {
                print_usage_and_exit(argv[0], argc, argv, 1);
            }
        } else if (strcmp(argv[i], "-o") == 0 || strcmp(argv[i], "--output") == 0) {
            if (i + 1 < argc) {
                output_file = argv[i + 1];
                i++;
            } else {
                print_usage_and_exit(argv[0], argc, argv, 1);
            }
        } else {
            print_usage_and_exit(argv[0], argc, argv, 1);
        }
    }

    if (count <= 0 || time_limit <= 0) {
        print_usage_and_exit(argv[0], argc, argv, 1);
    }

    struct timeval start_time, end_time;
    gettimeofday(&start_time, NULL);

    for (int j = 0; j < count; j++) {
        double mem_usage = 0;
        double mem_limit = 1;

        gettimeofday(&end_time, NULL);
        double time_elapsed = (end_time.tv_sec - start_time.tv_sec) * 1000000 + end_time.tv_usec - start_time.tv_usec;

        if (time_elapsed > time_limit) {
            printf("Test %d: Time limit exceeded\n", j + 1);
            continue;
        }

        mem_usage = (mem_usage + time_elapsed * mem_limit) / (j + 1);

        if (output_file!= NULL) {
            FILE* fp = fopen(output_file, "a");
            fprintf(fp, "%d\t%.3f\n", j + 1, mem_usage);
            fclose(fp);
        }

        printf("Test %d: %.3f\n", j + 1, mem_usage);
    }

    gettimeofday(&end_time, NULL);
    double total_time = (end_time.tv_sec - start_time.tv_sec) * 1000000 + end_time.tv_usec - start_time.tv_usec;
    printf("Total time: %.3f seconds\n", total_time);

    return 0;
}