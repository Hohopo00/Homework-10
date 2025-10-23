#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

// ������� ���������� ������� ������������
float area_triangle(float a, float b, float c) {
    float p = (a + b + c) / 2.0;
    return sqrt(p * (p - a) * (p - b) * (p - c));
}

// ������� ��������� ������������
void draw_triangle(int a, int b, int c, char symbol) {
    

    // ���������� ����� ������� ������� ��� ���������
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

  
    printf("\n������ ����������� �� ��������� %d, %d, %d:\n\n", a, b, c);

    // ��������� ������������
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

// ������� ������ �������� ������
void name_figure(int sides) {
    printf("\n������: ");
    switch (sides) {
    case 3: printf("�����������"); break;
    case 4: printf("���������������"); break;
    default: printf("������������� � %d ���������", sides);
    }
    printf("\n");
}

// ������� ����
void show_menu() {
    printf("\n=== ���� �������� ��� ������������ ===\n");
    printf("1) ���������� �������\n");
    printf("2) ������� �������� ������\n");
    printf("3) ���������� ������\n");
    printf("4) �����\n");
    printf("�������� ��������: ");
}

int main() {
    setlocale(LC_ALL, "RUS"); 
    int choice;
    float a, b, c;
    char symbol = '*';
    int sides = 3; // ����������� ����� 3 �������

    // ���� ������ ������������
    printf("������� ������� ������������:\n");
    printf("������� a: ");
    scanf("%f", &a);
    printf("������� b: ");
    scanf("%f", &b);
    printf("������� c: ");
    scanf("%f", &c);



    do {
        show_menu();
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("\n������� ������������: %.2f\n", area_triangle(a, b, c));
            break;

        case 2:
            name_figure(sides);
            break;

        case 3:
            printf("\n������� ������ ��� ���������: ");
            scanf(" %c", &symbol);
            draw_triangle((int)a, (int)b, (int)c, symbol);
            break;

        case 4:
            printf("����� �� ���������.\n");
            break;

        default:
            printf("�������� �����! ���������� �����.\n");
        }

        if (choice != 4) {
            printf("\n������� Enter ��� �����������...");
            getchar();
            getchar();
        }

    } while (choice != 4);

    return 0;
}