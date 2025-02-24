#include "pch.h"
#include <utility>
#include <limits.h>
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
	std::ifstream file;
	std::ofstream file1;
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
	std::string content, line;
	while (std::getline(file, line)) {
		content += line + "\n";
	}
	file.close();
	const char* c = "lol";
	const char* cont = content.c_str();
	return c;
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
	std::string text, str;
	while (std::getline(file, str))
	{
		text += str + '\n';
	}

	return text.find(thing) != std::string::npos;
}

// Поиск в файле
int count(const char* path, const char* thing)
{
	int count = 0;
	return count;
}

// Васильев
// экспрт 
bool save(const char* path, const char* filename, const char* data) {
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