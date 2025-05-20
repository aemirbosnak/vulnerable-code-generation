//FormAI DATASET v1.0 Category: Phone Book ; Style: asynchronous
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>

#define MAX_ENTRIES 1000

struct phonebook_entry{
    char name[50];
    char number[20];
};

struct phonebook_entry* phonebook[MAX_ENTRIES];

int num_entries = 0;

typedef void (*callback)(void*);

void add_entry(char* name, char* number, callback cb){
    if(num_entries >= MAX_ENTRIES){
        printf("Phonebook has reached its maximum capacity\n");
        cb(NULL);
        return;
    }
    struct phonebook_entry* entry = (struct phonebook_entry*)malloc(sizeof(struct phonebook_entry));
    strcpy(entry->name, name);
    strcpy(entry->number, number);
    phonebook[num_entries++] = entry;
    cb(entry);
}

void search_by_name(char* name, callback cb){
    for(int i=0; i<num_entries; i++){
        if(strcmp(phonebook[i]->name, name) == 0){
            cb(phonebook[i]);
            return;
        }
    }
    cb(NULL);
}

void search_by_number(char* number, callback cb){
    for(int i=0; i<num_entries; i++){
        if(strcmp(phonebook[i]->number, number) == 0){
            cb(phonebook[i]);
            return;
        }
    }
    cb(NULL);
}

void delete_entry_by_name(char* name, callback cb){
    for(int i=0; i<num_entries; i++){
        if(strcmp(phonebook[i]->name, name) == 0){
            struct phonebook_entry* entry = phonebook[i];
            for(int j=i+1; j<num_entries; j++){
                phonebook[j-1] = phonebook[j];
            }
            num_entries--;
            cb(entry);
            return;
        }
    }
    cb(NULL);
}

void print_entry(struct phonebook_entry* entry){
    if(entry == NULL){
        printf("Entry not found\n");
        return;
    }
    printf("Name: %s\nPhone Number: %s\n", entry->name, entry->number);
}

void save_to_file(char* filename, callback cb){
    FILE* file = fopen(filename, "w");
    if(file == NULL){
        perror("Error opening file");
        cb(NULL);
        return;
    }
    for(int i=0; i<num_entries; i++){
        fprintf(file, "%s,%s\n", phonebook[i]->name, phonebook[i]->number);
    }
    fclose(file);
    cb(NULL);
}

void read_from_file(char* filename, callback cb){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        perror("Error opening file");
        cb(NULL);
        return;
    }
    char line[100];
    while(fgets(line, 100, file) != NULL){
        char* name = strtok(line, ",");
        char* number = strtok(NULL, "\n");
        add_entry(name, number, NULL);
    }
    fclose(file);
    cb(NULL);
}

int main(){

    add_entry("Alice", "123-4567", print_entry);
    add_entry("Bob", "234-5678", print_entry);

    search_by_name("Alice", print_entry);
    search_by_number("234-5678", print_entry);

    delete_entry_by_name("Bob", print_entry);

    save_to_file("phonebook.csv", print_entry);

    read_from_file("phonebook.csv", print_entry);

    return 0;
}