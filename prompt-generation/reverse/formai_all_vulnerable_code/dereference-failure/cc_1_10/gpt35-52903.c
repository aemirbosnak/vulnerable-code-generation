//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_SIZE 256

typedef struct {
    char* name;
    int age;
    char* city;
} Person;

Person* read_csv(char* filename, int* size);
void print_person(Person p);
void print_database(Person* db, int size);

int main(){
    int size = 0;
    Person* database = read_csv("people.csv", &size);

    // Print the database
    printf("======= PEOPLE DATABASE =======\n");
    print_database(database, size);
    
    // Free allocated memory
    for(int i=0; i<size; i++){
        free(database[i].name);
        free(database[i].city);
    }
    free(database);
    
    return 0;
}

Person* read_csv(char* filename, int* size){
    FILE* file = fopen(filename, "r");
    if(file == NULL){
        printf("Error opening file: %s\n", filename);
        exit(1);
    }
    
    // Allocate initial memory
    int capacity = 10;
    Person* database = (Person*) calloc(capacity, sizeof(Person));
    
    char line[MAX_SIZE];
    while(fgets(line, MAX_SIZE, file) != NULL){
        // Resize if necessary
        if((*size) >= capacity){
            capacity *= 2;
            database = (Person*) realloc(database, capacity * sizeof(Person));
        }
        
        // Parse the line
        char* token = strtok(line, ",");
        database[*size].name = (char*) malloc(strlen(token) + 1);
        strcpy(database[*size].name, token);
        token = strtok(NULL, ",");
        database[*size].age = atoi(token);
        token = strtok(NULL, ",");
        database[*size].city = (char*) malloc(strlen(token) + 1);
        strcpy(database[*size].city, token);
        
        (*size)++;
    }
    
    fclose(file);
    return database;
}

void print_person(Person p){
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("City: %s\n", p.city);
    printf("\n");
}

void print_database(Person* db, int size){
    for(int i=0; i<size; i++){
        print_person(db[i]);
    }
}