//FormAI DATASET v1.0 Category: System process viewer ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>
#include <unistd.h>
#include <pwd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

// Define the maximum buffer size
#define MAX_BUF_SIZE 1024

// Define the structure to store the process details
typedef struct{
    char name[MAX_BUF_SIZE];
    char status[MAX_BUF_SIZE];
    pid_t pid;
    uid_t uid;
    gid_t gid;
    int rss;
    int vms;
}Process;

// Initialize the function to read the process details
void read_process(Process* p, char* proc_dir)
{
    char buf[MAX_BUF_SIZE];

    // Read the process name
    sprintf(buf, "%s/cmdline", proc_dir);
    FILE* fp = fopen(buf, "r");
    if(fp == NULL)
    {
        perror("Error opening command line file");
        exit(EXIT_FAILURE);
    }
    fgets(buf, MAX_BUF_SIZE, fp);
    fclose(fp);
    sscanf(buf, "%s", p->name);

    // Read the process status
    sprintf(buf, "%s/status", proc_dir);
    fp = fopen(buf, "r");
    if(fp == NULL)
    {
        perror("Error opening status file");
        exit(EXIT_FAILURE);
    }
    while(fgets(buf, MAX_BUF_SIZE, fp) != NULL)
    {
        if(strncmp(buf, "State:", 6) == 0)
        {
            sscanf(buf, "State:\t%s", p->status);
            break;
        }
    }
    fclose(fp);

    // Read the process ID, UID, GID, RSS, and VMS
    sscanf(proc_dir, "/proc/%d", &p->pid);
    sprintf(buf, "/proc/%d/stat", p->pid);
    fp = fopen(buf, "r");
    if(fp == NULL)
    {
        perror("Error opening stat file");
        exit(EXIT_FAILURE);
    }
    fgets(buf, MAX_BUF_SIZE, fp);
    fclose(fp);
    char* token = strtok(buf, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    sscanf(token, "%u", &p->uid);
    token = strtok(NULL, " ");
    sscanf(token, "%u", &p->gid);
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    token = strtok(NULL, " ");
    sscanf(token, "%d", &p->rss);
    token = strtok(NULL, " ");
    sscanf(token, "%d", &p->vms);
}

int main(int argc, char** argv)
{
    // Open the directory for reading
    DIR* dir = opendir("/proc");
    if(dir == NULL)
    {
        perror("Unable to open /proc directory");
        exit(EXIT_FAILURE);
    }

    // Loop through all the directories in /proc to find processes
    struct dirent* ent;
    while((ent = readdir(dir)) != NULL)
    {
        // Ignore "." and ".." directories
        if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        // Check if the directory name contains only digits
        int i = 0;
        while(ent->d_name[i] != '\0')
        {
            if(!isdigit(ent->d_name[i]))
                break;
            i++;
        }
        if(ent->d_name[i] == '\0')
        {
            // Read the process details
            Process p;
            char proc_dir[MAX_BUF_SIZE];
            sprintf(proc_dir, "/proc/%s", ent->d_name);
            read_process(&p, proc_dir);

            // Print the process details
            printf("Process Name: %s\n", p.name);
            printf("Process ID: %d\n", p.pid);
            printf("Process Status: %s\n", p.status);
            printf("Process UID: %d\n", p.uid);
            printf("Process GID: %d\n", p.gid);
            printf("Process Resident Set Size: %d KB\n", p.rss / 1024);
            printf("Process Virtual Memory Size: %d KB\n\n", p.vms / 1024);
        }
    }

    // Close the directory
    closedir(dir);

    return 0;
}