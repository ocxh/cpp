#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	char fname[50];
	struct Node* lp;
	struct Node* rp;
}Node;

void Insert(Node** start, char filename[]); //Linked List에 노드 추가
bool ckWord(char filename[], char word[]); //같은 단어 있는지 체크
void prtnode(Node* start); //LinkedList 출력
void free_node(Node* start); //LinkedList free()

int main()
{
	char filename[20];
	char word[20];
	Node* start_p = NULL;

	printf("단어: ");
	scanf("%s", word);
	while (1)
	{
		printf("파일 이름(0=종료): ");
		scanf("%s", filename);
		if(!strcmp(filename,"0")) break;

		if (ckWord(filename, word))
		{
			Insert(&start_p, filename);
		}
	}
	prtnode(start_p);
	free_node(start_p);
	return 0;
}

void Insert(Node** start, char filename[])
{
	Node* now = *start;
	Node* new_p = (Node*)malloc(sizeof(Node));
	Node* pre_p = NULL;

	strcpy(new_p->fname, filename);
	new_p->lp = NULL;
	new_p->rp = NULL;

	if (*start == NULL)
	{
		*start = new_p;
	}
	else {
		while (now != NULL)
		{
			pre_p = now;
			now = now->rp;
		}
		new_p->lp = pre_p;
		pre_p->rp = new_p;
	}
}

bool ckWord(char *filename, char *word)
{
	FILE* fp = NULL;
	char bf[100];

	fp = fopen(filename, "r");
	if (fp == NULL) {
		printf("존재하지 않는 파일 이름입니다.\n");
		fclose(fp);
		return false;
	}
	else {
		while (!feof(fp))
		{
			fscanf(fp, "%s", bf);
			bf[99] = NULL;
			if (strcmp(bf, word) == 0)
			{
				fclose(fp);
				return true;
			}
		}
		fclose(fp);
		return false;
	}
}

void prtnode(Node* start)
{
	Node* now = start;
	
	printf("---해당 단어가 포함된 파일 리스트---\n");
	while (now != NULL)
	{
		printf("파일 이름: %s \n", now->fname);
		now = now->rp;
	}
}

void free_node(Node* start)
{
	Node* now = start;
	Node* next_p = NULL;
	while (now != NULL)
	{
		next_p = now->rp;
		free(now);
		now = next_p;
	}
}