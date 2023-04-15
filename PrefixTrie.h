#pragma once
#include <iostream>
#include <vector>
#include "TrieNode.h"
#define ALPHABET_SIZE 72

class PrefixTree
{
	TrieNode* _root = new TrieNode;
	int _lang{ 0 };

	const unsigned char shift()
	{
		switch (_lang)
		{
		case 1: return 'a';
		default: return abs('ё');//'а';
		}
	}
	const unsigned  char sh = shift();//shift();
	const int alphSize()
	{
		switch (_lang)
		{
		case 1: return 26;
		default: return 72;
		}
	}
	
	unsigned char abs(char c) { return (c >= 0) ? c : c + 256; };

	TrieNode* getNewNode(void); // Возвращает новый узел с пустыми детьми
	void insert(TrieNode* root, const std::string& key); // Вставляет ключ в дерево
	bool search(TrieNode* root, const std::string& key); // Возвращает true если ключ есть в дереве, иначе false
	bool isEmpty(TrieNode* root); //Возвращает false если root имеет лист, иначе true
	TrieNode* remove(TrieNode* root, const std::string& key, int depth = 0); // Рекурсивная функция удаления ключа из дерева
	int countWords(TrieNode* root, int& count); // считает количество слов в дереве
	void findMinPrefixes(TrieNode* root, char buf[], int ind, std::string& res); // поиск минимального уникального префикса слова
	void findAllWords(TrieNode* root, size_t depth, std::string buff, std::vector<std::string>& result, size_t& count); // поиск всех слов
	void findAllWordsByPrefix(TrieNode* root, const std::string& prefix, std::vector<std::string>& result); // поиск всех слов по префиксу
	void deleteTrie(TrieNode* root); //удаляет все узлы в дереве
public:
	PrefixTree() = default;
	PrefixTree(int lang);
	~PrefixTree();

	void insert_Word(const std::string& word); // Вставляет слово
	void prefixSearch(const std::string& prefix, std::vector<std::string>& result);
};


