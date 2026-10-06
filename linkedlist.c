#include "linkedlist.h"
#include <stdlib.h>

void ll_init(LL_T *list) {
    list->head = NULL;
}


/* ================= PUSH FRONT ================= */

void ll_push_front(LL_T *list, double value) {
    LLNode_T *new = malloc(sizeof(LLNode_T));

    if (new == NULL)
        return;

    new->value = value;
    new->next = list->head;

    list->head = new;
}


/* ================= PUSH BACK ================= */

void ll_push_back(LL_T *list, double value) {
    LLNode_T *new = malloc(sizeof(LLNode_T));

    if (new == NULL)
        return;

    new->value = value;
    new->next = NULL;

    if (list->head == NULL) {
        list->head = new;
        return;
    }

    LLNode_T *p = list->head;

    while (p->next != NULL) {
        p = p->next;
    }

    p->next = new;
}


/* ================= POP FRONT ================= */

int ll_pop_front(LL_T *list, double *value) {
    if (list->head == NULL)
        return 0;

    LLNode_T *temp = list->head;

    *value = temp->value;
    list->head = temp->next;

    free(temp);

    return 1;
}


/* ================= POP BACK ================= */

int ll_pop_back(LL_T *list, double *value) {
    if (list->head == NULL)
        return 0;

    /* Nur ein Element */
    if (list->head->next == NULL) {
        *value = list->head->value;

        free(list->head);
        list->head = NULL;

        return 1;
    }

    LLNode_T *p = list->head;

    while (p->next->next != NULL) {
        p = p->next;
    }

    *value = p->next->value;

    free(p->next);
    p->next = NULL;

    return 1;
}


/* ================= SEARCH ================= */

int ll_search(LL_T *list, double value) {
    LLNode_T *p = list->head;
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

int ll_remove_at(LL_T *list, uint32_t index) {
    if (list->head == NULL)
        return 0;

    /* Erstes Element */
    if (index == 0) {
        double value;
        return ll_pop_front(list, &value);
    }

    LLNode_T *p = list->head;
    uint32_t i = 0;

    while (p != NULL && i < index - 1) {
        p = p->next;
        i++;
    }

    if (p == NULL || p->next == NULL)
        return 0;

    LLNode_T *temp = p->next;

    p->next = temp->next;

    free(temp);

    return 1;
}


/* ================= TO ARRAY ================= */

double *ll_to_array(LL_T *list, uint32_t *out_size) {
    uint32_t size = 0;
    LLNode_T *p = list->head;

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

void ll_clear(LL_T *list) {
    LLNode_T *p = list->head;

    while (p != NULL) {
        LLNode_T *temp = p;
        p = p->next;

        free(temp);
    }

    list->head = NULL;
}