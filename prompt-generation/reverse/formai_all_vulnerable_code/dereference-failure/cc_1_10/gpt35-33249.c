//FormAI DATASET v1.0 Category: Digital Diary ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <stdbool.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

#define MAX_ENTRY_LENGTH 500

void add_entry_to_file(char* entry, char* filename){
    // Appends an entry to a file with the given filename.
    FILE* fp = fopen(filename, "a");
    fprintf(fp, "%s\n", entry);
    fclose(fp);
}

bool file_exists(char* filename){
    // Returns true if a file with the given filename exists, otherwise false.
    if(access(filename, F_OK) != -1){
        return true;
    }
    return false;
}

void create_file(char* filename){
    // Creates an empty file with the given filename.
    int file_descriptor = open(filename, O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR);
    close(file_descriptor);
}

void print_entries(char* filename){
    // Prints all entries in the file with the given filename.
    FILE* fp = fopen(filename, "r");
    char entry[MAX_ENTRY_LENGTH];
    while(fgets(entry, MAX_ENTRY_LENGTH, fp)){
        printf("%s", entry);
    }
    fclose(fp);
}

int main(){
    char* filename = "diary.txt";
    
    if(!file_exists(filename)){
        create_file(filename);
    }

    char entry[MAX_ENTRY_LENGTH];
    char* date_string;
    time_t current_time;
    struct tm* time_info;

    while(true){
        printf("Enter a new diary entry (type 'exit' to quit):\n");
        fgets(entry, MAX_ENTRY_LENGTH, stdin);

        if(strcmp(entry, "exit\n") == 0){
            break;
        }

        time(&current_time);
        time_info = localtime(&current_time);
        date_string = asctime(time_info);
        date_string[strlen(date_string) - 1] = '\0';

        char entry_with_date[MAX_ENTRY_LENGTH];
        strcpy(entry_with_date, "[");
        strcat(entry_with_date, date_string);
        strcat(entry_with_date, "] ");
        strcat(entry_with_date, entry);

        add_entry_to_file(entry_with_date, filename);

        printf("\nEntries:\n");
        print_entries(filename);
        printf("\n");
    }

    return 0;
}