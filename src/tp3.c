#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "instant.h"
#include "bmh.h"
#include "brute.h"
#include "read.h"

int main(int argc, char** argv) {
    if(argc < 3) {
        puts("Faltam argumentos");
        return 1;
    }
    char* stat = argv[1];
    bool is_alt = false;
    int size = 0;

    switch (stat[0]) {
        case 'D':
        case 'A':
            is_alt = stat[0] == 'A';
            break;
        default:
            puts("Valor inválido de estratégia");
            return 1;
    }
    problem_input_t* input = read_file(argv[2], &size);

    instant before = now();
    for (int i = 0; i < input->queries_len; i++) {
        // Cria um intervalo de busca a partir do texto original.
        char* copy = strdup(input->haystack);
        query_t* q = &input->queries[i];
        // Demarca o fim da busca
        copy[q->b] = '\0';

        char* slice = copy + q->a-1;

        bool result;
        if (is_alt)
            result = bmh_strstr(slice, input->needle);
        else
            result = brute_strstr(slice, input->needle);

        bool expected = strstr(slice, input->needle) != NULL;

        if(result) {
            puts("sim");
        } else {

            puts("não");
        }

        if (result != expected)
            puts("\e[31mDiferença\e[0m\n");


        free(copy);
    }

    instant after = now();

    print_time_elapsed(after, before);


    input_free(input);
    return 0;
}
