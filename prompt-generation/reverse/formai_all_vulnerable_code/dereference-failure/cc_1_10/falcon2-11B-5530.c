//Falcon2-11B DATASET v1.0 Category: Antivirus scanner ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>
#include <dirent.h>
#include <sys/file.h>
#include <signal.h>

#define MAX_FILE_NAME_SIZE 100
#define MAX_FILE_SIZE 100000
#define MAX_SIGNATURES 1000

int threads;
int num_signatures;
int num_files;
char **file_list;
char **signature_list;

void *scan_file(void *data);

void check_for_signatures(void)
{
    int i;
    char *signature;

    if (num_signatures == 0)
    {
        printf("No signatures to check for\n");
        return;
    }

    for (i = 0; i < num_signatures; i++)
    {
        signature = signature_list[i];

        if (strstr(file_list[i], signature)!= NULL)
        {
            printf("Found signature '%s' in file '%s'\n", signature, file_list[i]);
        }
    }
}

void scan_directory(const char *directory_path)
{
    DIR *dir;
    struct dirent *entry;
    int ret;
    char *filename;

    if ((dir = opendir(directory_path)) == NULL)
    {
        perror("opendir");
        exit(EXIT_FAILURE);
    }

    while ((entry = readdir(dir))!= NULL)
    {
        if (entry->d_type == DT_REG)
        {
            filename = entry->d_name;

            if (strlen(filename) > MAX_FILE_NAME_SIZE)
            {
                fprintf(stderr, "Error: file name is too long: %s\n", filename);
                continue;
            }

            ret = strlen(filename) + 1;
            file_list = realloc(file_list, (num_files + 1) * sizeof(char *));
            if (file_list == NULL)
            {
                fprintf(stderr, "Error: failed to realloc file list\n");
                exit(EXIT_FAILURE);
            }
            file_list[num_files] = malloc(ret * sizeof(char));
            if (file_list[num_files] == NULL)
            {
                fprintf(stderr, "Error: failed to malloc file list\n");
                exit(EXIT_FAILURE);
            }
            strcpy(file_list[num_files], filename);
            num_files++;
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[])
{
    char *directory_path = ".";
    char *signature_file_path = "signatures.txt";
    int ret;
    char *filename;
    char *signature;
    char *thread_data;
    int i;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s <directory> [signatures.txt]\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    directory_path = argv[1];

    if (argc > 2)
    {
        signature_file_path = argv[2];
    }

    if (argc > 3)
    {
        threads = atoi(argv[3]);
    }

    if ((ret = mkdir("tmp", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH))!= 0)
    {
        perror("mkdir");
        exit(EXIT_FAILURE);
    }

    if ((ret = chdir("tmp"))!= 0)
    {
        perror("chdir");
        exit(EXIT_FAILURE);
    }

    if ((ret = access(signature_file_path, R_OK)) == -1)
    {
        fprintf(stderr, "Error: %s not found or not readable\n", signature_file_path);
        exit(EXIT_FAILURE);
    }

    num_signatures = 0;
    signature_list = malloc(sizeof(char *) * MAX_SIGNATURES);
    if (signature_list == NULL)
    {
        fprintf(stderr, "Error: failed to allocate signature list\n");
        exit(EXIT_FAILURE);
    }

    if ((ret = read_signatures(signature_file_path, &signature_list[num_signatures]))!= 0)
    {
        fprintf(stderr, "Error: failed to read signatures from %s\n", signature_file_path);
        exit(EXIT_FAILURE);
    }

    num_signatures = num_signatures + ret;

    scan_directory(directory_path);

    for (i = 0; i < num_files; i++)
    {
        thread_data = malloc(sizeof(char *) * MAX_FILE_SIZE);
        if (thread_data == NULL)
        {
            fprintf(stderr, "Error: failed to allocate thread data\n");
            exit(EXIT_FAILURE);
        }

        filename = file_list[i];

        if ((ret = read_file(filename, thread_data, MAX_FILE_SIZE)) == -1)
        {
            fprintf(stderr, "Error: failed to read file %s\n", filename);
            exit(EXIT_FAILURE);
        }

        if (strlen(thread_data) > 0)
        {
            if ((ret = fork()) == 0)
            {
                scan_file(thread_data);
                exit(EXIT_SUCCESS);
            }
        }
    }

    if (num_signatures == 0)
    {
        printf("No signatures found\n");
    }

    return 0;
}

void *scan_file(void *data)
{
    char *signature;
    int ret;

    for (int i = 0; i < num_signatures; i++)
    {
        signature = signature_list[i];

        if (strstr(data, signature)!= NULL)
        {
            printf("Found signature '%s' in file\n", signature);
        }
    }

    return NULL;
}

int read_signatures(const char *file_path, char **signature_list)
{
    FILE *file;
    char line[MAX_FILE_SIZE];
    char *signature;
    int num_lines = 0;

    if ((file = fopen(file_path, "r")) == NULL)
    {
        fprintf(stderr, "Error: failed to open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)!= NULL)
    {
        if (num_lines >= MAX_SIGNATURES)
        {
            fprintf(stderr, "Error: too many signatures\n");
            exit(EXIT_FAILURE);
        }

        signature = strdup(line);
        signature_list[num_lines] = signature;
        num_lines++;
    }

    fclose(file);

    return num_lines;
}

int read_file(const char *file_path, char *data, int max_size)
{
    FILE *file;
    char *line;
    int num_lines = 0;

    if ((file = fopen(file_path, "r")) == NULL)
    {
        fprintf(stderr, "Error: failed to open file %s\n", file_path);
        exit(EXIT_FAILURE);
    }

    while (fgets(line, sizeof(line), file)!= NULL)
    {
        if (num_lines >= max_size)
        {
            fprintf(stderr, "Error: file is too long\n");
            exit(EXIT_FAILURE);
        }

        strcat(data, line);
        num_lines++;
    }

    fclose(file);

    return num_lines;
}