#include "String.h"

string::string()
{
	this->_capacity = 1;
	this->_size = 0;
	this->_data = new char[_capacity];
	_data[_size] = '\0';
}

string::string(const string& str)
{
	this->_capacity = str._capacity;
	this->_data = new char[this->_capacity];
	this->_size = str._size;
	strcpy(this->_data, str._data);
	_data[_size] = '\0';
}

string::string(const string& str, size_t pos, size_t len)
{
	if (pos + len > str._size) return;
	this->_size = len;
	this->_capacity = 1;
	while (this->_capacity <= len) this->_capacity *= 2;
	this->_data = new char[_capacity];
	for (size_t i = pos; i < pos + len; i++)
		this->_data[i - pos] = str._data[i];
	_data[_size] = '\0';
}

string::string(const char* s)
{
	if (s == NULL) return;
	this->_size = strlen(s);
	this->_capacity = 1;
	while (this->_capacity <= _size) this->_capacity *= 2;
	this->_data = new char[_capacity];
	strcpy(this->_data, s);
	_data[_size] = '\0';
}

string::string(const char* s, size_t n)
{
	if (s == NULL) return;
	this->_size = strlen(s) * n;
	this->_capacity = 1;
	while (this->_capacity <= _size) this->_capacity *= 2;
	this->_data = new char[_capacity];
	for (int j = 0; j < n; j++)
		for (int i = 0; i < strlen(s); i++)
			_data[i + strlen(s) * j] = s[i];
	_data[_size] = '\0';
}

string::string(size_t n, char c)
{
	this->_size = n;
	this->_capacity = 1;
	while (_capacity <= _size) this->_capacity *= 2;
	this->_data = new char[_capacity];
	for (int i = 0; i < n; i++)
		_data[i] = c;
	_data[_size] = '\0';
}

string::~string()
{
	if (_data != NULL) {
		this->_capacity = 0;
		this->_size = 0;
		delete[] this->_data;
	}
}

string& string::operator=(const string& str)
{
	if (this == &str) {
		return *this;
	}
	if (_data != NULL) {
		delete[] _data;
	}
	this->_capacity = str._capacity;
	this->_data = new char[this->_capacity];
	this->_size = str._size;
	strcpy(this->_data, str._data);
	_data[_size] = '\0';
	return *this;
}

string& string::operator=(const char* s)
{
	if (_data != NULL) {
		delete[] _data;
	}
	this->_size = strlen(s);
	this->_capacity = 1;
	while (this->_capacity <= _size) this->_capacity *= 2;
	this->_data = new char[_capacity];
	strcpy(this->_data, s);
	_data[_size] = '\0';
	return *this;
}

string& string::operator=(char c)
{
	this->_size = 1;
	this->_capacity = 2;
	this->_data = new char[_capacity];
	_data[0] = c;
	_data[_size] = '\0';
	return *this;
}

size_t string::size() const
{
	return _size;
}

size_t string::length() const
{
	return _size;
}

void string::resize(size_t n)
{
	if (n <= _size) {
		char* res = new char[n];
		for (int i = 0; i < n; i++)
			res[i] = _data[i];
		delete[] _data;
		this->_size = n;
		_data = res;
	}
	/*else {
		char* res = new char[n + _size];
		for (int i=)
	}*/
}

void string::resize(size_t n, char c)
{
}

size_t string::capacity() const
{
	return _capacity;
}

void string::reserve(size_t n)
{
}

void string::clear()
{
}

bool string::empty() const
{
	return false;
}

void string::shrink_to_fit()
{
}

