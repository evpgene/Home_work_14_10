#include "PrefixTrie.h"
#include <iostream>
#include <vector>
#include "TrieNode.h"

#define ALPHABET_SIZE 72

PrefixTree::PrefixTree(int lang) : _lang(lang)
{
};

PrefixTree::~PrefixTree() 
{
	deleteTrie(_root);
};



void PrefixTree::deleteTrie(TrieNode* root)
{
	if (!root)
		return;

	for (size_t i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
			deleteTrie(root->children[i]);
	}
	delete (root);
	root = nullptr;
	return;
};


TrieNode* PrefixTree::remove(TrieNode* root, const std::string& key, int depth)
{
	// ���� ������ ������
	if (!root)
		return nullptr;
	// ���� ����� �� ����� �����
	if (depth == key.size()) {
		if (root->isEndOfWord)
			root->isEndOfWord = false;
		// ���� ���� �� �������� ���������, ������� ���
		if (isEmpty(root)) {
			delete (root);
			root = nullptr;
		}

		return root;
	}


	int index = abs(key[depth]) - sh;
	root->children[index] = remove(root->children[index], key, depth + 1);
	if (isEmpty(root) && root->isEndOfWord == false) {
		delete (root);
		root = nullptr;
	}
	// ���������� ����� ������
	return root;
}


TrieNode* PrefixTree::getNewNode(void)
{
	TrieNode* nodePtr = new TrieNode;
	nodePtr->isEndOfWord = false;
	for (int i = 0; i < ALPHABET_SIZE; i++)
		nodePtr->children[i] = nullptr;
	return nodePtr;
}

void PrefixTree::insert(TrieNode* root, const std::string& key)
{
	for (size_t i = 0; i < key.length(); i++)
	{
		int index = abs(key[i]) - sh;
		if (!root->children[index])
		{
			root->children[index] = getNewNode();
		}
		root = root->children[index];
	}
	root->isEndOfWord = true;
}

bool PrefixTree::search(TrieNode* root, const std::string& key)
{
	for (int i = 0; i < key.length(); i++)
	{
		int index = abs(key[i]) - sh;
		if (!root->children[index])
			return false;

		root = root->children[index];
	}
	return (root != nullptr && root->isEndOfWord);
}

bool PrefixTree::isEmpty(TrieNode* root)
{
	for (int i = 0; i < ALPHABET_SIZE; i++)
		if (root->children[i])
			return false;
	return true;
}


int PrefixTree::countWords(TrieNode* root, int& count)
{
	if (!root)
		return -1;

	if (root->isEndOfWord)
	{
		count++;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
			int tmp_int = countWords(root->children[i], count); //tmp_int ������ ��� ������� ������������� ��������
	}
	return count;
}

void PrefixTree::findAllWords(TrieNode* root, size_t depth, std::string buff, std::vector<std::string>& result, size_t& count)
{

	if (!root)
		return;
	//���� ����� �������, �� ��������� ��� � ���������
	if (root->isEndOfWord)
	{
		result.resize(count);
		result.push_back(buff);
		count++;
	}
	//����������� �� ��� ���� ������� �������
	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
		{
			buff.resize(depth);
			buff.push_back(sh + i);
			findAllWords(root->children[i], depth + 1, buff, result, count);
		}
	}
	return;
}

void PrefixTree::findAllWordsByPrefix(TrieNode* root, const std::string& prefix, std::vector<std::string>& result)
{

	result.resize(0);
	if (!root)
		return;
	//��� �� ����� ��������
	for (size_t i = 0; i < prefix.length(); i++)
	{
		int index = abs(prefix[i]) - sh;
		if (!root)
			break;
			root = root->children[index];
	}
	//���� ��� ��������� ����
	size_t count{ 0 };
	std::string buff;
	size_t depth{ 0 };
	findAllWords(root, depth, buff, result, count);
	//��������� ��������� ��� ����� �������� � ���������
	for (size_t i = 0; i < count; i++)
	{
		result[i] = prefix + result[i];
	}
}

void PrefixTree::findMinPrefixes(TrieNode* root, char buf[], int ind, std::string& res)
{
	if (!root)
		return;

	int number_count{ 0 };
	int number = countWords(root, number_count);
	if (number == 1 or root->isEndOfWord)
	{
		buf[ind] = '\0';
		std::cout << buf << " ";
		std::string str = buf;
		res += buf;
		res += " ";
		if (!root->isEndOfWord)
			return;
	}

	for (int i = 0; i < ALPHABET_SIZE; i++)
	{
		if (root->children[i])
		{
			buf[ind] = sh + i;
			buf[ind + 1] = '\0';
			findMinPrefixes(root->children[i], buf, ind + 1, res);
		}
	}
}


void PrefixTree::insert_Word(const std::string& word)
{
	insert(_root, word);
}

void PrefixTree::prefixSearch(const std::string& prefix, std::vector<std::string>& result)
{
	findAllWordsByPrefix(_root, prefix, result);
	return;
}

