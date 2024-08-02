#include <iostream>
using namespace std;

string encrypt(string text, int s)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
                result += char((text[i] - 'A' + s) % 26 + 'A');
            else
                result += char((text[i] - 'a' + s) % 26 + 'a');
        }
        else
        {

            result += text[i];
        }
    }
    return result;
}

string decrypt(string text, int s)
{
    string result = "";
    for (int i = 0; i < text.length(); i++)
    {
        if (isalpha(text[i]))
        {
            if (isupper(text[i]))
                result += char((text[i] - 'A' + 26 - s) % 26 + 'A');
            else
                result += char((text[i] - 'a' + 26 - s) % 26 + 'a');
        }
        else
        {
            result += text[i];
        }
    }
    return result;
}

int main()
{
    string text;
    cout << "Enter the following text: ";
    getline(cin, text);

    int a;
    cout << "Enter the key: ";
    cin >> a;

    string encryptedText = encrypt(text, a);
    cout << "The Encrypted text: " << encryptedText << endl;
    cout << "The Decrypted text: " << decrypt(encryptedText, a) << endl;

    return 0;
}
