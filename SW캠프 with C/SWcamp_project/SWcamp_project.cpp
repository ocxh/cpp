#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	char fname[50];
	struct Node* lp;
	struct Node* rp;
}Node;

//메뉴 조작 함수
int main_menu(); //메인 메뉴를 보여줌
void ChangeNum(); //번호 수정 메뉴의 함수
void View_std(); //번호로 수강생 조회
//문자열 처리 함수
void SearchW(char* st, char word[], int* index1, int* index2); //문자열에서 해당 단어의 맨앞, 뒤 인덱스 return
char* Nstring(char* st, int index1, int index2, char Nword[]); //SearchW의 인덱스2개와 새로운단어로 새로운 문자열생성
//노드 관련 함수
void Insert(Node** start, char filename[]); //노드 추가
void Delete(Node** start, char filename[]); //노드 삭제
void Replace(Node** start, char word[], char Rword[]); //특정 단어 수정/삭제
bool ckWord(char filename[], char word[]); //같은 단어 있는지 체크
void prtnode(Node* start); //LinkedList 출력
void free_node(Node* start); //LinkedList free()

int main()
{
	printf("프로그램 실행 시 텍스트 파일이 깨지는 오류는 텍스트 파일을 재생성 해줘야 합니다.\n");
	printf("프로그램 실행 시 라인이 덮어씌워지거나 줄바꿈이 되는 등의 오류가 발생하였습니다.\n\n");
	main_menu();

	return 0;
}

int main_menu()
{
	int option = 0;
	while (1)
	{
		printf("==원하는 기능을 선택하세요==\n");
		printf("1. 기존 번호 수정 2. 수강생 조회 3. 종료: ");
		scanf("%d", &option);
		printf("\n");

		if (option == 1)
		{
			ChangeNum();
			break;
		}
		else if (option == 2)
		{
			View_std();
			break;
		}
		else if (option == 3)
		{
			printf("프로그램을 종료합니다\n");
			break;
		}
		else {
			printf("올바르지 않은 옵션값\n");
		}
		
	}
	return 0;
}

void ChangeNum()
{
	char filename[20]; //파일 이름
	char word[20]; //검색할 단어
	char Rword[20]; //변경할 단어
	Node* start_p = NULL; //시작노드

	//검색할 단어 입력 받기
	printf("기존 전화번호: ");
	scanf("%s", word);
	while (1)
	{
		//해당 단어 검색할 파일명 입력 받기
		printf("파일 이름(0=종료): ");
		scanf("%s", filename);
		if (!strcmp(filename, "0")) break;

		if (ckWord(filename, word)) //해당 파일에 단어가 있으면 노드생성
		{
			Insert(&start_p, filename);
		}
	}
	prtnode(start_p); //생성된 노드 출력
	while (1)
	{
		//만들어진 Linked List에서 제외할 파일 입력
		printf("제외할 파일명(0=종료): ");
		scanf("%s", filename);
		if (!strcmp(filename, "0")) break;

		Delete(&start_p, filename);
	}
	prtnode(start_p);

	printf("수정할 번호: ");
	getc(stdin); //\n을 버퍼에서 빼오기(해당 코드 누락 시 gets_s 씹힘 
	gets_s(Rword);
	printf("%s\n", Rword);
	Replace(&start_p, word, Rword); //노드 파일들의 기존 단어를 새로운 단어로 교체

	free_node(start_p); //모든 노드에 대하여 free실행
	return;
}

void View_std()
{
	char filename[20]; //파일 이름
	char word[20]; //검색할 단어
	char Rword[20]; //변경할 단어
	Node* start_p = NULL; //시작노드

	//검색할 학생 번호 입력 받기
	printf("수강생 번호: ");
	scanf("%s", word);
	while (1)
	{
		//해당 번호 검색할 파일명 입력 받기
		printf("과목 파일 이름(0=종료): ");
		scanf("%s", filename);
		if (!strcmp(filename, "0")) break;

		if (ckWord(filename, word)) //해당 파일에 번호가 있으면 노드생성
		{
			Insert(&start_p, filename);
		}
	}
	prtnode(start_p); //생성된 노드 출력

	return;
}

void SearchW(char* st, char word[], int* index1, int* index2)
{
	char s[100];
	char check_s[20] = "";
	char w[20];

	strcpy(s, st); //기존 문자열
	strcpy(w, word); //기존 단어

	for (int i = 0; i < strlen(s); i++)
	{
		//해당되는 단어가 있는 부분의 인덱스, +strlen(word)
		memcpy(check_s, &s[i], strlen(word));
		if (!strcmp(check_s, word))
		{
			//포인터로 값을 변경
			*index1 = i + 1;
			*index2 = i + strlen(word);
		}

	}
}

char* Nstring(char* st, int index1, int index2, char Nword[])
{
	char s1[100] = "";
	char s2[100] = "";
	char line[100];
	char new_line[100];

	strcpy(line, st); //기존 문자열 가져오기
	memcpy(s1, &line[0], index1 - 1); //s1에 line[0]부터 단어의 맨 앞 인덱스까지 복사
	memcpy(s2, &line[index2], strlen(line) - index2); //s2에 line[인덱스2]부터 기존 문자열-인덱스2 까지
	strcpy(new_line, s1); //새로운 문자열에 우선 s1넣기
	strcat(new_line, Nword); //새로운 문자열(s1)에 새로운 단어 추가
	strcat(new_line, s2); //새로운 문자열(s1+Nword)에 s2 넣기
	//new_line[99] = NULL; //마지막은 NULL
	return new_line; //return
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
			printf("[제외완료] 파일명: %s\n", filename);
			return;
		}
		now = next_p;
	}
	printf("[Error]해당 이름의 파일이 존재하지 않습니다\n");
}

void Replace(Node** start, char word[], char Rword[]) //기존 단어word, 교체 단어 Rword
{
	Node* now = *start; //시작노드
	while (now != NULL)
	{
		int index1, index2;
		char line[256];
		char new_line[256];
		int alls = 0; //누적 문자열 길이
		char* exist = NULL;
		
		FILE* fp = fopen(now->fname, "r+");
		while (!feof(fp))
		{
			fgets(line, sizeof(line), fp); //파일에서 한 줄 읽어오기

			if (strstr(line, word) != NULL) //단어를 찾으면
			{
				//printf("찾음: %s\n", line);
				//새로운 문자열 생성
				SearchW(line, word, &index1, &index2);
				strcpy(new_line, Nstring(line, index1, index2, Rword));
				//printf("새로 만들어진 line: %s", new_line);
				//파일 포인터를 해당 라인의 처음으로 옮김
				if (alls == 0) fseek(fp, alls, SEEK_SET); //첫줄은 파일포인터 0부터
				else fseek(fp, alls, SEEK_SET); //그 외에는 누적 문자열길이+1 만큼 이동

				//새로운 문자열 쓰기
				fputs(new_line, fp);
				break;
			}
			alls += strlen(line)-1; //현재까지 읽은 줄 누적 길이
		}
		fclose(fp);
		now = now->rp; //다음 파일로
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
	
	printf("---해당 번호가 포함된 수강파일 리스트---\n");
	while (now != NULL)
	{
		printf("수강파일 이름: %s \n", now->fname);
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