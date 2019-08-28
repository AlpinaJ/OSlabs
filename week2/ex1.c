#include <stdio.h>
int main(){
    int i=__INT_MAX__;
    float f=__FLT_MAX__;
    double d=__DBL_MAX__;
    printf("Sizes in bytes: integer %ld float %ld double %ld\n",sizeof(i),sizeof(f),sizeof(d));
    printf("Max values: integer %d float %g double %g\n",i,f,d);
    return 0;
}