   /* Use the slash-star style comments or the system won't see your
      identification information */
   /*
   ID: samotbn1
   TASK: ride
   LANG: C++    
   PROG: ride             
   */
   /* LANG can be C++11 or C++14 for those more recent releases */
   #include <bits/stdc++.h>
   #define endl '\n'
   using namespace std;
   typedef long long ll;
   typedef vector<int> vi;
   typedef pair<int,int> pii;

   void solve()
   {
      ofstream fout ("ride.out");
      ifstream fin ("ride.in");
      string s1, s2;
      int n1, n2;
      char c;
      n1 = n2 = 1;
      fin>>s1>>s2;
      for(int i =0; i < s1.size(); i++)
      {
         c = s1[i];
         n1 *= ((int)c - 64);
      }
      for(int i =0; i < s2.size(); i++)
      {
         c = s2[i];
         n2 *= ((int)c-64);
      }
      if((n1 % 47) == (n2 % 47))
         fout<<"GO"<<endl;
      else
         fout<<"STAY"<<endl;
   }

   int main()
   {
      cin.tie(0);
      ios::sync_with_stdio(0);

      solve();
      return 0;
   }
