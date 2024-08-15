#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "instant.h"
#include "bmh.h"
#include "brute.h"
#include "read.h"

int main(int argc, char** argv) {
    if(argc < 3) {
        puts("Faltam argumentos");
        return 1;
    }
    bool is_bmh = false;
    int size = 0;

    char strat = argv[1][0];

    switch (strat) {
        case 'N':
        case 'B':
            is_bmh = strat == 'B';
            break;
        default:
            puts("Valor inválido de estratégia");
            return 1;
    }
    problem_input_t* input = read_file(argv[2], &size);

    FILE* output = fopen("saida.txt", "w");

    instant before = now();
    for (int i = 0; i < input->queries_len; i++) {
        query_t* q = &input->queries[i];

        // Slice representa o texto que será buscado
        char* slice = input->haystack;

        // Salvamos o caractere no fim da busca
        char old_char = slice[q->b];
        // Demarca o fim da busca
        slice[q->b] = '\0';

        // Ajusta para começar em `a`
        slice = slice + q->a-1;

        bool result;
        if (is_bmh)
            result = bmh_strstr(slice, input->needle);
        else
            result = brute_strstr(slice, input->needle);

        if(result) {
            fputs("sim", output);
        } else {
            fputs("não", output);
        }

        bool expected = strstr(slice, input->needle) != NULL;

        if (result != expected && 0)
            puts("\e[31mDiferença\e[0m\n");

        // Desfaz final da string
        slice[q->b] = old_char;
    }

    instant after = now();

    print_time_elapsed(after, before);

    fclose(output);
    input_free(input);
    return 0;
}
