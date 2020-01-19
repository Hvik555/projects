#include <iostream>
#include <functional>
#include "msort.h"
#include <vector>
#include <string>
#include <algorithm>
#include "msort.h"

struct string_size_less
{

  bool operator()( const std::string& a,
                   const std::string& b ) const
  {
    return a.size() < b.size();
  }

};

const int max = 1024;

int main()
{
  int your_mark = 1;
  // 2-es
  int x[] = { 3, 7, 4, 1, 2, 5, 6, 9 };
  mergesort_util<int> ui( x, sizeof( x ) / sizeof( x[ 0 ] ), false );
  ui.split( 0, 7 );

  std::string s[] = { "Cobol", "ABAP", "Simula", "C" };
  mergesort_util<std::string> us( s, sizeof( s ) / sizeof( s[ 0 ] ), false );
  us.split( 0, 1 );

  int v[ max ];
  for( int i = 0; i < max; ++i )
  {
    v[ i ] = max - i;
  }
  mergesort_util<int> um( v, max, false );
  um.split( 0, max - 1 );

  if ( 1 == x[ 2 ] && 7 == x[ 1 ] && 4 == x[ 3 ] &&
       max - 1 == v[ 0 ] && max == v[ 1 ] && 2 == v[ max - 1 ] )
  {
    your_mark = s[ 2 ].size() - s[ 0 ].size();
  }

  // 3-as
  us.split( 0, 3 );

  ui.set_merge_on();
  ui.sort();

  mergesort_util<int> uv( v, max );
  uv.split( 0, max - 1 );


  if ( 1 == v[ 0 ] && max == v[ max - 1 ] &&
      "C" == s[ 2 ] && "Cobol" == s[ 1 ] &&
      3 == x[ your_mark ] && 7 == x[ 6 ] )
  {
    your_mark = x[ 0 ] + x[ 1 ];
  }

  // 4-es
  mergesort_util<int, std::greater<int> > vg( v, max );
  vg.sort();

  mergesort( s, sizeof( s ) / sizeof( s[ 0 ] ), string_size_less() );

  mergesort( x, sizeof( x ) / sizeof( x[ 0 ] ) );

  if ( "C" == s[ 0 ] && "ABAP" == s[ 1 ] && v[ 0 ] == max && 1 == x[ 0 ] &&
        3 == x[ 2 ] && max / 2 == v[ max / 2 ] )
  {
    your_mark = x[ your_mark ];
  }
  //5-os
 std::vector<std::string> vsl( s, s + sizeof( s ) / sizeof( s[ 0 ] ) );
  mergesort( vsl, std::greater<std::string>() );

  std::vector<int> vi;
  vi.push_back( 3 );
  vi.push_back( 1 );
  vi.push_back( 8 );
  vi.push_back( 2 );
  vi.push_back( 5 );

  mergesort( vi );

  if ( 1 == vi[ 0 ] && 8 == vi[ your_mark ] && 3 == vi[ 2 ] &&
       "C" == vsl[ 2 ] && 'S' == vsl[ 0 ][ 0 ] )
  {
    your_mark = vsl[ 1 ].size();
  }
  std::cout << "Your mark is " << your_mark;
  std::endl( std::cout );
}
