#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>
#include <time.h>

#define max_file_name 250
#define max_numb_names 100
#define max_len_names 100

char names[max_numb_names][max_len_names] = { 0 }, new_names[max_numb_names][max_len_names] = { 0 };
char *text=NULL;
char trash3[] = "int chrolicj() { int a = 5; int b = 10; int c = a + b; int d = a * b; int e = b / a; if (c > d) { return -99; } else { return 1; }char str1[20] = { 1 }; char str2[20] = { 0 }; char str3[40]; strcat(str1, str2); strcpy(str3, str1); if (strcmp(str1, str2)) { return 226; }return 123; } ";
char trash2[] = "void awdjapss(){int dajwdasdawwqweha = 5;int dkwjhalnsmd = 10;int tyurioepqw;tyurioepqw = dajwdasdawwqweha + dkwjhalnsmd;tyurioepqw = dajwdasdawwqweha - dkwjhalnsmd;tyurioepqw = dajwdasdawwqweha * dkwjhalnsmd;tyurioepqw = dajwdasdawwqweha / dkwjhalnsmd;tyurioepqw = dajwdasdawwqweha % dkwjhalnsmd;tyurioepqw = ++dajwdasdawwqweha;tyurioepqw = --dkwjhalnsmd;tyurioepqw = dajwdasdawwqweha & dkwjhalnsmd;tyurioepqw = dajwdasdawwqweha | dkwjhalnsmd;tyurioepqw = dajwdasdawwqweha ^ dkwjhalnsmd;tyurioepqw = ~dajwdasdawwqweha;tyurioepqw = dajwdasdawwqweha << 1;tyurioepqw = dkwjhalnsmd >> 1;tyurioepqw = dajwdasdawwqweha && dkwjhalnsmd;tyurioepqw = dajwdasdawwqweha || dkwjhalnsmd;tyurioepqw = !dajwdasdawwqweha;tyurioepqw = dajwdasdawwqweha == dkwjhalnsmd;tyurioepqw = dajwdasdawwqweha != dkwjhalnsmd;tyurioepqw = dajwdasdawwqweha > dkwjhalnsmd;tyurioepqw = dajwdasdawwqweha < dkwjhalnsmd;return 0;} ";
char trash[] = "void x(){for(size_t i=0;i<5;i++){int sum=0;int anjmkd[24],xffsfar[12],awdu25n1_jwdn[1];if(sum==(i+15-152*2/461)){  sum+=(i*2-i/i+5-1+sum);}else{int anjmkd[24],xffsfar[12],awdu25n1_jwdn[1];if((sum+10*0+15/5*32)==  sum){sum+=i;sum-=anjmkd[i%20];}}}} ";
FILE* file_in;
FILE* file_out;
unsigned int len = 0;

void scan() {
	char c;
	unsigned int size = 0;
	while ((c=getc(file_in))!=EOF)
	{
		size++;
		text= (char*)realloc(text, (size + 1) * sizeof(char));
		text[size-1] = c;
	}
	size++;
	text = (char*)realloc(text, size * sizeof(char));
	text[size - 1] = '\0';
	len = size;
	fclose(file_in);
}

void comm()
{
	for(int i=0;i<len-1;i++)
	{
		if (text[i] == '/' && text[i + 1] == '/')
		{
			int counter = i;
			while (text[counter] != '\n')
			{
				counter++;
			}
			int b = i;
			while (counter < len) {
				text[b] = text[counter];
				b++;
				counter++;
			}
		}
		if (text[i] == '/' && text[i + 1] == '*')
		{
			int counter = i;
			while (!(text[counter - 1] == '*' && text[counter] == '/'))
			{
				counter++;
			}
			counter++;

			int buf = i;
			while (counter < len) {
				text[buf] = text[counter];
				buf++;
				counter++;
			}
		}
	}
}

void put() {
	unsigned int i=0;
	int flag = 0;
	int count = 0;
	int k = 0;
	while (text[i])
	{
		if ((text[i]=='v' && text[i+1]=='o' && text[i+2] == 'i' && text[i + 3] == 'd')||(text[i] == 'i' && text[i + 1] == 'n' && text[i+2] == 't')|| (text[i] == 'c' && text[i + 1] == 'h' && text[i + 2] == 'a' && text[i + 3] == 'r'))
		{
			if (flag==0)
			{
				flag += 1;
				fputs(trash, file_out);
			}
			if (flag==1)
			{
				flag += 1;
				fputs(trash2, file_out);
			}
			if (flag == 2 )
			{
				flag += 1;
				fputs(trash3, file_out);
			}
		}
		
		if (text[i] != ' ') 
			putc((int)text[i++], file_out);
		else { 
			putc(' ', file_out);
			while (text[i] == ' ') i++;
		}
	}
	fclose(file_out);
}

void str_del() {
	int flag = 0;
	for (unsigned long long i = 0; text[i] != '\0'; i++) {
		if (text[i] == '#') 
			flag = 1;
		if (text[i] == '\n') {
			if (flag == 0) 
				text[i] = ' ';
			else 
				flag = 0;
		}
	}
}

void tab_del() {
	for (unsigned long long i = 0; text[i] != '\0'; i++) {
		if (text[i] == '\t') {
			text[i] = ' ';
		}
	}
}

void obfus() {
	comm();
	tab_del();
	str_del();
	put();
}

void open_files() {
	char in_file_name[max_file_name], out_file_name[max_file_name];

	printf("Enter input file: ");
	scanf("%s", in_file_name);
	printf("Enter output file:");
	scanf("%s", out_file_name);
	file_in = fopen(in_file_name, "r");
	file_out = fopen(out_file_name, "w");
	scan();
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	open_files();
	obfus();
}
