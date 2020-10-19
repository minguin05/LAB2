/*tree.c*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<search.h>

struct node {
	char *name;
	int mid;
	int final;

};

int compare(const void *cp1, const void *cp2){
	return strcmp(((struct node *)cp1)->name, ((struct node *)cp2)->name);
}

void print_node(const void *, VISIT, int);

int main(){
	int stu_num = 0;

	printf("How number of student: ");
	scanf("%d", &stu_num);

	char nametable[stu_num*20]; /* 이름을 저장할 테이블 */
	struct node nodetable[stu_num]; /* 저장할 노드 테이블 */
	struct node *root = NULL; /* 루트 노드 */

	char *nameptr = nametable;
	struct node *nodeptr = nodetable;
	struct node **ret;
	int i = 0;

	while (i++ < stu_num){
		printf("\nNew Student: 1.Student name  2.mid   3.final\n");
		scanf("%s%d%d", nameptr, &nodeptr->mid, &nodeptr->final);
		nodeptr->name = nameptr;
		/* 트리에 넣기 */
		ret = (struct node **) tsearch((void *) nodeptr,
		(void **) &root, compare);
		printf("\"%s\" 님이 ", (*ret)->name);
		if (*ret == nodeptr)
			printf("트리에 추가되었습니다.\n");
		else
			printf("트리에 이미 존재합니다.\n");
			nameptr += strlen(nameptr) + 1;
			nodeptr++;
	}
	twalk((void *) root, print_node);



	return 0;
}

/* twalk 가 노드를 처음 만날때 출력 */
void print_node(const void *nodeptr, VISIT order, int level)
{
	if (order == preorder || order == leaf)
		printf("이름 = %-5s, mid = %-5d, final = %d \n",
		(*(struct node **)nodeptr)->name,
		(*(struct node **)nodeptr)->mid,
		(*(struct node **)nodeptr)->final);
}

 
