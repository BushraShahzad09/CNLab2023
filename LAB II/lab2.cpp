#include<bits/stdc++.h>
#include <cstdlib>
using namespace std;
map<char,int>mp;
void keyOrder(string key)
{
	for(int i=0;i<key.length();i++)
	{
		mp[key[i]]=i;
	}
}
string encryption(string text,string key)
{
	string enc="";
	int keyLength=key.length();
	int textLength=text.length();
	int row,col;
	if(textLength%keyLength)
	{
		row=textLength/keyLength;
		row++;
	}
	else row=textLength/keyLength;
	col=keyLength;
	char matrix[row][col];
	int index=0;
	// encryption matrix
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(text[index]=='\0')
			{
				matrix[i][j]='*';
				break;
			}
			else if((text[index]>=65 && text[index]<=90) || (text[index]>=97 && text[index]<=122)  || text[index]==' ') 
			{
				matrix[i][j]=text[index];
				index++;
			}
		}
	}
	// print encrypted matrix
		for(int i=0;i<row;i++)
			{
			for(int j=0;j<col;j++)
			{
				cout<<matrix[i][j]<<" ";
			}
			cout<<"\n";
		}
	// print map
	cout<<"\nprinting map :\n";
	for(auto &it:mp)
	{
		cout<<it.first<<" "<<it.second<<" ";
		cout<<endl;
	}
	// encryting string
	for(auto &it:mp)
	{
		int x=it.second;
		for(int i=0;i<row;i++)
		{
			enc+=matrix[i][x];
		}
	}
	//cout<<"\n";
//	cout<<enc<<" ";
	return enc;
}
string decryption(string enc,string key)
{
	string dec="";
	int keyLength=key.length();
	int encLength=enc.length();
	int row2,col2;
	if(encLength%keyLength)
	{
		row2=encLength/keyLength;
		row2++;
	}
	else row2=encLength/keyLength;
	col2=keyLength;
	char matrix2[row2][col2];
	int index2=0;
		// decryption matrix
/*	for(int i=0;i<row2;i++)
	{
		for(int j=0;j<col2;j++)
		{
			matrix2[i][j]=enc[index2];
			index2++;
		}
	}*/
	for(auto &it:mp)
	{
		int x=it.second;
		for(int i=0;i<row2;i++)
		{
			matrix2[i][x]=enc[index2];
			index2++;
		}
	}
		// print decrypted matrix
		for(int i=0;i<row2;i++)
			{
			for(int j=0;j<col2;j++)
			{
				cout<<matrix2[i][j]<<" ";
			}
			cout<<"\n";
		}
		// changing decrypted matrix into encrypted matrix
	//	char decCipher[row2][col2];
   	//	auto it::mp.begin();
   	//	int index=0;
   	   // for(auto &it:mp)
   	   // {
   	    //	it.second=index;
   	  // 	index++;
	//	}
   	    
    /*	int l = 0;
    	int j;
    	int k=0;
    	while ( key[l]!='\0')
    	{
        	j = mp[key[l++]];
        	for (int i=0; i<row2; i++)
       		{
            	decCipher[i][k]=matrix2[i][j];
        	}
        	k++;
    	}
    		// print decrypted matrix_opopop
    		cout<<"\nprinting chamged matrix:\n";
		for(int i=0;i<row2;i++)
			{
			for(int j=0;j<col2;j++)
			{
				cout<<decCipher[i][j]<<" ";
			}
			cout<<"\n";
		}*/
		//decryting string using map
			for(int i=0;i<row2;i++)
			{
				for(int j=0;j<col2;j++)
				{
					if(matrix2[i][j]!='*')
					dec+=matrix2[i][j];
				}
			}
			cout<<"\nDecrypted : ";
	cout<<dec<<" ";
	
	return dec;
}
int main()
{
	string str="";
	string key="";
	cout<<"Enter the text you want to encrypt : ";
    getline(cin,str);
	cout<<"Enter key : ";
    getline(cin,key);
    int counter=0;
	int choice;
	string str1="";
	string str2="";
    while(counter==0)
    {
    	cout<<"\nEnter 1 to encrypt or 2 to decrypt and 3 to quit.\n";
    	cin>>choice;
    	keyOrder(key);
    	switch(choice)
    	{
    		case 1:
    			str1= encryption(str,key);
    			cout<<"\nEncrypted text : ";
    			cout<<str1;
    			break;
    		case 2:
    			str2=decryption(str1,key);
    			break;
    		case 3:
    			counter=1;
    			break;
    		default:
    			cout<<"Invalid input\n";
		}
	}
	return 0;
	
}
