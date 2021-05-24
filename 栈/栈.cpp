#include <stdio.h>
#include<stdlib.h>
#define MaxSize 100				//顺序栈的初始分配空间大小
typedef char ElemType;			//假设顺序栈中所有元素为char类型
typedef struct
{
	ElemType data[MaxSize];		//保存栈中元素
	int top;					//栈顶指针
} SqStack;						//顺序栈类型

void InitStack(SqStack& st)		//初始化顺序栈st
{
	st.top = -1;
}
void DestroyStack(SqStack st)	//销毁顺序栈st
{  }

int Push(SqStack& st, ElemType x)	//进栈元素x
{
	if (st.top == MaxSize - 1)
		return 0;
	st.top++;
	st.data[st.top] = x;
	return 1;
	//将该函数中的代码补齐
}

int Pop(SqStack& st, ElemType& x)	//出栈元素x
{	//将该函数中的代码补齐
	if (st.top == -1)
		return 0;
	x = st.data[st.top];
	st.top--;
	return 1;
	//将该函数中的代码补齐
}

int GetTop(SqStack st, ElemType& x)	//取栈顶元素x
{
	if (st.top == -1)					//栈空
		return 0;
	else
	{
		x = st.data[st.top];
		return 1;
	}
}

int StackEmpty(SqStack st)		//判断栈是否为空
{
	if (st.top == -1) return 1;
	else return 0;
}
int isNumberAndOp(char c) //判断表达式中数字与运算符
{
	if ((c <= '9' && c >= '0') || c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	else return 0;
}



int main()             //主函数
{
	printf("请输入表达式；");
	char c;
	char tc;
	c = getchar();
	SqStack st;
	InitStack(st);
	while (c != '#')
	{
		if (isNumberAndOp(c))
			c = getchar();
		else if (c == '(')
		{
			Push(st, c);
			c = getchar();
		}
		else if (c == ')')
		{
			if (StackEmpty(st))
			{
				printf("no");
				return 0;
			}
			else
			{
				Pop(st, tc);
				c = getchar();
			}
		}
	}
printf("yes");

	return 0;
}
