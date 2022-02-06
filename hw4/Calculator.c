
#define _CRT_SECURE_NO_WARNIGS
typedef int Element;
#include "Stack_Link.h"
#define MAX 100

typedef enum { Iparen, rparen, plus, minus, times, divide, mod, eos, space, operand }precedence;
static int icp[] = { 20, 19, 12, 12, 13, 13, 13, 0 };
static int isp[] = { 0, 19, 12, 12, 13, 13, 13, 0 };

void change_postfix(char*, char*);
precedence get_token(char*);
char print_token(precedence);
int eval(char*);
int binaryok(char*);
int pairok(char*);
void removespace(char*, char*);

int main(void)
{
	char infix[MAX] = { 0 };
	char postfix[MAX] = { 0 };
	char temparr[MAX] = { 0 }; //�ӽþ�

	int result;
	int i;
	printf("Arithmetic Expression : ");
	fgets(infix, sizeof(infix), stdin);
	infix[strlen(infix) - 1] = '\0';

	if (binaryok(infix) == 0) //not ok
		printf("Error : Check the binary expression !");
	if (pairok(infix) == 0) //not ok
		printf("Error : Check the pairs of Parenthesis !");

	else if (binaryok(infix) != 0 && pairok(infix) != 0)
	{
		removespace(infix, temparr);
		printf("%s", temparr);
		change_postfix(temparr, postfix); //postfix�
		printf("Input : %s \n", infix);
		printf("Post : ");
		printf("%s", postfix);
		result = eval(postfix);
		printf("\nResult : %d \n", result);
	}
}
int  eval(char* post)
{
	precedence token;
	char t[MAX];
	int temp;
	int i = 0, j = 0;
	Stack* pStack = CreateStack(1000);
	while ((token = get_token(post)) != eos)
	{
		if (token == space && i > 0)
		{
			t[i] = '\0';
			temp = (int)atof(t);
			Push(pStack, temp);
			i = 0;
		}
		else if ((!isalpha(*post) && operand == token))
			t[i++] = *post;
		else
		{
			if (token <= space && !isalpha(*post) && token != Iparen)
			{
				switch (token)
				{
				case plus: Push(pStack, Pop(pStack) + Pop(pStack)); break;
				case minus: temp = Pop(pStack);
					Push(pStack, Pop(pStack) - temp); break;
				case times: Push(pStack, Pop(pStack) * Pop(pStack)); break;
				case divide:
					if ((temp = Pop(pStack)) != 0)
						Push(pStack, Pop(pStack) / temp); break;
				case mod: temp = Pop(pStack);
					Push(pStack, Pop(pStack) % (int)temp); break;
				default:
					break;

				}
			}
		}
		post++;
	}
	return Pop(pStack);
	DestroyStack(pStack);
}

precedence get_token(char* symbol)
{
	switch (*symbol)
	{
	case '(': return Iparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '*': return times;
	case '/': return divide;
	case '%': return mod;
	case '\0': return eos;
	case ' ': return space;
	default: return operand;
	}
}
void change_postfix(char* str, char* postfix)
{
	int i = 0, j = 0, flag = 0;
	precedence token;

	Stack* pStack = CreateStack(1000);

	Push(pStack, eos);
	while ((token = get_token(str + i)) != eos)
	{
		if (token == operand)
		{
			*(postfix + j++) = *(str + i);
			flag = 1;
		}
		else
		{
			if (flag)
			{
				*(postfix + j++) = ' ';
				flag = 0;
			}
			if (token == rparen)
			{
				while ((token = (int)Pop(pStack)) != Iparen)
				{
					//*(postfix + j++) = ' ';
					*(postfix + j++) = print_token(token);
					*(postfix + j++) = ' ';
				}
				if (token != Iparen)
				{

					*(postfix + j++) = print_token(token);
					*(postfix + j++) = ' ';
				}
			}
			else
			{
				while (icp[token] <= isp[(int)Top(pStack)])
				{
					//*(postfix + j++) = ' ';
					*(postfix + j++) = print_token((int)Pop(pStack));
					*(postfix + j++) = ' ';
				}
				Push(pStack, token);
			}
		}
		i++;
	}
	//*(postfix + j++) = ' ';
	while ((token = (int)Pop(pStack)) != eos)
		if (*(postfix + j - 1) != ' ')
		{
			*(postfix + j++) = ' ';
			*(postfix + j++) = print_token(token);
		}
		else
			*(postfix + j++) = print_token(token);
	*(postfix + j) = '\0';

	DestroyStack(pStack);
}
char print_token(precedence token)
{
	switch (token)
	{
	case plus: return '+';
	case minus: return '-';
	case times: return '*';
	case divide: return '/';
	case mod: return '%';
	default: return '\0';
	}
}
int pairok(char* str) {
	int i = 0, count = 0;
	precedence token;
	while ((token = get_token(str + i)) != eos)
	{
		if (token == Iparen)count++;
		if (token == rparen)count--;
		i++;
	}
	if (count == 0)
		return 1;
	else return 0;
}
int binaryok(char* str)
{
	int i = 0, flag = 0, re = 1; //re: �Ͽ� � �ӽ� �
	precedence token;
	while ((token = get_token(str + i)) != eos)
	{
		if (token == operand && flag == 1 && get_token(str + i - 1) == space)
		{
			re = 0; break; //not okay
		}
		else if (token == space && get_token(str + i - 1) == operand)
			flag = 1;
		else if (token != space && token != operand)
			flag = 0;
		i++;
	}
	return re;
}
void removespace(char* str, char* temparr)
{
	int i = 0, j = 0, ress = 0;
	while (*(str + i) != '\0') {
		if (*(str + i) != ' ') {
			*(temparr + j++) = *(str + i);
		}
		i++;
	}
	printf("%d", ress);
}