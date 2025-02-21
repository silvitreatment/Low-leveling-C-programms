#include <stdio.h>
#include <stdarg.h>

void minprintf(char *fmt, ...) {
    va_list ap;
    char *p, *sval;
    int ival;
    double dval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            putchar(*p);
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int);
                printf("%d", ival);
                break;
            case 'f':
                dval = va_arg(ap, double);
                printf("%f", dval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                printf("%s", sval);
                break;
            case 'c':
                ival = va_arg(ap, int);
                putchar(ival);
                break;
            case '%':
                putchar('%');
                break;
            default:
                putchar(*p);
                break;
        }
    }
    va_end(ap);
}

void minscanf(char *fmt, ...) {
    va_list ap;
    char *p;
    int *ival;
    float *fval;
    char *sval;

    va_start(ap, fmt);
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            continue;
        }
        switch (*++p) {
            case 'd':
                ival = va_arg(ap, int *);
                scanf("%d", ival);
                break;
            case 'f':
                fval = va_arg(ap, float *);
                scanf("%f", fval);
                break;
            case 's':
                sval = va_arg(ap, char *);
                scanf("%s", sval);
                break;
            case 'c':
                sval = va_arg(ap, char *);
                scanf("%c", sval);
                break;
            default:
                break;
        }
    }
    va_end(ap);
}


int main() {
    int i;
    float f;
    char str[100];
    char c;

    printf("Тест minprintf:\n");
    minprintf("Целое число: %d, Дробное число: %f, Строка: %s, Символ: %c\n", 42, 3.14, "Hello", 'A');

    printf("\nТест minscanf:\n");
    printf("Введите целое число, дробное число, строку и символ: ");
    minscanf("%d %f %s %c", &i, &f, str, &c);


    printf("Вы ввели:\n");
    printf("Целое число: %d\n", i);
    printf("Дробное число: %f\n", f);
    printf("Строка: %s\n", str);
    printf("Символ: %c\n", c);

    return 0;
}