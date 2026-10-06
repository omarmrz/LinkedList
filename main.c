#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "linkedlist.h"
#include "dll.h"


/* =========================================================
   AUSGABE LL
   ========================================================= */

void print_ll(LL_T *list) {
    uint32_t size;
    double *array = ll_to_array(list, &size);

    printf("[ ");

    for (uint32_t i = 0; i < size; i++) {
        printf("%.2f ", array[i]);
    }

    printf("]\n");

    free(array);
}




void test_ll() {
    LL_T list;
    double value;

    printf("\n==============================\n");
    printf("       TEST LINKED LIST\n");
    printf("==============================\n");

    ll_init(&list);

    printf("\nPush Front 10.50:\n");
    ll_push_front(&list, 10.5);
    print_ll(&list);

    printf("Push Front 20.50:\n");
    ll_push_front(&list, 20.5);
    print_ll(&list);

    printf("Push Back 30.50:\n");
    ll_push_back(&list, 30.5);
    print_ll(&list);

    printf("Suche 30.50: Position %d\n",
           ll_search(&list, 30.5));

    printf("\nRemove Position 1:\n");
    ll_remove_at(&list, 1);
    print_ll(&list);

    printf("Pop Front: ");

    if (ll_pop_front(&list, &value))
        printf("%.2f\n", value);

    print_ll(&list);

    printf("Pop Back: ");

    if (ll_pop_back(&list, &value))
        printf("%.2f\n", value);

    print_ll(&list);

    printf("\nListe leeren:\n");
    ll_clear(&list);
    print_ll(&list);
}





/* =========================================================
   BENCHMARK
   ========================================================= */

void benchmark() {
    const uint32_t N = 10000;

    LL_T ll;


    double value;

    clock_t start;
    clock_t end;

    double time_ll;



    printf("\n\n==============================\n");
    printf("          BENCHMARK\n");
    printf("==============================\n");

    printf("N = %u\n", N);


    /* =====================================================
       PUSH FRONT
       ===================================================== */

    printf("\n--- Push Front ---\n");

    ll_init(&ll);

    start = clock();

    for (uint32_t i = 0; i < N; i++) {
        ll_push_front(&ll, (double)i);
    }

    end = clock();

    time_ll = (double)(end - start) / CLOCKS_PER_SEC;

    ll_clear(&ll);




    start = clock();



    end = clock();





    printf("LL :  %.6f s\n", time_ll);



    /* =====================================================
       PUSH BACK
       ===================================================== */

    printf("\n--- Push Back ---\n");

    ll_init(&ll);

    start = clock();

    for (uint32_t i = 0; i < N; i++) {
        ll_push_back(&ll, (double)i);
    }

    end = clock();

    time_ll = (double)(end - start) / CLOCKS_PER_SEC;

    ll_clear(&ll);




    start = clock();



    end = clock();




    printf("LL :  %.6f s\n", time_ll);



    /* =====================================================
       SEARCH
       ===================================================== */

    printf("\n--- Search ---\n");

    ll_init(&ll);


    for (uint32_t i = 0; i < N; i++) {
        ll_push_back(&ll, (double)i);

    }


    start = clock();

    for (uint32_t i = 0; i < N; i++) {
        ll_search(&ll, (double)i);
    }

    end = clock();

    time_ll = (double)(end - start) / CLOCKS_PER_SEC;


    start = clock();



    end = clock();



    printf("LL :  %.6f s\n", time_ll);


    ll_clear(&ll);



    /* =====================================================
       REMOVE IN DER MITTE
       ===================================================== */

    printf("\n--- Remove in der Mitte ---\n");

    ll_init(&ll);


    for (uint32_t i = 0; i < N; i++) {
        ll_push_back(&ll, (double)i);

    }


    start = clock();

    for (uint32_t i = 0; i < N / 2; i++) {
        ll_remove_at(&ll, N / 2 - 1 - i);
    }

    end = clock();

    time_ll = (double)(end - start) / CLOCKS_PER_SEC;


    start = clock();



    end = clock();


    printf("LL :  %.6f s\n", time_ll);


    ll_clear(&ll);



    /* =====================================================
       POP BACK
       ===================================================== */

    printf("\n--- Pop Back ---\n");

    ll_init(&ll);

    for (uint32_t i = 0; i < N; i++) {
        ll_push_front(&ll, (double)i);
    }

    start = clock();

    for (uint32_t i = 0; i < N; i++) {
        ll_pop_back(&ll, &value);
    }

    end = clock();

    time_ll = (double)(end - start) / CLOCKS_PER_SEC;






    start = clock();



    end = clock();



    printf("LL :  %.6f s\n", time_ll);


    ll_clear(&ll);

}


/* =========================================================
   MAIN
   ========================================================= */

int main() {

    test_ll();



    benchmark();

    return 0;
}