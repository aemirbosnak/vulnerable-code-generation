//Falcon-180B DATASET v1.0 Category: Data mining ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int id;
    char name[50];
    int age;
} Person;

void read_data(Person *data, int n) {
    FILE *fp = fopen("data.txt", "r");
    for (int i = 0; i < n; i++) {
        fscanf(fp, "%d %s %d", &data[i].id, data[i].name, &data[i].age);
    }
    fclose(fp);
}

void write_data(Person *data, int n, char *filename) {
    FILE *fp = fopen(filename, "w");
    for (int i = 0; i < n; i++) {
        fprintf(fp, "%d %s %d\n", data[i].id, data[i].name, data[i].age);
    }
    fclose(fp);
}

void sort_data(Person *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (data[j].age > data[j + 1].age) {
                Person temp = data[j];
                data[j] = data[j + 1];
                data[j + 1] = temp;
            }
        }
    }
}

void calculate_average_age(Person *data, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += data[i].age;
    }
    double avg_age = (double) sum / n;
    printf("Average age: %.2f\n", avg_age);
}

int main() {
    int n;
    printf("Enter the number of records: ");
    scanf("%d", &n);

    Person *data = (Person *) malloc(n * sizeof(Person));

    read_data(data, n);

    sort_data(data, n);

    printf("Sorted data:\n");
    for (int i = 0; i < n; i++) {
        printf("%d %s %d\n", data[i].id, data[i].name, data[i].age);
    }

    calculate_average_age(data, n);

    free(data);

    return 0;
}