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
		printf("å ������ �Է��ϼ���(���ͽ� ����): ");
		gets_s(buffer, 100);
		if(buffer[0] == '\0') break;
		p = (Node *)malloc(sizeof(Node));
		if(p==NULL) break;
		strcpy(p->title, buffer);
		printf("���ǿ���: ");
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
		printf("���� %s, �⵵ %d \n", p->title, p->year);
		p = p->link;
	}
	
	//�޸� ����
	p = start;
	while(p != NULL)
	{
		next_p = p->link;
		free(p);
		p = next_p;	
	} 
	
	return 0;
}
