//FormAI DATASET v1.0 Category: System process viewer ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUF_SIZE 1024

char *trim(char *str)
{
    char *end = str + strlen(str) - 1;
    while (isspace((unsigned char)*end)) end--;
    *(end + 1) = '\0';
    while (*str && isspace((unsigned char)*str)) str++;
    return str;
}

int main(int argc, char *argv[]) {
    char buf[BUF_SIZE];
    char cmd[BUF_SIZE], pid_str[BUF_SIZE], user[BUF_SIZE], cpu[BUF_SIZE], mem[BUF_SIZE];
    char *tok;
    int num_procs = 0;

    FILE *fp = popen("ps -aux", "r");

    if (fp == NULL)
    {
        printf("Error: Could not open pipe for %s\n", "ps -aux");
        return 1;
    }

    printf("PID\tUSER\t\tCPU\tMEM\tCOMMAND\n");

    while (fgets(buf, BUF_SIZE, fp) != NULL)
    {
        // Tokenize the current line
        tok = strtok(buf, " ");
        int index = 0;
        while (tok != NULL && index < 5)
        {
            if (index == 0)
            {
                strncpy(user, trim(tok), BUF_SIZE-1);
            }
            else if (index == 1)
            {
                strncpy(pid_str, trim(tok), BUF_SIZE-1);
            }
            else if (index == 2)
            {
                strncpy(cpu, trim(tok), BUF_SIZE-1);
            }
            else if (index == 3)
            {
                strncpy(mem, trim(tok), BUF_SIZE-1);
            }
            index++;
            tok = strtok(NULL, " ");
        }
 
        if (index > 0)
        {
            // Get the command for the given PID
            snprintf(cmd, BUF_SIZE-1, "ps -p %s -o comm=", pid_str);
            FILE *fp_cmd = popen(cmd, "r");
            char cmd_buf[BUF_SIZE];
            fgets(cmd_buf, BUF_SIZE, fp_cmd);

            if (strlen(cmd_buf) > 0)
            {
                num_procs++;
                printf("%s\t%s\t%s\t%s\t%s", pid_str, user, cpu, mem, cmd_buf);
            }
            pclose(fp_cmd);
        }
    }

    printf("Total number of processes: %d\n", num_procs);
    pclose(fp);
    return 0;
}