#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<Windows.h>


int a[11][8];

int k;
void    RSWPA(int n) {            //��ѡ ����  ȥ��   ���

	
	int i;

	srand((unsigned)time(NULL));
	for (k = 1; k <= n; k++) {

		for (i = 1; i <= 7; i++)
		{

			a[k][i] = rand() % 35 + 1;

			if (a[k][i - 1] == a[k][i]) {
				a[k][i] = rand() % 35 + 1;
			}

		}



	}



	int  j, t;                                   //����

	for (k = 1; k <= n; k++) {

		for (j = 0; j < 7; j++) {
			for (i = 1; i < (7 - j); i++) {

				if (a[k][i + 1] < a[k][i]) {
					t = a[k][i];
					a[k][i] = a[k][i + 1];
					a[k][i + 1] = t;

				}
			}
		}

	}



	printf("\n");




	//���ظ���ʵ�ִ��������
	for (k = 1; k <= n; k++) {

		for (j = 0; j < 7; j++) {
			for (i = 1; i < (7 - j); i++) {

				if (a[k][i + 1] == a[k][i]) {

					a[k][i] = a[k][i] + 1;
					t = a[k][i];
					a[k][i] = a[k][i + 1];
					a[k][i + 1] = t;

				}
			}
		}
	}

	
										//���    
	for (k = 1; k <= n; k++) {
		printf(" *%d*       ", k);
		for (i = 1; i <= 7; i++) {


			printf(" %d\t", a[k][i]);

		}printf("\n");
		Sleep(500);
	}


	printf("\n");

}
