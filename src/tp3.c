#include <stdio.h>
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
    // codigo
    instant after = now();

    print_time_elapsed(after, before);


    input_free(input);
    return 0;
}
