#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    int int_v;
    float float_v;
    double double_v;
    int_v = INT_MAX;
    float_v = FLT_MAX;
    double_v = DBL_MAX;
    printf("Int: %d, size: %lu\n", int_v, sizeof(int_v));
    printf("Float: %.1f, size: %lu\n", float_v, sizeof(float_v));
    printf("Double: %lf, size: %lu\n", double_v, sizeof(double_v));
    return 0;
}