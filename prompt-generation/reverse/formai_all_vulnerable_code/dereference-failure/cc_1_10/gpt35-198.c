//FormAI DATASET v1.0 Category: Data recovery tool ; Style: satisfied
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void recover(char* data, int size, char* filename){
    FILE *fptr = fopen(filename, "wb");
    if(fptr == NULL){
        printf("Error opening file!");
        return;
    }
    fwrite(data, sizeof(char), size, fptr);
    fclose(fptr);
    printf("%s recovered successfully!\n", filename);
}

int main(){
    char file_data[][10] = {
        "Hello",
        "World",
        "I",
        "Am",
        "A",
        "Chatbot",
        "And",
        "I",
        "Love",
        "Coding"
    };
    int file_sizes[] = {5, 5, 1, 2, 1, 7, 3, 1, 4, 6};

    char* recovered_data = malloc(50);
    int recovered_size = 0;
    char* temp_data = NULL;
    int temp_size = 0;

    for(int i=0;i<10;i++){
        temp_size = strlen(file_data[i]);
        temp_data = realloc(recovered_data, recovered_size + temp_size + 1);
        if(temp_data == NULL){
            printf("Error allocating memory!\n");
            free(recovered_data);
            return -1;
        }
        recovered_data = temp_data;
        strcpy(&(recovered_data[recovered_size]), file_data[i]);
        recovered_size += temp_size;
    }

    recover(recovered_data, recovered_size, "recovered_data.txt");
    free(recovered_data);
    return 0;
}