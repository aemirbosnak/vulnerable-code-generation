//Gemma-7B DATASET v1.0 Category: Math exercise ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    char *p_buffer = NULL;
    int i_buffer_size = 0;
    char *p_command = NULL;
    int i_command_size = 0;
    int i_status = 0;
    time_t t_start, t_end;

    p_buffer = malloc(1024);
    if (p_buffer == NULL)
    {
        exit(1);
    }

    i_buffer_size = 1024;
    p_buffer = realloc(p_buffer, i_buffer_size);

    p_command = malloc(1024);
    if (p_command == NULL)
    {
        exit(1);
    }

    i_command_size = 1024;
    p_command = realloc(p_command, i_command_size);

    t_start = time(NULL);

    printf("Enter command: ");
    fgets(p_command, i_command_size, stdin);

    i_status = system(p_command);

    t_end = time(NULL);

    printf("Time taken: %ld seconds\n", t_end - t_start);

    printf("Status: %d\n", i_status);

    free(p_buffer);
    free(p_command);

    return 0;
}