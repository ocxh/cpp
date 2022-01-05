#include<stdio.h>

int my_strlen(char *s)
{
	int length = 0;
	while(*s != NULL)
	{
		s++;
		length++;
	}
	return length;
}

void my_strcpy(char *s, char *news)
{
	int length = my_strlen(s);
	for(int i=0; i<length; i++)
	{
		news[i] = s[i];	
	}
	news[length] = NULL;
}

void my_strcat(char *s, char *msg, char *news)
{
	int length1 = my_strlen(s);
	int length2 = my_strlen(msg);
	
	my_strcpy(s, news);
	for(int i=0; i<length2; i++)
	{
		news[i+length1] = msg[i];
	}
	news[length1+length2] = NULL;
}

void my_strcat2(char *s, char *msg, char *news, int pos)
{
	int length1 = my_strlen(s);
	int length2 = my_strlen(msg);
	
	for(int i=0; i<pos; i++)
	{
		news[i] = s[i];
	}
	for(int i=0; i<length2; i++)
	{
		news[i+pos] = msg[i];
	}
	for(int i=0; i<length1; i++)
	{
		news[i+pos+length2]  = s[i+pos];
	}
}

int my_strcmp(char *s1, char *s2)
{
	int length1 = my_strlen(s1);
	int length2 = my_strlen(s2);
	
	if(length1 != length2) return -1;
	
	for(int i=0; i<length1; i++)
	{
		if(s1[i] != s2[i]) return -1;
	}
	
	return 0;
}

int main(void)
{
	char str1[100] = "Hello Programming World!";
	char str2[100] = "Hello Programming World!";
	printf("%d", my_strcmp(str1, str2));
}
