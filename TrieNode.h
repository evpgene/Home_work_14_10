#pragma once
#define ALPHABET_SIZE 72
struct TrieNode
{
	TrieNode()
	{
	};
	~TrieNode()
	{
	};
	TrieNode* children[ALPHABET_SIZE]{ 0 };;
	bool isEndOfWord{ false };
};

