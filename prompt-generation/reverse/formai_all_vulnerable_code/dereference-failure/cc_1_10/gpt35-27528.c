//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: paranoid
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define MAX_LEN 1024 //Maximum length of each CSV field

//Function to count the number of fields in a row
int count_fields(char* row) {
    int count = 0;
    char* field = strtok(row, ",");
    while (field) {
        count++;
        field = strtok(NULL, ",");
    }
    return count;
}

//Function to check if a field has any invalid characters
bool field_check(char* field) {
    for (int i=0; i<strlen(field); i++) {
        char c = field[i];
        if ((c<32 || c>126) && c!='\t' && c!='\r' && c!='\n') { //Invalid characters are ASCII 0-31, 127 and non-printable characters
            return false;
        }
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    char* filename = argv[1];

    FILE* fp = fopen(filename, "r");
    if (!fp) {
        printf("Error: Cannot open file '%s'\n", filename);
        return 1;
    }

    //Processing CSV file line by line
    char line[MAX_LEN];
    int row_num = 0;
    int field_num = 0;
    while (fgets(line, MAX_LEN, fp)) {
        row_num++;

        //Checking if line length exceeds maximum length
        if (strlen(line) == MAX_LEN - 1 && line[MAX_LEN-1] != '\n') {
            printf("Error: Line %d is too long\n", row_num);
            return 1;
        }

        //Checking if number of fields in line is consistent
        int num_fields = count_fields(line);
        if (row_num == 1) {
            field_num = num_fields;
        } else {
            if (num_fields != field_num) {
                printf("Error: Number of fields in line %d is inconsistent with line 1\n", row_num);
                return 1;
            }
        }

        //Processing individual fields in the line
        char* field = strtok(line, ",");
        while (field) {
            //Checking if field has invalid characters
            if (!field_check(field)) {
                printf("Error: Invalid character in field '%s' in line %d\n", field, row_num);
                return 1;
            }
            field = strtok(NULL, ",");
        }
    }

    //File is valid
    printf("CSV file '%s' is valid\n", filename);
    fclose(fp);
    return 0;
}