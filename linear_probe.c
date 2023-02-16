#include <stdio.h>
#define SIZE 10

int hash(int key){
    return key%SIZE;
}

int probe(int HT[], int key){
    //index of key
    int index = hash(key);
    int i=0;
    while(HT[index+i]%SIZE != 0){
        i++;
    return (index+i)%SIZE;
    }
}

void insert(int HT[], int key){
    int index = hash(key);

    if(HT[index] != 0)
        index = probe(HT,key);
    HT[index] = key;   
}

int search(int HT[],int key)
{
    int index = hash(key);
    int i=0;
    while(HT[(index+i)%SIZE] != key)
        i++;
    return (index+i)%SIZE;
}
int main(){
    int HT[10] = {0};

    insert(HT,12);
    insert(HT,25);
    insert(HT,35);
    insert(HT,26);

    printf("\nKey found at %d \n",search(HT,35));

    return 0;
}