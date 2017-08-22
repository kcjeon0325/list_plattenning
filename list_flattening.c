typedef strcut nodeT {
	int value;
	struct nodeT *next;
	struct nodeT *prev;
	struct nodeT *child;
} node;

int append_child(node **tail, note *child)
{
	(*tail)->next = child;
	child->prev = *tail;

	while(child->next) child=child->next;
	*tail = child;
}

int list_flattening(node *head, node **tail)
{
	node *curr;

	curr = head;

	while(curr)
	{
		if(curr->child)
		{
			append_child(&tail, curr->child);
		}
		curr=curr->next;
	}
}