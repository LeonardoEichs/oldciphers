#include <iostream>
#include <string>
using namespace std;

class Playfair {
public:
    void encrypt(string key, string text, bool ij, bool enc ) {
	      createGrid(key, ij);
        prepareText(text, ij, enc);
	      if (enc)
          encrypt(1);
        else
          encrypt(-1);
	      show();
    }

private:
    string txt_f;
    char _m[5][5];

    void encrypt(int direction) {
	     int a, b, c, d;
       string txt;
	     for (string::const_iterator i = txt_f.begin(); i != txt_f.end(); i++ ) {
	        if (getCharPos(*i++, a, b ))
		        if (getCharPos(*i, c, d )) {
		            if( a == c ) {
                  txt += getChar( a, b + direction );
                  txt += getChar( c, d + direction );
                }
		            else if(b == d) {
                  txt += getChar( a + direction, b );
                  txt += getChar( c + direction, d );
                }
		            else {
                  txt += getChar( c, b );
                  txt += getChar( a, d );
                }
		        }
        }
	      txt_f = txt;
    }

    void show() {
      cout << "----------------\n OUTPUT:\n>>> ";

      string::iterator si = txt_f.begin();
      int cnt = 0;
      while (si != txt_f.end()) {
	       cout << *si;
         si++;
         cout << *si << " ";
         si++;
	       if( ++cnt >= 26 )
             cout << endl, cnt = 0;
       }
    }

    char getChar(int a, int b) {
      return _m[(b + 5) % 5][(a + 5) % 5];
    }

    bool getCharPos( char l, int &a, int &b ) {
      for (int y = 0; y < 5; y++ )
        for (int x = 0; x < 5; x++ )
		      if (_m[y][x] == l ){
            a = x;
            b = y;
            return true;
          }
      return false;
    }

    void prepareText(string text, bool ij, bool enc) {
      for (string::iterator si = text.begin(); si != text.end(); si++) {
        *si = toupper(*si);
        if (*si < 65 || *si > 90)
          continue;
	      if (*si == 'J' && ij)
          *si = 'I';
	      else if (*si == 'Q' && !ij)
          continue;
	      txt_f += *si;
      }

      if (enc) {
	       string txt = "";
         size_t len = txt_f.length();
	       for (size_t x = 0; x < len; x += 2 ) {
		         txt += txt_f[x];
		         if (x + 1 < len) {
		             if (txt_f[x] == txt_f[x + 1])
                    txt += 'X';
		             txt += txt_f[x + 1];
		         }
	       }
	       txt_f = txt;
	    }
	    if (txt_f.length() & 1)
        txt_f += 'X';
    }

    void createGrid( string key, bool ij ) {
	    key += "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
      string nk = "";
	    for( string::iterator si = key.begin(); si != key.end(); si++ ) {
	       *si = toupper( *si );
         if( *si < 65 || *si > 90 )
            continue;
	       if( ( *si == 'J' && ij ) || ( *si == 'Q' && !ij ) )
            continue;
	       if( nk.find( *si ) == -1 )
            nk += *si;
	    }
	    copy (nk.begin(), nk.end(), &_m[0][0] );
    }
};

int main( int argc, char* argv[] ) {
    string key, i, txt;
    bool ij, enc;

    cout << "(E)ncrypt\n(D)ecrypt\n>> ";
    getline(cin, i);
    enc = ( i[0] == 'e' || i[0] == 'E' );

    cout << "Enter a key:\n>> ";
    getline(cin, key );

    cout << "I <-> J (Y/N):\n>> ";
    getline(cin, i );
    ij = ( i[0] == 'y' || i[0] == 'Y' );

    cout << "Enter the text:\n>> ";
    getline( cin, txt );

    Playfair pf;
    pf.encrypt( key, txt, ij, enc);

    return 0;
}
