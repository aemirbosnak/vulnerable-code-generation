//Falcon2-11B DATASET v1.0 Category: Data mining ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[50];
    int age;
    int score;
} data;

void read_data(data *data, FILE *input) {
    char line[100];
    int count = 0;
    while (fgets(line, sizeof(line), input)) {
        if (count == 0) {
            sscanf(line, "%s %d %d", data[count].name, &data[count].age, &data[count].score);
            count++;
        } else {
            printf("Invalid input format: %s\n", line);
            exit(1);
        }
    }
}

void perform_data_mining(data *data) {
    int highest_score = 0;
    int lowest_age = 100;
    int sum = 0;
    for (int i = 0; i < 10; i++) {
        if (data[i].score > highest_score) {
            highest_score = data[i].score;
        }
        if (data[i].age < lowest_age) {
            lowest_age = data[i].age;
        }
        sum += data[i].score;
    }
    printf("Highest score: %d\n", highest_score);
    printf("Lowest age: %d\n", lowest_age);
    printf("Average score: %f\n", (float)sum / 10);
}

void write_data(data *data, FILE *output) {
    for (int i = 0; i < 10; i++) {
        fprintf(output, "%s %d %d\n", data[i].name, data[i].age, data[i].score);
    }
}

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    data data[10];
    read_data(data, input);
    perform_data_mining(data);
    write_data(data, output);
    fclose(input);
    fclose(output);
    return 0;
}