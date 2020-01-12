#include "pathfinder.h"

bool mx_isalpha(int c) {
    if((c >= 65 && c <= 89) || (c >= 48 && c <= 57))
        return 1;
    else
        return 0;
}
