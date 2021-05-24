#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;           //数据域
	struct Node* next;  //指针域
};

//创建链表
struct Node* createList() {
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode 变成了结构体变量
	//变量使用前必须被初始化
	//headNode->data = 1;
	headNode->next = NULL;  //头节点是空的
	return headNode;
}

//创建结点
struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//打印
void printList(struct Node* headNode) {
	struct Node* pMove = headNode->next;
	while (pMove) {
		printf("%d ", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}

//插入结点,参数：插入哪个链表，插入的数据是多少；(头插法)
void Headinsert(struct Node* headNode, int data) {
	//插入新的结点 
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}

//插入结点 （尾插法）
void Tailinsert(struct Node* headNode, int data) {
	struct Node* cu = headNode->next;
	struct Node* newNode = createNode(data);
	while (cu->next) {
		cu = cu->next;
	}
	cu->next = newNode;
}

//遍历链表 找出指定的值有多少个
int bianli(struct Node* headNode, int num) {
	struct Node* cur = headNode->next;
	int a = 0;
	while (cur) {
		if (cur->data == num) {
			a++;
		}
		cur = cur->next;
	}
	return a;
}
//删除数据(删除指定的值)
void del(struct Node* headNode, int posData) {
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL)
		printf("无法删除 链表为空 \n");
	else {
		while (posNode->data != posData) {
			posNodeFront = posNode;
			posNode = posNodeFront->next;
			if (posNode == NULL) {
				printf("没有找到相关节点无法删除");
				return;
			}
		}
		posNodeFront->next = posNode->next;
		free(posNode);
	}
}


void invert(struct Node* head) {   //链表倒置
	struct Node* p0, * p1, * temp, * p2;
	p0 = head->next;
	p1 = p0->next;
	temp = p0;
	while (p1 != NULL) {
		p2 = p1->next;	//必须放在前面，否则死循环
		p1->next = p0;
		p0 = p1;
		p1 = p2;
	}
	head->next = p0;
	temp->next = NULL;

}

int main() {
	struct Node* list = createList();
	int x;  int y;
	Headinsert(list, 1);
	Headinsert(list, 2);
	Headinsert(list, 3);
	Headinsert(list, 3);
	Headinsert(list, 5);
	Headinsert(list, 3);
	Tailinsert(list, 1);
	Tailinsert(list, 1);
	while (1) {
		printf("请输入操作码：\n");
		printf("----------------------------------\n");
		printf("|1.查看链表   2.删除指定元素（单个）|\n");
		printf("|3.链表倒置   4.删除指定元素（所有）|\n");
		printf("----------------------------------\n");
		scanf_s("%d", &x);
		switch (x)
		{
		case 1:  printf("链表元素有：\n");
			printList(list);
			break;

		case 2:  printf("请输入您要删除的元素：");
			scanf_s("%d", &y);
			del(list, y);
			break;

		case 3:  invert(list);
			printf("链表倒置后：\n");
			printList(list);
			break;

		case 4:  printf("请输入您要删除的元素：");
			scanf_s("%d", &y);
			int b = bianli(list, 3);
			for (int i = 1; i <= b; i++) {
				del(list, y);
			}
			printf("删除后：\n");
			printList(list);
			break;

		default:   printf("输入不合法，程序关闭\n");
			return 0;
			break;
		}
	}

}