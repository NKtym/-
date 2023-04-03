#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include "Error.h"
//#include "SP.h"

int main()
{
    FILE* file;
    file = fopen("geom.txt", "r");
    char str[40];
    int cnt = 1;
    fgets(str, 40, file);
    if (Figur(str)) {
        printf("Неправильное название фигуры в %d строке %s\n", cnt,str);
        if (first(str))
            printf("Конкретная ошибка:Ошибка открывающей скобки\n");
    } else if (Arg(str))
        printf("Неправильно введены координаты в %d строке %s\n", cnt,str);
    else if(num(str))
	printf("Неправильная передача аргументов в %d строке %s\n",cnt,str);
    else if(flout(str))
	printf("Неправильная запись дробного аргумента в %d строке %s\n",cnt,str);
    else if (Simval(str))
        printf("Неправильная постановка запятой в %d строке %s\n", cnt,str);
    else if (End(str))
        printf("Ошибка завершающей скобки в %d строке %s\n", cnt,str);
    else
        printf("%s\n", str);
    for (long unsigned int i = 0; i < strlen(str); i++) {
        if (str[i] == '\n' && fgets(str, 40, file) != NULL) {
            cnt++;
            if (Figur(str)) {
                printf("Неправильное название фигуры во %d строке %s\n", cnt,str);
                if (first(str))
                    printf("Конкретная ошибка:Ошибка открывающей скобки\n");
            } else if (Arg(str))
                printf("Неправильно введены координаты во %d строке %s\n", cnt,str);
            else if(num(str))
	        printf("Неправильная передача аргументов во %d строке %s\n",cnt,str);
    	    else if(flout(str))
		printf("Неправильная запись дробного аргумента во %d строке %s\n",cnt,str);
	    else if (Simval(str))
                printf("Неправильная постановка запятой во %d строке %s\n", cnt,str);
            else if (End(str))
                printf("Ошибка завершающей скобки во %d строке %s\n", cnt,str);
            else
                printf("%s\n", str);
            i = 0;
        }
	//double r=radius(str);
	//printf("Radius:%lf",r);
	//int s=area(r);
	//int p=perimeter(r);
	//printf("Area:%d\nPerimeter:%d\n",s,p);
    }
    fclose(file);
    return 0;
}
