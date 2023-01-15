#include "stdio.h"
#include "stdlib.h"
#include "functions.h"


struct elem *create(int value) { // create a new one-element list
    struct elem *pom;
    pom = (struct elem *) malloc(sizeof(struct elem));
    pom->val = value;
    pom->next = NULL;
    return pom;
}

struct elem *addAtTheEnd(struct elem *lis, int value){
    if (lis->next == NULL){
        struct elem *new;
        new = create(value);
        lis->next = new;
        return lis;
    }
    lis = lis->next;
    addAtTheEnd(lis, value);
    return lis;
}

void connectTwoLists(struct elem *lis1, struct elem *lis2){
    // go as deep as possible
    while (lis1->next != NULL){
        lis1 = lis1->next;
    }
    // connect both lists
    lis1->next = lis2;
}

struct elem *deleteLast(struct elem *lis){
    if (lis->next != NULL){
        lis = lis->next;
        deleteLast(lis);
    } else{
        free(lis);
        lis = NULL;
    }
    return lis;
}

struct elem *searchFor(struct elem *lis, int sval)
{ // returns pointer to the element in list with certain value
// returns NULL otherwise
    while (lis!=NULL) {
        if (lis->val==sval) return lis->next;
        lis = lis->next;
    }
    return NULL;
}

struct elem *deleteAllSpecific(struct elem *lis, int val){
    struct elem *pom, *poprz;
    pom = lis;
    while (1) {
        while (pom != NULL && pom->val != val) {
            //search for val
            poprz = pom;
            pom = pom->next;
        }
        if (pom != NULL) {// val is in the list
            if (pom == lis) { //delete first element
                lis = lis->next;
                free(pom);

            } else { // pass deleted element
                poprz->next = pom->next;
                free(pom);
            }
            // poprz knows where we ended our search
            pom = poprz;
        }
//         if we reached the end of list
        if (pom->next == NULL){
            break;
        }

    }
    return lis;
}

struct elem *reverseOrder(struct elem *lis){
    struct elem *poprz = NULL;
    struct elem *obec = lis;
    struct elem *nast = NULL;
    while (obec != NULL){
        // switch to the next pointer
        nast = obec->next;
        // sw poprzitch direction of currently modified pointer
        obec->next = poprz;
        // move all pointers one step forward to apply the same logic
        poprz = obec;
        obec = nast;
    }
    return poprz;
}

struct elem *groupSublists(struct elem *lis){
    struct elem *pos = lis;
    struct elem *neg = lis;
    struct elem *pos_next = pos->next;
    while (pos_next->next != NULL){
//        while (pos_next->val < 0){
//            pos_next = pos_next->next;
//        }
        if (pos_next->val > 0){

        }
        pos->next = pos_next;
        pos_next = pos_next->next;
//        pos_next = pos_next->next;
    }
}

// print out the whole list head to tail
void print(struct elem *lis){
    while (lis != NULL){
        printf("%d ", lis->val);
        lis = lis->next;
    }
    printf("\n");
}

void printBackwards(struct elem *lis){
    if (lis->next == NULL){
        printf("%d ", lis->val);
        return;
    }
    printBackwards(lis->next);
    printf("%d ", lis->val);
}
