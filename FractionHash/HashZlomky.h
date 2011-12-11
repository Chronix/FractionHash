#include "hash.h"
#include "Zlomek.h"

template<int N>
class HashZlomky : public Hash<Zlomek, N>
{
public:
	unsigned h(Zlomek& entry);
};

template<int N>
inline unsigned HashZlomky<N>::h(Zlomek& entry)
{
	return (entry.a * entry.b) % N;
}