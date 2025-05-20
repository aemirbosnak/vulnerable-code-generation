//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: imaginative
// Guardians of the Digital Realm: File Backup Odyssey

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Entities:
typedef struct File {
    char name[128];
    char data[10240];
    time_t timestamp;
} File;

// Strongholds:
char sourcePath[128];
char backupPath[128];

// Lore:
int main() {
    // Overture:
    printf("------------------------------------------------\n");
    printf("Guardians of the Digital Realm: File Backup Odyssey\n");
    printf("------------------------------------------------\n");

    // Prologue:
    time_t now;
    time(&now);
    printf("\nTime of Embarkment: %s\n", ctime(&now));

    // Realm Initialization:
    printf("Source Path: ");
    scanf("%s", sourcePath);
    printf("Backup Path: ");
    scanf("%s", backupPath);

    // Reconnaissance:
    FILE *source = fopen(sourcePath, "r");
    if (!source) {
        printf("Source Realm Unreachable!\n");
        return 1;
    }

    // Safekeeping:
    FILE *backup = fopen(backupPath, "w");
    if (!backup) {
        printf("Backup Realm Corrupted!\n");
        return 1;
    }

    // Legendary Artifact:
    File artifact;

    // Quest for Preservation:
    while (fread(&artifact, sizeof(artifact), 1, source)) {
        printf("Protecting: %s\n", artifact.name);
        fwrite(&artifact, sizeof(artifact), 1, backup);
    }

    // Epilogue:
    fclose(source);
    fclose(backup);
    printf("\nFiles Shielded from Digital Perils.\n");

    // Farewell:
    time(&now);
    printf("Time of Triumph: %s\n", ctime(&now));
    printf("------------------------------------------------\n");

    return 0;
}