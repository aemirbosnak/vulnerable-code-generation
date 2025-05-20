//GEMINI-pro DATASET v1.0 Category: File Backup System ; Style: retro
// Welcome to the Retro File Backup System!

#include <stdio.h>
#include <stdlib.h>

// Inspired by classic command-line games, let's use a retro style for our program.

// Our trusty cassette tape metaphor for data storage:
typedef struct CassetteTape {
    char **tracks;
    int num_tracks;
} CassetteTape;

// Let's define some basic commands for our system:
enum Command {
    BACKUP, RESTORE, LIST, EXIT
};

// A function to print our retro-style command prompt:
void print_prompt() {
    printf("\n\033[1;32mRetro File Backup System>\033[0m ");
}

// Here's where the file backup magic happens:
int backup_file(char *file_name, CassetteTape *tape) {
    FILE *file = fopen(file_name, "rb");
    if (!file) {
        printf("Error opening file %s!\n", file_name);
        return -1;
    }
    
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    rewind(file);
    
    char *data = malloc(file_size);
    fread(data, 1, file_size, file);
    fclose(file);
    
    tape->tracks = realloc(tape->tracks, (tape->num_tracks + 1) * sizeof(char *));
    tape->tracks[tape->num_tracks] = data;
    tape->num_tracks++;
    
    printf("File backed up successfully to Cassette Track %d!\n", tape->num_tracks);
    return 0;
}

// Load a file from the cassette tape back onto the disk:
int restore_file(char *file_name, CassetteTape *tape, int track) {
    if (track < 0 || track >= tape->num_tracks) {
        printf("Invalid track number %d!\n", track);
        return -1;
    }
    
    FILE *file = fopen(file_name, "wb");
    if (!file) {
        printf("Error opening file %s for writing!\n", file_name);
        return -1;
    }
    
    fwrite(tape->tracks[track], 1, strlen(tape->tracks[track]), file);
    fclose(file);
    
    printf("File restored successfully from Cassette Track %d!\n", track);
    return 0;
}

// Display a list of all files stored on the cassette tape:
void list_files(CassetteTape *tape) {
    if (tape->num_tracks == 0) {
        printf("No files have been backed up yet!\n");
    } else {
        printf("Files stored on Cassette Tracks:\n");
        for (int i = 0; i < tape->num_tracks; i++) {
            printf("  Track %d: %s\n", i, tape->tracks[i]);
        }
    }
}

// Main loop to handle user commands:
int main() {
    // Create a new CassetteTape to store our files:
    CassetteTape tape = {NULL, 0};
    
    char command[20];
    int track;
    char file_name[50];
    
    while (1) {
        print_prompt();
        scanf("%s", command);
        
        switch (command[0]) {
            case 'B':
            case 'b':
                printf("Enter file name to backup: ");
                scanf("%s", file_name);
                backup_file(file_name, &tape);
                break;
            
            case 'R':
            case 'r':
                printf("Enter file name to restore: ");
                scanf("%s", file_name);
                printf("Enter track number: ");
                scanf("%d", &track);
                restore_file(file_name, &tape, track);
                break;
            
            case 'L':
            case 'l':
                list_files(&tape);
                break;
            
            case 'E':
            case 'e':
                printf("Exiting Retro File Backup System...\n");
                exit(0);
                break;
            
            default:
                printf("Invalid command!\n");
                break;
        }
    }
    
    return 0;
}