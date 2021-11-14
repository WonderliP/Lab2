#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double f(double x){

return x*pow((sin (x)), 2);
}

double Left_Rectangle(double a, double b, int n){
    double delta = (b-a)/n;
    double summa = 0.0;
    for (int i = 0; i <= n-1; i++){
        summa += delta*f(a+i*delta);
    }
    return summa;
}
double Right_Rectangle(double a, double b, int n){
    double delta = (b-a)/n;
    double summa = 0.0;
    for (int i = 0; i <= n; i++){
        summa += delta*f(a+i*delta);
    }
    return summa;
    }
double Trapezies(double a, double b, int n){
    double delta = (b-a)/n;
    double summa = f(a)+f(b);
    for (int i = 0; i <= n-1; i++){
        summa += 2*f(a+i*delta);
    }
    summa *= delta/2;
    return summa;
}
double Sympson(double a, double b, int n){
    double delta = (b-a)/n;
    double summa = f(a)+f(b);
    int z;
    for (int i = 0; i <= n-1; i++){
        z = 2+2*(i%2);
        summa += z*f(a+i*delta);
    }
    summa *= delta/3;
    return summa;
    }
int main()
{

    printf("Hello world!\n");
    printf("My variant: 5\n");
    printf("Chosen function: y = x*(sin(x))^2\n");
    printf("My function must be integrated between 0 and 1\n\n");
    printf("Choose the variant of programme (1,2,3,4)\n\n");
    printf("Your variant:  ");

    double a = 0;
    double b = 1;
    int n = 100;
    double calculation_error = 0.001;

    printf("Left rectangle = %lf\n", Left_Rectangle(a, b, n) );
    printf("Right rectangle = %lf\n", Right_Rectangle(a, b, n) );
    printf("Trapezies = %lf\n", Trapezies(a, b, n) );
    printf("Sympson = %lf\n", Sympson(a, b, n));

    int counter = 5;
    int i = 0;
    double differential;

    do{
        i++;
        differential = Left_Rectangle(a, b, counter*i) - Left_Rectangle(a, b, counter*(i+1));
    }while (differential > calculation_error);
    int auxiliary_var = counter*(i+1);
    printf("\nN for Left rectangle = %d", auxiliary_var);
    i = 0;
    counter = 500;

     do{
        i++;
        differential = Right_Rectangle(a, b, counter*i) - Right_Rectangle(a, b, counter*(i+1));
    }while (differential > calculation_error);
    printf("\nN for Right rectangle = %d\n", auxiliary_var);


    return 0;
}
