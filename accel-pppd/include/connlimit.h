#ifndef __CONNLIMIT_H
#define __CONNLIMIT_H

static inline uint64_t cl_key_from_ipv4(uint32_t ip)
{
	return ip;
}

static inline uint64_t cl_key_from_mac(uint8_t hw[6])
{
	union {
		uint8_t hw[6];
		uint64_t key;
	} key;
	
	memcpy(key.hw, hw, sizeof(hw));

	return key.key;
}

int connlimit_check(uint64_t key);

#endif
