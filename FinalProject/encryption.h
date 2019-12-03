#ifndef ENCRYPTION_H
#define ENCRYPTION_H
#include "blowfish.h"

#include <string>
#include <cstdlib>
#include <iomanip>
#include <iostream>
using namespace std;

string Algorithm1(string input)
{
  // Reverse Text

  for( int i = 0; i < input.length(); i++ )
  {
    input[i] = tolower(input[i]);
  }

  char* output = new char[input.length()];
  for(int i = 1; i <= input.length(); i++)
  {
      output[i-1] = input[input.length() - i];
  }
  return output;
}

string Algorithm2(string input)
{
  // Ceasar Ciphers

  srand(time(NULL));
  int key = rand()%24 + 1;
  char c;

  cout << "The key is: " << key << endl << endl;

  for( int i = 0; i < input.length(); i++ )
  {
    input[i] = tolower(input[i]);
  }

  char* encrypt = new char[input.length()];
  for( int x = 0; x < input.length(); x++ )
  {
    c = input[x];
    if( c+key > 122 )
      encrypt[x] = ((c + key)%122)+96;
    else if( c <= 57 && c >= 48 )
      encrypt[x] = c;
    else if( c < 97 )
    {
      encrypt[x] = c;
    }
    else
      encrypt[x] = (c + key);

  }
  return encrypt;
}

string Algorithm3(string input)
{
  // Monoalphabetic Cipher

  char a = 'm', b = 'n', c = 'b', d = 'v', e = 'c', f = 'x', g = 'z', h = 'a', i = 's';
  char j = 'd', k = 'f', l = 'g', m = 'h', n = 'j', o = 'k', p = 'l', q = 'p', r = 'o';
  char s = 'i', t = 'u', u = 'y', v = 't', w = 'r', x = 'e', y = 'w', z = 'q';

  cout << "a b c d e f g h i j k l m n o p q r s t u v w x y z" << endl;
  cout << a << " " << b << " " << c << " " << d << " " << e << " " << f << " ";
  cout << g << " " << h << " " << i << " " << j << " " << k << " " << l << " ";
  cout << m << " " << n << " " << o << " " << p << " " << q << " " << r << " ";
  cout << s << " " << t << " " << u << " " << v << " " << w << " " << x << " ";
  cout << y << " " << z << " " << endl << endl;


  for( int i = 0; i < input.length(); i++ )
  {
    input[i] = tolower(input[i]);
  }

  char* output = new char[input.length()];
  for( int x = 0; x < input.length(); x++ )
  {
    if( input[x] == 'a' )
      output[x] = a;
    else if( input[x] == 'b' )
      output[x] = b;
    else if( input[x] == 'c' )
      output[x] = c;
    else if( input[x] == 'd' )
      output[x] = d;
    else if( input[x] == 'e' )
      output[x] = e;
    else if( input[x] == 'f' )
      output[x] = f;
    else if( input[x] == 'g' )
      output[x] = g;
    else if( input[x] == 'h' )
      output[x] = h;
    else if( input[x] == 'i' )
      output[x] = i;
    else if( input[x] == 'j' )
      output[x] = j;
    else if( input[x] == 'k' )
      output[x] = k;
    else if( input[x] == 'l' )
      output[x] = l;
    else if( input[x] == 'm' )
      output[x] = m;
    else if( input[x] == 'n' )
      output[x] = n;
    else if( input[x] == 'o' )
      output[x] = o;
    else if( input[x] == 'p' )
      output[x] = p;
    else if( input[x] == 'q' )
      output[x] = q;
    else if( input[x] == 'r' )
      output[x] = r;
    else if( input[x] == 's' )
      output[x] = s;
    else if( input[x] == 't' )
      output[x] = t;
    else if( input[x] == 'u' )
      output[x] = u;
    else if( input[x] == 'v' )
      output[x] = v;
    else if( input[x] == 'w' )
      output[x] = w;
    else if( input[x] == 'x' )
      output[x] = x;
    else if( input[x] == 'y' )
      output[x] = y;
    else if( input[x] == 'z' )
      output[x] = z;
    else //if( input[i] <= 57 && input[i] >= 48 )
    {
      output[x] = input[x];
    }
    /*
    else
      output[x] = '/';
    */
  }

  return output;
}

void BlowFishAlg(string input)
{
  BLOWFISH bf("FEDCBA9876543210");
  string asdf;
  asdf = bf.Encrypt_CBC(input);
  cout << "Encrypted: " << asdf << endl;
  asdf = bf.Decrypt_CBC(asdf);
  cout << "Decrypted: " << asdf;
}

//FOR VIGENERE SHIFT
int find_index(char letter){
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    for(int i = 0; i < alphabet.length(); i++){
     if(tolower(letter) == alphabet[i])
         return i+1;
    }

     return 0;
}

char find_letter(int index){
    string alphabet = "abcdefghijklmnopqrstuvwxyz";

    return alphabet[index-1];

}

char find_upperletter(int index){
      string alphabet = "abcdefghijklmnopqrstuvwxyz";

    return toupper(alphabet[index-1]);

}

int find_numchar(string str){
   int len = 0;

   for(int i = 0; i < str.length(); i++){
    if(find_index(str[i]) > 0)
        len++;
   }

 return len;
}

void Algorithm4(string message, string key)
{
  int index;
  int arr_len = find_numchar(key);
  int* keys = new int[arr_len];
  int count = 0;

  for(int i = 0; i < key.length(); i++){
      if(find_index(key[i]) == 0){
          continue;
      }
      keys[count] = find_index(key[i]);
      count++;
  }

  for(int i = 0;i < arr_len; i++){
   cout<<keys[i];
   cout<<' ';
  }
  cout<<'\n';

  int arrCount = 0;
   for(int i =0; i < message.length(); i++){
     if(message[i] == ' '){ // if space
        cout<<' ';
        continue;
     }

     index=find_index(message[i]);
     if(index == 0){ // if not a letter
       cout<<message[i];
       continue;
     }

      if(arrCount >= arr_len)
          arrCount = 0;

      int sum = index + keys[arrCount];
      arrCount++;

      if(sum >26){
          int left = sum%26;
          if(isupper(message[i])){
              cout<<find_upperletter(left);
          }else{
          cout<<find_letter(left);
          }
      }else{
      if(isupper(message[i])){
       cout<<find_upperletter(sum);
      } else{
       cout<<find_letter(sum);
      }
      }
  }
  cout<<"\n";
  //cout << index << endl;
  delete [] keys;
}



#endif
