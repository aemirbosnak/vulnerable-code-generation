//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    // Our story begins with two lovers, Romeo and Juliet.
    char romeo[] = "Romeo.txt";
    char juliet[] = "Juliet.txt";

    // They have whispered sweet nothings to each other in these files.
    FILE *romeo_file = fopen(romeo, "r");
    FILE *juliet_file = fopen(juliet, "r");

    if (romeo_file == NULL || juliet_file == NULL) {
        // Alas, their love was short-lived.
        printf("Oh, cruel fate! The files could not be opened.\n");
        return EXIT_FAILURE;
    }

    // But fear not, for Friar Laurence, the wise old priest,
    // has a plan to safeguard their precious words.

    // He creates a secret sanctuary, a backup file,
    // where their love will be preserved for all eternity.
    FILE *backup_file = fopen("TheSecretSanctuary.txt", "w");

    if (backup_file == NULL) {
        // A tragic twist! The backup file could not be created.
        printf("Alas, the backup file could not be created.\n");
        return EXIT_FAILURE;
    }

    // Friar Laurence carefully copies every line,
    // from Romeo's passionate whispers to Juliet's tender replies.
    char line[1024];
    while (fgets(line, sizeof(line), romeo_file) != NULL) {
        fputs(line, backup_file);
    }
    while (fgets(line, sizeof(line), juliet_file) != NULL) {
        fputs(line, backup_file);
    }

    // With the backup complete, Friar Laurence smiles,
    // knowing that their love will endure even the darkest of nights.
    printf("Their love is safe, forevermore.\n");

    // He closes the sacred tomes,
    // his heart filled with hope for the star-crossed lovers.
    fclose(romeo_file);
    fclose(juliet_file);
    fclose(backup_file);

    return EXIT_SUCCESS;
}