#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.c"

int main(){

    printf("v1.0\n");
    // create list
    LinkedList* list = create();
    Node* head = list->head;

    insert(list, 0);
    insert(list, 2);
    insert(list, 4);
    insert(list, 6);

    printLinkedList(list);

    update(list, 2, 55);
    printLinkedList(list);

    // testing search
    Node* searched_node = search(list, 6);
    if(searched_node != NULL){
        printf("value exists\n");
    }

    // deleting a node
    printf("deleting index %d:\n", getSize(list));
    delete(list);
    printLinkedList(list);
    
    // clear from memory
    clear(list);
    printf("compiled\n");
    return 0;
}