// linkedlist.c
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "linkedlist.h"

// node structure; static
typedef struct Node {
    void* data;
    struct Node* next;
} Node;

// Function that creates a new empty Linked List
LinkedList* create(){
    // malloc LinkedList
    LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
    assert(list != NULL);

    // error
    if(list == NULL){
        printf("Error: Failed to allocate memory for LinkedList");
        exit(EXIT_FAILURE);
    }

    list->size = 0;

    // create and malloc head node
    list->head = (Node*) malloc(sizeof(Node));

    assert(list->head != NULL);

    // error
    if(list->head == NULL){
        printf("Error: Failed to allocate memory for Node");
        exit(EXIT_FAILURE);
    }
    return list;
}

// Function to insert a new node in the LinkedList at the tail, append
void insert(LinkedList* list, void* data){
    assert(list != NULL && list->head != NULL);
    int list_size = getSize(list);
    insertAt(list, list_size, data);
}

// Function to insert a new node in the LinkedList at an index assigned data
void insertAt(LinkedList* list, int index, void* data){
    Node* head = list->head;

    int list_size = getSize(list);

    // add a check here to make index at max and min limits

    // check bounds
    assert(head != NULL || index < list_size || index >= 0);

    // error
    if(head == NULL){
        printf("Error: Node does not exist");
    }

    // create new node
    Node* node = (Node*) malloc(sizeof(Node));
    assert(node != NULL);

    // error
    if(node == NULL){
        printf("Error: Failed to allocate memory for Node");
    }

    node->data = data;

    // inserting at index = 0; first node pointed by head
    if(index == 0){
        node->next = head->next;
        head->next = node;
    }
    // inserting node at any index thats not the 0 or |list| index
    else if(index > 0 && index < list_size){ // can be just index > 0??
        Node* index_node = getNode(list, index-1);
        node->next = index_node->next;
        index_node->next = node;
    }
    // inserting at tail
    else{
        Node* index_node = getNode(list, index-1);
        node->next = index_node->next;
        index_node->next = node;
    }
    list->size++; // increase size by 1
}

// Function to delete a node in the LinkedList at the tail, pop
void delete(LinkedList* list){
    assert(list != NULL && list->head != NULL);
    int list_size = getSize(list);
    deleteAt(list, list_size-1);
}

// Function to delete a node in the LinkedList at an index
void deleteAt(LinkedList* list, int index){
    Node* head = list->head;

    int list_size = getSize(list);
    // check bounds
    assert(head != NULL || index < list_size || index >= 0);

    // error
    if(head == NULL){
        printf("Error: Node does not exist");
    }

    // deleting at index = 0; first node pointed by head
    if(index == 0){
        Node* del_node = head->next;
        head->next = head->next->next;
        free(del_node);
    }
    // deleting node at any index thats not the 0 or |list| index
    else if(index > 0 && index < list_size){ // can be just index > 0??
        Node* index_node = getNode(list, index-1);
        Node* del_node = index_node->next;
        index_node->next = del_node->next;
        free(del_node);
    }
    // deleting at tail
    else{
        Node* index_node = getNode(list, index-1);
        free(index_node->next);
        index_node->next = NULL;
    }
    list->size--; // decrease size by 1
}

// Function to update the value at a given index node
void update(LinkedList* list, int index, void* data){
    assert(list != NULL && list->head != NULL);
    Node* node = getNode(list, index);
    node->data = data;
}

// Function to search for a value in the LinkedList
Node* search(LinkedList* list, void* value){
    Node* head = list->head;
    // check bounds
    assert(head != NULL || value != NULL);

    // error
    if(head == NULL){
        printf("Error: Node does not exist");
    }

    Node* curr = head->next;

    // traverse list until index reached, then return the node at index
    while(curr != NULL){
        if(curr->data == value){
            return curr;
        }
        curr = curr->next;
    };

    return NULL; // node not found
}

// Function to clear the entire LinkedList, deallocating memory and resetting list to empty state
void clear(LinkedList* list){

    // error
    if(isEmpty(list) == 1){
        printf("Error: Queue is empty\n");
    }

    Node* curr = list->head; // current node
    Node* next; // next node

    // traverse nodes updating curr, next. free the node and move onto next
    while(curr != NULL){
        next = curr->next;
        free(curr);
        curr = next;
    }
    // empty LinkedList
    list->head = NULL;
    list->size = 0;

    free(list); // free LinkedList malloc'd structure
}

// Function to check if the LinkedList is empty or not
_Bool isEmpty(LinkedList* list){
    assert(list != NULL && list->head != NULL);
    // error
    if(list->head == NULL){
        printf("Error: Node does not exist\n");
    }
    if(list->head->next != NULL){
        return 0; // list is NOT empty
    }
    return 1; // list is empty
}

// Function to retrieve data at a certain index in the LinkedList
void* getValue(LinkedList* list, int index){
    // get node at index, return data at node, simple
    Node* index_node = getNode(list, index);
    if(index_node != NULL){
        return index_node->data;
    }
    return NULL;
}

// Function that will traverse the LinkedList at an index and return the Node associated
Node* getNode(LinkedList* list, int index){

    Node* head = list->head;

    // check bounds
    assert(head != NULL || index <= getSize(list) || index >= 0);

    Node* curr = head->next;
    int counter = 0;

    // traverse list until index reached, then return the node at index
    while(curr != NULL){
        if(counter == index){
            return curr;
        }
        curr = curr->next;
        counter++;
    };

    return NULL; // node not found
}

// Function to print the LinkedList in the format 1 -> 2 -> 3 -> etc...
// NOTE: this is a testing function and only supports integer data types
void printLinkedList(LinkedList* list){

    Node* head = list->head;
    assert(head != NULL);
    // point to first node and check if it exists
    Node* curr = head->next;
    assert(curr != NULL); 
    
    // check to see if its an integer type, else terminate
    //assert(sizeof(curr->data) == sizeof(int));
    while(curr != NULL){
        printf("%d", curr->data);
        if(curr->next){
            printf(" -> ");
        }
        curr = curr->next;
    }
    printf("\n");
}

// Function that returns the length of the LinkedList
int getSize(LinkedList* list){
    return list->size;
}