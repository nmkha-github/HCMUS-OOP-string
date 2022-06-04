#ifndef STRING_H_
#define STRING_H_
#include <cstring>
#include <iostream>
#define _CRT_SECURE_NO_WARNINGS
#pragma warning (disable: 4996)

class string {
private:
	size_t _capacity;
	size_t _size;
	char* _data;
	static const size_t npos = -1;
public:
	//Constructor
	string();
	string(const string& str);
	string(const string& str, size_t pos, size_t len);
	string(const char* s);
	string(const char* s, size_t n);
	string(size_t n, char c);
	//Destructor
	~string();
	//Assignment
	string& operator= (const string& str);
	string& operator= (const char* s);
	string& operator= (char c);
	//Capacity
	size_t size() const;
	size_t length() const;
	void resize(size_t n);
	void resize(size_t n, char c);
	size_t capacity() const;
	void reserve(size_t n = 0);
	void clear();
	bool empty() const;
	void shrink_to_fit();
	//Character access
	const char& operator[] (size_t pos) const;
	const char& at(size_t pos) const;
	const char& back() const;
	const char& front() const;
	//Modifiy
	string& operator+= (const string& str);
	string& operator+= (const char* s);
	string& operator+= (char c);
	string& append(const string& str);
	string& append(const string& str, size_t subpos, size_t sublen);
	string& append(const char* s);
	string& append(const char* s, size_t n);
	string& append(size_t n, char c);
	void push_back(char c);
	string& assign(const string& str);
	string& assign(const string& str, size_t subpos, size_t sublen);
	string& assign(const char* s);
	string& assign(const char* s, size_t n);
	string& assign(size_t n, char c);
	string& insert(size_t pos, const string& str);
	string& insert(size_t pos, const string& str, size_t subpos, size_t sublen);
	string& insert(size_t pos, const char* s);
	string& insert(size_t pos, const char* s, size_t n);
	string& insert(size_t pos, size_t n, char c);
	string& erase(size_t pos, size_t len);
	string& replace(size_t pos, size_t len, const string& str);
	string& replace(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen);
	string& replace(size_t pos, size_t len, const char* s);
	string& replace(size_t pos, size_t len, const char* s, size_t n);
	string& replace(size_t pos, size_t len, size_t n, char c);
	void swap(string& str);
	void pop_back();
	//Operation
	const char* c_str() const;
	const char* data() const;
	size_t copy(char* s, size_t len, size_t pos = 0) const;
	size_t find(const string& str, size_t pos = 0) const;
	size_t find(const char* s, size_t pos = 0) const;
	size_t find(const char* s, size_t pos, size_t n) const;
	size_t find(char c, size_t pos = 0) const;
	size_t rfind(const string& str, size_t pos) const;
	size_t rfind(const char* s, size_t pos) const;
	size_t rfind(const char* s, size_t pos, size_t n) const;
	size_t rfind(char c, size_t pos) const;
	size_t find_first_of(const string& str, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos = 0) const;
	size_t find_first_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_of(char c, size_t pos = 0) const;
	size_t find_last_of(const string& str, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos = npos) const;
	size_t find_last_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_of(char c, size_t pos = npos) const;
	size_t find_first_not_of(const string& str, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos = 0) const;
	size_t find_first_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_first_not_of(char c, size_t pos = 0) const;
	size_t find_last_not_of(const string& str, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos = npos) const;
	size_t find_last_not_of(const char* s, size_t pos, size_t n) const;
	size_t find_last_not_of(char c, size_t pos = npos) const;
	string substr(size_t pos = 0, size_t len = npos) const;
	int compare(const string& str) const;
	int compare(size_t pos, size_t len, const string& str) const;
	int compare(size_t pos, size_t len, const string& str, size_t subpos, size_t sublen) const;
	int compare(const char* s) const;
	int compare(size_t pos, size_t len, const char* s) const;
	int compare(size_t pos, size_t len, const char* s, size_t n) const;
};
string operator+ (const string& lhs, const string& rhs);
string operator+ (const string& lhs, const char* rhs);
string operator+ (const char* lhs, const string& rhs);
string operator+ (const string& lhs, char          rhs);
string operator+ (char          lhs, const string& rhs);
bool operator== (const string& lhs, const string& rhs);
bool operator== (const char* lhs, const string& rhs);
bool operator== (const string& lhs, const char* rhs);
bool operator!= (const string& lhs, const string& rhs);
bool operator!= (const char* lhs, const string& rhs);
bool operator!= (const string& lhs, const char* rhs);
bool operator<  (const string& lhs, const string& rhs);
bool operator<  (const char* lhs, const string& rhs);
bool operator<  (const string& lhs, const char* rhs);
bool operator<= (const string& lhs, const string& rhs);
bool operator<= (const char* lhs, const string& rhs);
bool operator<= (const string& lhs, const char* rhs);
bool operator>  (const string& lhs, const string& rhs);
bool operator>  (const char* lhs, const string& rhs);
bool operator>  (const string& lhs, const char* rhs);
bool operator>= (const string& lhs, const string& rhs);
bool operator>= (const char* lhs, const string& rhs);
bool operator>= (const string& lhs, const char* rhs);
void swap(string& x, string& y);
std::istream& operator>> (std::istream& is, string& str);
std::ostream& operator<< (std::ostream& os, const string& str);
std::istream& getline(std::istream& is, string& str, char delim);
std::istream& getline(std::istream& is, string& str);
#endif