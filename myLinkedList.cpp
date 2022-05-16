#pragma once
#ifndef __MYLIST_H__
#define __MYLIST_H__
#include<iostream>
using namespace std;

template<typename T>class Node {
private:
	T data;
	Node<T>* next;
	template<typename U>friend class LinkedList;
public:
	Node() {
		this->next = NULL;
		this->data = NULL;
	}	
	
};

template<typename T>class LinkedList {
private:
	Node<T>* head;
public:
	LinkedList()
	{
		this->head = NULL;
	}
	Node<T>* initializeNode(T value)
	{
		Node* node = new Node;
		node->data = value;
		node->next = NULL;
		return node;
	}
	void initializeList(Node<T>*& node)
	{
		if (Empty())
			this->head = node;
	}
	Node<T>* getHead() { return head; }
	bool Empty()
	{
		return this->head == NULL;
	}
	void addFront(T value) {
		Node<T>* newNode = new Node<T>[1];
		newNode->data = value;
		if (Empty()) 
		{
			initializeList(newNode);
			return;
		}
		else {
			newNode->next = this->head;
			this->head = newNode;
		}
	}
	void addLast(T value) {
		Node<T>* newNode = new Node<T>[1];
		newNode->data = value;
		Node<T>* temp = this->head;	
		if (Empty()) {
			addFront(value);
			return;
		}
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newNode;
	}
	void addAtIndex(int index, T value) {
		if (index > size() || index < 0) {
			cout << "index out of bound !" << endl;
			return;
		}
		Node<T>* node = new Node<T>[1];
		node->data = value;
		int count = 0;
		Node<T>* temp = head;
		while (temp != NULL && count < index) {
			if (count == index - 1) {
				if (temp->next != NULL) {
					node->next = temp->next;
				}
				temp->next = node;
				cout << "new node added at index " << index << " !" << endl;
				break;
			}
			count++;
			temp = temp->next;
		}
	}

	int size() {
		int sz = 0;
		Node<T>* temp = head;
		while (temp != NULL) {
			sz++;
			temp = temp->next;
		}
		return sz;
	}

	void print() {
		if (head == NULL) {
			cout << "linked list is empty" << endl;
			return;
		}
		Node<T>* temp = head;
		string deli = "";
		while (temp != NULL) {
			cout << deli << temp->data ;
			deli = " => ";
			temp = temp->next;
		}
	}

	void remove() {
		if (head == NULL) {
			cout << "linked list is empty !" << endl;
			return;
		}
		if (head->next == NULL) {
			head = NULL;
			cout << "last item removed" << endl;
			return;
		}

		Node<T>* temp = head;
		while (temp != NULL) {
			if (temp->next->next == NULL) {
				temp->next = NULL;
				cout << "last item removed" << endl;
				break;
			}
			temp = temp->next;
		}

	}

	void remove(int index) {
		if (head == NULL) {
			cout << "linked list is empty !" << endl;
			return;
		}
		if (index >= size() || index < 0) {
			cout << "index out of bound !" << endl;
			return;
		}
		if (index == 0) {
			removeFront();
			cout << "item removed at index " << index << endl;
			return;
		}

		int count = 0;
		Node<T>* temp = head;
		while (temp != NULL) {
			if (count == index - 1) {
				temp->next = temp->next->next;
				cout << "item removed at index " << index << endl;
				break;
			}
			count++;
			temp = temp->next;
		}
	}

	void removeFront() {
		if (head == NULL) {
			cout << "linked list is empty !" << endl;
			return;
		}
		head = head->next;
		cout << "front item removed" << endl;
	}

	T get(int index) {
		if (Empty()) {
			cout << "linked list is empty !" << endl;
			return nullptr;
		}
		if (index >= size() || index < 0) {
			cout << "index out of bound !" << endl;
			return nullptr;
		}
		if (index == 0) {
			return head->data;
		}
		int count = 0;
		T res=NULL;
		Node<T>* temp = head;
		while (temp != NULL) {
			if (count++ == index) {
				res = temp->data;
				break;
			}
			temp = temp->next;
		}
		return res;
	}
	Node<T>* getPrevious(Node<T>* node) {
		Node<T>* tmp;
		if (node == head)
			return NULL;
		else {
			tmp = head;
			while (tmp->next != node)
				tmp = tmp->next;
			return tmp;
		}

	}
	Node<T>* Element(int index) {
		if (Empty()) {
			cout << "linked list is empty !" << endl;
			return nullptr;
		}
		if (index >= size() || index < 0) {
			cout << "index out of bound !" << endl;
			return nullptr;
		}
		if (index == 0) {
			return head;
		}
		int count = 0;
		Node<T>* temp = head;
		while (temp != NULL) {
			if (count++ == index) {
				break;
			}
			temp = temp->next;
		}
		return temp;
	}
	void swap(Node<T>* before, Node<T>* ahead) {
		if (head == NULL || before == NULL || ahead == NULL) {
			cout << "Nothing to swap!";
			return;
		}

		Node<T>* prev = getPrevious(before);
		Node<T>* prev2 = getPrevious(ahead);

		if (prev != NULL)
			prev->next = ahead;
		if (prev2 != NULL)
			prev2->next = before;
		Node<T>* tmp = before->next;
		before->next = ahead->next;
		ahead->next = tmp;
		if (head == before)
			head = ahead;
		else {
			if (head == ahead)
				head = before;
		}
	}
};
#endif