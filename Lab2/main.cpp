#include<iostream>
#include<string>
#include"Huffman.h"

using namespace std;

int main() {
	string sentence = "it is test string";
	List<Element_HuffmanTree*>* table = getEncodingTable(sentence);
	cout << "Input string: " << sentence << endl;
	cout << "Memory: " << sentence.size() * 8 << " bits.\n";
	cout << "\nThe frequency and code table: \n";
	Element_List<Element_HuffmanTree*>* temp = table->head;
	while (temp != NULL) {
		cout << temp->data->symbol << "\t";
		temp = temp->next;
	}
	cout << endl;
	temp = table->head;
	while (temp != NULL) {
		cout << temp->data->frequence << "\t";
		temp = temp->next;
	}
	cout << endl;
	temp = table->head;
	while (temp != NULL) {
		temp->data->bits->printlist();
		cout << "\t";
		temp = temp->next;
	}
	cout << endl;

	string code = EncodeString(table, sentence);

	cout << "\nEncoding result: " << code;
	
	cout << "\nMemory: " << code.size() << " bits.\n";

	cout << "\nCode String: " << code;

	cout << "\nDecoding result: " << DecodeString(table, code);

	cout << "\n\nCompression rate: " << sentence.size() * 8.0 / code.size() << endl;
}