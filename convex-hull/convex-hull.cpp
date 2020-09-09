//PROBLEM LINK:https://omegaup.com/arena/IOI15Geom/practice/#problems/Convex-hull
//PROBLEM PATH:/home/josephy/competitive-programming/geometry/convex-hull.cpp
#include<bits/stdc++.h>
#define fi first 
#define se second
#define pb push_back
#define pob pop_back
#define pof pop_front
#define pf push_front
#define sz(x) (int) x.size()
#define space(x) getline(cin,x)
#define all(x) x.begin(), x.end()
#define mcm( a, b) a*b/__gcd(a,b)
#define adj(x) vector<  vector < x > >  
#define clr(x) memset( x, 0, sizeof(x))
#define press(x) setprecision(x)<<fixed
#define deb(x) cerr<< #x<< "is "<< x<<"\n"
using namespace std;

typedef long double ld;
typedef set < int > si;
typedef vector< int > vi;
typedef long long int ll;
typedef set < string > ss;
typedef pair < ll, ll > pll;
typedef pair < int , int > pii;
typedef unsigned long long int ull;

void DBG()
{
    cerr<<"]\n";
    return;
}

template<class H, class... T > 
void DBG( H h, T... t)
{
    cerr << h;
    if( sizeof...(t))
        cerr<<", ";
    DBG(t...);
}
#define dbg(...) cerr <<" values[ "<< #__VA_ARGS__ << " ] ---> [ ", DBG(__VA_ARGS__)

template < typename... T> 
void read(T&... args)
{
    ((cin >> args), ...);
}

template < typename... T > 
void print(T... args)
{
    ((cout << args <<" "), ...);
}

constexpr ll mod = 1e9+7;
constexpr ll MAXN = 1e6+3;
constexpr int inf = 2e9;
constexpr short dx4[] = {-1,0,1,0};
constexpr short dy4[] = {0,1,0,-1};
constexpr short dx8[] = {-1,-1,-1,0,1,1,1,0};
constexpr short dy8[] = {-1,0,1,1,1,0,-1,-1};

struct pps
{
    double x, y;

    pps operator + ( const pps & b)
    {
        return {x+b.x, y+b.y};
    }

    pps operator - ( const pps & b)
    {
        return {x-b.x , y-b.y};
    }

    pps operator * ( const double & c)
    {
        return {x*c, y*c};
    }

    double operator * ( const pps & b) /// producto cruz
    {
        return ( x * b.y) - (y * b.x);
    }

    double operator ^ ( const pps & b)
    {
        return (x*b.x) + (y*b.y);
    }
};

double area ( pps a, pps b, pps c)
{
    return abs( ( ( a * b)  * ( a* c)) ) / 2 ;
}

bool colineales ( pps a ,pps b, pps c)
{
    if( area ( a,b,c) == 0 )
        return true;
    return false;
}

bool sentido ( pps a, pps o, pps b)
{
    return ((a - o) * ( b - o) )> 0 ;
}

bool perpendicular  ( pps a, pps o, pps b)
{
    if( ( (a-o) ^ ( b-o) ) == 0 )
        return true;
    return false;
}

bool comp ( pps a, pps b )
{
    if ( a.x != b.x)
        return a.x < b.x;
    return a.y < b.y;
}

vector < pps > ch;
int n;
int x,y;
pps vx[100002];


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    
    cin>>n;
    for(int c = 0; c<n; c++ )
    {
        cin>>vx[c].x >> vx[c].y;
    }
    sort(vx, vx+n, comp);

    for(int c = 0; c<n; c++ )
    {
        while( ch.size() >= 2 )
        {
            pps ult = ch[ch.size()-1];
            pps pen = ch[ch.size()-2];
            if( sentido(ult, pen, vx[c]))
                ch.pop_back();
            else
                break;
        }
        ch.push_back(vx[c]);
    }
      for(int c = n-2; c>=0; c-- )
    {
        while( ch.size() >= 2 )
        {
            pps ult = ch[ch.size()-1];
            pps pen = ch[ch.size()-2];
            if( sentido(ult, pen, vx[c]))
                ch.pop_back();
            else
                break;
        }
        ch.push_back(vx[c]);
    }
        ch.pop_back();
    cout<<sz(ch)<<"\n";
    for(auto v:ch)
        cout<<v.y<<" "<<v.x<<"\n";

}