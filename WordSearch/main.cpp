#include <iostream>
#include <vector>
#include <fstream>
#include <queue>

using namespace std;

struct Node {
    char val;
    vector<Node*> children;
    bool endOfWord;
    Node(char c, bool endWord) : val(c), endOfWord(endWord) {}
    Node(char c) : val(c), endOfWord(false) {}
    Node() : val(0), endOfWord(false) {}
};

enum Direction{
    Up,
    Down,
    Left,
    Right,
    DiagUpLeft,
    DiagUpRight,
    DiagDownLeft,
    DiagDownRight
};

class WordSearch{

    vector<vector<char>> ts;
    Node dict;

public:

    void PrintDict(Node *root)
    {
        if(root == NULL)
            return;

        queue<Node*> qn;
        qn.push(root);
        qn.push(NULL);

        while(!qn.empty())
        {
            Node* tn = qn.front();
            qn.pop();
            if(tn == NULL && !qn.empty())
            {
                qn.push(NULL);
                cout << endl;
            } else if(tn != NULL){
                char out = tn->endOfWord?tn->val:tolower(tn->val);

                for(auto child:tn->children)
                {
                    char c = child->endOfWord?child->val:tolower(child->val);
                    cout << c;
                    qn.push(child);
                }
                cout << "|";
            }
        }
        cout << endl << endl;
    }

    bool AddWordToDict(string word)
    {
        Node *node = &dict;
        for(int x = 0; x < word.length(); x++)
        {
            if(isalpha(word[x])){
                Node *temp = node;
                char letter = toupper(word[x]);
                for(auto let:node->children)
                {
                    if(let->val == letter)
                    {
                        node = let;
                        break;
                    }
                }
                if(temp == node)
                {
                    node = new Node(letter);
                    if(x == word.length() - 1)
                        node->endOfWord = true;
                    temp->children.push_back(node);
                }
            }
        }
        return true;
    }

    bool IsDictionaryWord(string word)
    {
        Node* node = &dict;
        for(int x = 0; x <= word.length(); x++)
        {
            Node *temp = node;
            char letter = toupper(word[x]);
            for(auto let:node->children)
            {
                if(let->val == letter)
                    node = let;
            }
            if(temp == node && node->endOfWord == true)
                return true;
        }
        return false;
    }

    bool IsPartialDictionaryWord(string word)
    {
        Node* node = &dict;
        for(int x = 0; x < word.length(); x++)
        {
            Node *temp = node;
            char letter = toupper(word[x]);
            for(auto let:node->children)
            {
                if(let->val == letter)
                    node = let;
            }
            if(temp == node)
                return false;
        }
        return true;
    }

    bool ReadDictFile(string dictfile)
    {
        ifstream inf(dictfile);
        string line;

        if(!inf.is_open())
            return false;
        while(!inf.eof())
        {
            vector<char> letters;
            getline(inf, line);
            AddWordToDict(line);
        }
        return true;
    }

    void PrintMatrix()
    {
        for(int x = 0; x < ts.size(); x++)
        {
            for(int y = 0; y < ts[x].size(); y++)
                cout << ts[x][y];
            cout << endl;
        }
    }

    bool ReadMatrixFile(string matrixFile)
    {
        ifstream inf(matrixFile);
        string line;

        if(!inf.is_open())
            return false;

        while(!inf.eof())
        {
            vector<char> letters;
            getline(inf, line);
            for(int x = 0; x < line.length(); x++)
                letters.push_back(toupper(line[x]));
            if(letters.size() > 0)
                ts.push_back(letters);
        }
        return true;
    }

    WordSearch(string matrixFile, string dictFile)
    {
        if(!ReadDictFile(dictFile))
        {
            cout << "Error reading dict file" << endl;
            return;
        }

        if(!ReadMatrixFile(matrixFile))
        {
            cout << "Error reading matrix file" << endl;
            return;
        }
    }

    string Search(int x, int y, int maxX, int maxY, Direction dir)
    {
        string temp, found;
        int tX = x, tY = y;
        while(tX < maxX && tX >= 0 &&
              tY < maxY && tY >= 0)
        {
            temp += ts[tX][tY];
            if(!IsPartialDictionaryWord(temp))
                return found;
            if(IsDictionaryWord(temp))
                found = temp;
            switch(dir)
            {
            case Up:
                tX--;
                break;
            case Down:
                tX++;
                break;
            case Left:
                tY--;
                break;
            case Right:
                tY++;
                break;
            case DiagUpLeft:
                tX--; tY--;
                break;
            case DiagUpRight:
                tX--; tY++;
                break;
            case DiagDownLeft:
                tX++; tY--;
                break;
            case DiagDownRight:
                tX++; tY++;
            }
        }
        return found;
    }

    bool findWords()
    {
        for(int x = 0; x < ts.size(); x++)
        {
            for(int y = 0; y < ts[x].size(); y++)
            {
                string found;
                found = Search(x,y,ts.size(), ts[x].size(), Up);
                if(found.length() > 0)
                    cout << "Found word " << found << " at: " << x << "," << y << " going up" << endl;
                found.clear();

                found = Search(x,y,ts.size(), ts[x].size(), Down);
                if(found.length() > 0)
                    cout << "Found word " << found << " at: " << x << "," << y << " going down" << endl;
                found.clear();

                found = Search(x,y,ts.size(), ts[x].size(), Left);
                if(found.length() > 0)
                    cout << "Found word " << found << " at: " << x << "," << y << " going left" << endl;
                found.clear();

                found = Search(x,y,ts.size(), ts[x].size(), Right);
                if(found.length() > 0)
                    cout << "Found word " << found << " at: " << x << "," << y << " going right" << endl;
                found.clear();

                found = Search(x,y,ts.size(), ts[x].size(), DiagUpLeft);
                if(found.length() > 0)
                    cout << "Found word " << found << " at: " << x << "," << y << " going diagonally up left" << endl;
                found.clear();

                found = Search(x,y,ts.size(), ts[x].size(), DiagUpRight);
                if(found.length() > 0)
                    cout << "Found word " << found << " at: " << x << "," << y << " going diagonally up right" << endl;
                found.clear();

                found = Search(x,y,ts.size(), ts[x].size(), DiagDownLeft);
                if(found.length() > 0)
                    cout << "Found word " << found << " at: " << x << "," << y << " going diagonally down left" << endl;
                found.clear();

                found = Search(x,y,ts.size(), ts[x].size(), DiagDownRight);
                if(found.length() > 0)
                    cout << "Found word " << found << " at: " << x << "," << y << " going diagonally down right" << endl;
                found.clear();
            }
        }

        return true;
    }
};

int main()
{
    WordSearch ws("wordsearch.txt", "WordList.txt");
    ws.findWords();
    return 0;
}