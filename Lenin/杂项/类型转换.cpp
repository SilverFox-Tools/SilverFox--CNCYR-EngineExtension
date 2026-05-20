#include <string>
#include <windows.h>
#include <vector>

using std::string;
using std::wstring;
using std::vector;

string wstring转string(const wstring& wstr)
{
    if (wstr.empty()) return "";

    int len = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
    if (len <= 0) return "";

    string str(len - 1, 0);

    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], len, NULL, NULL);

    return str;
}

string ANSI转UTF8(const string& ansi)
{
    if (ansi.empty()) return "";

    // ANSI -> UTF-16
    int wlen = MultiByteToWideChar(CP_ACP, 0, ansi.c_str(), ansi.length(), NULL, 0);
    wstring wbuf(wlen, L'\0');
    MultiByteToWideChar(CP_ACP, 0, ansi.c_str(), -1, &wbuf[0], wlen);

    // UTF-16 -> UTF-8
    int ulen = WideCharToMultiByte(CP_UTF8, 0, wbuf.c_str(), wbuf.length(), NULL, 0, NULL, NULL);
    string ubuf(ulen, '\0');
    WideCharToMultiByte(CP_UTF8, 0, wbuf.c_str(), -1, &ubuf[0], ulen, NULL, NULL);

    return ubuf;
}

string charpp转string(char** ppArgs, int nNumArgs)
{
    if (!ppArgs || nNumArgs <= 0) return "";

    string result;
    for (int i = 0; i < nNumArgs; i++) {
        if (ppArgs[i]) {
            result += ppArgs[i];
            if (i < nNumArgs - 1) result += " ";
        }
    }
    return result;
}

char* string转charp(string str)
{
    char* pStr = new char[str.length() + 1];
    strcpy_s(pStr, str.length() + 1, str.c_str());
	return pStr;
}

vector<string> charpp转list_vector(char** ppArgs, int nNumArgs)
{
    vector<string> result;
    if (!ppArgs || nNumArgs <= 0) return result;

    // 直接从ppArgs转，跳过第0个（程序名）
    for (int i = 1; i < nNumArgs; i++) {
        if (ppArgs[i]) {
            result.push_back(ANSI转UTF8(ppArgs[i]));
        }
    }
    return result;
}