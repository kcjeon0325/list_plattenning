typedef strcut nodeT {
	int value;
	struct nodeT *next;
	struct nodeT *prev;
	struct nodeT *child;
} node;

int append_child(node **tail, node *child)
{
	(*tail)->next = child;
	child->prev = *tail;

	while(child->next) child=child->next;
	*tail = child;
}

int list_flattening(node *head, node **tail)
{
	node *cur_node;

	cur_node = head;

	while(cur_node)
	{
		if(cur_node->child)
		{
			append_child(&tail, cur_node->child);
		}
		cur_node=cur_node->next;
	}
}

void seperate(node *head)
{
	node *cur_node = head;
	while(cur_node)
	{
		if(cur_node->child)
		{
			cur_node->child->prev->next = NULL;
			cur_node->child->prev = NULL;
			seperate(cur_node);

		}
		cur_node = cur_node->next;
	}	
}

int list_unflattening(node *head, node **tail)
{
	node *cur_node = head;
	
	seperate(head);
	while(cur_node->next) cur_node=cur_node->next;
	*tail = cur_node;

	return 1;
}