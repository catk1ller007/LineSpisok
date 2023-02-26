#include<iostream>
#include "TNode.h"


class LineList
{
public:
	LineList() {
		head = nullptr;
	}
	~LineList() {
		delete head;
	}
	void Add(int a) 
	{
		TNode* p = new TNode(a);
		if (head == 0) {
			head = p;
		}
		else 
		{
			TNode* current = head->getNext();
				while ((current!=0) &&(current->getNext()!=0))
				{
					current = current->getNext();
				}
				current->setNext(p);
		}
	}
	LineList(const LineList& tmp) {
		if (tmp.head == 0) {
			head = 0;
		}
		else {
			head = new TNode(*(tmp.head));
			//TNode* current = tmp.head->getNext();
		}
		TNode* current = tmp.head->getNext();
		while (current != 0) {
			TNode* p = new TNode(current->getInfo());
			this->Add(int(p));
			current = current->getNext();
		}
	}
	
	LineList& operator=(LineList tmp) {
		if (tmp.head == 0) {
			delete head;
			head = 0;
		}
		else {
			delete head;
			head = new TNode(tmp.head->getInfo());
		}
		TNode* cur = tmp.head->getNext();
		TNode* new_cur = head;
		while (cur != 0) {
			TNode* p = new TNode(tmp.head->getInfo()); // может быть вместо head быть cur
			new_cur->setNext(p);
			cur = cur->getNext();
		}
		return *this;
	}
	void deleteNextMax() {
		int max = INT_MIN;
		TNode* p = nullptr;
		TNode* current = head;
		while(current!=0) {
			if (current->getInfo() > max) {
				max = current->getInfo();
				p = current;
			}
			current = current->getNext();
		}
		if (p != nullptr) {
			current = p->getNext();
			while (current != 0) {
				p->setNext(current->getNext());
				current->setNext(nullptr);
				delete current;
				current = p->getNext();
			}
		}
	
	}

	void Insert(int k, int a) {
		TNode* p = head;
		int i = 0;
		for (i = 0; i < k && p != 0; i++) {
			p = p->getNext();
		}
		if (i == k) {
			TNode* current = new TNode(a);
			current->setNext(p->getNext());
			p->setNext(current);
		}
	}

	//Удалить из списка все звенья содержащие нулевую инфу
	void deleteZero() {
		TNode* p = head;
		while ((p!=0) && (p->getInfo()!=0))
		{
			head = p->getNext();
			p->setNext(nullptr);
			delete p;
			p = head;
		}
		if (p != 0) {
			TNode* prev = head;
			TNode* current = p->getNext();
			while (current != nullptr) {
				if (current->getInfo() == 0) {
					prev->setNext(current->getNext());
					current->setNext(nullptr);
					delete current;
					current = prev->getNext();
				}
				else {
					prev = current;
					current = current->getNext();
				}
			}
		}
	}
private:
	TNode* head;
};