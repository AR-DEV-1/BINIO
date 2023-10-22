#include <fstream>
#include <iostream>
using namespace std;
const int MAX = 100;
int buff [MAX];
int main()
{
  for(int j=0; j<MAX; j++)
  buff[j] = j;
  ofstream os("binio.dat", ios::binary);

  os.write( reinterpret_cast<char*>(buff), MAX*sizeof(int) );
  os.close();

  for(j=0; j<MAX; j++)
    buff[j] = 0;

  ifstream is("binio.dat", ios::binary);

  is.read( reinterpret_cast<char*>(buff), MAX*sizeof(int) );


    for(j=0; j<MAX; j++)
      if ( buff[j] != j )
      { cerr << "Data is incorrect/corrupted, Restart the app\n"; return 1; }
  cout << "Data has been accessed with ease , It has been written!\n";
  return 0;
}
