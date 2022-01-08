#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	int number;
	char name[50];
	struct Node* lp;
	struct Node* rp;
}Node;

int main()
{
	Node* p = NULL;
	Node *next_p = NULL;
	Node* pre_p = NULL;
	Node* start = NULL;
	Node* end = NULL;
	char input[50];
	while (1)
	{
		
		printf("����ȣ �Է�(���ʹ� ����): ");
		gets_s(input, 50);
		if (input[0] == '\0') {
			end = p;
			break;
		}
		p = (Node*)malloc(sizeof(Node));
		if (p == NULL) break;
		p->number = atoi(input);
		printf("��� �̸� �Է�: ");
		gets_s(input);
		strcpy(p->name, input);
		if (start == NULL) {
			start = p;
			p->lp = NULL;
		}
		else
		{
			pre_p->rp = p;
			p->lp = pre_p;
		}
		pre_p = p;
	}

	p = start;
	printf("ó�������� �� ������\n");
	while (p != NULL)
	{
		printf("����ȣ: %d, ����̸�: %s \n", p->number, p->name);
		p = p->rp;
	}

	p = end;
	printf("�� ������ ó�� ������\n");
	while (p != NULL)
	{
		printf("����ȣ: %d, ����̸�: %s \n", p->number, p->name);
		p = p->lp;
	}

	p = start;
	while (p != NULL)
	{
		next_p = p->rp;
		free(p);
		p = next_p;
	}

	return 0;
}
