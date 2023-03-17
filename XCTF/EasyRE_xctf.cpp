#include <bits/stdc++.h>
using namespace std;

int main()
{
	char flag[] = "xIrCj~<r|2tWsv3PtI\x7Fzndka";
	for (char& i : flag)
		i = static_cast<char>((i ^ 6) - 1);
		
    reverse(begin(flag), end(flag));
	
	cout << flag;
}