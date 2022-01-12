#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	char fname[50];
	struct Node* lp;
	struct Node* rp;
}Node;

void Insert(Node** start, char filename[]); //노드 추가
void Delete(Node** start, char filename[]); //노드 삭제
void Replace(Node** start, char word[], char Rword[]); //특정 단어 수정/삭제
bool ckWord(char filename[], char word[]); //같은 단어 있는지 체크
void prtnode(Node* start); //LinkedList 출력
void free_node(Node* start); //LinkedList free()

int main()
{
	char filename[20];
	char word[20];
	char Rword[20];
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
	while (1)
	{
		printf("제외할 파일명(0=종료): ");
		scanf("%s", filename);
		if (!strcmp(filename, "0")) break;

		Delete(&start_p, filename);
	}
	prtnode(start_p);

	printf("수정할 단어(엔터시 삭제): ");
	getc(stdin); //\n을 버퍼에서 빼오기(해당 코드 누락 시 gets_s 씹힘 
	gets_s(Rword);
	printf("%s\n", Rword);
	Replace(&start_p, word, Rword);

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

void Delete(Node** start, char filename[])
{
	Node* now = *start;
	Node* pre_p = NULL;
	Node* next_p = NULL;
	while (now != NULL)
	{
		pre_p = now->lp;
		next_p = now->rp;
		if (!strcmp(now->fname, filename))
		{
			if (pre_p == NULL) //해당 파일이름의 노드가 첫번째 노드라면
			{
				free(now);
				*start = next_p;
			}
			else if (next_p == NULL) //해당 파일이름의 노드가 마지막 노드라면
			{
				free(now);
				pre_p->rp = NULL;
			}
			else
			{
				pre_p->rp = next_p;
				next_p->lp = pre_p;
				free(now);
			}
			printf("[삭제완료] 파일명: %s\n", filename);
			return;
		}
		now = next_p;
	}
	printf("[Error]해당 이름의 파일이 존재하지 않습니다\n");
}

void Replace(Node** start, char word[], char Rword[])
{
	Node* now = *start;
	char nword[20];
	int slen = 0;
	while (now != NULL)
	{
		FILE* fp = fopen(now->fname, "r+");
		while (!feof(fp))
		{
			fscanf(fp, "%s", nword);
			nword[19] = NULL;
			if (!strcmp(word, nword))
			{
				fseek(fp, -1*strlen(nword), SEEK_CUR);
				fwrite(Rword, strlen(Rword), 1, fp);
				printf("변경성공\n");
				break;
			}
		}
		fclose(fp);
		now = now->rp;
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