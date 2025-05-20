//GEMINI-pro DATASET v1.0 Category: Database Indexing System ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct IndexEntry {
    char *key;
    int offset;
};

struct Database {
    int numEntries;
    struct IndexEntry *index;
    char *data;
};

void createDatabase(struct Database *db) {
    db->numEntries = 0;
    db->index = NULL;
    db->data = NULL;
}

void destroyDatabase(struct Database *db) {
    free(db->index);
    free(db->data);
}

int addEntry(struct Database *db, char *key, char *data) {
    int offset = db->numEntries;
    db->numEntries++;
    db->index = realloc(db->index, db->numEntries * sizeof(struct IndexEntry));
    if (!db->index) {
        return -1;
    }
    db->index[offset].key = strdup(key);
    if (!db->index[offset].key) {
        return -1;
    }
    db->index[offset].offset = offset;
    db->data = realloc(db->data, strlen(data) + 1);
    if (!db->data) {
        return -1;
    }
    strcpy(db->data + offset, data);
    return 0;
}

char *getEntry(struct Database *db, char *key) {
    int i;
    for (i = 0; i < db->numEntries; i++) {
        if (strcmp(db->index[i].key, key) == 0) {
            return db->data + db->index[i].offset;
        }
    }
    return NULL;
}

int main() {
    struct Database db;
    createDatabase(&db);
    addEntry(&db, "hello", "world");
    addEntry(&db, "foo", "bar");
    printf("%s\n", getEntry(&db, "hello"));
    printf("%s\n", getEntry(&db, "foo"));
    destroyDatabase(&db);
    return 0;
}