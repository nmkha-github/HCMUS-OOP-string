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
	for (int i=0; i<str._size; i++)
		this->_data[i] = str._data[i];
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
	for (int i = 0; i < _size; i++)
		this->_data[i] = s[i];
	_data[_size] = '\0';
}

string::string(const char* s, size_t n)
{
	if (s == NULL && n > strlen(s)) return;
	this->_size = n;
	this->_capacity = 1;
	while (this->_capacity <= _size) this->_capacity *= 2;
	this->_data = new char[_capacity];
	for (int i = 0; i < n; i++)
		_data[i] = s[i];
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
		for (int i = std::min(n, _size); i < std::max(n, _size); i++)
			_data[i] = '\0';
		this->_size = n;
		_data[_size] = '\0';
	}
}

void string::resize(size_t n, char c)
{
	if (n >= _capacity) {
		while (_capacity <= n) _capacity *= 2;
		char* res = new char[_size];
		for (int i = 0; i < _size; i++)
			res[i] = _data[i];
		delete[] _data;
		_data = new char[_capacity];
		for (int i = 0; i < _size; i++)
			_data[i] = res[i];
		delete[] res;
	}
	for (int i = std::min(n, _size); i < std::max(n, _size); i++)
		_data[i] = c;
	this->_size = n;
	_data[_size] = '\0';
}

size_t string::capacity() const
{
	return _capacity;
}

void string::reserve(size_t n)
{
	if (n >= _capacity) {
		while (_capacity <= n) _capacity *= 2;
		char* temp = new char[_size];
		for (int i = 0; i < _size; i++)
			temp[i] = _data[i];
		delete[] _data;
		_data = new char[_capacity];
		for (int i = 0; i < _size; i++)
			_data[i] = temp[i];
		_data[_size] = '\0';
	}
}

void string::clear()
{
	delete[] _data;
	this->_data = new char[0];
	this->_size = 0;
	this->_capacity = 1;
}

bool string::empty() const
{
	return _size == 0;
}

void string::shrink_to_fit()
{
	if (_size != _capacity) {
		char* temp = new char[_size];
		for (size_t i = 0; i < _size; i++)
			temp[i] = _data[i];
		delete[] _data;
		_data = temp;
		_capacity = _size;
	}
}

const char& string::operator[](size_t pos) const
{
	if (pos >= _size) return '\0';
	return _data[pos];
}

const char& string::at(size_t pos) const
{
	if (pos >= _size) return '\0';
	return _data[pos];
}

const char& string::back() const
{
	if (_size == 0) return '\0';
	return _data[_size - 1];
}

const char& string::front() const
{
	if (_size == 0) return '\0';
	return _data[0];
}

string& string::operator+=(const string& str)
{
	reserve(_size + str._size);
	for (int i = 0; i < str._size; i++)
		_data[_size + i] = str._data[i];
	_size += str._size;
	_data[_size] = '\0';
	return *this;
}

string& string::operator+=(const char* s)
{
	if (s != NULL) {
		reserve(_size + strlen(s));
		for (int i = 0; i < strlen(s); i++)
			_data[_size + i] = s[i];
		_size += strlen(s);
		_data[_size] = '\0';
	}
	return *this;
}

string& string::operator+=(char c)
{
	reserve(_size + 1);
	_data[_size] = c;
	_size += 1;
	_data[_size] = '\0';
	return *this;
}

string& string::append(const string& str)
{
	return operator+=(str);
}

string& string::append(const string& str, size_t subpos, size_t sublen)
{
	if (str._data != NULL && subpos < str._size) {
		if (subpos + sublen > str._size)
			sublen = str._size - subpos;
		reserve(_size + sublen);
		for (int i = 0; i < sublen; i++)
			_data[_size + i] = str._data[subpos + i];
		_size += sublen;
	}
	return *this;
}

string& string::append(const char* s)
{
	return operator+=(s);
}

string& string::append(const char* s, size_t n)
{
	if (s != NULL && n <= strlen(s)) {
		reserve(_size + n);
		for (int i = 0; i < n; i++)
			_data[_size + i] = s[i];
		_size += n;
	}
	return *this;
}

string& string::append(size_t n, char c)
{
	reserve(_size + n);
	for (int i = 0; i < n; i++)
		_data[_size + i] = c;
	_size += n;
	return *this;
}

void string::push_back(char c)
{
	reserve(_size + 1);
	_data[_size] = c;
	_size += 1;
}

string& string::assign(const string& str)
{
	return operator=(str);
}

string& string::assign(const string& str, size_t subpos, size_t sublen)
{
	if (str._data != NULL && subpos < str._size) {
		if (subpos + sublen > str._size)
			sublen = str._size - subpos;
		reserve(_size + sublen);
		for (int i = 0; i < sublen; i++)
			_data[i] = str._data[subpos + i];
		_size = sublen;
	}
	return *this;
}

string& string::assign(const char* s)
{
	return operator=(s);
}

string& string::assign(const char* s, size_t n)
{
	if (s != NULL && n <= strlen(s)) {
		reserve(_size + n);
		for (int i = 0; i < n; i++)
			_data[i] = s[i];
		_size = n;
	}
	return *this;
}

string& string::assign(size_t n, char c)
{
	reserve(_size + n);
	for (int i = 0; i < n; i++)
		_data[i] = c;
	_size = n;
}

std::ostream& operator<<(std::ostream& os, const string& str)
{
	for (int i=0; i<str.size(); i++)
		os << str[i];
	return os;
}
