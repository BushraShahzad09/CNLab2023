#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
string formatted_string(string &str)
{
    string new_str = "";
    for (auto it : str)
    {
        if (isalpha(it))
        {
            new_str += tolower(it);
        }
    }
    return new_str;
}
int main()
{
    char matrix[5][5];
    set<char> s;
    string plain_text = "";
    string key;
    cout << "Enter plain text you want to encrypt: ";
    getline(cin, plain_text);
    plain_text = formatted_string(plain_text);
    cout << "Enter key: ";
    getline(cin, key);

    int i = 0, j = 0;

    for (auto it : key)
    {
        if (s.find(it) == s.end())
        {
            matrix[i][j] = it;
            j++;
            if (j == 5)
            {
                j = 0;
                i++;
            }
        }
        s.insert(it);
    }
    char letter;
    for (int k = 0; k < 26; k++)
    {
        letter = char(k + 97);
        if (letter == 'j')
        {
            letter = 'i';
        }
        if (s.find(letter) == s.end())
        {
            matrix[i][j] = letter;
            j++;
            if (j == 5)
            {
                j = 0;
                i++;
            }
        }
        s.insert(letter);
    }
    // printing matrix
    cout << "\nprinting matrix\n";
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << "\n";
    }
    // length of string
    string pair_text = "";
    for (int q = 0; q < plain_text.length(); q++)
    {
        if (pair_text.length() != 0 && pair_text[pair_text.length() - 1] == plain_text[q])
        {
            pair_text += 'x';
            q++;
        }
        pair_text += plain_text[q];
    }
    int len = pair_text.length();
    if (len % 2 != 0)
    {
        pair_text += 'x';
    }
    cout << "\nplain_text: " << plain_text << "\n";
    cout << "\npair_text: " << pair_text << "\n";
    string enc = "";

    for (int q = 0; q < pair_text.length(); q += 2)
    {
        char l1 = pair_text[q];
        char l2 = pair_text[q + 1];
        int row1, col1, row2, col2;
        for (int row = 0; row < 5; row++)
        {
            for (int col = 0; col < 5; col++)
            {
                if (matrix[row][col] == l1)
                {
                    row1 = row;
                    col1 = col;
                }
                if (matrix[row][col] == l2)
                {
                    row2 = row;
                    col2 = col;
                }
            }
        }
        enc += matrix[row1][col2];
        enc += matrix[row2][col1];
    }
    cout << "\nEncrypted string: " << enc << "\n";
    // decryption
    string dec = "";
    string dec_temp = "";
    for (int q = 0; q < enc.length(); q += 2)
    {
        char l1 = enc[q];
        char l2 = enc[q + 1];
        int row1, col1, row2, col2;
        for (int row = 0; row < 5; row++)
        {
            for (int col = 0; col < 5; col++)
            {
                if (matrix[row][col] == l1)
                {
                    row1 = row;
                    col1 = col;
                }
                if (matrix[row][col] == l2)
                {
                    row2 = row;
                    col2 = col;
                }
            }
        }
        dec_temp += matrix[row1][col2];
        dec_temp += matrix[row2][col1];
    }
    cout << "\nDecrypted temp string: " << dec_temp << "\n";
    for (int q = 0; q < dec_temp.length(); q++)
    {
        if (dec_temp[q] == 'x')
        {
            dec_temp[q] = dec_temp[q - 1];
        }
    }
    cout << "\nDecrypted  string: " << dec_temp << "\n";

    return 0;
}