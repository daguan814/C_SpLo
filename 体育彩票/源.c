//��Ŀʮ�ġ�������Ʊ��ģ�����ɺͶҽ�
//����Ҫ��
//ģ��36ѡ7���й�������Ʊ����1��36�����ȡ��7������Ϊһ�Ų�Ʊ�ĺ��룬������������Ų�Ʊ��
//����˳����۰����ֲ�ͬ�Ĳ����㷨��ָ�����н�������бȽϣ����ÿ�ֲ����㷨�ıȽϴ������н������

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include<Windows.h>
#include"agent.h"



int  main() {
        
	
	

	while (1) {
		int select;

			printf("********************************\n");
			printf("*                              *\n");
			printf("*     ��ӭ�����й�������Ʊ     *\n");
			printf("*       1.��ѡ�����Ʊ         *\n");
			printf("*       2.�����н�����         *\n");
			printf("*       3.˳�����             *\n");
			printf("*       4.�۰����             *\n");
			printf("*       5.�趨�н�����         *\n");
			printf("*       6.�����Ʊ����         *\n");
			printf("*       0.�˳�                 *\n");
			printf("*                              *\n");
			printf("********************************\n\n");

			printf("��ѡ��:");

			scanf_s("%d", &select);
		switch (select) {
		case 1:
			printf("��������Ҫ����Ĳ�Ʊ����(���9��)��");
			int f; scanf_s("%d", &f);
			while (f >= 10 || f <= 0) {
				printf("���볬���綨ֵ�����������룺");
				int f; scanf_s("%d", &f);

			}
			RSWPA(f);
			break;

		case 2:
			Sleep(1000);
			RSWPB(1);
			break;

		case 3:
			Search_seq('r');
			break;
		case 4:
	
			Search_bin('r');
			break;
		case 5:
			setprice();
			printf("\n");
			break;
		case 6:
			setbuy();
			break;
		case 0: return 0 ;
			break;
		default: printf("������0----3֮�����\n");
		}
	
	}
	
	
}




