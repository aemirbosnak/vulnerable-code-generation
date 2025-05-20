//MISTRAL-7B DATASET v1.0 Category: Text processing ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define TAB "\t"
typedef struct {
    int number;
    char *string;
} Data;
void swap(Data *a, Data *b) {
    int temp = a->number;
    char *temp_str = a->string;
    a->number = b->number;
    a->string = b->string;
    b->number = temp;
    b->string = temp_str;
}
int compare(const void *a, const void *b) {
    Data *data_a = (Data *)a;
    Data *data_b = (Data *)b;
    return data_a->number - data_b->number;
}
int main() {
    FILE *file = fopen("input.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return 1;
    }
    Data *data = NULL;
    size_t num_elements = 0;
    size_t capacity = 1;
    data = (Data *)malloc(capacity * sizeof(Data));
    char line[1024];
    while (fgets(line, sizeof(line), file)) {
        char *token = strtok(line, TAB);
        int number = atoi(token);
        capacity *= 2;
        data = (Data *)realloc(data, capacity * sizeof(Data));
        data[num_elements].number = number;
        token = strtok(NULL, TAB);
        data[num_elements].string = strdup(token);
        num_elements++;
    }
    qsort(data, num_elements, sizeof(Data), compare);
    printf("Sorted integers:\n");
    for (size_t i = 0; i < num_elements; i++) {
        printf("%d\t%s\n", data[i].number, data[i].string);
    }
    for (size_t i = 0; i < num_elements; i++) {
        free(data[i].string);
    }
    free(data);
    fclose(file);
    return 0;
}