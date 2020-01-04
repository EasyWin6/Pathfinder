#include "Pathfinder.h"

int main(int argc, char* argv[]) {
    (void)argc;
    char *str = mx_file_to_str(argv[1]);
    char **str1 = mx_split(str, '\n');
    char **line1 = mx_parser(str1[1]);
    for (int i = 0; line1[i] != NULL; i++) {
        mx_printstr(line1[i]);
        mx_printstr("\n");
    }
    return 0;
}
