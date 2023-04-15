#pragma once
#include "Header.h"
#include <iostream>
#include <vector>
#include "PrefixTrie.h"
#include <string>

int main()
{

	system("chcp 1251");

	PrefixTree english(1);
	PrefixTree russian(0);

	{	//��������� ������ � ���������� ������� - ������ �������� �����
		std::string filename = "1000 english words.txt"; //C://Users/Admin/Documents/Skillfactory/
		std::vector<std::string> reedFile;
		int n = 0;
		read_arr(filename, reedFile, n); // ������ ������ �� �����
		for (auto& str : reedFile)
		{
			english.insert_Word(str);
		}
	}

	{
		//��������� ������ � ������� ������� - ������ �������� �����
		std::string filename = "1000 ���� �������� �����.txt"; //C://Users/Admin/Documents/Skillfactory/
		std::vector<std::string> reedFile;
		int n = 0;
		read_arr(filename, reedFile, n); // ������ ������ �� �����
		for (auto& str : reedFile)
		{
			russian.insert_Word(str);
		};
	}

	std::string prefix;
	std::vector<std::string> result_en;
	std::vector<std::string> result_ru;
	english.prefixSearch("a", result_en);
	const char russ[]{ '�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�','�' }; //������� �������
	const char engl[]{ 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'g', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' }; //���������� �������

	do
	{
		std::cout << "������� ��������� ����� ����� � ������� ����" << std::endl;
		std::cin >> prefix;
		std::cout << std::endl;

		bool ru{ true };
		for (const auto c : prefix)
		{
			bool ok{ false };
			for (const auto alph : russ)
			{
				if (c == alph)
				{
					ok = true;
					break;
				}
			}
			ru = ru && ok;
		}
		bool en{ true };
		if (!ru)
		{
			for (const auto c : prefix)
			{
				bool ok{ false };
				for (const auto alph : engl)
				{
					if (c == alph)
					{
						ok = true;
						break;
					}
				}
				en = en && ok;
			}
		}
		if (ru)
		{
			int count{ 0 };
			russian.prefixSearch(prefix, result_ru);
			for (const auto& string : result_ru) {
				std::cout << ++count << " " << string << std::endl;
			};

			if (count)
			{
				std::cout << "�������� ������� ����� - ������� �����" << std::endl;
				std::string sel;
				int cmd{ 0 };

				std::cin >> sel;
				try
				{
					cmd = std::stoi(sel);
				}
				catch (std::exception& except)
				{
					std::cout << std::endl << except.what() << std::endl;
					cmd = 0;
				}
				if (cmd)
					std::cout << result_ru[cmd - 1] << std::endl;
			}
		}
		else if (en)
		{
			int count{ 0 };
			english.prefixSearch(prefix, result_en);
			for (const auto& string : result_en) {
				std::cout << ++count << " " << string << std::endl;
			};
			if (count)
			{
				std::cout << "�������� ������� ����� - ������� �����" << std::endl;
				std::string sel;
				int cmd{ 0 };

				std::cin >> sel;
				try
				{
					cmd = std::stoi(sel);
				}
				catch (std::exception& except)
				{
					std::cout << std::endl << except.what() << std::endl;
					cmd = 0;
				}
				if (cmd)
					std::cout << result_en[cmd - 1] << std::endl;
			}
		}

	} while (true);

	return 0;
}