//GEMINI-pro DATASET v1.0 Category: Time Travel Simulator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void travel(const char **, char ***, int *);
char **parse_times(char *);
void print_times(char **, int);
char *decode_time(char *, int);

int main()
{
    srand(time(NULL));
    char *input = NULL;
    char **times = NULL;
    int count = 0;

    while (1)
    {
        printf("Enter a time sequence (e.g. 1200,1300,1400) or quit: ");
        getline(&input, &count, stdin);

        if (strcmp(input, "quit\n") == 0)
            break;

        times = parse_times(input);
        travel(times, &times, &count);
        print_times(times, count);
    }

    return 0;
}

void travel(const char **times, char ***times_ptr, int *count_ptr)
{
    int i, j, k, l;
    char temp[256];
    char **new_times = NULL;

    *times_ptr = realloc(*times_ptr, (*count_ptr + 2) * sizeof(char *));

    for (i = 0; i < *count_ptr; i++)
    {
        for (j = i + 1; j < *count_ptr; j++)
        {
            if (strcmp(times[i], times[j]) > 0)
            {
                strcpy(temp, times[i]);
                strcpy(times[i], times[j]);
                strcpy(times[j], temp);
            }
        }
    }

    for (i = 0; i < *count_ptr; i++)
    {
        for (j = 0; j < *count_ptr; j++)
        {
            for (k = j + 1; k < *count_ptr; k++)
            {
                for (l = k + 1; l < *count_ptr; l++)
                {
                    new_times = realloc(new_times, (*count_ptr + 1) * sizeof(char *));
                    new_times[*count_ptr] = malloc(64 * sizeof(char));

                    sprintf(new_times[*count_ptr], "%s%s%s%s", times[i], times[j], times[k], times[l]);

                    if (decode_time(new_times[*count_ptr], l) == 0)
                    {
                        free(new_times[*count_ptr]);
                        new_times[*count_ptr] = NULL;
                    }
                    else
                        (*count_ptr)++;
                }
            }
        }
    }

    for (i = 0; i < *count_ptr; i++)
        free(times[i]);

    free(times);

    *times = new_times;
}

char **parse_times(char *input)
{
    char **times = NULL;
    int count = 0, i = 0, j = 0;
    char *token = NULL;

    token = strtok(input, ",");
    while (token != NULL)
    {
        times = realloc(times, (count + 1) * sizeof(char *));
        times[count] = malloc(64 * sizeof(char));
        strcpy(times[count++], token);
        token = strtok(NULL, ",");
    }

    return times;
}

void print_times(char **times, int count)
{
    int i;

    for (i = 0; i < count; i++)
        printf("%s, ", times[i]);

    printf("\n");
}

char *decode_time(char *time, int count)
{
    int i, j, sum = 0;
    char *decoded = malloc(64 * sizeof(char));

    for (i = 0; i < count; i++)
    {
        sum += ((time[i] - '0') * pow(10, count - i - 1));
        decoded[i] = ((rand() % (sum + 1)) + 48);
    }

    decoded[count] = '\0';

    for (i = 0; i < count; i++)
    {
        for (j = i + 1; j < count; j++)
        {
            if (decoded[i] == decoded[j])
            {
                free(decoded);
                return NULL;
            }
        }
    }

    return decoded;
}