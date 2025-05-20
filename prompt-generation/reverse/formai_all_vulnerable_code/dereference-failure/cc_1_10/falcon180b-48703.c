//Falcon-180B DATASET v1.0 Category: File handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_DATA 1000

struct Data {
    int value;
    time_t timestamp;
};

void initData(struct Data* data) {
    for (int i = 0; i < MAX_DATA; i++) {
        data[i].value = 0;
        data[i].timestamp = 0;
    }
}

void addData(struct Data* data, int value) {
    time_t now = time(NULL);
    data[0].value = value;
    data[0].timestamp = now;
    for (int i = 1; i < MAX_DATA; i++) {
        data[i].value = data[i - 1].value;
        data[i].timestamp = data[i - 1].timestamp;
    }
}

void printData(struct Data* data) {
    for (int i = 0; i < MAX_DATA; i++) {
        printf("%d - %ld\n", data[i].value, data[i].timestamp);
    }
}

int main() {
    struct Data data;
    initData(&data);

    int choice;
    do {
        printf("1. Add data\n2. Print data\n3. Exit\n");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                int value;
                printf("Enter value: ");
                scanf("%d", &value);
                addData(&data, value);
                break;
            }
            case 2: {
                printData(&data);
                break;
            }
            case 3: {
                exit(0);
            }
            default: {
                printf("Invalid choice\n");
            }
        }
    } while (choice!= 3);

    return 0;
}