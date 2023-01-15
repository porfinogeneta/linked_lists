#include "stdio.h"
#include "stdlib.h"
#include "functions.h"


void printDouble(struct doubleElem *lis){
    // left to right
    while (lis != NULL){
        printf("%d ", lis->val);
        lis = lis->next;
    }
//    // right to left
//    struct doubleElem *last;
//    while (last != NULL){
//        printf("%d ", last->val);
//        last = lis->previous;
//    }
}


struct doubleElem *createDouble(int value) { // create a new one-element list
    struct doubleElem *pom;
    pom = (struct doubleElem *) malloc(sizeof(struct doubleElem));
    pom->val = value;
    pom->next = NULL;
    pom->previous = NULL;
    return pom;
}

struct doubleElem *deleteDoubleFirst(struct doubleElem *lis){
    // in case there is only one item in the list
    if (lis->next == NULL){
        free(lis);
        return NULL;
    } else{
        struct doubleElem *second;
        second = lis->next;
        free(lis);
        second->previous = NULL;
        return second;
    }
}

struct doubleElem *deleteDoubleLast(struct doubleElem *lis){
    // in case there is only one item in the list
    if (lis->next == NULL){
        free(lis);
        return NULL;
    } else{
        struct doubleElem *last;
        // go deep
        while (lis->next != NULL){
            lis = lis->next;
        }
        // delete last and switch pointers
        last = lis->previous;
        last->next = NULL;
        free(lis);
        return last;
    }
}

struct doubleElem *addToTheEnd(struct doubleElem *lis, int val){
    // create our element to add
    struct doubleElem *new_last = createDouble(val);
    new_last->next = NULL;
    new_last->previous = NULL;

    // in case there wasn't any list
    if (lis == NULL){
        lis = new_last;
        return lis;
    }

    // in case something is in the list
    while (lis->next != NULL){
        lis = lis->next;
    }
    // we reached the last element
    lis->next = new_last;
    new_last->previous = lis;

    return lis;
}
