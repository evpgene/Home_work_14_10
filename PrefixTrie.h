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
		default: return abs('�');//'�';
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

	TrieNode* getNewNode(void); // ���������� ����� ���� � ������� ������
	void insert(TrieNode* root, const std::string& key); // ��������� ���� � ������
	bool search(TrieNode* root, const std::string& key); // ���������� true ���� ���� ���� � ������, ����� false
	bool isEmpty(TrieNode* root); //���������� false ���� root ����� ����, ����� true
	TrieNode* remove(TrieNode* root, const std::string& key, int depth = 0); // ����������� ������� �������� ����� �� ������
	int countWords(TrieNode* root, int& count); // ������� ���������� ���� � ������
	void findMinPrefixes(TrieNode* root, char buf[], int ind, std::string& res); // ����� ������������ ����������� �������� �����
	void findAllWords(TrieNode* root, size_t depth, std::string buff, std::vector<std::string>& result, size_t& count); // ����� ���� ����
	void findAllWordsByPrefix(TrieNode* root, const std::string& prefix, std::vector<std::string>& result); // ����� ���� ���� �� ��������
	void deleteTrie(TrieNode* root); //������� ��� ���� � ������
public:
	PrefixTree() = default;
	PrefixTree(int lang);
	~PrefixTree();

	void insert_Word(const std::string& word); // ��������� �����
	void prefixSearch(const std::string& prefix, std::vector<std::string>& result);
};


