#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

// Функция вычисления площади треугольника
float area_triangle(float a, float b, float c) {
    float p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// Функция рисования треугольника
void draw_triangle(int a, int b, int c, char symbol) {
    

    // Определяем самую длинную сторону как основание
    int base, side1, side2;
    if (a >= b && a >= c) {
        base = a;
        side1 = b;
        side2 = c;
    }
    else if (b >= a && b >= c) {
        base = b;
        side1 = a;
        side2 = c;
    }
    else {
        base = c;
        side1 = a;
        side2 = b;
    }

  
    printf("\nРисуем треугольник со сторонами %d, %d, %d:\n\n", a, b, c);

    // Рисование треугольника
    for (int i = 0; i < height; i++) {
        double progress = (height > 1) ? (double)i / (height - 1) : 0;
        int left_pos = (int)(progress * (base - 1));
        int right_pos = base - 1 - (int)(progress * (base - 1));

        for (int j = 0; j < base; j++) {
            if (i == height - 1) {
                printf("%c ", symbol);
            }
            else if (j == left_pos || j == right_pos) {
                printf("%c ", symbol);
            }
            else {
                printf("  ");
            }
        }
        printf("\n");
    }
}

// Функция вывода названия фигуры
void name_figure(int sides) {
    printf("\nФигура: ");
    switch (sides) {
    case 3: printf("Треугольник"); break;
    case 4: printf("Четырехугольник"); break;
    default: printf("Многоугольник с %d сторонами", sides);
    }
    printf("\n");
}

// Главное меню
void show_menu() {
    printf("\n=== МЕНЮ ОПЕРАЦИЙ ДЛЯ ТРЕУГОЛЬНИКА ===\n");
    printf("1) Рассчитать площадь\n");
    printf("2) Вывести название фигуры\n");
    printf("3) Нарисовать фигуру\n");
    printf("4) Выход\n");
    printf("Выберите операцию: ");
}

int main() {
    setlocale(LC_ALL, "RUS"); 
    int choice;
    float a, b, c;
    char symbol = '*';
    int sides = 3; // Треугольник имеет 3 стороны

    // Ввод сторон треугольника
    printf("Введите стороны треугольника:\n");
    printf("Сторона a: ");
    scanf("%f", &a);
    printf("Сторона b: ");
    scanf("%f", &b);
    printf("Сторона c: ");
    scanf("%f", &c);



    do {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\nПлощадь треугольника: %.2f\n", area_triangle(a, b, c));
            break;

        case 2:
            name_figure(sides);
            break;

        case 3:
            printf("\nВведите символ для рисования: ");
            scanf(" %c", &symbol);
            draw_triangle((int)a, (int)b, (int)c, symbol);
            break;

        case 4:
            printf("Выход из программы.\n");
            break;

        default:
            printf("Неверный выбор! Попробуйте снова.\n");
        }

        if (choice != 4) {
            printf("\nНажмите Enter для продолжения...");
            getchar();
            getchar();
        }

    } while (choice != 4);

    return 0;
}