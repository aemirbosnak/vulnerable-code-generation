//FormAI DATASET v1.0 Category: Database Indexing System ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define a struct to hold data for indexing
typedef struct {
    int id;
    char name[50];
    int age;
    char address[100];
} Person;

// define a struct to hold the index information
typedef struct {
    int id;
    long offset;
} IndexEntry;

// define a struct to hold the index
typedef struct {
    int count;
    IndexEntry *entries;
} Index;

// function to read a Person from a binary file at a given offset
Person read_person(FILE *fp, long offset) {
    Person p;
    fseek(fp, offset, SEEK_SET);
    fread(&p, sizeof(Person), 1, fp);
    return p;
}

// function to write a Person to a binary file at the end of the file
long write_person(FILE *fp, Person p) {
    fseek(fp, 0, SEEK_END);
    long offset = ftell(fp);
    fwrite(&p, sizeof(Person), 1, fp);
    return offset;
}

// function to create an index from a binary file
Index create_index(FILE *fp) {
    Index idx;
    idx.count = 0;
    idx.entries = NULL;
    long offset = 0;
    while (1) {
        Person p = read_person(fp, offset);
        if (feof(fp)) {
            break;
        }
        offset += sizeof(Person);
        int found = 0;
        for (int i = 0; i < idx.count; i++) {
            if (idx.entries[i].id == p.id) {
                found = 1;
                break;
            }
        }
        if (!found) {
            idx.count++;
            idx.entries = realloc(idx.entries, idx.count * sizeof(IndexEntry));
            idx.entries[idx.count - 1].id = p.id;
            idx.entries[idx.count - 1].offset = offset - sizeof(Person);
        }
    }
    return idx;
}

// function to print a Person
void print_person(Person p) {
    printf("ID: %d\n", p.id);
    printf("Name: %s\n", p.name);
    printf("Age: %d\n", p.age);
    printf("Address: %s\n", p.address);
}

int main() {
    // create some sample data
    Person p1 = {1, "Alice", 25, "123 Main St."};
    Person p2 = {2, "Bob", 30, "456 High St."};
    Person p3 = {3, "Charlie", 35, "789 Maple Ave."};
    
    // open a binary file for writing and write the sample data to it
    FILE *fp = fopen("data.bin", "wb");
    write_person(fp, p1);
    write_person(fp, p2);
    write_person(fp, p3);
    fclose(fp);
    
    // open the binary file for reading and create an index for it
    fp = fopen("data.bin", "rb");
    Index idx = create_index(fp);
    fclose(fp);
    
    // print the index
    for (int i = 0; i < idx.count; i++) {
        printf("ID: %d, Offset: %ld\n", idx.entries[i].id, idx.entries[i].offset);
    }
    
    // open the binary file for reading, read the data for a given ID, and print it
    fp = fopen("data.bin", "rb");
    int id = 2;
    for (int i = 0; i < idx.count; i++) {
        if (idx.entries[i].id == id) {
            Person p = read_person(fp, idx.entries[i].offset);
            print_person(p);
            break;
        }
    }
    fclose(fp);
    
    return 0;
}