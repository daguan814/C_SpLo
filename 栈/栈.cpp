#include <stdio.h>
#include<stdlib.h>
#define MaxSize 100				//˳��ջ�ĳ�ʼ����ռ��С
typedef char ElemType;			//����˳��ջ������Ԫ��Ϊchar����
typedef struct
{
	ElemType data[MaxSize];		//����ջ��Ԫ��
	int top;					//ջ��ָ��
} SqStack;						//˳��ջ����

void InitStack(SqStack& st)		//��ʼ��˳��ջst
{
	st.top = -1;
}
void DestroyStack(SqStack st)	//����˳��ջst
{  }

int Push(SqStack& st, ElemType x)	//��ջԪ��x
{
	if (st.top == MaxSize - 1)
		return 0;
	st.top++;
	st.data[st.top] = x;
	return 1;
	//���ú����еĴ��벹��
}

int Pop(SqStack& st, ElemType& x)	//��ջԪ��x
{	//���ú����еĴ��벹��
	if (st.top == -1)
		return 0;
	x = st.data[st.top];
	st.top--;
	return 1;
	//���ú����еĴ��벹��
}

int GetTop(SqStack st, ElemType& x)	//ȡջ��Ԫ��x
{
	if (st.top == -1)					//ջ��
		return 0;
	else
	{
		x = st.data[st.top];
		return 1;
	}
}

int StackEmpty(SqStack st)		//�ж�ջ�Ƿ�Ϊ��
{
	if (st.top == -1) return 1;
	else return 0;
}
int isNumberAndOp(char c) //�жϱ��ʽ�������������
{
	if ((c <= '9' && c >= '0') || c == '+' || c == '-' || c == '*' || c == '/')
		return 1;
	else return 0;
}



int main()             //������
{
	printf("��������ʽ��");
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
