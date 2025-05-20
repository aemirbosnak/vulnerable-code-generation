//FormAI DATASET v1.0 Category: Building a JSON Parser ; Style: retro
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/*define the JSON structure*/
typedef struct {
    char name[30];
    int age;
    char gender[10];
    char occupation[30];
} person;

int main() {
    char jsonstr[1000];
    FILE *fp;
    fp = fopen("person.json", "r");
    fgets(jsonstr, 1000, fp); /*read the json file into a string*/

    /*parse the string into json format*/
    char *start_str, *end_str;
    start_str = strstr(jsonstr, "{");
    end_str = strstr(jsonstr, "}");
    if(!start_str || !end_str) {
        printf("Invalid JSON format");
        exit(1);
    }
    int json_len = end_str - start_str + 1;
    char json[json_len + 1];
    strncpy(json, start_str, json_len);
    json[json_len] = '\0';

    /*parse the json into a person structure*/
    person p;
    char *tok;
    tok = strtok(json, ",\"");
    while(tok) {
        if(strcmp(tok, "name") == 0) {
            tok = strtok(NULL, ",\"");
            strcpy(p.name, tok);
        }
        else if(strcmp(tok, "age") == 0) {
            tok = strtok(NULL, ",\"");
            p.age = atoi(tok);
        }
        else if(strcmp(tok, "gender") == 0) {
            tok = strtok(NULL, ",\"");
            strcpy(p.gender, tok);
        }
        else if(strcmp(tok, "occupation") == 0) {
            tok = strtok(NULL, ",\"");
            strcpy(p.occupation, tok);
        }
        tok = strtok(NULL, ",\"");
    }

    /*print the person structure*/
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Gender: %s\n", p.gender);
    printf("Occupation: %s\n", p.occupation);
    fclose(fp);
    return 0;
}