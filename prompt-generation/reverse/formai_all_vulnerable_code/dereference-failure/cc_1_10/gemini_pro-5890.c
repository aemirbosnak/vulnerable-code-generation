//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Dire backup fairies to dance
#define BACKUP_FAIRY_LETS_DO_THIS (1<<0)
// Dire backup fairies to delete old backups
#define BACKUP_FAIRY_DELETE_PREVIOUS (1<<1)
// Dire backup fairies to pack backups with gzip
#define BACKUP_FAIRY_PACK_WITH_GZIP (1<<2)

// The fairies' favorite chants
typedef enum BackupFairyChants {
    BACKUP_FAIRY_CHANT_START,
    BACKUP_FAIRY_CHANT_FILE_LISTED,
    BACKUP_FAIRY_CHANT_SNAPSHOT_TAKEN,
    BACKUP_FAIRY_CHANT_CLEANUP_DONE,
} BackupFairyChants;

// The backup fairies' mystical dance routine
typedef struct BackupFairyDance {
    char *name;
    int (*dance)(char *, char *, char *, int);
} BackupFairyDance;

// This fairy lists all the files in the given directory
int backup_fairy_list_files(char *dir, char *output, char *prefix, int flags) {
    printf("The backup fairy chants: %s\n", BACKUP_FAIRY_CHANT_FILE_LISTED);
    FILE *fp = popen("ls -1", "r");
    while (fgets(output, 1024, fp) != NULL) {
        printf("%s%s\n", prefix, output);
    }
    pclose(fp);
    return 0;
}

// This fairy takes a snapshot of the files in the given directory using tar
int backup_fairy_take_snapshot(char *dir, char *output, char *prefix, int flags) {
    printf("The backup fairy chants: %s\n", BACKUP_FAIRY_CHANT_SNAPSHOT_TAKEN);
    char command[1024];
    snprintf(command, sizeof(command), "tar cvf %s %s", output, dir);
    system(command);
    return 0;
}

// This fairy packs the snapshot using gzip
int backup_fairy_pack_snapshot(char *dir, char *output, char *prefix, int flags) {
    printf("The backup fairy chants: %s\n", BACKUP_FAIRY_CHANT_FILE_LISTED);
    char command[1024];
    snprintf(command, sizeof(command), "gzip %s", output);
    system(command);
    return 0;
}

// This fairy deletes the previous backups
int backup_fairy_cleanup(char *dir, char *output, char *prefix, int flags) {
    printf("The backup fairy chants: %s\n", BACKUP_FAIRY_CHANT_CLEANUP_DONE);
    char command[1024];
    snprintf(command, sizeof(command), "rm -rf %s", output);
    system(command);
    return 0;
}

// The backup fairies' grand performance
int main(int argc, char *argv[]) {
    // The backup fairies' grand dance routine
    BackupFairyDance backup_fairies[] = {
        {"List Files", backup_fairy_list_files},
        {"Take Snapshot", backup_fairy_take_snapshot},
        {"Pack Snapshot", backup_fairy_pack_snapshot},
        {"Cleanup", backup_fairy_cleanup},
    };

    // Invoke the fairies' dances
    int flags = BACKUP_FAIRY_LETS_DO_THIS | BACKUP_FAIRY_DELETE_PREVIOUS | BACKUP_FAIRY_PACK_WITH_GZIP;
    for (int i = 0; i < sizeof(backup_fairies) / sizeof(BackupFairyDance); i++) {
        backup_fairies[i].dance("/tmp", "/tmp/backup.tar.gz", "", flags);
    }

    return 0;
}