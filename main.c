#include "stdio.h"
#include "stdlib.h"
#include "functions.h"



int main() {
//    struct elem *list1 = create(48);
//    addAtTheEnd(list1, -16);
//    addAtTheEnd(list1, -24);
//    addAtTheEnd(list1, 12);
//    addAtTheEnd(list1, 13);
//    addAtTheEnd(list1, 14);
//    addAtTheEnd(list1, 15);
//    struct elem *list2 = create(24);
//    addAtTheEnd(list2, 12);
//    addAtTheEnd(list2, 24);
//    connectTwoLists(list1, list2);
//    deleteLast(list);
//    struct elem *after = deleteAllSpecific(list1, 24);
//    struct elem *res = reverseOrder(list1);
//    groupSublists(list1);
//    print(list1);
//    printBackwards(after);
    // double
//    struct doubleElem *lista = addToTheEnd(NULL, 12);
//    addToTheEnd(lista, 14);
//    addToTheEnd(lista, 16);
//    addToTheEnd(lista, 17);
//    struct doubleElem *res = deleteDoubleLast(lista);
    // optimalized
    struct list *ends;
    ends = (struct list *) malloc(sizeof(struct list));
    ends = addAtTheEndOpti(ends, 12);
    addAtTheEndOpti(ends, 14);
    addAtTheEndOpti(ends, 16);
    addAtTheEndOpti(ends, 18);
    struct list *res = deleteAtTheEndOpti(ends);
    printOpti(res);
//    printDouble(res);
    return 0;
}