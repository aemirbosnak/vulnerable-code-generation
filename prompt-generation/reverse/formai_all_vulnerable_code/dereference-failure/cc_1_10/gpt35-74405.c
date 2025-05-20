//FormAI DATASET v1.0 Category: Database simulation ; Style: multi-threaded
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FIELDS 10 // maximum number of fields in a record
#define MAX_RECORDS 100 // maximum number of records in a table

struct field {
    char name[20];
    char type[10];
};

struct record {
    char** values;
};

struct table {
    char name[20];
    struct field fields[MAX_FIELDS];
    int num_fields;
    struct record records[MAX_RECORDS];
    int num_records;
};

struct database {
    struct table tables[10];
    int num_tables;
};

struct query {
    struct database* db;
    char* statement;
};

void execute_query(struct query* q) {
    // parse statement and perform appropriate action
    // create table or insert or select etc.
    if (strstr(q->statement, "CREATE TABLE")) {
        // extract table name and field names and types
        char* saveptr1, * saveptr2;
        char* token1 = strtok_r(q->statement, " ", &saveptr1); // CREATE
        token1 = strtok_r(NULL, " ", &saveptr1); // TABLE
        char* table_name = strtok_r(NULL, " ", &saveptr1);
        struct table new_table;
        strcpy(new_table.name, table_name);
        
        char* token2 = strtok_r(NULL, "()", &saveptr1);
        int i = 0;
        while (token2 != NULL) {
            char* field_name = strtok_r(token2, " ", &saveptr2);
            char* field_type = strtok_r(NULL, " ", &saveptr2);
            strcpy(new_table.fields[i].name, field_name);
            strcpy(new_table.fields[i].type, field_type);
            i++;
            token2 = strtok_r(NULL, "()", &saveptr1);
        }
        new_table.num_fields = i;
        q->db->tables[q->db->num_tables++] = new_table;
    } else if (strstr(q->statement, "INSERT INTO")) {
        // extract table name and values for fields
        char* saveptr1, * saveptr2;
        char* token1 = strtok_r(q->statement, " ", &saveptr1); // INSERT
        token1 = strtok_r(NULL, " ", &saveptr1); // INTO
        char* table_name = strtok_r(NULL, " ", &saveptr1);
        char* token2 = strtok_r(NULL, "()", &saveptr1);
        struct record new_record;
        char* value = strtok_r(token2, ",", &saveptr2);
        int i = 0;
        while (value != NULL) {
            new_record.values[i++] = value;
            value = strtok_r(NULL, ",", &saveptr2);
        }
        new_record.values[i] = NULL; // add NULL terminator
        struct table* table = NULL;
        for (int i = 0; i < q->db->num_tables; i++) {
            if (strcmp(q->db->tables[i].name, table_name) == 0) {
                table = &q->db->tables[i];
                break;
            }
        }
        if (table == NULL) {
            printf("Table %s does not exist\n", table_name);
            return;
        }
        table->records[table->num_records++] = new_record;
    } else if (strstr(q->statement, "SELECT")) {
        // extract table name and field name(s)
        char* saveptr1, * saveptr2;
        char* token1 = strtok_r(q->statement, " ", &saveptr1); // SELECT
        char* field_names = strtok_r(NULL, " ", &saveptr1);
        char* token2 = strtok_r(NULL, " ", &saveptr1); // FROM
        char* table_name = strtok_r(NULL, " ", &saveptr1);
        struct table* table = NULL;
        for (int i = 0; i < q->db->num_tables; i++) {
            if (strcmp(q->db->tables[i].name, table_name) == 0) {
                table = &q->db->tables[i];
                break;
            }
        }
        if (table == NULL) {
            printf("Table %s does not exist\n", table_name);
            return;
        }
        if (strcmp(field_names, "*") == 0) {
            // print all fields
            for (int i = 0; i < table->num_fields; i++) {
                printf("%s\t", table->fields[i].name);
            }
            printf("\n");
            for (int i = 0; i < table->num_records; i++) {
                for (int j = 0; j < table->num_fields; j++) {
                    printf("%s\t", table->records[i].values[j]);
                }
                printf("\n");
            }
        } else {
            // print specified fields
            char* field_name = strtok_r(field_names, ",", &saveptr2);
            while (field_name != NULL) {
                for (int i = 0; i < table->num_fields; i++) {
                    if (strcmp(table->fields[i].name, field_name) == 0) {
                        // print field name
                        printf("%s\t", table->fields[i].name);
                        // print values for this field
                        for (int j = 0; j < table->num_records; j++) {
                            printf("%s\t", table->records[j].values[i]);
                        }
                        printf("\n");
                        break;
                    }
                }
                field_name = strtok_r(NULL, ",", &saveptr2);
            }
        }
    }
}

void* process_queries(void* arg) {
    struct query* q = (struct query*)arg;
    execute_query(q);
    free(q->statement);
    free(q);
    return NULL;
}

int main() {
    struct database db;
    db.num_tables = 0;
    while (1) {
        // read query from user
        printf("Enter query: ");
        char* statement = (char*)malloc(sizeof(char) * 200);
        fgets(statement, 200, stdin);
        strtok(statement, "\n"); // remove newline character
        if (strstr(statement, "exit")) {
            break;
        }
        // create new query and add to thread queue
        struct query* q = (struct query*)malloc(sizeof(struct query));
        q->db = &db;
        q->statement = statement;
        pthread_t tid;
        pthread_create(&tid, NULL, process_queries, q);
    }
    return 0;
}