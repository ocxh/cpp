#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int year;
	char title[100];
	struct Node *link;
}Node;


int main(void)
{
	char buffer[100];
	Node *p, *next_p;
	Node *pre_p = NULL;
	Node *start = NULL;
	while(1)
	{	
		printf("책 제목을 입력하세요(엔터시 종료): ");
		gets_s(buffer, 100);
		if(buffer[0] == '\0') break;
		p = (Node *)malloc(sizeof(Node));
		if(p==NULL) break;
		strcpy(p->title, buffer);
		printf("출판연도: ");
		gets_s(buffer, 100);
		p->year = atoi(buffer);
		if(start==NULL) start = p;
		else pre_p->link = p;
		
		p->link = NULL;
		pre_p = p;
	}
	
	p = start;
	while(p != NULL)
	{
		printf("제목 %s, 년도 %d \n", p->title, p->year);
		p = p->link;
	}
	
	//메모리 해제
	p = start;
	while(p != NULL)
	{
		next_p = p->link;
		free(p);
		p = next_p;	
	} 
	
	return 0;
}
