#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float f(int m1,int m2,float r){

    float G;

    double force;

    G = 6.67384*(pow(10,-11));
    force=G*(m1*m2)/pow(r,2);
    return force;
}


int main()
{
    int mass1,mass2;
    float distance;

    printf("Welcome to Physics Academy \n");
    printf("----------------------- \n");

    printf("Please enter first mass(kg): \n");
    scanf("%d", &mass1);

    printf("Please enter second mass(kg): \n");
    scanf("%d", &mass2);

    printf("Please enter distance(m): \n");
    scanf("%f", &distance);

    printf("Gravity Force is %.12f Newton",f(mass1,mass2,distance));

    return 0;
}
