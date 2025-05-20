//FormAI DATASET v1.0 Category: Database Indexing System ; Style: single-threaded
#define MAX_LENGTH 100

typedef struct {
  int id;
  char name[MAX_LENGTH];
  char address[MAX_LENGTH];
} Record;

typedef struct {
  Record* records;
  int num_records;
} Database;

typedef struct {
  int* keys;
  int num_keys;
} Index;

Database create_database(int num_records) {
  Database db;
  db.records = malloc(num_records * sizeof(Record));
  db.num_records = num_records;
  return db;
}

void insert_record(Database* db, Record new_record) {
  db->records[db->num_records] = new_record;
  db->num_records++;
}

Index create_index(int num_keys) {
  Index index;
  index.keys = malloc(num_keys * sizeof(int));
  index.num_keys = num_keys;
  return index;
}

void insert_index(Index* index, int key) {
  index->keys[index->num_keys] = key;
  index->num_keys++;
}

void index_database(Database* db, Index* index) {
  for (int i = 0; i < db->num_records; i++) {
    insert_index(index, db->records[i].id);
  }
}

int search_database(Database db, int target_id) {
  for (int i = 0; i < db.num_records; i++) {
    if (db.records[i].id == target_id) {
      return i;
    }
  }
  return -1;
}

int search_index(Index index, int target_id) {
  for (int i = 0; i < index.num_keys; i++) {
    if (index.keys[i] == target_id) {
      return i;
    }
  }
  return -1;
}

int main() {
  Database db = create_database(5);
  insert_record(&db, (Record){1, "John Smith", "123 Main St"});
  insert_record(&db, (Record){2, "Jane Doe", "456 Elm St"});
  insert_record(&db, (Record){3, "Bob Johnson", "789 Oak St"});
  insert_record(&db, (Record){4, "Alice Adams", "321 Pine St"});
  insert_record(&db, (Record){5, "Charlie Brown", "654 Maple St"});
  
  Index index = create_index(db.num_records);
  index_database(&db, &index);
  
  int target_id = 4;
  int index_position = search_index(index, target_id);
  if (index_position != -1) {
    int db_position = index.keys[index_position];
    printf("Record found: %d %s %s\n", db.records[db_position].id, db.records[db_position].name, db.records[db_position].address);
  } else {
    int db_position = search_database(db, target_id);
    if (db_position != -1) {
      printf("Record found: %d %s %s\n", db.records[db_position].id, db.records[db_position].name, db.records[db_position].address);
    } else {
      printf("Record not found\n");
    }
  }
  
  return 0;
}