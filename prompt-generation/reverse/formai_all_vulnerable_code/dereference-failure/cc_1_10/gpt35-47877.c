//FormAI DATASET v1.0 Category: Antivirus scanner ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct virus{
    char name[32];
    int signature[16];
    struct virus *next;
} virus;

virus *head = NULL;

// Function to add a new virus to the linked list
void add_virus(char *name, int *signature, int signature_length){
    virus *new_virus = malloc(sizeof(virus));
    strcpy(new_virus->name, name);
    memcpy(new_virus->signature, signature, sizeof(int) * signature_length);
    new_virus->next = NULL;
    
    if(head == NULL){
        head = new_virus;
    }
    else{
        virus *current_virus = head;
        while(current_virus->next != NULL){
            current_virus = current_virus->next;
        }
        current_virus->next = new_virus;  
    }
}

// Function to print all the viruses in the linked list
void print_viruses(){
    virus *current_virus = head;
    while(current_virus != NULL){
        printf("Virus Name: %s\n", current_virus->name);
        printf("Signature: ");
        for(int i=0; i<16; i++){
            printf("%d ", current_virus->signature[i]);
        }
        printf("\n\n");
        current_virus = current_virus->next;
    }
}

// Function to scan a file for viruses and return the number of viruses found
int scan_file(char *filename){
    FILE *file = fopen(filename, "r");
    int num_viruses_found = 0;
    int current_byte;
    int current_signature_index = 0;
    virus *current_virus = head;
    int virus_match = 0;
    
    while((current_byte = fgetc(file)) != EOF){
        if(current_byte == current_virus->signature[current_signature_index]){
            current_signature_index++;
            if(current_signature_index == 16){
                num_viruses_found++;
                printf("Virus Found: %s\n", current_virus->name);
                current_signature_index = 0;
                virus_match = 1;
            }
        }
        else{
            current_signature_index = 0;
        }
        
        if(virus_match){
            fseek(file, -15, SEEK_CUR);
            virus_match = 0;
            current_virus = head;
        }
        else if(current_virus->next != NULL){
            current_virus = current_virus->next;
        }
    }
    
    fclose(file);
    return num_viruses_found;
}

int main(){
    // Add sample viruses to the linked list
    int virus1_signature[] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0xAB, 0xCD, 0x12, 0x34, 0x56, 0x78, 0x90, 0x12, 0x34, 0x56};
    add_virus("Virus 1", virus1_signature, 16);
    
    int virus2_signature[] = {0xBB, 0xCC, 0xDD, 0xAA, 0x11, 0x22, 0x33, 0x44, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22};
    add_virus("Virus 2", virus2_signature, 16);
    
    int virus3_signature[] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF, 0x99, 0x88, 0x77, 0x66, 0x55, 0x44, 0x33, 0x22};
    add_virus("Virus 3", virus3_signature, 16);
    
    // Print all the viruses in the linked list
    printf("Loaded Viruses:\n\n");
    print_viruses();
    
    // Scan a sample file for viruses
    char *filename = "sample.txt";
    int num_viruses_found = scan_file(filename);
    printf("Total Number of Viruses Found: %d\n", num_viruses_found);
    
    return 0;
}