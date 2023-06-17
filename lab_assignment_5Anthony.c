#include <stdio.h>
#include <stdlib.h>
typedef struct node {
char letter;
struct node* next;
} node;
// Returns number of nodes in the linkedList.
int length(node* head)
{
if (head == NULL) {
return 0;
} else {
return 1 + length(head->next);
}
}
// parses the string in the linkedList
// if the linked list is head -> |a|->|b|->|c|
// then toCString function wil return "abc"
char* toCString(node* head)
{
int len = length(head);
char* str = malloc(len + 1);
char* current = str;
while (head) {
*current++ = head->letter;
head = head->next;
}
*current = '\0';
return str;
}
// inserts character to the linkedlist
// f the linked list is head -> |a|->|b|->|c|
// then insertChar(&head, 'x') will update the linked list as foolows:
// head -> |a|->|b|->|c|->|x|
void insertChar(node** po, char c)
{
node* nNode = (node*)malloc(sizeof(node));
nNode->letter = c;
nNode->next = NULL;

if (*po == NULL){
 *po = nNode;
} else {
nNode->next = *po;
*po = nNode;
}
}
// deletes all nodes in the linkedList.
void deleteList(node** po)
{
while (*po){
node* temp = *po;
*po = (*po)->next;
free(temp);
}
}

int main(void)
{
int i, strLen, numInputs;
node* head = NULL;
char* str;
char c;
FILE* inFile = fopen("input.txt","r");
fscanf(inFile, " %d\n", &numInputs);
while (numInputs-- > 0)
{
fscanf(inFile, " %d\n", &strLen);
for (i = 0; i < strLen; i++)
{
fscanf(inFile," %c", &c);
insertChar(&head, c);
}
str = toCString(head);
printf("String is : %s\n", str);
free(str);
deleteList(&head);
if (head != NULL)
{
printf("deleteList is not correct!");
break;
}
}
fclose(inFile);
}
