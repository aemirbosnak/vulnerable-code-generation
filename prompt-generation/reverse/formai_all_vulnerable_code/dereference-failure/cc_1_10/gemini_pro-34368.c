//GEMINI-pro DATASET v1.0 Category: Warehouse Management System ; Style: minimalist
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

typedef struct WarehouseBin{
    int id;
    int capacity;
    int stock;
}WarehouseBin;

typedef struct Warehouse{
    int num_bins;
    WarehouseBin *bins;
}Warehouse;

Warehouse create_warehouse(int num_bins){
    Warehouse w, *pw = &w;
    assert(num_bins > 0);
    pw->num_bins = num_bins;
    pw->bins = malloc(sizeof(WarehouseBin) * num_bins);
    for(int i=0; i<num_bins; i++)
        pw->bins[i] = (WarehouseBin){i, 100, 0};
    return w;
}

int add_items(Warehouse *pw, int bin_id, int num_items){
    assert(pw && bin_id >= 0 && bin_id < pw->num_bins && num_items >= 0);
    if(num_items + pw->bins[bin_id].stock > pw->bins[bin_id].capacity )
        return 1;
    pw->bins[bin_id].stock += num_items;
    return 0;
}

int remove_items(Warehouse *pw, int bin_id, int num_items){
    assert(pw && bin_id >= 0 && bin_id < pw->num_bins && num_items >= 0);
    if(num_items > pw->bins[bin_id].stock )
        return 1;
    pw->bins[bin_id].stock -= num_items;
    return 0;
}

void print_warehouse(Warehouse w){
    for(int i=0; i<w.num_bins; i++)
        printf("%d %d %d\n",w.bins[i].id, w.bins[i].capacity, w.bins[i].stock);
    printf("\n");
}

int main(){
    Warehouse w = create_warehouse(2);
    print_warehouse(w);
    add_items(&w, 0, 50);
    add_items(&w, 1, 30);
    print_warehouse(w);
    remove_items(&w, 0, 20);
    remove_items(&w, 1, 15);
    print_warehouse(w);
    return 0;
}