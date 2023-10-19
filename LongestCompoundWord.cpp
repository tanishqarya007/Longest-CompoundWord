#include<bits/stdc++.h>
#include "Trie.cpp"
#include "readFile.cpp"
using namespace std;

static bool compare(string &a, string &b)
{
    return a.size() < b.size();
}

struct queuePair
{
    string compoundWord;
    string word;
    int index;
};

int main()
{
    auto start = chrono::high_resolution_clock::now();
    Trie trie;

    vector<string> value = fileReading();

    sort(value.begin(), value.end(), compare);

    queue<queuePair> q;

    // cout << value.size() << endl;

    vector<int> visited(value.size(), 0);

    for (int k = 0; k < value.size(); k++)
    {
        vector<int> indices = trie.getIndices(value[k]);

        for (auto i : indices)
        {
            q.push({value[k], value[k].substr(i), k});
        }

        trie.insert(value[k]);
    }

    string longest = "";
    string secondLongest = "";

    while (!q.empty())
    {
        auto top = q.front();
        q.pop();

        string compoundWord = top.compoundWord;
        string suff = top.word;
        int index = top.index;

        vector<int> indices = trie.getIndices(suff);

        for (auto i : indices)
        {
            if (i == suff.length() && !visited[index])
            {
                visited[index] = 1;
                if (compoundWord.length() > longest.length())
                {
                    secondLongest = longest;
                    longest = compoundWord;
                }
                else if (compoundWord.length() > secondLongest.length())
                {
                    secondLongest = compoundWord;
                }
            }
            q.push({compoundWord, suff.substr(i), index});
        }
    }

    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    cout << "Longest Compound Word : " << longest << endl;
    cout << "Second Longest Compound Word : " << secondLongest << endl;
    cout << "Time taken to process the input: " << duration.count() << " milli seconds" << endl;
    return 0;
}