#ifndef PURE
#define PURE = 0
#endif

template<class T, int N>
class Hash
{
public:
	virtual unsigned h(T& entry) PURE;
	bool operator <<(T& entry);
	bool operator +=(T& entry);
	bool operator -=(T& entry);
	unsigned operator +();
	Hash& operator ~();
	T* operator>>(T& entry);

	bool prvni();
	T* aktual();
	bool dalsi();

	Hash() { init = false; }
	virtual ~Hash() { if (init) delete[] tab; }
private:
	T** tab;
	T* iter;
	unsigned akt;
	unsigned count;
	bool init;
};

template<class T, int N>
bool Hash<T, N>::operator<<(T& entry)
{
	unsigned index = h(entry);
	
	if (tab[index] == nullptr)
	{
		tab[index] = &entry;
		count++;
		return true;
	}

	return false;
}

template<class T, int N>
T* Hash<T, N>::operator>>(T& entry)
{
	unsigned index = h(entry);
	return tab[index];
}

template<class T, int N>
bool Hash<T, N>::operator+=(T& entry)
{
	return (*this << entry);
}

template<class T, int N>
bool Hash<T, N>::operator-=(T& entry)
{
	unsigned index = h(entry);

	if (*(tab[index]) == entry)
	{
		tab[index] = nullptr;
		count--;
		return true;
	}

	return false;
}

template<class T, int N>
unsigned Hash<T, N>::operator+()
{
	return count;
}

template<class T, int N>
Hash<T, N>& Hash<T, N>::operator~()
{
	if (init) delete[] tab;
	tab = new T*[N];
	for (int i = 0; i < N; ++i) tab[i] = nullptr;
	init = true;
	return *this;
}

template<class T, int N>
bool Hash<T, N>::prvni()
{
	for (akt = 0; akt < N; ++akt)
	{
		if (tab[akt] != nullptr)
		{
			iter = tab[akt++];
			return true;
		}
	}
	
	return false;
}

template<class T, int N>
T* Hash<T, N>::aktual()
{
	return iter;
}

template<class T, int N>
bool Hash<T, N>::dalsi()
{
	for (;akt < N;)
	{
		if (tab[akt] != nullptr)
		{
			iter = tab[akt++];
			return true;
		}

		akt++;
	}

	return false;
}