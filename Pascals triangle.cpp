#include <iostream>
#include <vector>
#include <string>
#include <stdlib.h>

using namespace std;

bool enough = false;

string to_string( vector<int> num );

vector<int> sum( vector<int> a, vector<int> b) {

  vector<int> sum;

  int longest = max( a.size(), b.size() );
  a.resize( longest );
  b.resize( longest );
  sum.resize( longest + 1);


  int carry = 0;
  for( int i = 0; ; i++ ) {

    if ((carry == 0) && (i >= longest)) {
      break;
    }

    int i_sum = a[i] + b[i] + carry;
    sum[i] = i_sum % 10;
    carry = i_sum / 10;

    // cout << carry << endl;
  }


  return sum;

}

string to_string( vector<int> num ) {
  string ret;
  vector<int>::reverse_iterator rit;
  for( rit = num.rbegin(); rit != num.rend(); rit++ ) {
    ret += *rit + 48;
  }

  while( ret[0] == '0') {
    ret.erase(0, 1);
  }

  if (ret.size() >= 61) {
    enough = true;
  }

  return ret;
}

int main() {

  vector< vector< vector<int> > > p;

  vector< vector<int> > row;

  // vector<int> column;

  /* numbers */
  vector<int> zero;
  // zero.push_back( 0 );

  vector<int> one;
  one.push_back( 1 );

  row.push_back( zero );
  row.push_back( one );
  row.push_back( zero );

  // row.push_back( column );
  p.push_back( row );

  int line = 2;

  vector<int> cur_num;

  p.resize( 1000 );

  cout << 1 << endl;

  for( int i = 0; i < 1000; i++) {
    p[i].reserve(i + 1 + 2);
  }

  while( !enough ) {
    // p.resize( p.size() + 1);
    // cout << p.size() << endl;

    p[ line - 1].reserve( line );

    // cout << line << endl;
    for( int i = 1; i <= line; i++) {

      if (i == 1) {
        p[ line - 1].push_back( zero );
        // continue;
      }

      // cout << "I:" << i << endl;
      // cout << to_string( p[line - 2][i - 1] );
      cur_num = sum(p[line - 2][i - 1], p[line - 2][i]);
      p[ line - 1 ].push_back( cur_num );

      // cout << "pushed back" << endl;

      cout << to_string( cur_num );

      // cout << "printed string" << endl;
      if (i == line) {
        p[ line - 1].push_back( zero );
        cout << endl;
      } else {
        cout << " ";
      }

      // cout << "case" << line << " ended" << endl;
    }
    line++;
  }

  return 0;
}
