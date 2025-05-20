//FormAI DATASET v1.0 Category: System event logger ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct{
    char* message;
    char* date;
}Log;

void add_entry(Log* logs, char* message){
    time_t current_time = time(NULL);
    char* date = asctime(localtime(&current_time));
    logs = (Log*) realloc(logs, sizeof(Log) * (strlen(logs) + 1));
    logs[strlen(logs)].date = date;
    logs[strlen(logs)].message = message;
}

void view_log(Log* logs){
    printf("**** C System Event Logger ****\n");
    for(int i = 0; i < strlen(logs); i++){
        printf("%s: %s\n", logs[i].date, logs[i].message);
    }
}

void write_log(Log* logs){
    FILE* file = fopen("log.txt", "a");
    for(int i = 0; i < strlen(logs); i++){
        fprintf(file, "%s: %s\n", logs[i].date, logs[i].message);
    }
    fclose(file);
}

int main(){
    Log* logs = (Log*) malloc(sizeof(Log));
    char* message = (char*) malloc(100*sizeof(char));
    int input;

    printf("**** C System Event Logger ****\n");
    while(1){
        printf("What would you like to do?\n");
        printf("1. Add a log entry\n");
        printf("2. View log entries\n");
        printf("3. Write log to file\n");
        printf("4. Exit\n");
        scanf("%d", &input);

        switch(input){
            case 1:
                printf("Enter message: ");
                scanf(" %[^\n]s", message);
                add_entry(logs, message);
                printf("Successfully added entry!\n\n");
                break;
            case 2:
                view_log(logs);
                printf("\n");
                break;
            case 3:
                write_log(logs);
                printf("Successfully wrote log to file!\n\n");
                break;
            case 4:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid input. Please try again.\n\n");
                break;
        }
    }

    free(message);
    free(logs);

    return 0;
}