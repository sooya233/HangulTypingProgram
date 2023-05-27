#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <filesystem>
#include "User.h"
using namespace std;

User::User() {
	common_path = "./Users";

	for (auto &it : filesystem::directory_iterator(common_path)) {
		string user_name = it.path().string();
		user_lists.push_back(user_name.substr(common_path.length()+1));
	}
}

void User::showUsers() {
	for (int i = 0; i < user_lists.size(); i++) {
		cout << user_lists[i] << endl;
	}
	cout << endl;
}

bool User::selectUser(string name) {
	auto result = find(user_lists.begin(), user_lists.end(), name);

	// 유저를 찾지 못했을 때
	if (result == user_lists.end()) {
		cout << "유저를 찾지 못했습니다. 다시 선택해 주세요." << endl;
		return false;
	}
	else {
		username = user_lists[result - user_lists.begin()];
		return true;
	}
}

string User::getUser() {
	return username;
}

void User::createUser(string name) {
	string user_path = common_path + "/" + name;
	string data_path = "./Default";

	auto result = filesystem::create_directories(user_path);
	if (result) {
		filesystem::copy(data_path, user_path, filesystem::copy_options::recursive);
		cout << "성공적으로 유저를 생성하였습니다." << endl << endl;
	}
	else {
		cout << "이미 존재하는 유저입니다. 다시 시도해 주세요." << endl << endl;
	}
}

void User::deleteUser(string name) {
	string user_path = common_path + "/" + name;

	auto result = filesystem::remove_all(user_path);
	if (result) {
		cout << "성공적으로 유저를 삭제하였습니다." << endl << endl;
	}
	else {
		cout << "삭제하려는 유저가 존재하지 않습니다. 다시 시도해 주세요." << endl << endl;
	}
}