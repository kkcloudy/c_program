#include<stdio.h>


#define HASH_SIZE 1024
#define MAC_LEN 6
#define IP_HASH(ip) (ip[0]+ip[1]+ip[2]+ip[3])
#define MAC_HASH(mac) (mac[2]+mac[3]+mac[4]+mac[5])
struct ip_info{
	unsigned int ip;
	unsigned char[MAC_LEN];
	struct ip_info *next;
	struct ip_info *hnext;
	struct ip_info *mhnext;
}

struct vir_pool{
	struct ip_info *ip_list;
	struct ip_info *ip_hash[HASH_SIZE];
	int ipnum;
	struct ip_info *last;
}
struct vir_dhcp{
char ifname[16];
char ifmac[MAC_LEN];
int low;
int high;
struct vir_pool dhcpfree;
struct vir_pool dhcprelease;
struct ip_info *cache_hash[HASH_LEN];
}
void dhcp_ip_hash_add(struct vir_pool *pool,struct ip_info *ip)
{
	if(pool == NULL || ip = NULL)
		return;
	unsigned char *tip =(unsigned char *)&(ip->ip);
	ip->hnext = pool->ip_hash[IP_HASH(tip)];
	pool->hash[IP_HASH(tip)] = ip;


}

void dhcp_ip_hash_del(struct vir_pool *pool,struct ip_info *ip)
{
	unsigned char *tip = (unsigned char *)(ip->ip)
	struct ip_info *s = pool->ip_hash[IP_HASH(tip)];
	
	if(s == NULL)
		return;
	if(s->ip == ip->ip){
		pool->ip_hash[IP_HASH(tip)] = s->hnext;
		return;
	}


	while(s->hnext != NULL){
	
		if(s->ip == ip->ip){
			s->hnext == s->hnext->hnext;
			return;
		}
		s = s->hnext;
	}
	return;
}


