#include <iostream>
#include <vector>
using namespace std;
void capsToSmall(string &str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            str[i] = str[i] + 32;
        }
    }
}
// encryption
string encryptn(string str, int key, vector<int> &arr)
{
    string enc = "";
    for (int i = 0; i < str.length(); i++)
    {
        string temp = to_string((str[i] - 'a' + key) % 26);
        enc += temp;
        arr.push_back((str[i] - 'a' + key) % 26);
    }
    cout << "your encrypted string is " << enc << endl;
    // for (auto it : arr)
    // {
    //     cout << it << "   ";
    // }
    return enc;
}
string decryptn(string enc, int key, vector<int> &arr)
{
    string dec = "";
    for (int i = 0; i < arr.size(); i++)
    {
        string temp = to_string((arr[i] + 'a' - key%26));
        dec += temp;
        arr.pop_back();
    }
    cout << "your decrypted string is " << dec << endl;
    // for (auto it : arr)
    // {
    //     cout << it << "   ";
    // }
    // cout << "noi thing in arr";
}
int main()
{
    int key, choice;
    string plainText = "";
    // string en = "";
    string str1;
    string str2;
    vector<int> arr;
    int quit = 0;
    while (quit == 0)
    {
        cout << "\nEnter 1 to enter text and key.\n";
        cout << "Enter 2 to encrypt text.\n";
        cout << "Enter 3 to decrypt text.\n";
        cout << "Enter 4 to quit.\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter text:\n";
            cin >> plainText;
            cout << "Enter key:";
            cin >> key;
            // function to convert capital letters into small letters
            capsToSmall(plainText);
            cout << "your string is " << plainText << "\n";

            break;
        case 2:
            str1 = encryptn(plainText, key, arr);
            //  cout << "\nyour encrypted string is " << en;

            break;
        case 3:
            str2 = decryptn(str1, key, arr);
            break;
        case 4:
            quit = 1;

            break;
        default:
            break;
        }
    }

    return 0;
}