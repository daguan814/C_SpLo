#include<stdio.h>
#include<Windows.h>


void Search_bin(char c) {
    extern int a[11][8];
    extern int k;
    extern int b[8];

    int count_2 = 0;
    int i, h, j,price;          //i (��)h�����ŵĸ�����ѡ����� j(��ĺ���)
    int zhong = 0;         //ÿ����н�������� 

    int sum1 = 0, sum2 = 0,sum3=0;   //���н�������   �ܹ����Ҵ���


    if (c == 'r') {                               //     ����Լ�����������     ##  δ��� 

        for (i = 1; i < k; i++) {           //   ��ѡ������

            for (h = 1; h <= 7; h++) {           //��������
                j = 7;

                if (b[h] == a[i][1] || b[h] == a[i][j / 2+1]||b[h]==a[i][j]) {    //�ȿ����ǲ����ڿ�ͷ���м���߿�ͷ
                    printf("�ҵ��񽱺���%d\n", b[h]);
                    zhong++;
                    count_2++;
                    
                }
                count_2++;


                if (b[h] < a[i][j / 2 + 1]) {                  //С���м�ڵ�
                    if (b[h] == a[i][j / 2]) {
                        count_2++;
                        printf("�ҵ��񽱺���%d\n", b[h]);
                        zhong++;
                       
                    }
                    else {
                        count_2 += 2;
                        j= j/2-1;
                        if (b[h] == a[i][j]) {
                            printf("�ҵ��񽱺���%d\n", b[h]);
                        
                            zhong++;
                            
                        };
                    }
                }

                if (b[h] > a[i][j / 2 + 1]) {                  //�����м�ڵ�
                    if (b[h] == a[i][j / 2 + 2]) {
                        count_2++;
                        printf("�ҵ��񽱺���%d\n", b[h]);
                        zhong++;
                    }
                    else {
                        count_2 += 2;
                        j= j/2+3;
                        if (b[h] == a[i][j]) {
                            printf("�ҵ��񽱺���%d\n", b[h]);
                            zhong++;
                                     //��ȥдbreak ԭ���ý��ź�������ԱȻᵼ�º���ı�����
                        }
                    }
                }



                
            } 
                printf("��*%d*���ѡ�����н��ĺ�����%d�������ҵĴ����ǣ�%d\n", i, zhong, count_2);
                switch (zhong) {
            case 3:
                price = 5;
                printf("������˰�ο��������5Ԫ\n\n");
                    printf("****************************\n\n");
                break;
            case 4:
                printf("����������Ƚ�������20Ԫ\n\n");
                printf("****************************\n\n");
                price = 20;  break;
            case 5:
                printf("������˶��Ƚ�������100Ԫ\n\n");
                printf("****************************\n\n");
                price = 100;  break;
            case 6:
                printf("�������һ�Ƚ������� һǧ Ԫ\n\n");
                printf("****************************\n\n");
                price = 1000;  break;
            case 7:
                printf("��������صȽ������� һ�� Ԫ\n\n");
                printf("****************************\n\n");
                price = 10000;  break;
            default:
                price = 0; break;

            }
              sum3 = sum3 + price;
                sum2 = sum2 + count_2;
                sum1 = sum1 + zhong;
                count_2 = 0;
                zhong = 0;
                Sleep(300);

        }

        printf("�ܹ��񽱵ĺ���������%d,�ܹ����Ҵ����ǣ�%d��\n", sum1, sum2);
        printf("���ι����Ʊ�����н��ܽ��Ϊ��%dԪ\n\n", sum3);
        printf("���������������Ʊ�Ľ��Ϊ��%dԪ\n\n\n", 2 * (k-1));
    }
}