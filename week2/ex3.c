#include <stdio.h>

void print_tree(int n){
    for(int i = 0; i <= n; i++){
        for(int j = 0; j < n - i; j++){
            printf(" ");
        }
        for(int j = 0; j < 2 * i - 1; j++){
            printf("*");
        }
        printf("\n");
    }
}

void print_square(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("*");
        }
        printf("\n");
    }
}

void print_right_triangle_top_left(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
}

void print_right_triangle_top_right(int n){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n - i - 1; j++){
            printf(" ");
        }
        for(int j = 0; j < i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
}

void print_right_triangle_bottom_left(int n){
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
}

void print_right_triangle_bottom_right(int n){
    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < n - i - 1; j++){
            printf(" ");
        }
        for(int j = 0; j < i + 1; j++){
            printf("*");
        }
        printf("\n");
    }
}

int main(){
    printf("Choose the figure:\n1)Tree\n2)Square\n3)Triangle Top Left\n4)Triangle Top Right\n5)Triangel Bottom Left\n6)Triangle Bottom Right\n");
    int figure_index;
    scanf("%d", &figure_index);
    int n;
    scanf("%d", &n);
    switch (figure_index)
    {
    case 1:
        print_tree(n);
        break;
    case 2:
        print_square(n);
        break;
    case 3:
        print_right_triangle_top_left(n);
        break;
    case 4:
        print_right_triangle_top_right(n);
        break;
    case 5:
        print_right_triangle_bottom_left(n);
        break;
    case 6:
        print_right_triangle_bottom_right(n);
        break;
    default:
        break;
    }
    return 0;
}