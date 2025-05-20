//MISTRAL-7B DATASET v1.0 Category: Educational ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <ctype.h>
#include <math.h>

typedef struct {
    char name[256];
    int age;
} Person;

void reverse_string(char* str) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; ++i) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

Person create_person(char* name, int age) {
    Person person;
    strcpy(person.name, name);
    person.age = age;
    return person;
}

void print_person(Person p) {
    printf("%s is %d years old.\n", p.name, p.age);
}

void print_reverse_string(char* str) {
    reverse_string(str);
    printf("%s\n", str);
}

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s <name> <age>\n", argv[0]);
        return 1;
    }

    Person p = create_person(argv[1], atoi(argv[2]));

    char name_copy[strlen(argv[1]) + 1];
    strcpy(name_copy, argv[1]);

    print_person(p);
    print_reverse_string(name_copy);

    FILE* fp = fopen("output.txt", "w");
    if (fp == NULL) {
        perror("Error opening output file");
        return 1;
    }

    fprintf(fp, "%s is %d years old.\n", argv[1], atoi(argv[2]));
    fclose(fp);

    mkdir("new_dir", 0777);

    double pi = M_PI;
    double x = sqrt(5);

    int random_num = rand();

    printf("Pi: %.2f\n", pi);
    printf("Square root of 5: %.2f\n", x);
    printf("Random number: %d\n", random_num);

    return 0;
}