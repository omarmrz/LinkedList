#ifndef LINKEDLIST_DLL_H
#define LINKEDLIST_DLL_H

#include <stdint.h>

typedef struct DLLNode {

    double value;
    struct DLLNode *next;
    struct DLLNode *prev;
} DLLNode;

typedef struct {
    DLLNode *head;
    DLLNode *tail;
} DLL;


/* Initialisierung */
void dll_init(DLL *list);



/* Einfügen */
void dll_push_front(DLL *list, double value);
void dll_push_back(DLL *list, double value);


/* Entfernen */
int dll_pop_front(DLL *list, double *value);
int dll_pop_back(DLL *list, double *value);


/* Suchen */
int dll_search(DLL *list, double value);


/* Löschen an Position */
int dll_remove_at(DLL *list, uint32_t index);


/* Export als Array */
double *dll_to_array(DLL *list, uint32_t *out_size);


/* Liste leeren */
void dll_clear(DLL *list);

#endif