#pragma once
#include<iostream>
#include "..\\Lab 1 real real\RedBlackTree.h"
#include "..\\Lab 1 real real\List.h"


class Element_HuffmanTree {
public:
	char symbol;
	int frequence;
	List<bool>* bits;
	Element_HuffmanTree* parent;
	Element_HuffmanTree* left;
	Element_HuffmanTree* right;


	Element_HuffmanTree() {
		this->symbol = NULL;
		this->frequence = 0;
		this->bits = new List<bool>();
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}

	Element_HuffmanTree(char symbol, int frequence) {
		this->symbol = symbol;
		this->frequence = frequence;
		this->bits = new List<bool>();
		this->parent = NULL;
		this->left = NULL;
		this->right = NULL;
	}
};

class HuffmanTree {
public:
	Element_HuffmanTree* root;
	List<Element_HuffmanTree*>* listNode;

	HuffmanTree(List<Element_HuffmanTree*>* listNode) {
		this->root = NULL;
		this->listNode = listNode;
	}

	Element_HuffmanTree* minfreq() {
		Element_List<Element_HuffmanTree*>* temp = listNode->head;
		Element_List<Element_HuffmanTree*>* min = listNode->head;
		while (temp != NULL) {
			if (min->data->frequence >= temp->data->frequence)
				min = temp;
			temp = temp->next;
		}
		return min->data;
	}

	void insert() {
		if (listNode->size >= 2) {
			Element_HuffmanTree* min1 = minfreq();
			listNode->pop(minfreq());
			Element_HuffmanTree* min2 = minfreq();
			listNode->pop(minfreq());
			Element_HuffmanTree* newNode = new Element_HuffmanTree();  //????
			newNode->frequence = min1->frequence + min2->frequence;
			min1->parent = newNode;
			min2->parent = newNode;
			newNode->left = min1;
			newNode->right = min2;
			root = newNode;
			listNode->pushback(newNode);
		}
		else
			throw invalid_argument("No more Node");
	}

	List<Element_HuffmanTree*>* encode() {
		List<Element_HuffmanTree*>* newlistNode = new List<Element_HuffmanTree*>;
		Element_HuffmanTree* temp = root;
		Stack<Element_HuffmanTree*>* stack = new Stack<Element_HuffmanTree*>;
		while (temp != NULL) {
			if (temp->right != NULL) {
				stack->push(temp->right);
				Element_List<bool>* temp2 = temp->bits->head;
				while (temp2 != NULL) {
					temp->right->bits->pushback(temp2->data);
					temp2 = temp2->next;
				}
				temp->right->bits->pushback(1);
			}
			if (temp->left != NULL) {
				Element_List<bool>* temp2 = temp->bits->head;
				while (temp2 != NULL) {
					temp->left->bits->pushback(temp2->data);
					temp2 = temp2->next;
				}
				temp->left->bits->pushback(0);
				temp = temp->left;
			}
			else {
				newlistNode->pushback(temp);
				if (!stack->isEmpty())
					temp = stack->pop();
				else
					temp = NULL;
			}
		}
		return newlistNode;
	}
};

List<Element_HuffmanTree*>* getEncodingTable(string sentence) {
	RedBlackTree<char, int>* mapsymbols = new RedBlackTree<char, int>();
	for (char c : sentence)
		mapsymbols->addvalue(c, 1);

	List<Element_HuffmanTree*>* listHuffmanNode = new List<Element_HuffmanTree*>;
	for (char c : sentence) {
		Element_RBT<char, int>* data = mapsymbols->find(c);
		Element_HuffmanTree* newNode = new Element_HuffmanTree(data->key, data->value);
		bool check = 0;
		Element_List<Element_HuffmanTree*>* temp = listHuffmanNode->head;
		while (temp != NULL) {
			if (temp->data->symbol == c) {
				check = 1;
				break;
			}
			else
				temp = temp->next;
		}
		if (!check)
			listHuffmanNode->pushback(newNode);
	}

	HuffmanTree* HmTree = new HuffmanTree(listHuffmanNode);
	while (listHuffmanNode->size >= 2)
		HmTree->insert();

	listHuffmanNode = HmTree->encode();
	List<Element_HuffmanTree*>* table = new List<Element_HuffmanTree*>();
	for (char c : sentence) {
		Element_List<Element_HuffmanTree*>* temp = listHuffmanNode->head;
		while (temp != NULL) {
			if (temp->data->symbol == c) {
				bool check = 0;
				Element_List<Element_HuffmanTree*>* temp2 = table->head;
				while (temp2 != NULL) {
					if (temp2->data->symbol == c) {
						check = 1;
						break;
					}
					else
						temp2 = temp2->next;
				}
				if (!check)
					table->pushback(temp->data);
				break;
			}
			else
				temp = temp->next;
		}
	}

	return table;
}

string EncodeString(List<Element_HuffmanTree*>* list, string sentence) {
	string result;
	for (char c : sentence) {
		Element_List<Element_HuffmanTree*>* temp = list->head;
		while (temp != NULL) {
			if (temp->data->symbol == c) {
				Element_List<bool>* temp2 = temp->data->bits->head;
				while (temp2 != NULL) {
					if (temp2->data == 1)
						result += "1";
					else
						result += "0";
					temp2 = temp2->next;
				}
				//result += " ";
				break;
			}
			else
				temp = temp->next;
		}
	}
	return result;
}

string DecodeString(List<Element_HuffmanTree*>* list, string code) {
	HuffmanTree* tree = new HuffmanTree(list);
	while (list->size >= 2)
		tree->insert();

	string result;
	int i = 0;
	while (i < code.size()) {
		Element_HuffmanTree* temp = tree->root;
		while (temp->symbol == NULL) {
			if (code[i] == '0')
				temp = temp->left;
			else if (code[i] == '1')
				temp = temp->right;
			else
				logic_error("Wrong code.");
			i++;
		}
		result += temp->symbol;
	}
	return result;
}