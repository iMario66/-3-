
//сборка
// gcc -std=c17 -Wall -Wextra -Wpedantic -Wconversion -g main.c -o main.exe
// .\main.exe


#include <stdio.h>



int main(void) {



    int L, R, D, K;
    int count_pairs = 0;

    int min_diff = 0, min_sum = 0;

    int best_a, best_b;

    printf("Please enter L, R, D, K:\n");
    scanf("%d %d %d %d", &L, &R, &D, &K);

    if(L >= R || L < 1 || R > 300 || D <= 0 || K <= 0) {
        printf("Incorrect data. Please try again!\n");
        return 1;
    }

    int a = L, b;

    printf("Pairs, that have GCD = 0:\n");

    //для 7 уровня
    int count_for_7_lvl = 0;

    //Для 9-10 уровня
    int total_while_cycles = 0;

    while(a + D <= R) {

        for(b = a+D; b <= R; ++b) {
            
            ++count_for_7_lvl;

            //для отсечения тех пар, чья сумма делится на K
            if((a+b) % K == 0) {
                continue;
            }

            //проверка, равен ли нод пары 1
            int flag = 1; // равен 1, если НОД = 1. Равен 0, если НОД != 1.
            int z = 2;
            while(z != a+1) {
                ++total_while_cycles;
                if(a % z == 0 && b % z == 0) {
                    flag = 0;
                    break;
                }
                ++z;
            }

            //вывод тех пар, чей НОД = 1
            if(flag == 1) { 
                ++count_pairs;
                printf("%d - %d\n", a, b);


                //для выбора лучшей пары проверка
                if(min_sum == 0) {
                    best_a = a;
                    best_b = b;
                    min_sum = a+b;
                    min_diff = b-a;
                }

                else {

                    if(b-a < min_diff) {
                        best_a = a;
                        best_b = b;
                        min_sum = a+b;
                        min_diff = b-a;
                    }

                    else if(b-a == min_diff) {
                        if(b+a < min_sum) {
                            best_a = a;
                            best_b = b;
                            min_sum = a+b;
                            min_diff = b-a;
                        }
                    }

                }
            }
        }

        ++a;

        

    }


    //вывод количества пар
    printf("Count of pairs, that have GCD = 1, is %d\n", count_pairs);

    //вывод лучшей пары (если есть хотя бы 1 пара в принципе)
    if(count_pairs != 0) {
         printf("The best pair is [ %d ] - [ %d ]\n", best_a, best_b);
    }
   
    printf("For 7lvl count of iterations is %d\n", count_for_7_lvl);

    printf("For 9-10lvl count of iterations in internal while is %d\n", total_while_cycles);

    return 0;

}