#pragma once

static unsigned int seed = 0x21367afd;
const unsigned int m = 0x5bd1e995;

void seed_reset(){
	seed = 0x21367afd;
}

unsigned int prng(const void *key, int len) {
	const int r = 24;

	unsigned int h = seed ^ len;
	const unsigned char * data = (const unsigned char *)key;

	while(len >= 4)
	{
		unsigned int k = *(unsigned int *)data;

		k *= m; 
		k ^= k >> r; 
		k *= m; 
		
		h *= m; 
		h ^= k;

		data += 4;
		len -= 4;
	}
	
	switch(len)
	{
	case 3: h ^= data[2] << 16;
	case 2: h ^= data[1] << 8;
	case 1: h ^= data[0];
	        h *= m;
	};
	h ^= h >> 13;
	h *= m;
	h ^= h >> 15;
	seed = h;
	return h;
} 
