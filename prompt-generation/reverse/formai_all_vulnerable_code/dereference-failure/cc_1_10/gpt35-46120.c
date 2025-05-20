//FormAI DATASET v1.0 Category: File Backup System ; Style: authentic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char* get_time(){
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    char *time_str = malloc(sizeof(char)*20);
    strftime(time_str, 20, "%Y_%m_%d_%H:%M:%S", tm);
    return time_str;
}

void write_to_backup(char* src_file, char* backup_loc){
    FILE* src = fopen(src_file, "rb");
    if(src == NULL){
        printf("Error: Unable to open the file %s", src_file);
        return;
    }

    char* backup_name = malloc(sizeof(char)*(strlen(backup_loc)+40));
    sprintf(backup_name, "%s/%s_backup_%s", backup_loc, src_file, get_time());
    FILE* backup = fopen(backup_name, "wb");
    if(backup == NULL){
        printf("Error: Unable to create backup file");
        fclose(src);
        return;
    }

    char buffer[1024];
    size_t nread;
    while((nread = fread(buffer, sizeof(char), 1024, src)) > 0){
        fwrite(buffer, sizeof(char), nread, backup);
    }

    fclose(src);
    fclose(backup);
    printf("Backup created successfully: %s", backup_name);
}

int main(){
    char src_file[100];
    char backup_loc[100];

    printf("Enter the file to be backed up: ");
    fgets(src_file, 100, stdin);
    src_file[strcspn(src_file, "\n")] = 0;

    printf("Enter the location to store the backup: ");
    fgets(backup_loc, 100, stdin);
    backup_loc[strcspn(backup_loc, "\n")] = 0;

    write_to_backup(src_file, backup_loc);
    
    return 0;
}