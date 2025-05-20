//Gemma-7B DATASET v1.0 Category: System administration ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sys_admin(char **arr, int size)
{
    int i = 0;
    char **temp = NULL;
    char cmd[1024] = "";

    printf("Enter command: ");
    fgets(cmd, 1024, stdin);

    for (i = 0; i < size && arr[i] != NULL; i++)
    {
        if (strcmp(cmd, arr[i]) == 0)
        {
            temp = arr[i + 1];
            break;
        }
    }

    if (temp != NULL)
    {
        sys_admin(temp, size);
    }
    else
    {
        printf("Command not found.\n");
    }
}

int main()
{
    char **arr = NULL;
    int size = 0;

    arr = malloc(10 * sizeof(char *));
    arr[0] = "ls";
    arr[1] = "pwd";
    arr[2] = "cp";
    arr[3] = "rm";
    arr[4] = "mv";
    arr[5] = "touch";
    arr[6] = "mkdir";
    arr[7] = "chmod";
    arr[8] = "chown";
    arr[9] = NULL;

    sys_admin(arr, size);

    free(arr);

    return 0;
}