//Falcon2-11B DATASET v1.0 Category: Digital Diary ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_ENTRY_LEN 80
#define MAX_FILE_LEN 1000000

typedef struct {
    char entry[MAX_ENTRY_LEN];
    int timestamp;
} Entry;

int main(int argc, char *argv[]) {
    if (argc!= 2) {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(1);
    }
    
    char filename[MAX_FILE_LEN];
    strcpy(filename, argv[1]);
    
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        exit(1);
    }
    
    int i;
    for (i = 0; i < 10; i++) {
        char date[10];
        time_t t;
        struct tm *tm;
        
        time(&t);
        tm = localtime(&t);
        strftime(date, sizeof(date), "%m-%d-%y %H:%M:%S", tm);
        
        Entry entry;
        entry.timestamp = i;
        strcpy(entry.entry, date);
        fputs(entry.entry, file);
        fputs("\n", file);
    }
    
    fclose(file);
    
    return 0;
}