//GPT-4o-mini DATASET v1.0 Category: File Backup System ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <unistd.h>

#define BACKUP_DIR "./backup/"

void create_backup_directory() {
    struct stat st = {0};
    if (stat(BACKUP_DIR, &st) == -1) {
        mkdir(BACKUP_DIR, 0700);
    }
}

char* get_current_timestamp() {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    char *timestamp = malloc(20);
    sprintf(timestamp, "%04d-%02d-%02d_%02d-%02d-%02d", 
            t->tm_year + 1900, t->tm_mon + 1, t->tm_mday,
            t->tm_hour, t->tm_min, t->tm_sec);
    return timestamp;
}

int copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb");
    if (src == NULL) {
        perror("Error opening source file");
        return -1;
    }

    FILE *dest = fopen(destination, "wb");
    if (dest == NULL) {
        perror("Error opening destination file");
        fclose(src);
        return -1;
    }

    char buffer[1024];
    size_t bytes;
    while ((bytes = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        fwrite(buffer, 1, bytes, dest);
    }

    fclose(src);
    fclose(dest);
    return 0;
}

void backup_file(const char *filename) {
    char *timestamp = get_current_timestamp();
    char backup_filename[256];
    snprintf(backup_filename, sizeof(backup_filename), "%s%s_backup_%s.bak", BACKUP_DIR, filename, timestamp);

    if (copy_file(filename, backup_filename) == 0) {
        printf("Backup of %s created successfully at %s\n", filename, backup_filename);
    } else {
        printf("Backup of %s failed\n", filename);
    }

    free(timestamp);
}

int main() {
    char filename[256];
    
    create_backup_directory();

    printf("Enter the name of the file you want to backup: ");
    scanf("%255s", filename);

    backup_file(filename);

    return 0;
}