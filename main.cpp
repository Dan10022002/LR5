#include <iostream>
#include <unordered_map>
#include <string>
#include <iterator>
#include <map>
#include <algorithm>
#include <vector>
#include <functional>
#include <set>
#include <ctime>

int main(){
std::cout << "Task one" << "\n";
std::unordered_multimap <int, std::string> Map;
std::cout << "Enter a number of elements: " << std::endl;
int n;
std::cin >> n;
std::cin.ignore(10, '\n');
for(int i=0;i<=n-1;++i)
{
    std::cout << "Enter your text: " << std::endl;
    std::string S1;
    std::getline(std::cin, S1);
    srand(time(nullptr));
    Map.emplace(std::pair<int, std::string>(rand()%21-10,S1));
}
auto p = [](const std::pair<int, std::string> m) 
    { 
        std::cout << "<" << m.first << ", " << m.second << ">  ";
    };
std::for_each(Map.cbegin(), Map.cend(), p);
std::cout << "\n";
Map.erase(5);
Map.erase(7);
std::for_each(Map.cbegin(), Map.cend(), p);
std::cout << "\n";
Map.insert( { {10, "loser"}, {10, "I'm"}, {10, "Hi"}});
std::for_each(Map.cbegin(), Map.cend(), p);
std::cout << "\n";
std::map <int, std::string> Map2;
auto iter = Map.begin();
auto iter2 = Map.end();
for (; iter != iter2; iter++)
    {
        Map2.insert(std::pair<int, std::string>(iter->first, iter->second));
    }
std::for_each(Map2.cbegin(), Map2.cend(), p);
std::cout << "\n";
std::cout << "The end of the task one." << "\n";
std::cout << "Task two." << "\n";
int a;
a = std::count_if(Map2.begin(), Map2.end(), [](const std::pair<int, std::string> m) {return ((m.first >= -1) && (m.first <= 5));});
std::cout << "There are " << a << " elements with keys [-1;5].";
std::cout << "\n";
std::vector<int> Vec;
std::transform(Map2.cbegin(), Map2.cend(), std::back_inserter(Vec),[](const std::pair<int, std::string> m) {return m.first;});
std::for_each(Vec.begin(), Vec.end(), [](int n){std::cout << n << " ";});
std::cout << "\n";
std::cout << "The end of the task two." << "\n";
std::cout << "Task three." << "\n";
auto x = std::find(Vec.begin(), Vec.end(), 0);
if (x == Vec.end())
    {
        std::cout << "There isn't a needed element." ;
    }
else std::cout << "There is a needed element." ;
std::cout << "\n";
std::replace_if(Vec.begin(), Vec.end(), std::bind(std::less<int>(), std::placeholders::_1, 0),-1);
std::for_each(Vec.cbegin(), Vec.cend(), [](int n){std::cout << n << " ";});
std::cout << "\n";
std::sort(Vec.begin(), Vec.end(), [](int m, int n) {return m > n;});
std::set<int> Set(Vec.begin(), Vec.end());
std::for_each(Set.cbegin(), Set.cend(), [](int n){std::cout << n << " ";});
std::cout << "\n";
std::cout << "The end of the task three.";
return 0;
}
