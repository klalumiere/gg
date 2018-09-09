/* -*-mode:c++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
  string line;
  bool keep_next_line = false;

  while ( getline( cin, line ) ) {
    if ( keep_next_line ) {
      keep_next_line = ( line.back() == '\\' );
      cout << line << endl;
      continue;
    }

    for ( size_t i = 0; i < line.length(); i++ ) {
      char c = line [ i ];

      if ( c == '#' ) {
        keep_next_line = ( line.back() == '\\' );
        cout << line << endl;
      }
      else if ( isspace( c ) ) {
        continue;
      }

      break;
    }
  }

  return 0;
}
