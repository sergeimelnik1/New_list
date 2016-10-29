#include "stdafx.h"
#include "iostream"
#include "double_line.h"

struct List *createlist(int data){
	List*n = new List;
	n->data = data;
	n->next = NULL;
	n->prev = NULL;
	return n;
}

void printlist(struct List *first){
	List*temp = first;
	while (temp != NULL){
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

struct List * search(List*node, int val){
	while (node != NULL && node->data != val){
		node = node->next;
	}
	return node;
}

struct List * addToend(List*lst, int number){
	struct List *temp, *p;
	temp = new List;
	p = lst->next;
	lst->next = temp;
	temp->data = number;
	temp->next = p;
	temp->prev = lst;
	if (p != NULL){
		p->prev = temp;
	}
	return temp;
}

struct List * addTobegin(List*lst, int number){
	List*n = new List;
	n->next = lst;
	n->prev = NULL;
	n->data = number;
	lst = n;
	return n;
}

struct List *deletehead(List*root){
	struct List*temp;
	temp = root->next;
	temp->prev = NULL;
	delete(root);
	return temp;
}

struct List *deletend(List*root){
	struct List*temp;
	temp = root->prev;
	temp->next = NULL;
	delete(root);
	return temp;
}

void deleteElem(List**lst, int number){
	struct List * node = search(*lst, number);
	if (node != NULL) {
	     struct List*p = node->prev;
	     struct List*n = node->next;
	     p->next = n;
	     n->prev = p;
	     delete node
	}
	else cout << "there is no such element";
}

void addTomiddle(List**lst, int number, int after){
	struct List * node = search(*lst,after);
	if (node != NULL) {
		List*n = new List;
	        struct List*p = node->next;
	        node->next = n;
	        n->next = p;
	        p->prev = n;
	}
	else cout << "there is no such element";
}

void sort(List**head) {
	List* temp = *head;
		while (temp->next) {
			if (temp->data > temp->next->data) {
				int c = temp->data;
				temp->data = temp->next->data;
				temp->next->data = c;
				temp = temp->next;
				sort(head);
			}
			else
				temp = temp->next;
		}	  
}
