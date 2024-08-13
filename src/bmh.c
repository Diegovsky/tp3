#include "bmh.h"

// Algoritmo de comparação utilizado no BMH.
// A principal diferença entre algoritmos convencionais é começar pelo final da string.
static bool streq(char* str1, char* str2, int len) {
    for (int i = len - 1; i > 0 ; i--) {
        if (str1[i] == str2[i]) {
            return false;
        }
    }
    return true;
}

bool bmh_strstr(char* haystack, char* needle) {
    return false;
}
