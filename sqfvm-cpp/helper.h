#ifndef _HELPER
#define _HELPER 1

#if !defined(_STRING) & !defined(_STRING_)
#error parsesqf requires <string> header
#endif // !_STRING
#if !defined(_VECTOR) & !defined(_VECTOR_)
#error parsesqf requires <vector> header
#endif // !_VECTOR
#if !defined(_OSTREAM) & !defined(_OSTREAM_)
#error parsesqf requires <ostream> header
#endif // !_OSTREAM
#if !defined(_ASTNODE)
#error parsesqf requires "astnode.h" header
#endif // !_ASTNODE


namespace sqf
{
	namespace parse
	{

		class helper
		{
			std::wostream* merr;
			std::wstring(*mdbgsegmentcb)(const wchar_t*, size_t, size_t);
			bool(*mcontains_nular)(std::wstring);
			bool(*mcontains_unary)(std::wstring);
			bool(*mcontains_binary)(std::wstring);
			short(*mprecedence)(std::wstring);
		public:
			helper(
				std::wostream* err,
				std::wstring(*dbgsegment)(const wchar_t*, size_t, size_t),
				bool(*contains_nular)(std::wstring),
				bool(*contains_unary)(std::wstring),
				bool(*contains_binary)(std::wstring),
				short(*precedence)(std::wstring)
			) : merr(err), mdbgsegmentcb(dbgsegment), mcontains_nular(contains_nular), mcontains_unary(contains_unary), mcontains_binary(contains_binary), mprecedence(precedence) {}
			std::wostream& err(void) { return *merr; }
			std::wstring dbgsegment(const wchar_t* full, size_t off, size_t length) { return mdbgsegmentcb(full, off, length); }
			bool contains_nular(std::wstring s) { return mcontains_nular(s); }
			bool contains_unary(std::wstring s) { return mcontains_unary(s); }
			bool contains_binary(std::wstring s) { return mcontains_binary(s); }
			short precedence(std::wstring s) { return mprecedence(s); }
		};
	}
}

#endif // !_HELPER