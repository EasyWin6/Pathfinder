#include "pathfinder.h"

void mx_usage(int argc) {
    if (argc != 2) {
        mx_printerr(INVALID_USAGE);
        exit(1);
    }
}
