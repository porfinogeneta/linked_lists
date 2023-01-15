
#ifndef LINKED_LISTS_FUNCTIONS_H

struct elem {
    int val;
    struct elem *next;
};

// create a new struct
struct list {
    struct elem *head;
    struct elem *tail;
};

struct doubleElem {
    int val;
    struct doubleElem *next;
    struct doubleElem *previous;
};

// optimalised
struct list *addAtTheEndOpti(struct list *ends, int value);
struct list *deleteAtTheEndOpti(struct list *ends);
void printOpti(struct list *ends);

// single way
struct elem *create(int value);
struct elem *addAtTheEnd(struct elem *lis, int value);
void connectTwoLists(struct elem *lis1, struct elem *lis2);
struct elem *deleteLast(struct elem *lis);
struct elem *searchFor(struct elem *lis, int sval);
struct elem *deleteAllSpecific(struct elem *lis, int val);
void print(struct elem *lis);
void printBackwards(struct elem *lis);
struct elem *reverseOrder(struct elem *lis);
struct elem *groupSublists(struct elem *lis);


// double
struct doubleElem *addToTheEnd(struct doubleElem *lis, int val);
struct doubleElem *createDouble(int value);
void printDouble(struct doubleElem *lis);
struct doubleElem *deleteDoubleFirst(struct doubleElem *lis);
struct doubleElem *deleteDoubleLast(struct doubleElem *lis);

#define LINKED_LISTS_FUNCTIONS_H

#endif //LINKED_LISTS_FUNCTIONS_H
