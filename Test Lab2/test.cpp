#include "pch.h"
#include "gtest/gtest.h"
#include "..\Lab2\Huffman.h"

TEST(First_Test) {
	string sentence = "le tuan anh";

	List<Element_HuffmanTree*>* table = getEncodingTable(sentence);

	Element_List<Element_HuffmanTree*>* temp = table->head;

	ASSERT_EQ(temp->data->symbol, 'l');
	ASSERT_EQ(temp->data->frequence, 1);
	Element_List<bool>* temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'e');
	ASSERT_EQ(temp->data->frequence, 1);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, ' ');
	ASSERT_EQ(temp->data->frequence, 2);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 't');
	ASSERT_EQ(temp->data->frequence, 1);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'u');
	ASSERT_EQ(temp->data->frequence, 1);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'a');
	ASSERT_EQ(temp->data->frequence, 2);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'n');
	ASSERT_EQ(temp->data->frequence, 2);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'h');
	ASSERT_EQ(temp->data->frequence, 1);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);

	string code = "100101111110100011100111111001000";

	ASSERT_EQ(EncodeString(table, sentence), code);
	ASSERT_EQ(DecodeString(table, code), sentence);
}

TEST(Second_Test) {
	string sentence = "pham hoang mai anh";

	List<Element_HuffmanTree*>* table = getEncodingTable(sentence);

	Element_List<Element_HuffmanTree*>* temp = table->head;

	ASSERT_EQ(temp->data->symbol, 'p');
	ASSERT_EQ(temp->data->frequence, 1);
	Element_List<bool>* temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'h');
	ASSERT_EQ(temp->data->frequence, 3);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'a');
	ASSERT_EQ(temp->data->frequence, 4);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'm');
	ASSERT_EQ(temp->data->frequence, 2);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, ' ');
	ASSERT_EQ(temp->data->frequence, 3);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'o');
	ASSERT_EQ(temp->data->frequence, 1);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'n');
	ASSERT_EQ(temp->data->frequence, 2);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'g');
	ASSERT_EQ(temp->data->frequence, 1);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp = temp->next;

	ASSERT_EQ(temp->data->symbol, 'i');
	ASSERT_EQ(temp->data->frequence, 1);
	temp2 = temp->data->bits->head;
	ASSERT_EQ(temp2->data, 0);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 1);
	temp2 = temp2->next;
	ASSERT_EQ(temp2->data, 0);

	string code = "010111110001110111010010000011111000110011011010000111";

	ASSERT_EQ(EncodeString(table, sentence), code);
	ASSERT_EQ(DecodeString(table, code), sentence);
}