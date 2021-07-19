#pragma once

template <typename K, typename V>
class Dictonary
{
public:
	struct Pair
	{
		K key;
		V value;
	};

	Dictonary(int nSize = 100)
	{
		m_pData = new Pair[nSize];
		m_nTableSize = nSize;
	}

	~Dictonary()
	{
	}

	void Add(K key, V value)
	{
		unsigned int nHash = Hash(key, sizeof(K));
		unsigned int nIndex = nHash % m_nTableSize;

		m_pData[nIndex].key = key;
		m_pData[nIndex].value = value;
	}

	V& operator[](K key)
	{
		unsigned int nHash = Hash(key, sizeof(K));
		unsigned int nIndex = nHash % m_nTableSize;

		return m_pData[nIndex].value;
	}

	unsigned int Hash(K key, int nSize)
	{
		unsigned int nHash = 0;
		for (unsigned int i = 0; i < nSize; ++i)
		{
			nHash = (nHash * 1313) + ((char*)&key)[i];
		}
		return nHash;
	}

private:
	Pair* m_pData;
	int m_nTableSize;
};

template <typename V>
class Dictonary<const char*, V>
{
public:
	struct Pair
	{
		const char* key;
		V value;
	};

	Dictonary(int nSize = 100)
	{
		m_pData = new Pair[nSize];
		m_nTableSize = nSize;
	}

	~Dictonary()
	{
	}

	void Add(const char* key, V value)
	{
		unsigned int nHash = Hash(key, strlen(key));
		unsigned int nIndex = nHash % m_nTableSize;

		m_pData[nIndex].key = key;
		m_pData[nIndex].value = value;
	}

	V& operator[](const char* key)
	{
		unsigned int nHash = Hash(key, strlen(key));
		unsigned int nIndex = nHash % m_nTableSize;

		return m_pData[nIndex].value;
	}

	unsigned int Hash(const char* key, int nSize)
	{
		unsigned int nHash = 0;
		for (unsigned int i = 0; i < nSize; ++i)
		{
			nHash = (nHash * 1313) + ((char*)&key)[i];
		}
		return nHash;
	}

private:
	Pair* m_pData;
	int m_nTableSize;
};
