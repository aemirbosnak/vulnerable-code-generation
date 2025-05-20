//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAX_PATH_LENGTH 1024
#define MAX_BUFFER_SIZE 8192

struct virus_signature
{
    char virus_name[32];
    char virus_signature[32];
};

struct virus_signature virus_signatures[] = 
{
    {"Virus1", "C0DEAB01"},
    {"Virus2", "DEADBEEF"},
    {"Virus3", "FEEDFACE"}
};

int num_virus_signatures = sizeof(virus_signatures)/sizeof(virus_signatures[0]);

void scan_file(char* filename)
{
    int fd;
    int nbytes;
    char buffer[MAX_BUFFER_SIZE];
    char md5hash[33];
    char scan_result[256];
    struct stat statbuf;

    if(stat(filename, &statbuf) < 0)
    {
        perror("Failed to get file stats!");
        return;
    }

    if((fd = open(filename, O_RDONLY)) < 0)
    {
        perror("Failed to open file");
        return;
    }

    while((nbytes = read(fd, buffer, sizeof(buffer))) > 0)
    {
        // Find MD5 hash
    }

    sprintf(scan_result, "File '%s' is clean", filename);

    // Check for virus signature
    for(int i=0; i<num_virus_signatures; i++)
    {
        if(strstr(buffer, virus_signatures[i].virus_signature))
        {
            sprintf(scan_result, "File '%s' is infected with virus '%s'", filename, virus_signatures[i].virus_name);
            break;
        }
    }

    printf("%s\n", scan_result);

    close(fd);
}

void scan_directory(char* dirname)
{
    DIR *dir;
    struct dirent *ent;
    char path[MAX_PATH_LENGTH];

    if((dir = opendir(dirname)) == NULL)
    {
        perror("Failed to open directory");
        return;
    }

    while((ent = readdir(dir)) != NULL)
    {
        if(strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        snprintf(path, MAX_PATH_LENGTH, "%s/%s", dirname, ent->d_name);

        if(ent->d_type == DT_DIR)
            scan_directory(path);
        else
            scan_file(path);
    }

    closedir(dir);
}

void signal_handler(int signum)
{
    if(signum == SIGINT || signum == SIGTERM)
        printf("\nScan cancelled by user\n");
}

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Usage: %s <directory>\n", argv[0]);
        return 0;
    }

    struct sigaction action;
    memset(&action, 0, sizeof(struct sigaction));
    action.sa_handler = signal_handler;
    sigaction(SIGINT, &action, NULL);
    sigaction(SIGTERM, &action, NULL);

    scan_directory(argv[1]);

    return 0;
}