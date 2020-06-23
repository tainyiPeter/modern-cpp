#include "stl_header.h"

using namespace std;

class SomeDataStructure {

};

class Widget {
public:
	//template<typename T>
	//void setName(T&& newName) // universal reference
	//{
	//	//name = std::move(newName);
	//	name = std::forward<T>(newName);
	//} // compiles, but is bad, bad, bad!

	void setName(const std::string& newName) // set from
	{
		cout << "const ..." << endl;
		name = newName;
	}

	void setName(std::string&& newName) // set from
	{
		cout << "&& ..." << endl;
		name = std::move(newName);
	} // rvalue

private:
	std::string name;
	std::shared_ptr<SomeDataStructure> p;
};


class Sign {
public:
	template <typename T>
	void setText(T&& txt) {

	}
};

class SignHistory {
	template <typename T>
	void add(__int64 level, T&& t)
	{

	}
};

template<typename T> // text is
void setSignText(T&& text) // univ. reference
{
	Sign sign;
	sign.setText(text); // use text, but
	// don't modify it
	auto now = // get current time
		std::chrono::system_clock::now();

	SignHistory signHistory;
	signHistory.add(now,
		std::forward<T>(text)); // conditionally cast
}

using Fraction = function<bool(int)>;

template<typename T>
Fraction // by-value return
reduceAndCopy(T&& frac) // universal reference param
{
	frac.reduce();
	return std::forward<T>(frac); // move rvalue into return
}


string getValue()
{
	string ret = "i am a dog";

	return std::move(ret);

}


//int main()
//{
//	string n = "panyanbo"; // n is local variable
//
//	string k = getValue();
//	cout << "k is " << k.c_str() << " n is " << n.c_str() << endl;
//	return 0;
//
//	Widget w;
//	w.setName("hello world!"); // moves n into w!
//
//	cout << "n is " << n.c_str() << endl;
//
//	return 0;
//}