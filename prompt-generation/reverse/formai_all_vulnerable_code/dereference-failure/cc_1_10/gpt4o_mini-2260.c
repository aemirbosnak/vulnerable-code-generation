//GPT-4o-mini DATASET v1.0 Category: Antivirus scanner ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <pthread.h>

#define MAX_PLAYERS 4
#define MAX_FILENAME_LENGTH 256
#define MAX_VIRUS_SIG 10

// Simple structure to hold player information
typedef struct {
    int player_id;
    char directory[MAX_FILENAME_LENGTH];
    int found_viruses;
    char *virus_signatures[MAX_VIRUS_SIG];
    int total_files_scanned;
} Player;

// Function declarations
void* scan_directory(void* arg);
int check_file_for_viruses(const char* filename, Player* player);
int is_virus_signature(const char* buffer, Player* player);

// Sample virus signatures
char* virus_signatures[MAX_VIRUS_SIG] = {
    "VIRUS_A",
    "VIRUS_B",
    "VIRUS_C",
    "VIRUS_D",
    "VIRUS_E",
    "VIRUS_F",
    "VIRUS_G",
    "VIRUS_H",
    "VIRUS_I",
    "VIRUS_J"
};

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <directory>\n", argv[0]);
        return 1;
    }

    pthread_t threads[MAX_PLAYERS];
    Player players[MAX_PLAYERS];
    int player_count = MAX_PLAYERS;

    // Initialize players
    for (int i = 0; i < player_count; i++) {
        players[i].player_id = i + 1;
        strncpy(players[i].directory, argv[1], MAX_FILENAME_LENGTH);
        players[i].found_viruses = 0;
        players[i].total_files_scanned = 0;

        // Assign virus signatures
        for (int j = 0; j < MAX_VIRUS_SIG; j++) {
            players[i].virus_signatures[j] = virus_signatures[j];
        }

        // Create a thread for each player
        pthread_create(&threads[i], NULL, scan_directory, &players[i]);
    }

    // Wait for all players to finish scanning
    for (int i = 0; i < player_count; i++) {
        pthread_join(threads[i], NULL);
    }

    // Summary of results
    printf("Scanning completed.\n");
    for (int i = 0; i < player_count; i++) {
        printf("Player %d scanned %d files and found %d viruses.\n",
               players[i].player_id, players[i].total_files_scanned, players[i].found_viruses);
    }

    return 0;
}

void* scan_directory(void* arg) {
    Player* player = (Player*)arg;
    DIR* dir;
    struct dirent* entry;
    char filepath[MAX_FILENAME_LENGTH];

    if ((dir = opendir(player->directory)) == NULL) {
        perror("Unable to scan directory");
        return NULL;
    }

    while ((entry = readdir(dir)) != NULL) {
        // Skip '.', '..', and hidden files
        if (entry->d_name[0] == '.' || entry->d_type != DT_REG) {
            continue;
        }

        // Build the full path to the file
        snprintf(filepath, sizeof(filepath), "%s/%s", player->directory, entry->d_name);

        // Check the file for viruses
        if (check_file_for_viruses(filepath, player)) {
            printf("Player %d found a virus in file: %s\n", player->player_id, filepath);
            player->found_viruses++;
        }
        player->total_files_scanned++;
    }

    closedir(dir);
    return NULL;
}

int check_file_for_viruses(const char* filename, Player* player) {
    FILE* file = fopen(filename, "r");
    char buffer[1024];
    int found = 0;

    if (!file) {
        perror("Unable to open file");
        return 0;
    }

    while (fgets(buffer, sizeof(buffer), file)) {
        if (is_virus_signature(buffer, player)) {
            found = 1;
            break;
        }
    }

    fclose(file);
    return found;
}

int is_virus_signature(const char* buffer, Player* player) {
    for (int i = 0; i < MAX_VIRUS_SIG; i++) {
        if (strstr(buffer, player->virus_signatures[i]) != NULL) {
            return 1; // Found a virus signature
        }
    }
    return 0; // No virus signature found
}