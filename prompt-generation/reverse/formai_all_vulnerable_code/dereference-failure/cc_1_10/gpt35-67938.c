//FormAI DATASET v1.0 Category: Log analysis ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_PLAYERS 10
#define MAX_LINE_LEN 512

typedef struct {
    char name[20];
    int num_messages;
    int num_warnings;
} Player;

void process_line(char *line, Player *players, int *num_players) {
    char name[20];
    char message_type[20];
    char *ptr;
    int i;

    // Extract player name
    ptr = strtok(line, " ");
    strcpy(name, ptr);

    // Find player in list or create new if not found
    for (i = 0; i < *num_players; i++) {
        if (strcmp(players[i].name, name) == 0) {
            break;
        }
    }
    if (i == *num_players) {
        strcpy(players[i].name, name);
        players[i].num_messages = 0;
        players[i].num_warnings = 0;
        (*num_players)++;
    }

    // Extract message type
    ptr = strtok(NULL, " ");
    strcpy(message_type, ptr);

    // Update player's message count based on type
    if (strcmp(message_type, "message") == 0) {
        players[i].num_messages++;
    } else if (strcmp(message_type, "warning") == 0) {
        players[i].num_warnings++;
    }
}

int main() {
    FILE *log_file;
    char line[MAX_LINE_LEN];
    Player players[MAX_PLAYERS];
    int num_players = 0;
    int i;

    // Open log file for reading
    log_file = fopen("game_log.txt", "r");
    if (log_file == NULL) {
        printf("Error opening log file.\n");
        return 1;
    }

    // Read lines from log file and process them
    while (fgets(line, MAX_LINE_LEN, log_file) != NULL) {
        process_line(line, players, &num_players);
    }

    // Print player information
    printf("Num players: %d\n", num_players);
    for (i = 0; i < num_players; i++) {
        printf("%s: messages=%d warnings=%d\n", players[i].name, players[i].num_messages, players[i].num_warnings);
    }

    // Close log file
    fclose(log_file);

    return 0;
}