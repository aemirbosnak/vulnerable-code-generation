//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: futuristic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_FILENAME_LENGTH 20
#define MAX_FILE_SIZE 1024

typedef struct virus{
    char* name;
    char* signature;
    struct virus* next;
}Virus;

void scan_file(char* filename, Virus* virus_list);
void print_virus_list(Virus* virus_list);
void free_virus_list(Virus* virus_list);

int main(){
    Virus* virus_list = NULL;
    Virus* virus1 = (Virus*)malloc(sizeof(Virus));
    virus1->name = "Virus 1";
    virus1->signature = "4D5A90000300000004000000FFFF";
    virus_list = virus1;
    Virus* virus2 = (Virus*)malloc(sizeof(Virus));
    virus2->name = "Virus 2";
    virus2->signature = "FFD8FFE000104A46494600010101006000600000FFDB0043000";
    virus2->next = NULL;
    virus1->next = virus2;

    printf("Welcome to the futuristic C Antivirus Scanner!\n");
    char filename[MAX_FILENAME_LENGTH];
    printf("Enter the name of the file you want to scan: ");
    fgets(filename, MAX_FILENAME_LENGTH, stdin);
    filename[strcspn(filename, "\n")] = '\0';
    printf("Scanning file '%s'...\n", filename);
    scan_file(filename, virus_list);
    printf("Scan completed!\n");
    print_virus_list(virus_list);
    free_virus_list(virus_list);

    return 0;
}

void scan_file(char* filename, Virus* virus_list){
    FILE* file = fopen(filename, "rb");
    if(file == NULL){
        printf("Failed to open file '%s'!\n", filename);
        return;
    }
    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    if(size > MAX_FILE_SIZE){
        printf("File size too large!\n");
        fclose(file);
        return;
    }
    rewind(file);
    char* contents = (char*)malloc(sizeof(char) * size);
    fread(contents, 1, size, file);
    for(int i = 0; i < size; i++){
        for(Virus* curr = virus_list; curr != NULL; curr = curr->next){
            if(memcmp(&contents[i], curr->signature, strlen(curr->signature)) == 0){
                printf("File '%s' contains virus '%s'\n", filename, curr->name);
                break;
            }
        }
    }
    fclose(file);
    free(contents);
}

void print_virus_list(Virus* virus_list){
    printf("Virus List:\n");
    for(Virus* curr = virus_list; curr != NULL; curr = curr->next){
        printf("Name: %s\n", curr->name);
        printf("Signature: %s\n", curr->signature);
    }
}

void free_virus_list(Virus* virus_list){
    Virus* next;
    for(Virus* curr = virus_list; curr != NULL; curr = next){
        next = curr->next;
        free(curr);
    }
}