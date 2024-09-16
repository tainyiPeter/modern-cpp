#ifndef _LAZY_HPP_
#define _LAZY_HPP_

#include "optional.hpp"
#include <functional>

//#include <boost/optional.hpp>
template<typename T>
struct Lazy
{
	Lazy() {}

	template <typename Func, typename... Args>
	Lazy(Func& f, Args && ... args)
	{
		m_func = [&f, &args...]{ return f(args...); };
	}

	T& Value()
	{
		if (!m_value.IsInit())
		{
			m_value = m_func();
		}

		return *m_value;
	}

	bool IsValueCreated() const
	{
		return m_value.IsInit();
	}

private:
	std::function<T()> m_func;
	Optional<T> m_value;
};

template<class Func, typename... Args>
Lazy<typename std::result_of<Func(Args...)>::type>

lazy(Func && fun, Args && ... args)
{
	std:: cout << "call lazy ..." << std::endl;
	std::cout << "type:" << std::is_same<float, \
		std::result_of<Func(Args...)>::type>::value << std::endl;
	std::cout << "args cnt:" << sizeof ... (args) << std::endl;


	return Lazy<typename std::result_of<Func(Args...)>::type>(
		std::forward<Func>(fun), std::forward<Args>(args)...);
}















#endif