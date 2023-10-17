#pragma once
#include <tchar.h>
#include <Windows.h>
#include "base91.h"

#ifndef READRESOURCE
#define READRESOURCE

char* resource_loader(LPCSTR  lpName, LPSTR lpType);

WCHAR* resource_decode(char* resource_data, size_t resource_size);

WCHAR* resource_encode(char* resource_data, size_t resource_size);

#endif // READRESOURCE
