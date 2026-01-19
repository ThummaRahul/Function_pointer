#include <stdio.h>
int sum(int a,int b)
{
    return a+b;
}
int mul(int a,int b)
{
    return a*b;
}
int sub(int a,int b)
{
    return a-b;
}
int main()
{
    int (*funptr)(int,int);

char operation;
scanf("%c",&operation);

if(operation == '+')
    funptr = sum;
else if(operation == '*')
    funptr = mul;
else if(operation == '-')
    funptr = sub;

printf("Result = %d", funptr(10,20));

}
