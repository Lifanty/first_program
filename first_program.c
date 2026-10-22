#include <stdio.h>
#include <math.h>

// Program checks if it is possible to make all sequence elements equal by removing exactly one element

int can_be_equal_after_removing_one(FILE *f);

int can_be_equal_after_removing_one(FILE *f)
{
    double first_val;
    double second_val = 0;
    int has_second = 0;
    double current;
    double eps = 1.e-12;
    
    int n = 0;          /* 1-й счётчик: общее количество элементов */
    int diff_count = 0; /* 2-й счётчик: элементы, не равные первому */

    /* Считываем первое число */
    if (fscanf(f, "%lf", &first_val) != 1)
    {
        printf("File is empty\n");
        return 0;
    }
    
    n = 1;

    /* Читаем остальные числа по одному */
    while (fscanf(f, "%lf", &current) == 1)
    {
        n++;

        if (fabs(current - first_val)>eps)
        {
            diff_count++;

            /* Запоминаем второе уникальное число */
            if (!has_second)
            {
                second_val = current;
                has_second = 1;
            }
            /* Если текущее число не равно ни первому, ни второму — появилось 3-е разное число! */
            else if (fabs(current - second_val)>eps)
            {
                return 0; 
            }
        }
    }
    
    if (diff_count <= 1 || diff_count == n - 1)
    {
        return 1;
    }

    return 0;
}

int main(void)
{
    FILE *f = fopen("C:\\Users\\Lifanty\\programs C\\first_program\\numbers.txt", "r");
    if (f == NULL)
    {
        printf("File error\n");
        return -1;
    }
    else
    {
        if (can_be_equal_after_removing_one(f))
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }

        fclose(f);
        return 0;
    }
}