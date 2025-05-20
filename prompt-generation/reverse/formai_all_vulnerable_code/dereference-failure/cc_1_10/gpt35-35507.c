//FormAI DATASET v1.0 Category: Digital Diary ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// function to read and write data to file
void write_to_file(FILE* diary_file, char* entry) {
    time_t current_time;
    char* timestamp = (char*)malloc(25*sizeof(char));
    char* diary_entry = (char*)malloc((strlen(entry)+50)*sizeof(char)); // extra 50 for timestamp and formatting

    // update timestamp
    current_time = time(NULL);
    sprintf(timestamp, "%s", asctime(localtime(&current_time)));
    timestamp[strlen(timestamp)-1] = '\0';

    // format diary entry
    sprintf(diary_entry, "\n%s\n%s\n", timestamp, entry);

    // write to file
    if(diary_file != NULL) {
        fputs(diary_entry, diary_file);
        printf("\nEntry added to digital diary!\n");
    } else {
        printf("\nCould not write to digital diary file.\n");
    }

    free(timestamp);
    free(diary_entry);
}

int main() {
    FILE* diary_file;
    char* entry = (char*)malloc(250*sizeof(char));
    char* response = (char*)malloc(5*sizeof(char));

    diary_file = fopen("digital_diary.txt", "a+");

    if(diary_file == NULL) {
        printf("\nDigital diary file not found!\nPlease create a file named 'digital_diary.txt' in the current directory.\n");
        exit(0);
    }

    printf("Welcome to your digital diary!\n");

    while(1) {
        printf("\nEnter your diary entry:\n");
        fgets(entry, 250, stdin);

        write_to_file(diary_file, entry);

        printf("\nDo you want to continue? (y/n)\n");
        fgets(response, 5, stdin);

        if(response[0] == 'n') {
            break;
        }
    }

    free(entry);
    free(response);
    fclose(diary_file);

    return 0;
}