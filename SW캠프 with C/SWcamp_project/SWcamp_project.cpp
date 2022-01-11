#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	char fname[50];
	struct Node* lp;
	struct Node* rp;
}Node;

bool ckWord(char filename[], char word[]); //같은 단어 있는지 체크
void prtnode(Node* start); //LinkedList 출력
void free_node(Node* start); //LinkedList free()

int main()
{
	char filename[20];
	char word[20];
	Node* p = NULL;
	Node* pre_p = NULL;
	//Node* next_p = NULL;
	Node* start_p = NULL;

	while (1)
	{
		printf("파일 이름(0=종료): ");
		scanf("%s", filename);
		if(!strcmp(filename,"0")) break;

		printf("단어: ");
		scanf("%s", word);
		if (ckWord(filename, word))
		{
			p = (Node*)malloc(sizeof(Node));
			strcpy(p->fname, filename);
			if (start_p == NULL)
			{
				p->lp = NULL;
				p->rp = NULL;
				start_p = p;
			}
			else
			{
				pre_p->rp = p;
				p->lp = pre_p;
				p->rp = NULL;
			}
			pre_p = p;
		}
	}
	prtnode(start_p);
	free_node(start_p);
	return 0;
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