#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int data;
	struct node *next;
}Node;

void add_node(Node **start, int value);
void insert_node(Node **start, int insert_after_value, int value);
void delete_node(Node **start, int value);
void print_list(Node *node);
void free_list(Node *node);

int main(int argc, char* argv[])
{
	// create first node "head"
	Node *head = NULL;
	add_node(&head, 5);
	add_node(&head, 128);
	add_node(&head, 41);

	insert_node(&head, 41, 97);

	// delete the first node
	delete_node(&head, 5);

	print_list(head);
	free_list(head);

	return 0;	
}

void add_node(Node **start, int value)
{
	Node *new_node = (Node*)malloc(sizeof(Node));
	new_node->data = value;
	new_node->next = NULL;
	
	if(*start == NULL) {
		*start = new_node;
		return;
	}
	else {
		Node *current;	
		current = *start;
		while(current->next != NULL) {
			current = current->next;
		}
		current->next = new_node;
		return;
	}
}

void insert_node(Node **start, int insert_after_value, int value)
{
	Node *current = *start; 
	
	while(current != NULL) {
		if(insert_after_value == current->data) {
			Node *new_node = (Node*)malloc(sizeof(Node));	
			new_node->data = value;
			new_node->next = NULL;
			if(current->next == NULL) {
				current->next = new_node;
				break;
			}
			else {
				new_node->next = current->next;
				current->next = new_node;
				break;
			}
		}
		current = current->next;
	}
}

void delete_node(Node **start, int value)
{
	Node *current = *start;
	Node *temp;

	if(value == current->data) {
		*start = current->next;
		free(current);
		return;
	}
	
	while(current != NULL) {
		if(current->next->data == value) {
			temp = current->next;
			current->next = current->next->next;	
			free(temp);
			return;
		}
		current = current->next;
	}
}

void print_list(Node *node)
{
	while(node != NULL) {
		printf("%d ", node->data); 
		node = node->next;
	}
	printf("\n");
}

void free_list(Node *node)
{
	Node *current, *temp;
	current = node;
	while(current != NULL) {
		temp = current;
		current = current->next;
		free(temp);
	}
}


