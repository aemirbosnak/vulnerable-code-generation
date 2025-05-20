//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_JSON_SIZE 1024
#define MAX_KEY_SIZE 256
#define MAX_VALUE_SIZE 256

typedef struct json_value{
    char key[MAX_KEY_SIZE];
    char value[MAX_VALUE_SIZE];
} json_value;

typedef struct json{
    json_value* values;
    int count;
} json;

char* read_json_file(char* filename){
    FILE* fp;
    char* buffer;
    long file_size;

    fp = fopen(filename, "r");
    if(fp == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    fseek(fp, 0, SEEK_END);
    file_size = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    buffer = (char*) malloc(file_size + 1);
    if(buffer == NULL){
        printf("Unable to allocate memory\n");
        exit(1);
    }

    fread(buffer, file_size, 1, fp);
    fclose(fp);

    buffer[file_size] = '\0';

    return buffer;
}

json parse_json(char* json_string){
    json j = {};
    j.values = (json_value*) malloc(MAX_JSON_SIZE * sizeof(json_value));
    if(j.values == NULL){
        printf("Unable to allocate memory\n");
        exit(1);
    }

    int json_index = 0, value_index = 0, in_string = 0, i;

    while(json_string[json_index]){
        if(json_string[json_index] == '\"'){
            in_string = in_string == 0 ? 1 : 0;
            if(in_string == 0){
                j.values[j.count].value[value_index] = '\0';
                j.count++;
                value_index = 0;
            }
        }else{
            if(in_string){
                j.values[j.count].value[value_index++] = json_string[json_index];
            }else if(json_string[json_index] != ':' && json_string[json_index] != '{' && json_string[json_index] != '}' && json_string[json_index] != '[' && json_string[json_index] != ']' && json_string[json_index] != ',' && json_string[json_index] != ' '){
                j.values[j.count].key[value_index++] = json_string[json_index];
            }
        }
        json_index++;
    }

    return j;
}

int main(){
    char json_string[MAX_JSON_SIZE];
    json j;
    int i;

    strcpy(json_string, read_json_file("example.json"));

    j = parse_json(json_string);

    for(i=0;i<j.count;i++){
        printf("%s : %s\n", j.values[i].key, j.values[i].value);
    }

    free(j.values);

    return 0;
}