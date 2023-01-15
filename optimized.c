#include "stdio.h"
#include "stdlib.h"
#include "functions.h"


void printOpti(struct list *ends){
    struct elem *current = ends->head;
    while(current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
}

struct list *addAtTheEndOpti(struct list *ends, int value){

    struct elem *new;
    new = create(value);
    new->val = value;
    new->next = NULL;
    // if only one element was in the list
    if (ends->head == NULL){
        ends->head = new;
        ends->tail = new;
    }else {
        // modify both in the list and in the elements
        ends->tail->next = new;
        ends->tail = new;
    }
    return ends;
}

struct list *deleteAtTheEndOpti(struct list *ends){
    struct elem *current = ends->head;
    // if only one element was in the list
    if (current->next == NULL){
        free(current);
        ends->head = NULL;
        ends->tail = NULL;
        return NULL;
    }else {
        // go deep inside of the list // two the lest items before the end
        while (current->next->next != NULL){
            current = current->next;
        }
        struct elem *last = current->next;
        free(last);
        current->next = NULL;
        ends->tail = current;

    }
    return ends;
}



