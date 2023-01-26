#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	char info;
	struct node * link;
} NODE;

NODE * new_node(char c) // regresa la direccion del nuevo nodo
{
	// Check if there is free memory
	NODE * node = (NODE *) malloc(sizeof(NODE));
	
	if(node == NULL) {
		printf("No memory available\n");
		exit(1);
		
	} else {
		// Initialize and bind the new node
		node->info = c;
		return node;
	}
}

NODE * create_list() //Crear el head de la lista
{
	// Check if there is free memory
	NODE * head = new_node(0);
	head->link = head;
	return head;
}

void insert(NODE * head, char c)
{
	// Check if there is free memory
	NODE * node = new_node(c);
	
	node->link = head->link;
	head->link = node;
}

/*
void delete(struct node ** p, struct node *xp)
{
	if (*p == NULL)
	{
		printf("Empty list");
		return;
	}
	struct node * node, * pred;
	node= *p;
	
	while(node !=NULL && node !=xp)
	{
		pred=node;
		node = node->link;
	}
	if(node == NULL)
	{
		printf("Node not found\n");
		return;
	}
	if(*p == xp)
	{
		p = (*p)->link;  //((*p)).link
	}
	else
	{
		pred->link = xp->link;
	}
	free(xp);
}
*/
void display(NODE * head )
{
	NODE * node = head->link; //le damos la direccion que guarda head para no imprimir head

	while(node != head) {
		printf("%c\n", node->info);
		node = node->link;
	}
}

int main()
{
	NODE * list = create_list();
	
	insert(list, 'E');
	insert(list, 'D');
	insert(list, 'C');
	insert(list, 'B');
	insert(list, 'A');
	
	display (list);
	printf("\n");
	
	//delete (&list, node);
	//print(list);
}