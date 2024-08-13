#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "read.h"

static char* read_string(FILE* file) {
    char* buf = malloc(MAX_SIZE);
    fgets(buf, MAX_SIZE, file);
    return buf;
}

problem_input_t* read_file(const char* name, int* restrict size) {
    FILE* file = stdin;
    if(strcmp(name, "-") != 0) {
        file = fopen(name, "r");
        if(file == NULL) {
            puts("Arquivo não encontrado");
            exit(1);
        }
    }
    problem_input_t* input = calloc(sizeof(problem_input_t), 1);
    
    // Lê as strings
    input->haystack = read_string(file);
    input->needle = read_string(file);

    // Inicializa o vetor de queries
    fscanf(file, "%u", &input->queries_len);
    input->queries = calloc(sizeof(query_t), input->queries_len);

    // Lê as queries
    for(int i = 0; i < input->queries_len; i++) {
        query_t* q = &input->queries[i];
        fscanf(file, "%u %u", &q->a, &q->b);
    }
    fclose(file);
    return input;
}

void input_free(problem_input_t* input) {
    free(input->queries);
    free(input->haystack);
    free(input->needle);

    free(input);
}
