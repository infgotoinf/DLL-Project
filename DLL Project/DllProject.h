#pragma once

#ifdef DLLPROJECT_EXPORTS
#define DLLPROJECT_API __declspec(dllexport)
#else
#define DLLPROJECT_API __declspec(dllimport)
#endif

#include <string>

// Белый
extern "C" DLLPROJECT_API bool open_file(const char* path);
extern "C" DLLPROJECT_API bool close_file(const char* path);
extern "C" DLLPROJECT_API const char* read(const char* path);

// Манько
extern "C" DLLPROJECT_API bool write(const char* path, const char* info);
extern "C" DLLPROJECT_API bool find(const char* path, const char* thing);
extern "C" DLLPROJECT_API int count(const char* path, const char* thing);

// Васильев
extern "C" DLLPROJECT_API bool save(const char* path, const char* filename, const char* data);