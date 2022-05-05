#include <cstdio>


unsigned int genPRNG ( const void * key, int len, unsigned int seed )
{

	const unsigned int m = 0x5bd1e995;
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
	
	return h;
} 

//test
main(){
    char input[2048];
    unsigned int m;
    unsigned int seed = 0x21367afd;
    scanf("%s", input);
    m = genPRNG(input,28, seed);
    printf("%02x \n", m);
    printf("\n");
    return 0;
}