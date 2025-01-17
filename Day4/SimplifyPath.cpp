#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string simplifyPath(string path)
    {
        vector<string> dirOrFiles;
        stringstream ss(path);
        string dirOrFile;
        while (getline(ss, dirOrFile, '/'))
        {
            if (!dirOrFiles.empty() && dirOrFile == "..")
                dirOrFiles.pop_back();
            else if (dirOrFile != "." && dirOrFile != "" && dirOrFile != "..")
                dirOrFiles.push_back(dirOrFile);
        }
        string ans = "";
        for (string dirOrFile : dirOrFiles)
            ans += "/" + dirOrFile;
        if (ans.empty())
            return "/";
        return ans;
    }
};