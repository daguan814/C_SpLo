#include<stdio.h>
#include<stdlib.h>

struct Node {
	int data;           //������
	struct Node* next;  //ָ����
};

//��������
struct Node* createList() {
	struct Node* headNode = (struct Node*)malloc(sizeof(struct Node));
	//headNode ����˽ṹ�����
	//����ʹ��ǰ���뱻��ʼ��
	//headNode->data = 1;
	headNode->next = NULL;  //ͷ�ڵ��ǿյ�
	return headNode;
}

//�������
struct Node* createNode(int data) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}

//��ӡ
void printList(struct Node* headNode) {
	struct Node* pMove = headNode->next;
	while (pMove) {
		printf("%d ", pMove->data);
		pMove = pMove->next;
	}
	printf("\n");
}

//������,�����������ĸ���������������Ƕ��٣�(ͷ�巨)
void Headinsert(struct Node* headNode, int data) {
	//�����µĽ�� 
	struct Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;
}

//������ ��β�巨��
void Tailinsert(struct Node* headNode, int data) {
	struct Node* cu = headNode->next;
	struct Node* newNode = createNode(data);
	while (cu->next) {
		cu = cu->next;
	}
	cu->next = newNode;
}

//�������� �ҳ�ָ����ֵ�ж��ٸ�
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
//ɾ������(ɾ��ָ����ֵ)
void del(struct Node* headNode, int posData) {
	struct Node* posNode = headNode->next;
	struct Node* posNodeFront = headNode;
	if (posNode == NULL)
		printf("�޷�ɾ�� ����Ϊ�� \n");
	else {
		while (posNode->data != posData) {
			posNodeFront = posNode;
			posNode = posNodeFront->next;
			if (posNode == NULL) {
				printf("û���ҵ���ؽڵ��޷�ɾ��");
				return;
			}
		}
		posNodeFront->next = posNode->next;
		free(posNode);
	}
}


void invert(struct Node* head) {   //������
	struct Node* p0, * p1, * temp, * p2;
	p0 = head->next;
	p1 = p0->next;
	temp = p0;
	while (p1 != NULL) {
		p2 = p1->next;	//�������ǰ�棬������ѭ��
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
		printf("����������룺\n");
		printf("----------------------------------\n");
		printf("|1.�鿴����   2.ɾ��ָ��Ԫ�أ�������|\n");
		printf("|3.������   4.ɾ��ָ��Ԫ�أ����У�|\n");
		printf("----------------------------------\n");
		scanf_s("%d", &x);
		switch (x)
		{
		case 1:  printf("����Ԫ���У�\n");
			printList(list);
			break;

		case 2:  printf("��������Ҫɾ����Ԫ�أ�");
			scanf_s("%d", &y);
			del(list, y);
			break;

		case 3:  invert(list);
			printf("�����ú�\n");
			printList(list);
			break;

		case 4:  printf("��������Ҫɾ����Ԫ�أ�");
			scanf_s("%d", &y);
			int b = bianli(list, 3);
			for (int i = 1; i <= b; i++) {
				del(list, y);
			}
			printf("ɾ����\n");
			printList(list);
			break;

		default:   printf("���벻�Ϸ�������ر�\n");
			return 0;
			break;
		}
	}

}