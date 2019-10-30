#pragma once
#include <string>
#include <vector>
#include <windows.h>

#pragma comment(lib, "User32.lib")

#undef tstring
#undef tcout
#if defined(_UNICODE) || defined(UNICODE)
#define tstring std::wstring
#define tcout std::wcout
#else
#define tstring std::string
#define tcout std::cout
#endif

class FileFinder {
	WIN32_FIND_DATA ffd;
	HANDLE _handle;

public:
	FileFinder(LPCTSTR pattern) { _handle = FindFirstFile(pattern, &ffd); }
	~FileFinder() { FindClose(_handle); }
	const TCHAR* FindFirst() const {
		return _handle != INVALID_HANDLE_VALUE ? ffd.cFileName : nullptr;
	}
	const TCHAR* FindNext() {
		return FindNextFile(_handle, &ffd) ? ffd.cFileName : nullptr;
	}
	std::vector<tstring> GetAllNames() {
		std::vector<tstring> result;
		for (auto name = FindFirst(); name; name = FindNext())
			result.push_back(name);
		return result;
	}
};