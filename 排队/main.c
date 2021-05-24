#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"agent.h"

int a[6][50];
 void create() {
	
	int i, j;
	srand((unsigned)time(NULL));
	for (i = 1; i <= 5;i++) {
		a[i][0]=  rand() % 45 + 1;
	}
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= a[i][0]; j++) {
			a[i][j] = 2;     //路人
		}
	}
	while (1) {
		i = rand() % 4 + 1;
		j = rand() % 45+ 1;
		if (a[i][j] == 2) {
			a[i][j] = 1;
			break;
		}
	}


	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= a[i][0]; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n");
	
	for (i = 1; i <= 5; i++) {
		
		int t;
		t= rand() % 4 + 1;
		a[i][0] = a[i][0] - t;
		for (int h = 1; h <= t; h++) {
             chu(i);
		}
		
	}
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= a[i][0]; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n");


	for (i = 1; i <= 5; i++) {
		printf("%d  ", a[i][0]);
	}
	int u;
	printf("请输入您要进去的队伍,或者插朋友的队：");
	scanf_s("%d", &u);
	/// <summary>
	/// ////////////////////////////////////////////////////////////////////////////////////
	/// </summary>
	ru(u);



	
	for (i = 1; i <= 5; i++) {
		for (j = 1; j <= a[i][0]+1; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n\n");


	
}

void chu(int u) {
	int c, j;
	c = u;
	int y;
	
	for (j = 2; j <= 45; j++) {
		a[c][j - 1] = a[c][j];
	}
}

void ru(int v) {
	int c, j;
	c = v;
	

	for (j = 2; j <= 45; j++) {
		if (a[c][j] != 1 && a[c][j] != 2) {
			a[c][j] = 3;
			break;
		}
	}
}






void main() {
	create();
}



		