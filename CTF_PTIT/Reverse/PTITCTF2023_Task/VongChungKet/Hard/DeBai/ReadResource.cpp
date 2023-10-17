#include "ReadResource.h"

char* resource_loader(LPCSTR  lpName, LPSTR lpType) {
	char* hLoadedResource = NULL;
	HMODULE m_hInstance = GetModuleHandleA(NULL);
	HRSRC hResource = FindResourceA(m_hInstance, lpName, lpType);
	if (!hResource) {
		return hLoadedResource;
	}

	hLoadedResource = (char*)LoadResource(m_hInstance, hResource);
	return hLoadedResource;
}

WCHAR* resource_decode(char* resource_data, size_t resource_size) {
	struct basE91 b91;
	char decoded[MAX_PATH] = { 0 };
	WCHAR* pwcsName = NULL;
	int nChars = 0;

	basE91_init(&b91);
	basE91_decode(&b91, resource_data, resource_size, decoded);
	basE91_decode_end(&b91, decoded);
	nChars = MultiByteToWideChar(CP_ACP, 0, decoded, -1, NULL, 0);
	pwcsName = new WCHAR[nChars];
	MultiByteToWideChar(CP_ACP, 0, decoded, -1, (LPWSTR)pwcsName, nChars);
	return pwcsName;
}

WCHAR* resource_encode(char* resource_data, size_t resource_size) {
	struct basE91 b91;
	char encoded[MAX_PATH] = { 0 };
	WCHAR* pwcsName = NULL;
	int nChars = 0;

	basE91_init(&b91);
	basE91_encode(&b91, resource_data, resource_size, encoded);
	basE91_encode_end(&b91, encoded);
	nChars = MultiByteToWideChar(CP_ACP, 0, encoded, -1, NULL, 0);
	pwcsName = new WCHAR[nChars];
	MultiByteToWideChar(CP_ACP, 0, encoded, -1, (LPWSTR)pwcsName, nChars);
	return pwcsName;
}