#pragma once
#include <iostream>
#include <vector>
#include <fstream> 
void read_arr(const std::string& filename, std::vector<std::string>& arr, int& n)
{
	std::fstream fs;

	fs.open(filename, std::fstream::in);
	if (fs.is_open())
	{
		fs >> n;  // читаем размер массива
		std::string tmp_string;

		// читаем из файла строки
		for (int i = 0; i < n; i++)
		{
			fs >> tmp_string; 
			arr.push_back(tmp_string);
		}

		fs.close(); // закрываем файл
	}
}