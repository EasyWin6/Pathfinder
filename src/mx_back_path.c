#include "pathfinder.h"

static int mx_get_stack_index(t_retpath *stack);
static void mx_push_to_stack(t_retpath *stack, int elem);
static int mx_pop_from_stack(t_retpath *stack);
static bool check_next_v(t_main *stct, t_retpath *stack, int next_v);

void mx_back_path(t_main *stct, t_retpath *stack) {
    int a = stack->c;

    if (mx_get_stack_index(stack) == stack->path[0]) {
        mx_ret_trip_output(stct, stack);
        return;
    }
    else {
        for (int i = 0; i < a; i++) {
            if (check_next_v(stct, stack, i)) {
                mx_push_to_stack(stack, i);
                mx_back_path(stct, stack);
                mx_pop_from_stack(stack);
            }
        }
    }
}

static int mx_get_stack_index(t_retpath *stack) {
    return stack->path[stack->size];
}

static void mx_push_to_stack(t_retpath *stack, int elem) {
    if (stack->size < stack->c) {
        stack->size++;
        stack->path[stack->size] = elem;
    }
}

static int mx_pop_from_stack(t_retpath *stack) {
    if (stack->size > 1) {
        stack->size--;
        return stack->path[stack->size + 1];
    }
    return stack->path[1];
}

static bool check_next_v(t_main *stct, t_retpath *stack, int next_v) {
    int k = mx_get_stack_index(stack);
    int j = stack->path[0];

    if (k != next_v) {
        if (stct->m_dist[k][next_v] == stct->m_floyd[j][k]
            - stct->m_floyd[j][next_v])
            return true;
    }
    return false;
}
