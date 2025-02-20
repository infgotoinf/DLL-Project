#pragma once

#ifdef DLLPROJECT_EXPORTS
#define DLLPROJECT_API __declspec(dllexport)
#else
#define DLLPROJECT_API __declspec(dllimport)
#endif

#include <string>

// Белый
extern "C" DLLPROJECT_API bool open_file(const std::string& path);
extern "C" DLLPROJECT_API bool close_file(const std::string& path);
extern "C" DLLPROJECT_API std::string read(const std::string& path);

// Манько
extern "C" DLLPROJECT_API void write(const std::string& path, std::string& info);
extern "C" DLLPROJECT_API bool find(const std::string& path, std::string& thing);
extern "C" DLLPROJECT_API int count(const std::string& path, std::string& thing);

// Васильев
extern "C" DLLPROJECT_API bool save(const std::string& path, const char* filename, const char* data);