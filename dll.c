#include "dll.h"
#include <stdlib.h>

void dll_init(DLL *list) {
    list->head = NULL;
    list->tail = NULL;
}


/* ================= PUSH FRONT ================= */

void dll_push_front(DLL *list, double value) {
    DLLNode *new = malloc(sizeof(DLLNode));

    if (new == NULL)
        return;

    new->value = value;
    new->prev = NULL;
    new->next = list->head;

    if (list->head != NULL) {
        list->head->prev = new;
    } else {
        /* Liste war leer */
        list->tail = new;
    }

    list->head = new;
}


/* ================= PUSH BACK ================= */

void dll_push_back(DLL *list, double value) {
    DLLNode *new = malloc(sizeof(DLLNode));

    if (new == NULL)
        return;

    new->value = value;
    new->next = NULL;
    new->prev = list->tail;

    if (list->tail != NULL) {
        list->tail->next = new;
    } else {
        /* Liste war leer */
        list->head = new;
    }

    list->tail = new;
}


/* ================= POP FRONT ================= */

int dll_pop_front(DLL *list, double *value) {
    if (list->head == NULL)
        return 0;

    DLLNode *temp = list->head;

    *value = temp->value;
    list->head = temp->next;

    if (list->head != NULL) {
        list->head->prev = NULL;
    } else {
        /* Liste ist jetzt leer */
        list->tail = NULL;
    }

    free(temp);

    return 1;
}


/* ================= POP BACK ================= */

int dll_pop_back(DLL *list, double *value) {
    if (list->tail == NULL)
        return 0;

    DLLNode *temp = list->tail;

    *value = temp->value;
    list->tail = temp->prev;

    if (list->tail != NULL) {
        list->tail->next = NULL;
    } else {
        /* Liste ist jetzt leer */
        list->head = NULL;
    }

    free(temp);

    return 1;
}


/* ================= SEARCH ================= */

int dll_search(DLL *list, double value) {
    DLLNode *p = list->head;
    uint32_t index = 0;

    while (p != NULL) {
        if (p->value == value)
            return (int)index;

        p = p->next;
        index++;
    }

    return -1;
}


/* ================= REMOVE AT ================= */

int dll_remove_at(DLL *list, uint32_t index) {
    if (list->head == NULL)
        return 0;

    DLLNode *p = list->head;
    uint32_t i = 0;

    while (p != NULL && i < index) {
        p = p->next;
        i++;
    }

    if (p == NULL)
        return 0;

    /* Erstes Element */
    if (p == list->head) {
        double value;
        return dll_pop_front(list, &value);
    }

    /* Letztes Element */
    if (p == list->tail) {
        double value;
        return dll_pop_back(list, &value);
    }

    /* Element in der Mitte */
    p->prev->next = p->next;
    p->next->prev = p->prev;

    free(p);

    return 1;
}


/* ================= TO ARRAY ================= */

double *dll_to_array(DLL *list, uint32_t *out_size) {
    uint32_t size = 0;
    DLLNode *p = list->head;

    /* Anzahl Elemente zählen */
    while (p != NULL) {
        size++;
        p = p->next;
    }

    *out_size = size;

    if (size == 0)
        return NULL;

    double *array = malloc(size * sizeof(double));

    if (array == NULL)
        return NULL;

    p = list->head;

    for (uint32_t i = 0; i < size; i++) {
        array[i] = p->value;
        p = p->next;
    }

    return array;
}


/* ================= CLEAR ================= */

void dll_clear(DLL *list) {
    DLLNode *p = list->head;

    while (p != NULL) {
        DLLNode *temp = p;
        p = p->next;

        free(temp);
    }

    list->head = NULL;
    list->tail = NULL;
}