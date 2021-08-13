#include <stdio.h>
#include <conio.h>
#include <string.h>
#define MAX 50
#include <math.h>
void push(int symbol);
int pop();
int top = -1, stack[MAX];

void main()
{
	char postfix[MAX];
	int i, len, a, b, temp, result;
	printf("enter postfix expression");
	gets(postfix);
	len = strlen(postfix);
	postfix[len] = '#';
	for (i = 0; postfix[i] != '#'; i++)
	{
		if (postfix[i] >= 48 && postfix[i] <= 57)
			push(postfix[i] - 48);
		else
		{
			a = pop();
			b = pop();
			switch (postfix[i])
			{
			case '+':
				temp = b + a;
				break;
			case '-':
				temp = b - a;
				break;
			case '*':
				temp = b * a;
				break;
			case '/':
				temp = b / a;
				break;
			case '%':
				temp = b % a;
				break;
			case '^':
				temp = pow(b, a);
				break;
			}
			push(temp);
		}
	}
	result = pop();
	printf("%d", result);
	getch();
}
void push(int symbol)
{
	if (top == MAX - 1)
	{
		printf("stack overflow");
		return;
	}
	else
	{
		top = top + 1;
		stack[top] = symbol;
	}
}
int pop()
{
	if (top == -1)
	{
		printf("stack underflow");
		return 0;
	}
	else
	{
		return stack[top--];
	}
}