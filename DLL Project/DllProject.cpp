#include "pch.h"
#include <utility>
#include "DllProject.h"
#include <fstream>
#include <string>

// Белый
// Открытие файла
bool open_file(const char* path) {
	std::ifstream file;
	file.open(path);
	if (file.is_open())
	{
		file.close();
		return true;
	}
	return false;
}

// Закрытие файла
bool close_file(const char* path) {
	std::ifstream file(path);
	std::ofstream file1(path);
	if (file.is_open()) file.close();
	if (file1.is_open()) file1.close();
	if (!file.is_open() || !file1.is_open()) {
		return true;
	}
	return false;
}

// Чтение файла
const char* read(const char* path) {
	std::ifstream file;
	file.open(path);
	if (!file.is_open())
	{
		return "Error!";
	}
	std::string line;
	char* content = new char[0] {};
	while (std::getline(file, line)) {
		strcpy_s(content, strlen(content) + line.size(), line.c_str());
	}
	file.close();

	return content;
}

// Манько
// Запись в файл
bool write(const char* path, const char* info)
{
	std::ofstream file1;
	file1.open(path);
	if (!file1.is_open())
	{
		return false;
	}
	file1 << info;
	return true;
}

// Поиск в файле
bool find(const char* path, const char* thing)
{
	std::ifstream file;
	std::string line, text, thing_str;

	file.open(path);
	while (std::getline(file, line)) {
		text += line + '\n';
	}
	file.close();
	thing_str.assign(thing, strlen(thing));

	return text.find(thing) != std::string::npos;
}

// Подсчёт совпадений в файле
int count(const char* path, const char* thing)
{
	std::ifstream file;
	std::string line, text, thing_str;

	file.open(path);
	while (std::getline(file, line)) {
		text += line + '\n';
	}
	file.close();
	thing_str.assign(thing, strlen(thing));

	if (text.find(thing) != std::string::npos)
	{
		int i = 1;
		size_t found = text.find(thing);
		for (; text.find(thing, found + 1) != std::string::npos; i++)
		{
			found = text.find(thing, found + 1);
		}
		return i;
	}
	return 0;
}

// Васильев
// экспрт 
bool save(const char* path, const char* filename, const char* data)
{
	std::ifstream file;
	std::ofstream file1;
	file1.open(filename);
	file.open(path);
    if (!file1.is_open() || !file.is_open()) {
        return false;
    }

    // форм даннх
	std::string text, str;
	while (std::getline(file, str))
	{
		text += str + '\n';
	}
    file1 << text + data;

    return true;
}

// Удаление файла
bool deleteFile(const char* path)
{
	return DeleteFileA(path);
}

// Размер в байтах
int b_size(const char* path)
{
	std::ifstream file(path, std::ios::binary | std::ios::ate);
	if (!file) {
		return -1;
	}
	return file.tellg();
}