#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

#include "encryption.h"

void EncryptionMenu()
{
  cout << "*********************************" << endl;
  cout << "*  1) Reverse Encryption.       *" << endl;
  cout << "*  2) Ceasar Cipher.            *" << endl;
  cout << "*  3) Monoalphabetic Cipher.    *" << endl;
  cout << "*  4) Vigenere SHIFT.           *" << endl;
  cout << "*  5) Blowfish Encryption.      *" << endl;
  cout << "*-------------------------------*" << endl;
  cout << "*  -1) QUIT                     *" << endl;
  cout << "*********************************" << endl;
}


int main()
{
  bool running = true;
  while( running )
  {
    int pick;
    EncryptionMenu();
    cout << "Select Encryption to use (1-5): ";
    cin >> pick;
    cin.ignore();

    if ( pick == 1 )
    {
      string a;
      cout << "Enter a sentence: " << endl;
      getline(cin, a);
      cout << endl;
      cout << Algorithm1(a) << endl << endl;
      char yes;
      cout << "choose a different algorithm (y or n): ";
      cin >> yes;
      if( yes != 'y' )
      {
        system("clear");
        running = false;
      }
      else
        system("clear");
    }
    else if ( pick == 2 )
    {
      string b;
      cout << "Enter a sentence: " << endl;
      getline(cin, b);
      cout << endl;
      cout << Algorithm2(b) << endl << endl;
      char yes;
      cout << "choose a different algorithm (y or n): ";
      cin >> yes;
      if( yes != 'y' )
      {
        system("clear");
        running = false;
      }
      else
        system("clear");
    }
    else if ( pick == 3 )
    {
      string c;
      cout << "Enter a sentence: " << endl;
      getline(cin, c);
      cout << endl;
      cout << Algorithm3(c) << endl << endl;
      char yes;
      cout << "choose a different algorithm (y or n): ";
      cin >> yes;
      if( yes != 'y' )
      {
        system("clear");
        running = false;
      }
      else
        system("clear");
    }
    else if ( pick == 4 )
    {
      string message;
      string key = "Vigenere";
      cout << "Enter Message to Be Encrypted:\n";
      getline(std::cin,message);
      cout << endl;
      cout << "Key: " << key << endl;
      Algorithm4(message, key);
      cout << endl;
      char yes;
      cout << "choose a different algorithm (y or n): ";
      cin >> yes;
      if( yes != 'y' )
      {
        running = false;
        system("clear");
      }
      else
        system("clear");
    }
    else if ( pick == 5 )
    {
      string d;
      cout << "Enter a sentence: " << endl;
      getline(cin, d);
      cout << endl;
      BlowFishAlg(d);
      cout << endl;
      char yes;
      cout << "choose a different algorithm (y or n): ";
      cin >> yes;
      if( yes != 'y' )
      {
        running = false;
        system("clear");
      }
      else
        system("clear");
    }
//********************************************************
    else if ( pick == -1 )
    {
      running = false;
      system("clear");
    }
    else
    {
      system("clear");
      cout << "try again." << endl;
    }

  }

}
