#ifndef LINKEDLIST_LINKEDLIST_H
#define LINKEDLIST_LINKEDLIST_H

#include <stdint.h>

typedef struct LLNode {
    double value;
    struct LLNode *next;
} LLNode_T;

typedef struct {
    LLNode_T *head;
} LL_T;

//initialisierung
void ll_init(LL_T *list);

//einfüg
void ll_push_front(LL_T *list, double value);
void ll_push_back(LL_T *list, double value);

//entfernen
int ll_pop_front(LL_T *list, double *value);
int ll_pop_back(LL_T *list, double *value);

//suchen
int ll_search(LL_T *list, double value);

//löschen an pos
int ll_remove_at(LL_T *list, uint32_t index);

//export als arr
double *ll_to_array(LL_T *list, uint32_t *out_size);

//leren
void ll_clear(LL_T *list);

#endif