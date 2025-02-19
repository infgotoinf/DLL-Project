#pragma once

#ifdef DLLPROJECT_EXPORTS
#define DLLPROJECT_API __declspec(dllexport)
#else
#define DLLPROJECT_API __declspec(dllimport)
#endif

// Манько
extern "C" DLLPROJECT_API void write(const char* info);
extern "C" DLLPROJECT_API bool find(const char* thing);

// Васильев
extern "C" DLLPROJECT_API bool save(const char* filename, const char* data);