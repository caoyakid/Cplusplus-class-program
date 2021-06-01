#include <iostream>
#include <string>
using namespace std;

/* prototype declaration*/
string replaceSubstring(string, string, string);
string replaceSubstring(const char *, const char *, const char *);

int main()
{
    string s1, s2, s3;
    cout << "Enter the first string: " << endl;
    getline(cin, s1);
    cout << "Enter the second string: " << endl;
    getline(cin, s2);
    cout << "Enter the third string: " << endl;
    getline(cin, s3);

    cout << "New string would be: " << endl
         << replaceSubstring(s1, s2, s3) << endl;

    return 0;
}

string replaceSubstring(string s1, string s2, string s3)
{
    return replaceSubstring(s1.data(), s2.data(), s3.data());
}

string replaceSubstring(const char *s1, const char *s2, const char *s3)
{
    const char *find = strstr(s1, s2);
    string result;
    while (find)
    {
        result.append(s1, find - s1);
        result.append(s3);
        s1 = find + strlen(s2);
        find = strstr(s1, s2);
    }
    result.append(s1);
    return result;
}
