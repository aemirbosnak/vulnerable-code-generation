//FormAI DATASET v1.0 Category: Database Indexing System ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 100
#define KEY_SIZE 20

typedef struct Row{
    char key[KEY_SIZE];
    char** data;
} Row;

Row* database[MAX_ROWS];

int num_rows = 0;
int num_columns = 0;

void print_database();

int binary_search(char* key) {
    int start = 0;
    int end = num_rows - 1;
    int mid;
    
    while(start <= end){
        mid = (start + end)/2;
        if(strcmp(database[mid]->key, key) == 0){
            return mid;
        }
        else if(strcmp(database[mid]->key, key) < 0){
            start = mid + 1;
        }
        else{
            end = mid - 1;
        }
    }
    return -1;
}

void insert_row(char* key, char** data) {
    Row* new_row = malloc(sizeof(Row));
    strcpy(new_row->key, key);
    new_row->data = malloc(sizeof(char*)*num_columns);
    for(int i=0; i<num_columns; i++){
        new_row->data[i] = malloc(sizeof(char)*100);
        strcpy(new_row->data[i], data[i]);
    }
    int index = binary_search(key);
    if(index == -1){
        index = num_rows;
        num_rows++;
    }
    database[index] = new_row;
}

void insert_column(char* column_name) {
    num_columns++;
    for(int i=0; i<num_rows; i++){
        database[i]->data = realloc(database[i]->data, sizeof(char*)*num_columns);
        database[i]->data[num_columns-1] = malloc(sizeof(char)*100);
        strcpy(database[i]->data[num_columns-1], "NULL");
    }
}

void update_cell(char* key, char* column_name, char* cell_data) {
    int row_index = binary_search(key);
    if(row_index != -1){
        for(int i=0; i<num_columns; i++){
            if(strcmp(column_name, database[row_index]->data[i]) == 0){
                strcpy(database[row_index]->data[i], cell_data);
            }
        }
    }
}

void print_database() {
    printf("\n\n");
    for(int i=0; i<num_columns; i++){
        printf("%-20s", database[0]->data[i]);
    }
    printf("\n\n");
    for(int i=0; i<num_rows; i++) {
        printf("%-20s", database[i]->key);
        for(int j=0; j<num_columns; j++){
            printf("%-20s", database[i]->data[j]);
        }
        printf("\n\n");
    }
}

void delete_row(char* key) {
    int index = binary_search(key);
    if(index != -1){
        free(database[index]);
        for(int i=index+1; i<num_rows; i++){
            database[i-1] = database[i];
        }
        num_rows--;
    }
}

int main() {
    insert_column("Name");
    insert_column("Age");
    insert_column("City");
    char *data[] = {"John", "23", "New York"};
    char *data1[] = {"Lucas", "34", "Paris"};
    char *data2[] = {"Marco", "30", "Milan"};
    insert_row("A001", data);
    insert_row("A003", data2);
    insert_row("A002", data1);
    print_database();
    printf("Delete row A001\n");
    delete_row("A001");
    print_database();
    printf("Update age of Marco\n");
    update_cell("A003", "Age", "31");
    print_database();
    return 0;
}