#include<stdio.h>
 
void setprice() {

	extern int b[8];

	int i;
	
	printf("����������Ҫ�趨���н����룺");
	for (i = 1; i <= 7; i++) {
		scanf_s("%d", &b[i]);
	}
}

void setbuy() {
	extern int a[11][8];

	int i;

	printf("����������Ҫ����ĺ��룺");
	for (i = 1; i <= 7; i++) {
		scanf_s("%d", &a[1][i]);
	}
}