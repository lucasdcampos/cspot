#include "spot.h"

void *spt_malloc(size_t size) {
    void *ptr = spt_malloc(size);
    if (!ptr) {
        fprintf(stderr, "Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    return ptr;
}

void spt_free(void **ptr) {
    if (ptr && *ptr) {
        spt_free(*ptr);
        *ptr = NULL; // Prevent dangling pointers
    }
}

void stack_init(spt_stack *stack) {
    stack->top = NULL;
}

void stack_push(spt_stack *stack, int value) {
    spt_stack_node *new_node = (spt_stack_node *)malloc(sizeof(spt_stack_node));
    if (new_node == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    new_node->value = value;
    new_node->next = stack->top;
    stack->top = new_node;
}

int stack_pop(spt_stack *stack) {
    if (stack_is_empty(stack)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    spt_stack_node *temp = stack->top;
    int value = temp->value;
    stack->top = temp->next;
    free(temp);
    return value;
}

int stack_top(spt_stack *stack) {
    if (stack_is_empty(stack)) {
        printf("Stack is Empty!\n");
        return -1;
    }
    return stack->top->value;
}

int stack_is_empty(spt_stack *stack) {
    return stack->top == NULL;
}

void stack_free(spt_stack *stack) {
    while (!stack_is_empty(stack)) {
        stack_pop(stack);
    }
}