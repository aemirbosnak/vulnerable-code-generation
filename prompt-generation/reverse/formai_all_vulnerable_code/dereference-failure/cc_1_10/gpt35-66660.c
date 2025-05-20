//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

#define MAX_FILE_SIZE 4096
#define VIRUS_SIGNATURE "uO3PCVtV6Rs854Ts"

void scan_file(char *filename);
void infect_file(char *filename);
void remove_virus(char *filename);

int main(int argc, char *argv[])
{
    DIR *dir;
    struct dirent *ent;

    if (argc != 2)
    {
        printf("Usage: %s directory\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    dir = opendir(argv[1]);
    if (dir == NULL)
    {
        printf("Unable to open directory '%s'\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    printf("Starting antivirus scan for directory '%s'\n", argv[1]);

    while ((ent = readdir(dir)) != NULL)
    {
        if (strcmp(ent->d_name, ".") == 0 || strcmp(ent->d_name, "..") == 0)
            continue;

        char pathname[MAX_FILE_SIZE];
        snprintf(pathname, sizeof(pathname), "%s/%s", argv[1], ent->d_name);

        scan_file(pathname);
    }

    closedir(dir);
    printf("Antivirus scan complete.\n");

    return 0;
}

void scan_file(char *filename)
{
    FILE *fp;
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;

    printf("Scanning file '%s'\n", filename);

    fp = fopen(filename, "r");
    if (fp == NULL)
    {
        printf("Unable to open file '%s'\n", filename);
        return;
    }

    bytes_read = fread(buffer, sizeof(char), sizeof(buffer), fp);
    if (bytes_read == 0)
    {
        printf("File '%s' is empty.\n", filename);
        fclose(fp);
        return;
    }

    if (strstr(buffer, VIRUS_SIGNATURE) != NULL)
    {
        printf("Virus found in file '%s'.\n", filename);
        remove_virus(filename);
    }

    fclose(fp);
}

void infect_file(char *filename)
{
    FILE *fp;

    printf("Infecting file '%s'\n", filename);

    fp = fopen(filename, "r+");
    if (fp == NULL)
    {
        printf("Unable to open file '%s'\n", filename);
        return;
    }

    fseek(fp, 0, SEEK_END);
    fwrite(VIRUS_SIGNATURE, sizeof(char), strlen(VIRUS_SIGNATURE), fp);

    fclose(fp);
}

void remove_virus(char *filename)
{
    FILE *fp;
    char buffer[MAX_FILE_SIZE];
    size_t bytes_read;
    size_t signature_length = strlen(VIRUS_SIGNATURE);

    printf("Removing virus from file '%s'\n", filename);

    fp = fopen(filename, "r+");
    if (fp == NULL)
    {
        printf("Unable to open file '%s'\n", filename);
        return;
    }

    // Read file into buffer
    bytes_read = fread(buffer, sizeof(char), sizeof(buffer), fp);

    // Find virus signature and remove it
    char *virus_start = strstr(buffer, VIRUS_SIGNATURE);
    if (virus_start != NULL)
    {
        int virus_offset = virus_start - buffer;
        fseek(fp, virus_offset, SEEK_SET);
        fwrite(" ", sizeof(char), signature_length, fp);
    }

    // Truncate file to remove any leftover signature bytes
    fseek(fp, -(long)(signature_length), SEEK_END);
    ftruncate(fileno(fp), ftell(fp));

    fclose(fp);
}