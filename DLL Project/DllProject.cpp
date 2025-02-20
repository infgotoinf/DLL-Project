#include "pch.h"
#include <utility>
#include <limits.h>
#include "DllProject.h"
#include <fstream>
#include <string>

std::ifstream file;
std::ofstream file1;

// �����
// �������� �����
bool open_file(const std::string& path) {
	file.open(path);
	if (file.is_open())
	{
		file.close();
		return true;
	}
	return false;
}

// �������� �����
bool close_file(const std::string& path) {
	if (file.is_open()) file.close();
	if (file1.is_open()) file1.close();
	if (!file.is_open() || !file1.is_open()) {
		return true;
	}
	return false;
}

// ������ �����
std::string read(const std::string& path) {
	file.open(path);
	if (file.is_open())
	{
		return "Error!";
	}
	std::string content, line;
	while (std::getline(file, line)) {
		content += line + "\n";
	}
	file.close();
	return content;
}

// ������
// ������ � ����
bool write(const std::string& path, const std::string& info)
{
	file1.open(path);
	if (!file1.is_open())
	{
		return false;
	}
	file1 << info;
	return true;
}

// ����� � �����
bool find(const std::string& path, const std::string& thing)
{
	std::string text, str;
	while (std::getline(file, str))
	{
		text += str + '\n';
	}

	return text.find(thing) != std::string::npos;
}

// ����� � �����
int count(const std::string& path, const char* thing)
{
	int count = 0;
	return count;
}

// ��������
// ������ 
bool save(const std::string& path, const char* filename, const char* data) {
	file1.open(filename);
	file.open(path);
    if (!file1.is_open() || !file.is_open()) {
        return false;
    }

    // ���� �����
	std::string text, str;
	while (std::getline(file, str))
	{
		text += str + '\n';
	}
    file1 << text + data;

    return true;
}