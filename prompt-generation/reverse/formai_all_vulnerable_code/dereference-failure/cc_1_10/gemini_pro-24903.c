//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Watson, our resident filesystem expert
struct Watson {
    char *backup_dir;
    char *file_to_backup;
};

// Elementary, my dear Watson!
void backup_file(struct Watson *watson) {
    // Gather the necessary information
    time_t now = time(NULL);
    struct tm *tm = localtime(&now);
    char backup_file[100];
    sprintf(backup_file, "%s/%s.%04d%02d%02d.bak",
        watson->backup_dir, watson->file_to_backup,
        tm->tm_year + 1900, tm->tm_mon + 1, tm->tm_mday);

    // Perform the backup
    FILE *src = fopen(watson->file_to_backup, "rb");
    if (!src) {
        printf("Unable to open file %s for backup.\n", watson->file_to_backup);
        return;
    }
    FILE *dst = fopen(backup_file, "wb");
    if (!dst) {
        fclose(src);
        printf("Unable to create backup file %s.\n", backup_file);
        return;
    }
    char buffer[1024];
    while (fread(buffer, 1, sizeof(buffer), src)) {
        fwrite(buffer, 1, sizeof(buffer), dst);
    }
    fclose(src);
    fclose(dst);

    // Report the success
    printf("File %s backed up successfully to %s.\n",
        watson->file_to_backup, backup_file);
}

int main() {
    // Create our Watson instance
    struct Watson watson;
    watson.backup_dir = "backups";
    watson.file_to_backup = "important.txt";

    // Initiate the backup process
    backup_file(&watson);

    return 0;
}