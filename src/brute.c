#include "brute.h"
#include <stdio.h>
#include <string.h>

bool brute_strstr(char* haystack, char* needle) {
    int i, j, k;
    int haystack_len = strlen(haystack);
    int needle_len = strlen(needle);


    for(i = 0; i <= (haystack_len - needle_len); i++) {
        k = i;
        j = 0;

        while(haystack[k] == needle[j] && j < needle_len) {
            j++;
            k++;
        }


        if(j == needle_len) {
            return true;
        }
    }
    return false;
}
