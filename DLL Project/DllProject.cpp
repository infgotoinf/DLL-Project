#include "pch.h"
#include <utility>
#include <limits.h>
#include "DllProject.h"
#include <fstream>
#include <windows.h>
#include <memory>
#include <string>

// Манько
// Запись в файл
void write(const char* info)
{
	std::ofstream file;
	file << info;
}

// Поиск в файле
bool find(const char* thing)
{
	// Запись введённой фигни в str
	std::string str_thing = "";
	for (int i = 0; thing[i] != '\0'; i++)
	{
		str_thing += thing[i];
	}
	
	std::ifstream file1;
	std::string str;

	// Сам поиск
	while (std::getline(file1, str))
	{
		std::string context = "";
		for (char const& character : str)
		{
			context.push_back(character);
			if (context.size() > str_thing.size())
			{
				context = context.substr(1, str_thing.size());
			}
			else if (context.size() < str_thing.size())
			{
				continue;
			}
			if (str_thing == context) return true;
		}
	}
	return false;
}

// Васильев
// экспрт 
bool save(const char* filename, const char* data) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }

    // форм даннх
    file << "Formatted Data:\n";
    file << data << "\n";
    file.close();
    return true;
}