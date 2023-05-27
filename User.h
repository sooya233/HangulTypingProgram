#include <string>
#include <vector>
using namespace std;

class User{
private:
    vector<string> user_lists;
    string username;
    string common_path;
public:
    User();
    void showUsers();
    bool selectUser(string name);
    string getUser();
    void createUser(string name);
    void deleteUser(string name);
};