#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 20

int top = -1, unsort[max], sort[max];
int sorted_top = -1;
void push1(int n)
{
    if (top == max - 1)
    {
        puts("stack is over flown");
        return;
    }
    else
    {
        top = top + 1;
        unsort[top] = n;
    }
}
int pop1()
{
    int del;
    if (top == -1)
    {
        puts("stack is underflown");
        return 0;
    }
    else
    {
        del = unsort[top];
        // printf("\n poped element is %d", del);
        top = top - 1;
    }
    return del;
}
int push2(int n)
{
    if (sorted_top == max - 1)
    {
        puts("stack is over flown");
        return 0;
    }
    else
    {
        sorted_top = sorted_top + 1;
        sort[sorted_top] = n;
    }
}
int pop2()
{
    int del;
    if (sorted_top == -1)
    {
        puts("stack is underflown");
        return 0;
    }
    else
    {
        del = sort[sorted_top];
        // printf("\n poped element is %d", del);
        sorted_top = sorted_top - 1;
    }
    return del;
}
void display1()
{
    int i;
    if (top == -1)
        puts("stack is empty");
    else
    {
        for (i = top; i >= 0; i--)
            printf("\t%d", unsort[i]);
    }
}
void display2()
{
    int i;
    if (sorted_top == -1)
        puts("stack is empty");
    else
    {
        for (i = sorted_top; i >= 0; i--)
            printf("\t%d", sort[i]);
    }
}
void sorting()
{
    while (top > -1)
    {
        int temp = pop1();
        while (sorted_top >= 0 && temp < sort[sorted_top])
        {
            int x = pop2();
            push1(x);
        }
        push2(temp);
    }
}


int main()
{
    printf("Enter how many numbers do you wanna put\n");
    int a;
    scanf("%d", &a);
    for(int i=0;i<a;i++){
        printf("Enter the %d. number\n",i+1);
        int b;
        scanf("%d", &b);
        push1(b);
    }
    printf("Displaying the stack entered by you\n");
    display1();
    sorting();
    printf("\n");
    display2();
    return 0;
}