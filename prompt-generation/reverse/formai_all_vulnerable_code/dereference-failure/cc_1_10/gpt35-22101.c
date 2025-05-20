//FormAI DATASET v1.0 Category: System boot optimizer ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOOT_OPTIMIZER_VERSION "1.0.0"

void print_help_message(char *program_name)
{
    printf("Usage: %s [OPTIONS]\n", program_name);
    printf("   -v, --version    Display version information and exit.\n");
    printf("   -h, --help       Display this help message and exit.\n");
    printf("   -c, --clean      Clean boot up files to optimize system boot time.\n");
}

void clean_boot_files()
{
    char *filepaths_to_delete[] = {"/var/log/system.log", "/var/log/kernel.log", "/private/var/log/system.log", "/private/var/log/kernel.log"};

    for (int i = 0; i < sizeof(filepaths_to_delete)/sizeof(char*); i++)
    {
        printf("Deleting %s\n", filepaths_to_delete[i]);
        if (remove(filepaths_to_delete[i]) != 0)
        {
            printf("Failed to delete %s\n", filepaths_to_delete[i]);
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        print_help_message(argv[0]);
        return 0;
    }

    for (int i = 1; i < argc; i++)
    {
        if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
        {
            print_help_message(argv[0]);
            return 0;
        }
        else if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--version") == 0)
        {
            printf("Boot Optimizer Version %s\n", BOOT_OPTIMIZER_VERSION);
            return 0;
        }
        else if (strcmp(argv[i], "-c") == 0 || strcmp(argv[i], "--clean") == 0)
        {
            clean_boot_files();
            return 0;
        }
        else
        {
            printf("Invalid argument: %s\n", argv[i]);
            return 1;
        }
    }

    return 0;
}