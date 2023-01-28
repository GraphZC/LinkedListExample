#include <stdio.h>

void foo(int *x_ptr) {
    *x_ptr = 10;
}

void bar(int **x_ptr_ptr, int *y_ptr) {
    *x_ptr_ptr = y_ptr;
}

int main() {
    int x = 5, y = 15;
    int *x_ptr = &x;
    int **x_ptr_ptr = &x_ptr;

    // **x_ptr_ptr -> *x_ptr -> x

    // foo(x_ptr);
    bar(x_ptr_ptr, &y);
    printf("%d", *x_ptr);
}