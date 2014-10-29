void FrontBackSplit(Node *head, Node** front,Node** back)
{
	if(head == NULL)
	{
		return;
	}
	
	Node* front_last_node;
	Node* slow = head;
	Node* fast = head;
	
	while(fast)
	{
		front_last_node = slow;
		slow = slow -> next;
		fast = (fast -> next) ? fast -> next -> next:NULL;		
	}
	
	front_last_node -> next = NULL;
	*front = head;
	*back = slow;
}
